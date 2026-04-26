/*
 * codegen.c -- HW6: Three-address intermediate code generation for K0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "token.h"
#include "type.h"
#include "symtab.h"
#include "tac.h"
#include "codegen.h"
#include "prodrule.h"
#include <ctype.h>
#include "k0gram.tab.h"

/* =========================================================================
 * String constant region
 * ========================================================================= */
#define MAX_STRINGS 256
static char *string_table[MAX_STRINGS];
static int   string_offsets[MAX_STRINGS];
static int   nstrings = 0;
static int   string_region_bytes = 0;

void add_string_const(const char *s)
{
    if (!s) return;
    /* Check if already present */
    for (int i = 0; i < nstrings; i++)
        if (strcmp(string_table[i], s) == 0) return;
    if (nstrings >= MAX_STRINGS) return;
    string_table[nstrings]   = strdup(s);
    string_offsets[nstrings] = string_region_bytes;
    /* Round up to next multiple of 8 */
    int len = strlen(s) + 1;  /* +1 for NUL */
    string_region_bytes += (len + 7) & ~7;
    nstrings++;
}

int string_const_offset(const char *s)
{
    if (!s) return 0;
    for (int i = 0; i < nstrings; i++)
        if (strcmp(string_table[i], s) == 0) return string_offsets[i];
    add_string_const(s);
    return string_const_offset(s);
}

int string_region_size(void) { return string_region_bytes; }

void print_string_region(FILE *f)
{
    if (nstrings == 0) return;
    fprintf(f, ".string\t%d\n", string_region_bytes);
    for (int i = 0; i < nstrings; i++) {
        fprintf(f, "\t");
        const char *s = string_table[i];
        while (*s) {
            unsigned char c = (unsigned char)*s++;
            if (c == '\n')       fprintf(f, "\\012");
            else if (c == '\t')  fprintf(f, "\\011");
            else if (c == '\\')  fprintf(f, "\\\\");
            else if (c < 32 || c > 126) fprintf(f, "\\%03o", c);
            else                 fputc(c, f);
        }
        fprintf(f, "\\000\n");
    }
}

/* =========================================================================
 * Temporary variable allocator
 * ========================================================================= */
static int temp_offset = 0;

int new_temp(void)
{
    int t = temp_offset;
    temp_offset += 8;
    return t;
}

void reset_temps(int start_offset)
{
    temp_offset = start_offset;
}

/* =========================================================================
 * Helpers
 * ========================================================================= */

/* Find function scope by name */
extern SymbolTable all_scopes[];
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

/* Get the addr for a named symbol, searching scope chain */
static struct addr addr_of(const char *name, SymbolTable current)
{
    SymbolTableEntry e = lookupsym_chain(current, (char*)name);
    if (e) return e->place;
    /* Unknown -- use a name reference */
    return ADDR_NAME((char*)name);
}

/* =========================================================================
 * Lab 10: Control-flow label assignment traversals
 * ========================================================================= */
void assign_first(struct tree *t)
{
    if (!t) return;

    for (int i = 0; i < t->nkids; i++)
        assign_first(t->kids[i]);

    switch (t->prodrule) {
    case R_STATEMENT:
    case R_SIMPLE_STATEMENT:
    case R_BLOCK:
    case R_CONTROL_STRUCTURE_BODY:
    case R_IF_EXPRESSION:
    case R_WHILE_STATEMENT:
    case R_DO_WHILE_STATEMENT:
    case R_FOR_STATEMENT:
        t->first = genlabel();
        t->has_first = 1;
        break;
    default:
        break;
    }
}

void assign_follow(struct tree *t)
{
    if (!t) return;

    if (t->prodrule == R_STATEMENTS || t->prodrule == R_STATEMENT_LIST) {
        for (int i = 0; i + 1 < t->nkids; i++) {
            if (t->kids[i] && t->kids[i + 1] && t->kids[i + 1]->has_first) {
                t->kids[i]->follow = t->kids[i + 1]->first;
                t->kids[i]->has_follow = 1;
            }
        }
        if (t->has_follow && t->nkids > 0 && t->kids[t->nkids - 1]) {
            t->kids[t->nkids - 1]->follow = t->follow;
            t->kids[t->nkids - 1]->has_follow = 1;
        }
    }

    if (t->prodrule == R_IF_EXPRESSION) {
        struct tree *then_body = (t->nkids >= 5) ? t->kids[4] : NULL;
        struct tree *else_body = (t->nkids >= 7) ? t->kids[6] : NULL;
        if (then_body && t->has_follow) {
            then_body->follow = t->follow;
            then_body->has_follow = 1;
        }
        if (else_body && t->has_follow) {
            else_body->follow = t->follow;
            else_body->has_follow = 1;
        }
    }

    if (t->prodrule == R_WHILE_STATEMENT) {
        struct tree *body = (t->nkids >= 5) ? t->kids[4] : NULL;
        if (body && t->has_first) {
            body->follow = t->first;
            body->has_follow = 1;
        }
    }

    for (int i = 0; i < t->nkids; i++)
        assign_follow(t->kids[i]);
}

