#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "token.h"
#include "type.h"
#include "symtab.h"
#include "typecheck.h"
#include "k0gram.tab.h"

/* =========================================================================
 * Helpers
 * ========================================================================= */

static void type_error(struct tree *t, const char *msg)
{
    const char *file = "<unknown>";
    int line = 0;
    /* Try to get location from first leaf in subtree */
    struct tree *cur = t;
    while (cur && !cur->leaf && cur->nkids > 0)
        cur = cur->kids[0];
    if (cur && cur->leaf) {
        if (cur->leaf->filename) file = cur->leaf->filename;
        line = cur->leaf->lineno;
    }
    fprintf(stderr, "%s:%d: error: %s\n", file, line, msg);
    semantic_errors++;
}

/* Are two types compatible for assignment (rhs -> lhs)?
 * Handles nullable: nullable can assign to nullable, but not to non-nullable.
 * none_type (inferred unknown) is compatible with anything. */
static int types_compatible(typeptr lhs, typeptr rhs)
{
    if (!lhs || !rhs) return 1;
    if (lhs == none_typeptr || rhs == none_typeptr) return 1;
    if (lhs->basetype == ANY_TYPE || rhs->basetype == ANY_TYPE) return 1;

    /* null literal can only go into a nullable type */
    if (rhs->basetype == NULL_TYPE) {
        return lhs->nullable;
    }

    /* base types must match */
    if (lhs->basetype != rhs->basetype) {
        /* Allow Int -> Float widening */
        if (lhs->basetype == FLOAT_TYPE && rhs->basetype == INT_TYPE) return 1;
        return 0;
    }

    /* Nullable check: nullable rhs cannot go into non-nullable lhs */
    if (rhs->nullable && !lhs->nullable) return 0;

    return 1;
}

/* Is this type numeric (Int or Float)? */
static int is_numeric(typeptr t)
{
    if (!t) return 0;
    return t->basetype == INT_TYPE || t->basetype == FLOAT_TYPE;
}

/* Result type of a numeric binary op: if either is float, result is float */
static typeptr numeric_result(typeptr a, typeptr b)
{
    if (!a || !b) return integer_typeptr;
    if (a->basetype == FLOAT_TYPE || b->basetype == FLOAT_TYPE)
        return float_typeptr;
    return integer_typeptr;
}

/* Find the local scope for a named function from the scope registry */
#define MAX_SCOPES 512
extern SymbolTable all_scopes[];   /* defined in symscan.c */
extern int         nscopes;

static SymbolTable find_func_scope(const char *fname)
{
    char label[256];
    snprintf(label, sizeof(label), "func %s", fname);
    for (int i = 0; i < nscopes; i++) {
        if (all_scopes[i]->scope_name &&
            strcmp(all_scopes[i]->scope_name, label) == 0)
            return all_scopes[i];
    }
    return NULL;
}

/* =========================================================================
 * Main type-checking traversal
 * Returns the inferred typeptr for the subtree.
 * ========================================================================= */
