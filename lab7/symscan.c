#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "token.h"
#include "type.h"
#include "symtab.h"
#include "symscan.h"
#include "k0gram.tab.h"

/* =========================================================================
 * Scope registry -- for printing and for checksyms lookup
 * ========================================================================= */
#define MAX_SCOPES 512
static SymbolTable all_scopes[MAX_SCOPES];
static int         nscopes = 0;

static void register_scope(SymbolTable st)
{
    if (nscopes < MAX_SCOPES) all_scopes[nscopes++] = st;
}

/* =========================================================================
 * extract_type_node() -- find the full_type/type child within a subtree
 * and build a typeptr from it.
 * ========================================================================= */

/* Find the first IDENT leaf text in a subtree (the base type name) */
static char *first_ident_text(struct tree *t)
{
    if (!t) return NULL;
    if (t->leaf && t->leaf->category == IDENT) return t->leaf->text;
    for (int i = 0; i < t->nkids; i++) {
        char *r = first_ident_text(t->kids[i]);
        if (r) return r;
    }
    return NULL;
}

/* Build a typeptr from a full_type or type subtree node */
static typeptr typeptr_from_tree(struct tree *t)
{
    if (!t) return none_typeptr;

    /* If the node is named "full_type" or "type", inspect its structure */
    const char *nm = t->symbolname ? t->symbolname : "";

    if (strcmp(nm, "full_type") == 0 || strcmp(nm, "type") == 0) {
        /* kids: IDENT [QUEST]  or  IDENT LANGLE type_args RANGLE [QUEST] */
        char *base_name = NULL;
        int   nullable  = 0;

        if (t->nkids >= 1 && t->kids[0] && t->kids[0]->leaf &&
            t->kids[0]->leaf->category == IDENT)
            base_name = t->kids[0]->leaf->text;

        /* Check for QUEST anywhere in the kids (nullable marker) */
        for (int i = 0; i < t->nkids; i++) {
            if (t->kids[i] && t->kids[i]->leaf &&
                t->kids[i]->leaf->category == QUEST)
                nullable = 1;
        }

        /* Check for generic: IDENT LANGLE type_args RANGLE */
        typeptr tp = none_typeptr;
        if (base_name && strcmp(base_name, "Array") == 0 && t->nkids >= 3) {
            /* Find type_args kid */
            struct tree *args = NULL;
            for (int i = 0; i < t->nkids; i++) {
                if (t->kids[i] && t->kids[i]->symbolname &&
                    strcmp(t->kids[i]->symbolname, "type_args") == 0) {
                    args = t->kids[i];
                    break;
                }
            }
            typeptr elem = args ? typeptr_from_tree(args) : any_typeptr;
            tp = alcarraytype(elem);
        } else {
            tp = base_name ? typename_to_typeptr(base_name) : none_typeptr;
        }

        if (tp && tp != none_typeptr) {
            /* For nullable, wrap in a new typeinfo copy with nullable=1.
             * Singletons are not nullable so we allocate a new one. */
            if (nullable && tp->basetype != NULL_TYPE) {
                typeptr ntp = calloc(1, sizeof(struct typeinfo));
                if (ntp) { *ntp = *tp; ntp->nullable = 1; tp = ntp; }
            }
        }
        return tp;
    }

    if (strcmp(nm, "type_args") == 0) {
        /* Return type of first type argument */
        if (t->nkids >= 1 && t->kids[0])
            return typeptr_from_tree(t->kids[0]);
        return any_typeptr;
    }

    if (strcmp(nm, "optional_type_annotation") == 0) {
        /* kids: COLON full_type */
        for (int i = 0; i < t->nkids; i++) {
            if (t->kids[i] && t->kids[i]->symbolname) {
                const char *kn = t->kids[i]->symbolname;
                if (strcmp(kn, "full_type") == 0 || strcmp(kn, "type") == 0)
                    return typeptr_from_tree(t->kids[i]);
            }
        }
    }

    if (strcmp(nm, "optional_return_type") == 0) {
        for (int i = 0; i < t->nkids; i++) {
            if (t->kids[i] && t->kids[i]->symbolname) {
                const char *kn = t->kids[i]->symbolname;
                if (strcmp(kn, "full_type") == 0 || strcmp(kn, "type") == 0)
                    return typeptr_from_tree(t->kids[i]);
            }
        }
        return none_typeptr;  /* no return type => Unit/void */
    }

    /* Leaf IDENT as bare type name */
    if (t->leaf && t->leaf->category == IDENT)
        return typename_to_typeptr(t->leaf->text);

    /* Recurse for wrapper nodes */
    for (int i = 0; i < t->nkids; i++) {
        typeptr r = typeptr_from_tree(t->kids[i]);
        if (r && r != none_typeptr) return r;
    }
    return none_typeptr;
}