void assign_bool_labels(struct tree *t)
{
    if (!t) return;

    if (t->prodrule == R_IF_EXPRESSION) {
        struct tree *cond = (t->nkids >= 3) ? t->kids[2] : NULL;
        struct tree *then_body = (t->nkids >= 5) ? t->kids[4] : NULL;
        struct tree *else_body = (t->nkids >= 7) ? t->kids[6] : NULL;
        if (cond && then_body && then_body->has_first) {
            cond->onTrue = then_body->first;
            cond->has_onTrue = 1;
        }
        if (cond) {
            if (else_body && else_body->has_first)
                cond->onFalse = else_body->first;
            else if (t->has_follow)
                cond->onFalse = t->follow;
            else
                cond->onFalse = genlabel();
            cond->has_onFalse = 1;
        }
    }

    if (t->prodrule == R_WHILE_STATEMENT) {
        struct tree *cond = (t->nkids >= 3) ? t->kids[2] : NULL;
        struct tree *body = (t->nkids >= 5) ? t->kids[4] : NULL;
        if (cond && body && body->has_first) {
            cond->onTrue = body->first;
            cond->has_onTrue = 1;
        }
        if (cond) {
            cond->onFalse = t->has_follow ? t->follow : genlabel();
            cond->has_onFalse = 1;
        }
    }

    for (int i = 0; i < t->nkids; i++)
        assign_bool_labels(t->kids[i]);
}
/*
 * Main code generation traversal
 *
 * Returns a linked list of TAC instructions for the subtree.
 * Sets t->place to the address where the expression result is stored.
 * ========================================================================= */
struct instr *codegen(struct tree *t, SymbolTable current)
{
    if (!t) return NULL;

    /* Leaf nodes */
    if (t->leaf) {
        switch (t->leaf->category) {
        case INTEGERLITERAL:
        case LONGLITERAL:
            t->place = ADDR_CONST(t->leaf->ival);
            return NULL;
        case REALLITERAL:
        case DOUBLELITERAL:
            /* Float constants -- store as int bits for now */
            t->place = ADDR_CONST((int)t->leaf->dval);
            return NULL;
        case BOOLEANLITERAL:
            t->place = ADDR_CONST(strcmp(t->leaf->text, "true") == 0 ? 1 : 0);
            return NULL;
        case STRINGLITERAL: {
            /* Strip surrounding quotes */
            char *raw = t->leaf->text;
            char *s = raw;
            int len = strlen(raw);
            if (len >= 2 && raw[0] == '"') {
                s = strndup(raw + 1, len - 2);
            }
            add_string_const(s);
            int off = string_const_offset(s);
            /* Store address of string into a temp */
            int tmp = new_temp();
            struct instr *i = gen(O_ADDR,
                                  ADDR_LOCAL(tmp),
                                  ADDR_STRING(off),
                                  ADDR_NONE);
            t->place = ADDR_LOCAL(tmp);
            return i;
        }
        case NULLLITERAL:
            t->place = ADDR_CONST(0);
            return NULL;
        case IDENT: {
            t->place = addr_of(t->leaf->text, current);
            return NULL;
        }
        default:
            t->place = ADDR_NONE;
            return NULL;
        }
    }

    const char *name = t->symbolname ? t->symbolname : "";

    /* ── collection_literal: just recurse for side effects, no place ── */
    if (strcmp(name, "collection_literal") == 0 ||
        strcmp(name, "collection_items")   == 0) {
        struct instr *code = NULL;
        for (int i = 0; i < t->nkids; i++)
            code = append(code, codegen(t->kids[i], current));
        t->place = ADDR_NONE;
        return code;
    }

    /* ── postfix_expr dot/safe-call/double-colon: skip member name ── */
    if (strcmp(name, "postfix_expr") == 0 && t->nkids == 3) {
        if (t->kids[1] && t->kids[1]->leaf) {
            int op = t->kids[1]->leaf->category;
            if (op == DOUBLE_COLON) {
                /* x::method -- return ADDR_NAME of the method */
                if (t->kids[2] && t->kids[2]->leaf)
                    t->place = ADDR_NAME(t->kids[2]->leaf->text);
                else
                    t->place = ADDR_NONE;
                return NULL;
            }
            if (op == DOT || op == SAFE_CALL) {
                /* receiver.member -- evaluate receiver, result is opaque */
                struct instr *code = codegen(t->kids[0], current);
                /* Use a temp to represent the result of the member access */
                int tmp = new_temp();
                t->place = ADDR_LOCAL(tmp);
                return code;
            }
        }
    }