typeptr typecheck(struct tree *t, SymbolTable current)
{
    if (!t) return none_typeptr;

    /* ── Leaf nodes ───────────────────────────────────────────────── */
    if (t->leaf) {
        /* Return type already annotated by checksyms pass */
        if (t->type) return t->type;

        switch (t->leaf->category) {
            case INTEGERLITERAL:
            case LONGLITERAL:      return integer_typeptr;
            case REALLITERAL:
            case DOUBLELITERAL:    return float_typeptr;
            case BOOLEANLITERAL:   return bool_typeptr;
            case CHARACTERLITERAL: return char_typeptr;
            case STRINGLITERAL:    return string_typeptr;
            case NULLLITERAL:      return null_typeptr;
            case IDENT: {
                SymbolTableEntry e = lookupsym_chain(current, t->leaf->text);
                if (e) { t->type = e->type; return e->type; }
                return none_typeptr;
            }
            default: return none_typeptr;
        }
    }

    const char *name = t->symbolname ? t->symbolname : "";

    /* ── Skip type annotation subtrees ───────────────────────────── */
    if (strcmp(name, "optional_type_annotation") == 0 ||
        strcmp(name, "optional_return_type")     == 0 ||
        strcmp(name, "full_type") == 0 ||
        strcmp(name, "type")      == 0 ||
        strcmp(name, "type_args") == 0)
        return none_typeptr;

    /* ── Skip import paths ────────────────────────────────────────── */
    if (strcmp(name, "import_declaration") == 0 ||
        strcmp(name, "import_path")        == 0 ||
        strcmp(name, "import_list")        == 0)
        return none_typeptr;

    /* ── function_declaration: typecheck body under local scope ──── */
    if (strcmp(name, "function_declaration") == 0) {
        SymbolTable local = NULL;
        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf) {
            local = find_func_scope(t->kids[1]->leaf->text);
        }
        if (!local) local = current;
        /* Skip kids[0..2] (FUN, name, params) -- check body */
        for (int i = 3; i < t->nkids; i++)
            typecheck(t->kids[i], local);
        return none_typeptr;
    }

    /* ── property_declaration: check initializer type ────────────── */
    if (strcmp(name, "property_declaration") == 0) {
        /* Get the declared name and its symbol entry */
        int is_const = 0;
        (void)is_const;  /* suppress unused warning -- reserved for future use */
        int name_idx = 1;
        if (t->nkids >= 1 && t->kids[0] && t->kids[0]->leaf &&
            t->kids[0]->leaf->category == CONST) {
            is_const = 1; name_idx = 2;
        }
        char *vname = NULL;
        if (name_idx < t->nkids && t->kids[name_idx] &&
            t->kids[name_idx]->leaf)
            vname = t->kids[name_idx]->leaf->text;

        /* Typecheck the initializer (last kid) */
        int last = t->nkids - 1;
        if (last > name_idx && t->kids[last] && t->kids[last]->symbolname &&
            strcmp(t->kids[last]->symbolname, "optional_initializer") == 0) {
            typeptr init_type = typecheck(t->kids[last], current);
            /* Check initializer type matches declared type */
            if (vname) {
                SymbolTableEntry e = lookupsym_chain(current, vname);
                if (e && e->type && init_type &&
                    init_type != none_typeptr) {
                    if (!types_compatible(e->type, init_type)) {
                        char msg[256];
                        snprintf(msg, sizeof(msg),
                            "type mismatch in declaration of '%s': "
                            "expected %s, got %s",
                            vname, typename(e->type), typename(init_type));
                        type_error(t->kids[last], msg);
                    }
                    /* Nullability: assigning null to non-nullable */
                    if (init_type->basetype == NULL_TYPE &&
                        e->type && !e->type->nullable) {
                        char msg[256];
                        snprintf(msg, sizeof(msg),
                            "null cannot be assigned to non-nullable '%s'",
                            vname);
                        type_error(t->kids[last], msg);
                    }
                }
            }
        }
        return none_typeptr;
    }

    /* ── Assignment expression: check mutability + types ─────────── */
    if (strcmp(name, "expression") == 0 && t->nkids == 3) {
        /* disjunction ASSIGN_OP expression */
        int op_cat = 0;
        if (t->kids[1] && t->kids[1]->leaf)
            op_cat = t->kids[1]->leaf->category;

        int is_assign = (op_cat == ASSIGNMENT || op_cat == ADD_ASSIGN ||
                         op_cat == SUB_ASSIGN  || op_cat == MUL_ASSIGN ||
                         op_cat == DIV_ASSIGN  || op_cat == MOD_ASSIGN);
        if (is_assign) {
            /* LHS must be a mutable (var) variable */
            struct tree *lhs = t->kids[0];
            /* Walk through expression wrappers to find the IDENT */
            struct tree *cur = lhs;
            while (cur && !cur->leaf && cur->nkids == 1)
                cur = cur->kids[0];
            if (cur && cur->leaf && cur->leaf->category == IDENT) {
                SymbolTableEntry e = lookupsym_chain(current,
                                                      cur->leaf->text);
                if (e) {
                    if (!e->is_mutable) {
                        char msg[256];
                        snprintf(msg, sizeof(msg),
                            "assignment to immutable variable '%s' "
                            "(declared as %s)",
                            e->name, e->is_const ? "const val" : "val");
                        type_error(cur, msg);
                    }
                    /* Type check rhs against lhs */
                    typeptr rhs_type = typecheck(t->kids[2], current);
                    if (rhs_type && rhs_type != none_typeptr &&
                        e->type && !types_compatible(e->type, rhs_type)) {
                        char msg[256];
                        snprintf(msg, sizeof(msg),
                            "type mismatch in assignment to '%s': "
                            "expected %s, got %s",
                            e->name, typename(e->type), typename(rhs_type));
                        type_error(t->kids[1], msg);
                    }
                    /* Nullability */
                    if (rhs_type && rhs_type->basetype == NULL_TYPE &&
                        e->type && !e->type->nullable) {
                        char msg[256];
                        snprintf(msg, sizeof(msg),
                            "null cannot be assigned to non-nullable '%s'",
                            e->name);
                        type_error(t->kids[1], msg);
                    }
                }
            }
            typecheck(t->kids[0], current);
            typecheck(t->kids[2], current);
            return none_typeptr;
        }
    }

    /* ── Arithmetic operators ─────────────────────────────────────── */
    if (strcmp(name, "additive_expr") == 0 ||
        strcmp(name, "multiplicative_expr") == 0) {
        if (t->nkids == 3) {
            typeptr lt = typecheck(t->kids[0], current);
            typecheck(t->kids[1], current);
            typeptr rt = typecheck(t->kids[2], current);
            /* String + String is OK (concatenation) */
            if (t->kids[1] && t->kids[1]->leaf &&
                t->kids[1]->leaf->category == ADD &&
                lt && lt->basetype == STRING_TYPE &&
                rt && rt->basetype == STRING_TYPE)
                return string_typeptr;
            if (lt != none_typeptr && rt != none_typeptr) {
                if (!is_numeric(lt)) {
                    char msg[128];
                    snprintf(msg, sizeof(msg),
                        "non-numeric left operand (%s) in arithmetic",
                        typename(lt));
                    type_error(t->kids[0], msg);
                }
                if (!is_numeric(rt)) {
                    char msg[128];
                    snprintf(msg, sizeof(msg),
                        "non-numeric right operand (%s) in arithmetic",
                        typename(rt));
                    type_error(t->kids[2], msg);
                }
            }
            t->type = numeric_result(lt, rt);
            return t->type;
        }
    }

    /* ── Comparison operators: result is bool ─────────────────────── */
    if (strcmp(name, "comparison_expr") == 0 ||
        strcmp(name, "equality_expr")   == 0) {
        if (t->nkids == 3) {
            typeptr lt = typecheck(t->kids[0], current);
            typecheck(t->kids[1], current);
            typeptr rt = typecheck(t->kids[2], current);
            /* Both sides should be the same base type */
            if (lt != none_typeptr && rt != none_typeptr &&
                lt->basetype != ANY_TYPE && rt->basetype != ANY_TYPE &&
                lt->basetype != rt->basetype &&
                !(is_numeric(lt) && is_numeric(rt))) {
                char msg[128];
                snprintf(msg, sizeof(msg),
                    "incompatible types in comparison: %s vs %s",
                    typename(lt), typename(rt));
                type_error(t->kids[1], msg);
            }
            t->type = bool_typeptr;
            return bool_typeptr;
        }
    }

    /* ── Logical operators: operands must be bool ─────────────────── */
    if (strcmp(name, "conjunction") == 0 ||
        strcmp(name, "disjunction") == 0) {
        if (t->nkids == 3) {
            typeptr lt = typecheck(t->kids[0], current);
            typecheck(t->kids[1], current);
            typeptr rt = typecheck(t->kids[2], current);
            if (lt != none_typeptr && lt->basetype != BOOL_TYPE &&
                lt->basetype != ANY_TYPE) {
                type_error(t->kids[0],
                    "non-boolean operand in logical expression");
            }
            if (rt != none_typeptr && rt->basetype != BOOL_TYPE &&
                rt->basetype != ANY_TYPE) {
                type_error(t->kids[2],
                    "non-boolean operand in logical expression");
            }
            t->type = bool_typeptr;
            return bool_typeptr;
        }
    }

    /* ── Prefix NOT: operand must be bool ─────────────────────────── */
    if (strcmp(name, "prefix_expr") == 0 && t->nkids == 2) {
        if (t->kids[0] && t->kids[0]->leaf &&
            t->kids[0]->leaf->category == NOT) {
            typeptr ot = typecheck(t->kids[1], current);
            if (ot != none_typeptr && ot->basetype != BOOL_TYPE &&
                ot->basetype != ANY_TYPE) {
                type_error(t->kids[1],
                    "non-boolean operand for '!' operator");
            }
            t->type = bool_typeptr;
            return bool_typeptr;
        }
        /* Unary minus/plus: operand must be numeric */
        if (t->kids[0] && t->kids[0]->leaf &&
            (t->kids[0]->leaf->category == SUB ||
             t->kids[0]->leaf->category == ADD)) {
            typeptr ot = typecheck(t->kids[1], current);
            if (ot != none_typeptr && !is_numeric(ot) &&
                ot->basetype != ANY_TYPE) {
                type_error(t->kids[1],
                    "non-numeric operand for unary +/-");
            }
            t->type = ot ? ot : integer_typeptr;
            return t->type;
        }
    }

    /* ── Function call: check argument count ──────────────────────── */
    if (strcmp(name, "postfix_expr") == 0 && t->nkids == 4) {
        /* postfix_expr LPAREN optional_value_arguments RPAREN */
        if (t->kids[1] && t->kids[1]->leaf &&
            t->kids[1]->leaf->category == LPAREN) {
            typeptr callee_type = typecheck(t->kids[0], current);

            /* Count arguments passed */
            int nargs = 0;
            struct tree *args = t->kids[2];
            if (args && args->symbolname) {
                if (strcmp(args->symbolname, "value_argument_list") == 0 ||
                    strcmp(args->symbolname, "value_argument") == 0) {
                    /* Count by traversing the left-recursive list */
                    struct tree *cur = args;
                    while (cur && cur->nkids >= 1) {
                        nargs++;
                        if (cur->nkids == 3)
                            cur = cur->kids[0];
                        else
                            break;
                    }
                    if (nargs == 0) nargs = 1;
                }
            }

            /* Check against declared parameter count if known */
            if (callee_type && callee_type->basetype == FUNC_TYPE &&
                callee_type->u.f.nparams > 0 &&
                nargs != callee_type->u.f.nparams) {
                char msg[128];
                snprintf(msg, sizeof(msg),
                    "wrong number of arguments: expected %d, got %d",
                    callee_type->u.f.nparams, nargs);
                type_error(t, msg);
            }

            /* Typecheck arguments */
            if (t->kids[2]) typecheck(t->kids[2], current);

            /* Return type of the call */
            if (callee_type && callee_type->basetype == FUNC_TYPE &&
                callee_type->u.f.returntype)
                return callee_type->u.f.returntype;
            return none_typeptr;
        }
    }

    /* ── if_expression: condition must be bool ────────────────────── */
    if (strcmp(name, "if_expression") == 0) {
        /* IF LPAREN condition RPAREN ... */
        if (t->nkids >= 3) {
            typeptr cond = typecheck(t->kids[2], current);
            if (cond != none_typeptr && cond->basetype != BOOL_TYPE &&
                cond->basetype != ANY_TYPE) {
                type_error(t->kids[2],
                    "if condition must be boolean");
            }
            for (int i = 3; i < t->nkids; i++)
                typecheck(t->kids[i], current);
        }
        return none_typeptr;
    }

    /* ── while_statement: condition must be bool ──────────────────── */
    if (strcmp(name, "while_statement") == 0) {
        if (t->nkids >= 3) {
            typeptr cond = typecheck(t->kids[2], current);
            if (cond != none_typeptr && cond->basetype != BOOL_TYPE &&
                cond->basetype != ANY_TYPE) {
                type_error(t->kids[2],
                    "while condition must be boolean");
            }
            for (int i = 3; i < t->nkids; i++)
                typecheck(t->kids[i], current);
        }
        return none_typeptr;
    }

    /* ── return_statement: infer return type (no checking for now) ── */
    if (strcmp(name, "return_statement") == 0) {
        if (t->nkids >= 2)
            return typecheck(t->kids[1], current);
        return none_typeptr;
    }

    /* ── Elvis operator: result is non-nullable ───────────────────── */
    if (strcmp(name, "elvis_expr") == 0 && t->nkids == 3) {
        typeptr lt = typecheck(t->kids[0], current);
        typeptr rt = typecheck(t->kids[2], current);
        /* If lhs is nullable T?, result is T */
        if (lt && lt->nullable) {
            typeptr result = alctype(lt->basetype);
            result->nullable = 0;
            t->type = result;
            return result;
        }
        (void)rt;
        t->type = lt ? lt : none_typeptr;
        return t->type;
    }

    /* ── optional_initializer: just return the expression type ─────── */
    if (strcmp(name, "optional_initializer") == 0) {
        /* kids: ASSIGNMENT expression -- return type of expression (kids[1]) */
        if (t->nkids >= 2 && t->kids[1])
            return typecheck(t->kids[1], current);
        if (t->nkids == 1 && t->kids[0])
            return typecheck(t->kids[0], current);
        return none_typeptr;
    }

    /* ── Default: recurse into all children ──────────────────────── */
    typeptr last_type = none_typeptr;
    for (int i = 0; i < t->nkids; i++) {
        typeptr ct = typecheck(t->kids[i], current);
        /* If a call returns func type, unwrap to return type */
        if (ct && ct->basetype == FUNC_TYPE && ct->u.f.returntype)
            ct = ct->u.f.returntype;
        if (ct && ct != none_typeptr) last_type = ct;
    }
    t->type = last_type;
    return last_type;
}