/* =========================================================================
 * Infer type from literal leaf -- for untyped declarations like val x = 5
 * ========================================================================= */
static typeptr typeptr_from_literal(struct tree *t)
{
    if (!t || !t->leaf) return none_typeptr;
    switch (t->leaf->category) {
        case INTEGERLITERAL:   return integer_typeptr;
        case LONGLITERAL:      return integer_typeptr;
        case REALLITERAL:      return float_typeptr;
        case DOUBLELITERAL:    return float_typeptr;
        case BOOLEANLITERAL:   return bool_typeptr;
        case CHARACTERLITERAL: return char_typeptr;
        case STRINGLITERAL:    return string_typeptr;
        case NULLLITERAL:      return null_typeptr;
        default:               return none_typeptr;
    }
}

/* Find the first literal in a subtree (for type inference from initializer) */
static typeptr infer_from_initializer(struct tree *t)
{
    if (!t) return none_typeptr;
    if (t->leaf) return typeptr_from_literal(t);
    for (int i = 0; i < t->nkids; i++) {
        typeptr r = infer_from_initializer(t->kids[i]);
        if (r && r != none_typeptr) return r;
    }
    return none_typeptr;
}

/* =========================================================================
 * Pass 1 -- buildsyms: populate symbol tables with full type information
 * ========================================================================= */
static void scan_node(struct tree *t, SymbolTable current);

static void insert_params(struct tree *t, SymbolTable local)
{
    if (!t) return;
    if (t->leaf) return;

    if (t->symbolname && strcmp(t->symbolname, "function_value_parameter") == 0) {
        char   *pname = NULL;
        typeptr ptype = none_typeptr;
        int     pline = 0;
        char   *pfile = NULL;

        if (t->nkids >= 1 && t->kids[0] && t->kids[0]->leaf &&
            t->kids[0]->leaf->category == IDENT) {
            pname = t->kids[0]->leaf->text;
            pline = t->kids[0]->leaf->lineno;
            pfile = t->kids[0]->leaf->filename;
        }
        /* kids[2] = full_type (after IDENT COLON full_type) */
        if (t->nkids >= 3 && t->kids[2])
            ptype = typeptr_from_tree(t->kids[2]);

        if (pname)
            insertsym(local, pname, ptype, 0, pline, pfile);
        return;
    }
    for (int i = 0; i < t->nkids; i++)
        insert_params(t->kids[i], local);
}