    /* ── Skip type annotation subtrees ───────────────────────────── */
    if (strcmp(name, "optional_type_annotation") == 0 ||
        strcmp(name, "optional_return_type")     == 0 ||
        strcmp(name, "full_type") == 0 ||
        strcmp(name, "type")      == 0 ||
        strcmp(name, "type_args") == 0 ||
        strcmp(name, "import_list") == 0 ||
        strcmp(name, "import_declaration") == 0 ||
        strcmp(name, "import_path") == 0) {
        t->place = ADDR_NONE;
        return NULL;
    }

    /* ── program: generate all top-level objects ──────────────────── */
    if (strcmp(name, "program") == 0) {
        /* Assign global variable offsets before generating code */
        assign_offsets(current, R_GLOBAL);
        struct instr *code = NULL;
        for (int i = 0; i < t->nkids; i++)
            code = append(code, codegen(t->kids[i], current));
        return code;
    }

    /* ── function_declaration ─────────────────────────────────────── */
    if (strcmp(name, "function_declaration") == 0) {
        char *fname = NULL;
        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf)
            fname = t->kids[1]->leaf->text;

        SymbolTable local = fname ? find_func_scope(fname) : current;
        if (!local) local = current;

        /* Assign offsets to locals and params */
        assign_offsets(local, R_LOCAL);
        /* Reset temp counter to just past the last local */
        int frame_base = local->nEntries * 8;
        reset_temps(frame_base);

        struct instr *code = NULL;

        /* proc pseudo-instruction */
        code = append(code, gen(D_PROC,
                                ADDR_NAME(fname ? fname : "?"),
                                ADDR_CONST(0),
                                ADDR_CONST(frame_base + 64)));

        /* Generate body */
        for (int i = 3; i < t->nkids; i++)
            code = append(code, codegen(t->kids[i], local));

        /* Implicit return const:0 for void functions (spec requirement) */
        code = append(code, gen(O_RET, ADDR_NONE, ADDR_CONST(0), ADDR_NONE));