static void scan_node(struct tree *t, SymbolTable current)
{
    if (!t) return;
    if (t->leaf) return;

    const char *name = t->symbolname ? t->symbolname : "";

    /* ── function_declaration ─────────────────────────────────────── */
    if (strcmp(name, "function_declaration") == 0) {
        char   *fname = NULL;
        int     fline = 0;
        char   *ffile = NULL;

        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf &&
            t->kids[1]->leaf->category == IDENT) {
            fname = t->kids[1]->leaf->text;
            fline = t->kids[1]->leaf->lineno;
            ffile = t->kids[1]->leaf->filename;
        }

        /* Build local scope first (needed for alcfunctype) */
        char scope_label[256];
        snprintf(scope_label, sizeof(scope_label), "func %s", fname ? fname : "?");
        SymbolTable local = mksymtab(SYM_NBUCKETS, scope_label, current);
        register_scope(local);

        /* Determine return type */
        typeptr rettype = none_typeptr;
        for (int i = 0; i < t->nkids; i++) {
            if (t->kids[i] && t->kids[i]->symbolname &&
                strcmp(t->kids[i]->symbolname, "optional_return_type") == 0) {
                rettype = typeptr_from_tree(t->kids[i]);
                break;
            }
        }

        /* Build function type and insert into enclosing scope */
        typeptr ftype = alcfunctype(local, rettype);
        if (fname)
            insertsym(current, fname, ftype, 0, fline, ffile);

        /* Insert parameters into local scope */
        if (t->nkids >= 3 && t->kids[2])
            insert_params(t->kids[2], local);

        /* Scan body under local scope */
        for (int i = 3; i < t->nkids; i++) {
            if (!t->kids[i] || !t->kids[i]->symbolname) continue;
            const char *kn = t->kids[i]->symbolname;
            if (strcmp(kn, "block") == 0 || strcmp(kn, "function_body") == 0) {
                scan_node(t->kids[i], local);
                break;
            }
        }
        return;
    }

    /* ── property_declaration ─────────────────────────────────────── */
    if (strcmp(name, "property_declaration") == 0) {
        int     is_const = 0;
        int     name_idx = 1;
        char   *vname    = NULL;
        int     vline    = 0;
        char   *vfile    = NULL;
        typeptr vtype    = none_typeptr;

        if (t->nkids >= 1 && t->kids[0] && t->kids[0]->leaf &&
            t->kids[0]->leaf->category == CONST) {
            is_const = 1; name_idx = 2;
        }

        if (name_idx < t->nkids && t->kids[name_idx] &&
            t->kids[name_idx]->leaf &&
            t->kids[name_idx]->leaf->category == IDENT) {
            vname = t->kids[name_idx]->leaf->text;
            vline = t->kids[name_idx]->leaf->lineno;
            vfile = t->kids[name_idx]->leaf->filename;
        }

        /* Try explicit type annotation first */
        int type_idx = name_idx + 1;
        if (type_idx < t->nkids && t->kids[type_idx] &&
            t->kids[type_idx]->symbolname &&
            strcmp(t->kids[type_idx]->symbolname, "optional_type_annotation") == 0) {
            vtype = typeptr_from_tree(t->kids[type_idx]);
        }

        /* If no explicit type, infer from initializer */
        if (vtype == none_typeptr) {
            int init_idx = t->nkids - 1;
            if (init_idx >= 0 && t->kids[init_idx] &&
                t->kids[init_idx]->symbolname &&
                strcmp(t->kids[init_idx]->symbolname, "optional_initializer") == 0) {
                vtype = infer_from_initializer(t->kids[init_idx]);
            }
        }

        if (vname)
            insertsym(current, vname, vtype, is_const, vline, vfile);

        for (int i = 0; i < t->nkids; i++)
            scan_node(t->kids[i], current);
        return;
    }

    /* ── for_statement: iterator variable ────────────────────────── */
    if (strcmp(name, "for_statement") == 0) {
        if (t->nkids >= 3 && t->kids[2] && t->kids[2]->leaf &&
            t->kids[2]->leaf->category == IDENT) {
            char   *iname = t->kids[2]->leaf->text;
            int     iline = t->kids[2]->leaf->lineno;
            char   *ifile = t->kids[2]->leaf->filename;
            typeptr itype = none_typeptr;
            /* 9-kid form has type annotation at kids[4] */
            if (t->nkids == 9 && t->kids[4])
                itype = typeptr_from_tree(t->kids[4]);
            insertsym(current, iname, itype, 0, iline, ifile);
        }
        if (t->nkids > 0)
            scan_node(t->kids[t->nkids - 1], current);
        return;
    }

    /* ── default: recurse ─────────────────────────────────────────── */
    for (int i = 0; i < t->nkids; i++)
        scan_node(t->kids[i], current);
}