        /* end pseudo-instruction */
        code = append(code, gen(D_END,
                                ADDR_NAME(fname ? fname : "?"),
                                ADDR_NONE,
                                ADDR_NONE));
        t->place = ADDR_NONE;
        return code;
    }

    /* ── property_declaration: emit ASN for initializer ──────────── */
    if (strcmp(name, "property_declaration") == 0) {
        int name_idx = 1;
        if (t->nkids >= 1 && t->kids[0] && t->kids[0]->leaf &&
            t->kids[0]->leaf->category == CONST)
            name_idx = 2;

        char *vname = NULL;
        if (name_idx < t->nkids && t->kids[name_idx] &&
            t->kids[name_idx]->leaf)
            vname = t->kids[name_idx]->leaf->text;

        struct addr dest = vname ? addr_of(vname, current) : ADDR_NONE;

        /* Find optional_initializer (last kid) */
        struct instr *code = NULL;
        int last = t->nkids - 1;
        if (last > name_idx && t->kids[last] && t->kids[last]->symbolname &&
            strcmp(t->kids[last]->symbolname, "optional_initializer") == 0) {
            /* optional_initializer: ASSIGNMENT expression
             * The expression is kids[1] (or kids[0] if only 1 kid) */
            struct tree *init = t->kids[last];
            struct tree *expr = NULL;
            for (int i = 0; i < init->nkids; i++) {
                if (init->kids[i] && init->kids[i]->leaf &&
                    init->kids[i]->leaf->category == ASSIGNMENT)
                    continue;
                expr = init->kids[i];
            }
            if (expr) {
                code = append(code, codegen(expr, current));
                /* Only emit ASN if we have both a valid dest and valid src */
                if (dest.region != R_NONE && dest.region != 0 &&
                    expr->place.region != R_NONE && expr->place.region != 0)
                    code = append(code, gen(O_ASN, dest, expr->place, ADDR_NONE));
            }
        }
        t->place = dest;
        return code;
    }

    /* ── Assignment expression ────────────────────────────────────── */
    if (strcmp(name, "expression") == 0 && t->nkids == 3) {
        int op_cat = 0;
        if (t->kids[1] && t->kids[1]->leaf)
            op_cat = t->kids[1]->leaf->category;

        int tac_op = -1;
        switch (op_cat) {
            case ASSIGNMENT: tac_op = O_ASN; break;
            case ADD_ASSIGN: tac_op = O_ADD; break;
            case SUB_ASSIGN: tac_op = O_SUB; break;
            case MUL_ASSIGN: tac_op = O_MUL; break;
            case DIV_ASSIGN: tac_op = O_DIV; break;
            case MOD_ASSIGN: tac_op = O_DIV; break; /* no MOD opcode, use DIV */
        }

        struct instr *code = codegen(t->kids[0], current);
        struct addr lhs = t->kids[0]->place;
        code = append(code, codegen(t->kids[2], current));
        struct addr rhs = t->kids[2]->place;

        if (tac_op == O_ASN) {
            code = append(code, gen(O_ASN, lhs, rhs, ADDR_NONE));
        } else if (tac_op > 0) {
            /* compound: lhs = lhs op rhs */
            int tmp = new_temp();
            code = append(code, gen(tac_op, ADDR_LOCAL(tmp), lhs, rhs));
            code = append(code, gen(O_ASN, lhs, ADDR_LOCAL(tmp), ADDR_NONE));
        }
        t->place = lhs;
        return code;
    }

    /* ── range_expr: place = start value (left side) ────────────── */
    if (strcmp(name, "range_expr") == 0 && t->nkids == 3) {
        struct instr *code = codegen(t->kids[0], current);
        code = append(code, codegen(t->kids[2], current));
        /* Place is the start of the range (left operand) */
        t->place = t->kids[0]->place;
        return code;
    }

    /* ── Binary arithmetic / comparison ──────────────────────────── */
    if (strcmp(name, "additive_expr")       == 0 ||
        strcmp(name, "multiplicative_expr") == 0 ||
        strcmp(name, "equality_expr")       == 0 ||
        strcmp(name, "comparison_expr")     == 0 ||
        strcmp(name, "conjunction")         == 0 ||
        strcmp(name, "disjunction")         == 0) {
        if (t->nkids == 3) {
            struct instr *code = codegen(t->kids[0], current);
            struct addr l = t->kids[0]->place;
            int op_cat = 0;
            if (t->kids[1] && t->kids[1]->leaf)
                op_cat = t->kids[1]->leaf->category;
            code = append(code, codegen(t->kids[2], current));
            struct addr r = t->kids[2]->place;

            int tac_op = O_ADD;
            switch (op_cat) {
                case ADD:    tac_op = O_ADD; break;
                case SUB:    tac_op = O_SUB; break;
                case MUL:    tac_op = O_MUL; break;
                case DIV:    tac_op = O_DIV; break;
                case MOD:    tac_op = O_DIV; break;
                case AND:    tac_op = O_BIF; break;
                case OR:     tac_op = O_BIF; break;
                case EQ:     tac_op = O_BEQ; break;
                case NEQ:    tac_op = O_BNE; break;
                case LANGLE: tac_op = O_BLT; break;
                case RANGLE: tac_op = O_BGT; break;
                case LTE:    tac_op = O_BLE; break;
                case GTE:    tac_op = O_BGE; break;
                default:     tac_op = O_ADD; break;
            }

            int tmp = new_temp();
            code = append(code, gen(tac_op, ADDR_LOCAL(tmp), l, r));
            t->place = ADDR_LOCAL(tmp);
            return code;
        }
    }

    /* ── Unary prefix ─────────────────────────────────────────────── */
    if (strcmp(name, "prefix_expr") == 0 && t->nkids == 2) {
        struct instr *code = codegen(t->kids[1], current);
        struct addr operand = t->kids[1]->place;
        int op_cat = 0;
        if (t->kids[0] && t->kids[0]->leaf)
            op_cat = t->kids[0]->leaf->category;

        if (op_cat == SUB) {
            int tmp = new_temp();
            code = append(code, gen(O_NEG, ADDR_LOCAL(tmp), operand, ADDR_NONE));
            t->place = ADDR_LOCAL(tmp);
        } else {
            t->place = operand;
        }
        return code;
    }

    /* ── Function call (postfix_expr with LPAREN) ─────────────────── */
    if (strcmp(name, "postfix_expr") == 0 && t->nkids == 4) {
        if (t->kids[1] && t->kids[1]->leaf &&
            t->kids[1]->leaf->category == LPAREN) {

            /* Get callee name */
            char *fname = NULL;
            struct tree *callee = t->kids[0];
            while (callee && !callee->leaf && callee->nkids == 1)
                callee = callee->kids[0];
            if (callee && callee->leaf && callee->leaf->category == IDENT)
                fname = callee->leaf->text;

            /* Map println -> printf with format string */
            int is_println = fname && strcmp(fname, "println") == 0;

            struct instr *code = NULL;

            /* Generate argument expressions */
            struct tree *args = t->kids[2];
            struct instr *arg_code = NULL;
            struct addr  arg_addrs[32];
            int nargs = 0;

            /* Collect args by walking the value_argument_list */
            struct tree *stack[64];
            int top = 0;
            struct tree *cur = args;
            while (cur && cur->symbolname) {
                if (strcmp(cur->symbolname, "value_argument_list") == 0
                    && cur->nkids == 3) {
                    stack[top++] = cur->kids[2];
                    cur = cur->kids[0];
                } else {
                    stack[top++] = cur;
                    break;
                }
            }
            /* stack now has args in reverse order, reverse it.
             * For println: skip codegen here -- the handler regenerates
             * args in the correct order (after format string addr). */
            for (int i = 0; i < top; i++) {
                struct tree *arg = stack[top - 1 - i];
                if (!is_println) {
                    arg_code = append(arg_code, codegen(arg, current));
                    if (nargs < 32) arg_addrs[nargs++] = arg->place;
                } else {
                    nargs++;  /* just count args for println */
                }
            }
            if (!is_println)
                code = append(code, arg_code);

            /* For println: add format string as first param */
            if (is_println) {
                /* Determine format string based on argument type:
                 * - STRINGLITERAL arg: the arg already holds a string addr
                 *   from an O_ADDR instruction -- use it directly as the
                 *   format string (no extra fmt needed, just call printf)
                 * - Any other arg (numeric, bool, etc.): use %d\n format */
                int arg_is_string = 0;
                if (nargs == 1) {
                    /* Walk the original arg subtree to check if it was a
                     * string literal */
                    struct tree *arg_tree = (top > 0) ? stack[0] : NULL;
                    /* Unwrap pass-through nodes */
                    while (arg_tree && !arg_tree->leaf && arg_tree->nkids == 1)
                        arg_tree = arg_tree->kids[0];
                    if (arg_tree && arg_tree->leaf &&
                        arg_tree->leaf->category == STRINGLITERAL)
                        arg_is_string = 1;
                }

                if (arg_is_string && nargs == 1) {
                    /* println("some string") -- arg IS the format string */
                    /* parm the string addr, call printf with 1 arg */
                    code = append(code, gen(O_PARM, ADDR_NONE,
                                           arg_addrs[0], ADDR_NONE));
                    int result = new_temp();
                    code = append(code, gen(O_CALL,
                                           ADDR_NAME("printf"),
                                           ADDR_CONST(1),
                                           ADDR_LOCAL(result)));
                    t->place = ADDR_LOCAL(result);
                    return code;
                }

                /* println(expr) -- numeric/bool: use %d\n format string.
                 * Emit in spec order:
                 *   1. addr  loc:fmt, string:0   (load format string)
                 *   2. <arg code already emitted above in arg_code>
                 *   3. parm  loc:value            (push value, rightmost param)
                 *   4. parm  loc:fmt              (push format string)
                 *   5. call  printf, 2, loc:result */
                add_string_const("%d\n");
                int sfmt = string_const_offset("%d\n");
                /* Allocate the format string temp BEFORE arg temps so it
                 * gets a lower offset, matching the spec layout */
                int tmp_str = new_temp();
                struct instr *fmt_instr = gen(O_ADDR,
                                             ADDR_LOCAL(tmp_str),
                                             ADDR_STRING(sfmt),
                                             ADDR_NONE);
                /* Rebuild: fmt_instr first, then arg_code already in code */
                /* We need to prepend fmt_instr before the arg code.
                 * Since arg_code is already appended to code, we need to
                 * restructure. Reset and redo in correct order. */
                /* Actually arg_code was appended to code earlier.
                 * We need format string addr BEFORE arg evaluation.
                 * Re-generate args after format string. */
                /* Regenerate cleanly: format addr, then args, then parms */
                struct instr *final_code = fmt_instr;
                /* Re-evaluate args after format string addr */
                for (int i = 0; i < top; i++) {
                    struct tree *arg = stack[top - 1 - i];
                    final_code = append(final_code, codegen(arg, current));
                    arg_addrs[i] = arg->place;
                }
                /* parm: push value args right to left */
                for (int i = nargs - 1; i >= 0; i--)
                    final_code = append(final_code, gen(O_PARM, ADDR_NONE,
                                                       arg_addrs[i], ADDR_NONE));
                /* parm: push format string last (it's param 1) */
                final_code = append(final_code, gen(O_PARM, ADDR_NONE,
                                                   ADDR_LOCAL(tmp_str), ADDR_NONE));
                int result = new_temp();
                final_code = append(final_code, gen(O_CALL,
                                                   ADDR_NAME("printf"),
                                                   ADDR_CONST(nargs + 1),
                                                   ADDR_LOCAL(result)));
                t->place = ADDR_LOCAL(result);
                return final_code;
            }

            /* Normal function call: params right to left */
            for (int i = nargs - 1; i >= 0; i--)
                code = append(code, gen(O_PARM, ADDR_NONE,
                                       arg_addrs[i], ADDR_NONE));
            int result = new_temp();
            code = append(code, gen(O_CALL,
                                   ADDR_NAME(fname ? fname : "?"),
                                   ADDR_CONST(nargs),
                                   ADDR_LOCAL(result)));
            t->place = ADDR_LOCAL(result);
            return code;
        }
    }

    /* ── return_statement ─────────────────────────────────────────── */
    if (strcmp(name, "return_statement") == 0) {
        if (t->nkids >= 2 && t->kids[1]) {
            struct instr *code = codegen(t->kids[1], current);
            code = append(code, gen(O_RET, ADDR_NONE,
                                   t->kids[1]->place, ADDR_NONE));
            t->place = ADDR_NONE;
            return code;
        }
        t->place = ADDR_NONE;
        return gen(O_RET, ADDR_NONE, ADDR_NONE, ADDR_NONE);
    }

    /* ── if_expression ────────────────────────────────────────────── */
    if (strcmp(name, "if_expression") == 0) {
        /* IF ( condition ) then_body [ELSE else_body] */
        struct tree *cond_tree = NULL;
        struct tree *then_tree = NULL;
        struct tree *else_tree = NULL;

        /* kids: IF, LPAREN, condition, RPAREN, then_body [, ELSE, else_body] */
        if (t->nkids >= 5) cond_tree = t->kids[2];
        if (t->nkids >= 5) then_tree = t->kids[4];
        if (t->nkids >= 7) else_tree = t->kids[6];

        struct instr *cond_code = codegen(cond_tree, current);
        struct addr cond = cond_tree ? cond_tree->place : ADDR_NONE;

        struct addr lbl_else  = genlabel();
        struct addr lbl_end   = genlabel();

        /* Branch to else if condition is false */
        struct instr *code = cond_code;
        code = append(code, gen(O_BNIF, lbl_else, cond, ADDR_NONE));

        /* Then body */
        code = append(code, codegen(then_tree, current));
        if (else_tree)
            code = append(code, gen(O_GOTO, lbl_end, ADDR_NONE, ADDR_NONE));

        /* Else label */
        code = append(code, gen(D_LABEL, lbl_else, ADDR_NONE, ADDR_NONE));

        /* Else body */
        if (else_tree)
            code = append(code, codegen(else_tree, current));

        /* End label */
        if (else_tree)
            code = append(code, gen(D_LABEL, lbl_end, ADDR_NONE, ADDR_NONE));

        t->place = ADDR_NONE;
        return code;
    }

    /* ── while_statement ──────────────────────────────────────────── */
    if (strcmp(name, "while_statement") == 0) {
        struct addr lbl_top  = genlabel();
        struct addr lbl_end  = genlabel();

        struct instr *code = NULL;
        code = append(code, gen(D_LABEL, lbl_top, ADDR_NONE, ADDR_NONE));

        struct tree *cond_tree = (t->nkids >= 3) ? t->kids[2] : NULL;
        code = append(code, codegen(cond_tree, current));
        struct addr cond = cond_tree ? cond_tree->place : ADDR_NONE;
        code = append(code, gen(O_BNIF, lbl_end, cond, ADDR_NONE));

        struct tree *body = (t->nkids >= 5) ? t->kids[4] : NULL;
        code = append(code, codegen(body, current));
        code = append(code, gen(O_GOTO, lbl_top, ADDR_NONE, ADDR_NONE));
        code = append(code, gen(D_LABEL, lbl_end, ADDR_NONE, ADDR_NONE));

        t->place = ADDR_NONE;
        return code;
    }

    /* ── for_statement ────────────────────────────────────────────── */
    if (strcmp(name, "for_statement") == 0) {
        /* 7-kid: FOR ( IDENT IN expr ) body
         * 9-kid: FOR ( IDENT : type IN expr ) body */
        char *iter_name = NULL;
        if (t->nkids >= 3 && t->kids[2] && t->kids[2]->leaf)
            iter_name = t->kids[2]->leaf->text;

        /* range expression: kids[4] for 7-kid, kids[6] for 9-kid */
        struct tree *range_tree = NULL;
        if (t->nkids == 9)       range_tree = t->kids[6];
        else if (t->nkids >= 5)  range_tree = t->kids[4];

        struct tree *body = t->kids[t->nkids - 1];

        struct addr iter_addr = iter_name ?
            addr_of(iter_name, current) : ADDR_NONE;

        struct instr *code = codegen(range_tree, current);
        struct addr range = range_tree ? range_tree->place : ADDR_NONE;

        /* Only emit ASN if we have a valid range expression */
        if (iter_addr.region != R_NONE && iter_addr.region != 0 &&
            range.region != R_NONE && range.region != 0)
            code = append(code, gen(O_ASN, iter_addr, range, ADDR_NONE));

        struct addr lbl_top = genlabel();
        struct addr lbl_end = genlabel();
        code = append(code, gen(D_LABEL, lbl_top, ADDR_NONE, ADDR_NONE));
        code = append(code, codegen(body, current));
        code = append(code, gen(O_GOTO, lbl_top, ADDR_NONE, ADDR_NONE));
        code = append(code, gen(D_LABEL, lbl_end, ADDR_NONE, ADDR_NONE));

        t->place = ADDR_NONE;
        return code;
    }

    /* ── do_while_statement ───────────────────────────────────────── */
    if (strcmp(name, "do_while_statement") == 0) {
        struct addr lbl_top = genlabel();

        struct instr *code = NULL;
        code = append(code, gen(D_LABEL, lbl_top, ADDR_NONE, ADDR_NONE));

        struct tree *body = (t->nkids >= 2) ? t->kids[1] : NULL;
        code = append(code, codegen(body, current));

        struct tree *cond_tree = (t->nkids >= 5) ? t->kids[4] : NULL;
        code = append(code, codegen(cond_tree, current));
        struct addr cond = cond_tree ? cond_tree->place : ADDR_NONE;
        code = append(code, gen(O_BIF, lbl_top, cond, ADDR_NONE));

        t->place = ADDR_NONE;
        return code;
    }

    /* ── Default: recurse into all children ──────────────────────── */
    struct instr *code = NULL;
    for (int i = 0; i < t->nkids; i++) {
        if (!t->kids[i]) continue;
        code = append(code, codegen(t->kids[i], current));
        /* Propagate place from last non-none child */
        if (t->kids[i]->place.region != R_NONE)
            t->place = t->kids[i]->place;
    }
    return code;
}

/* =========================================================================
 * output_ic() -- write the .ic file
 * ========================================================================= */
void output_ic(struct instr *code, const char *src_filename)
{
    /* Build output filename: strip path, replace .kt with .ic */
    const char *base = src_filename;
    const char *slash = strrchr(src_filename, '/');
    if (slash) base = slash + 1;
    const char *backslash = strrchr(base, '\\');
    if (backslash) base = backslash + 1;

    char outname[512];
    strncpy(outname, base, sizeof(outname) - 4);
    outname[sizeof(outname) - 4] = '\0';
    char *dot = strrchr(outname, '.');
    if (dot) *dot = '\0';
    strcat(outname, ".ic");

    FILE *f = fopen(outname, "w");
    if (!f) {
        fprintf(stderr, "codegen: cannot open %s for writing\n", outname);
        return;
    }

    /* .string region */
    if (string_region_size() > 0) {
        fprintf(f, ".string\t%d\n", string_region_size());
        for (int i = 0; i < nstrings; i++) {
            fprintf(f, "\t");
            const char *s = string_table[i];
            while (*s) {
                unsigned char c = (unsigned char)*s++;
                if      (c == '\n') fprintf(f, "\\012");
                else if (c == '\t') fprintf(f, "\\011");
                else if (c == '\\') fprintf(f, "\\\\");
                else if (c < 32 || c > 126) fprintf(f, "\\%03o", c);
                else fputc(c, f);
            }
            fprintf(f, "\\000\n");
        }
    }

    /* .data region for global variables */
    /* Walk global scope and emit .data declarations */
    {
        extern SymbolTable all_scopes[];
        extern int nscopes;
        int has_globals = 0;
        /* First scope registered is global */
        if (nscopes > 0) {
            SymbolTable g = all_scopes[0];
            for (int i = 0; i < g->nBuckets; i++) {
                SymbolTableEntry e = g->tbl[i];
                while (e) {
                    /* Only emit non-function globals */
                    if (!e->type || e->type->basetype != FUNC_TYPE) {
                        if (!has_globals) {
                            fprintf(f, ".data\n");
                            has_globals = 1;
                        }
                        fprintf(f, "\t%s\t8\n", e->name);
                    }
                    e = e->next;
                }
            }
        }
    }

    /* .code region */
    fprintf(f, ".code\n");

    /* Print TAC to file -- reuse tacprint logic but to FILE* */
    struct instr *l = code;
    while (l) {
        int op = l->opcode;

        if (op == D_PROC) {
            fprintf(f, "%s:\n", l->dest.u.name ? l->dest.u.name : "?");
            l = l->next; continue;
        }
        if (op == D_END) {
            l = l->next; continue;
        }
        if (op == D_LABEL) {
            fprintf(f, "lab%d:\n", l->dest.u.offset);
            l = l->next; continue;
        }
        if (op == O_RET) {
            fprintf(f, "\treturn");
            if (l->src1.region != R_NONE) {
                fprintf(f, "\t");
                /* print src1 */
                struct addr a = l->src1;
                switch (a.region) {
                    case R_LOCAL:  fprintf(f, "loc:%d",    a.u.offset); break;
                    case R_CONST:  fprintf(f, "const:%d",  a.u.offset); break;
                    default:       break;
                }
            }
            fprintf(f, "\n");
            l = l->next; continue;
        }

        /* Helper lambda-like macro for printing addr to file */
        #define FADDR(a) do { \
            switch ((a).region) { \
                case R_LOCAL:  fprintf(f, "loc:%d",    (a).u.offset); break; \
                case R_GLOBAL: fprintf(f, "global:%d", (a).u.offset); break; \
                case R_CONST:  fprintf(f, "const:%d",  (a).u.offset); break; \
                case R_LABEL:  fprintf(f, "lab%d",     (a).u.offset); break; \
                case R_NAME:   fprintf(f, "%s",         (a).u.name ? (a).u.name : "?"); break; \
                case R_STRING: fprintf(f, "string:%d", (a).u.offset); break; \
                case R_NONE:   break; \
                case 0:        break; /* uninitialized -- skip */ \
                default:       break; /* skip unknown regions  */ \
            } \
        } while(0)

        if (op == O_CALL) {
            fprintf(f, "\tcall\t"); FADDR(l->dest);
            fprintf(f, ",%d,", l->src1.u.offset); FADDR(l->src2);
            fprintf(f, "\n"); l = l->next; continue;
        }
        if (op == O_PARM) {
            fprintf(f, "\tparm\t"); FADDR(l->src1);
            fprintf(f, "\n"); l = l->next; continue;
        }
        if (op == O_GOTO) {
            fprintf(f, "\tgoto\t"); FADDR(l->dest);
            fprintf(f, "\n"); l = l->next; continue;
        }
        if (op == O_ASN) {
            /* Skip if either operand is uninitialized */
            if (l->dest.region == 0 || l->src1.region == 0 ||
                l->src1.region == R_NONE) {
                l = l->next; continue;
            }
            fprintf(f, "\tasn\t"); FADDR(l->dest);
            fprintf(f, ","); FADDR(l->src1);
            fprintf(f, "\n"); l = l->next; continue;
        }
        if (op == O_NEG) {
            fprintf(f, "\tneg\t"); FADDR(l->dest);
            fprintf(f, ","); FADDR(l->src1);
            fprintf(f, "\n"); l = l->next; continue;
        }
        if (op == O_ADDR) {
            fprintf(f, "\taddr\t"); FADDR(l->dest);
            fprintf(f, ","); FADDR(l->src1);
            fprintf(f, "\n"); l = l->next; continue;
        }
        if (op >= O_BLT && op <= O_BNIF) {
            { char *opn = opcodename(op); fprintf(f, "\t");
              for (char *p = opn; *p; p++) fputc(tolower((unsigned char)*p), f);
              fprintf(f, "\t"); }
            FADDR(l->dest);
            if (l->src1.region != R_NONE) { fprintf(f, ","); FADDR(l->src1); }
            if (l->src2.region != R_NONE) { fprintf(f, ","); FADDR(l->src2); }
            fprintf(f, "\n"); l = l->next; continue;
        }
        /* binary ops -- lowercase */
        { char *opn = opcodename(op); fprintf(f, "\t");
          for (char *p = opn; *p; p++) fputc(tolower((unsigned char)*p), f);
          fprintf(f, "\t"); }
        FADDR(l->dest); fprintf(f, ",");
        FADDR(l->src1);
        if (l->src2.region != R_NONE) { fprintf(f, ","); FADDR(l->src2); }
        fprintf(f, "\n");
        #undef FADDR
        l = l->next;
    }

    fclose(f);
    printf("wrote %s\n", outname);
}