SymbolTable buildsyms(struct tree *t)
{
    init_predefined();
    SymbolTable global = mksymtab(SYM_NBUCKETS, "global", predefined_scope);
    register_scope(global);
    scan_node(t, global);
    return global;
}

/* =========================================================================
 * Pass 2 -- checksyms: undeclared variable detection
 *           Also annotates IDENT leaves with their typeptr.
 * ========================================================================= */
static void check_node(struct tree *t, SymbolTable current);

static void check_node(struct tree *t, SymbolTable current)
{
    if (!t) return;

    if (t->leaf) {
        if (t->leaf->category == IDENT && t->leaf->text) {
            SymbolTableEntry e = lookupsym_chain(current, t->leaf->text);
            if (!e) {
                fprintf(stderr,
                        "%s:%d: error: undeclared identifier '%s'\n",
                        t->leaf->filename ? t->leaf->filename : "<unknown>",
                        t->leaf->lineno, t->leaf->text);
                semantic_errors++;
            } else {
                /* Annotate the leaf with the type from the symbol table */
                t->type = e->type;
            }
        }
        return;
    }

    const char *name = t->symbolname ? t->symbolname : "";

    /* Skip import paths */
    if (strcmp(name, "import_declaration") == 0 ||
        strcmp(name, "import_path") == 0 ||
        strcmp(name, "import_list") == 0)
        return;

    /* Skip type annotation nodes */
    if (strcmp(name, "optional_type_annotation") == 0 ||
        strcmp(name, "optional_return_type") == 0 ||
        strcmp(name, "type") == 0 ||
        strcmp(name, "full_type") == 0 ||
        strcmp(name, "type_args") == 0)
        return;

    /* function_declaration: check body under its local scope */
    if (strcmp(name, "function_declaration") == 0) {
        SymbolTable local = NULL;
        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf) {
            char label[256];
            snprintf(label, sizeof(label), "func %s", t->kids[1]->leaf->text);
            for (int i = 0; i < nscopes; i++) {
                if (all_scopes[i]->scope_name &&
                    strcmp(all_scopes[i]->scope_name, label) == 0) {
                    local = all_scopes[i]; break;
                }
            }
        }
        if (!local) local = current;
        /* Skip kids[1] (name) and kids[2] (param list) -- declaration sites */
        for (int i = 3; i < t->nkids; i++)
            check_node(t->kids[i], local);
        return;
    }

    /* property_declaration: skip the name, check initializer */
    if (strcmp(name, "property_declaration") == 0) {
        int last = t->nkids - 1;
        if (last >= 0) check_node(t->kids[last], current);
        return;
    }

    /* for_statement: skip iterator name, check range and body */
    if (strcmp(name, "for_statement") == 0) {
        for (int i = 3; i < t->nkids; i++)
            check_node(t->kids[i], current);
        return;
    }

    /* postfix_expr with dot/safe-call: only check receiver */
    if (strcmp(name, "postfix_expr") == 0) {
        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf) {
            int op = t->kids[1]->leaf->category;
            if (op == DOT || op == SAFE_CALL || op == DOUBLE_COLON) {
                check_node(t->kids[0], current);
                return;
            }
        }
        for (int i = 0; i < t->nkids; i++)
            check_node(t->kids[i], current);
        return;
    }

    for (int i = 0; i < t->nkids; i++)
        check_node(t->kids[i], current);
}

void checksyms(struct tree *t, SymbolTable current)
{
    check_node(t, current);
}

/* =========================================================================
 * Output: print all symbol tables
 * ========================================================================= */
void printsyms_all(SymbolTable global)
{
    for (int i = 0; i < nscopes; i++)
        printsymtab(all_scopes[i]);
}