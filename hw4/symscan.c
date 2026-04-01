#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "token.h"
#include "symtab.h"
#include "symscan.h"
#include "k0gram.tab.h"

/* =========================================================================
 * Internal list of per-function symbol tables so we can print them all.
 * ========================================================================= */
#define MAX_SCOPES 512
static SymbolTable all_scopes[MAX_SCOPES];
static int         nscopes = 0;

static void register_scope(SymbolTable st)
{
    if (nscopes < MAX_SCOPES)
        all_scopes[nscopes++] = st;
}

/* =========================================================================
 * Helper: extract the declared type string from a full_type subtree.
 * Returns a pointer to the leaf->text of the first IDENT in the subtree.
 * For Array<Int> this returns "Array"; good enough for HW4.
 * ========================================================================= */
static char *extract_type(struct tree *t)
{
    if (!t) return NULL;
    if (t->leaf && t->leaf->category == IDENT)
        return t->leaf->text;
    for (int i = 0; i < t->nkids; i++) {
        char *r = extract_type(t->kids[i]);
        if (r) return r;
    }
    return NULL;
}

/* =========================================================================
 * Pass 1 -- buildsyms: populate symbol tables
 * ========================================================================= */

static void scan_node(struct tree *t, SymbolTable current);

/* Walk function_value_parameters; insert each param into local table */
static void insert_params(struct tree *t, SymbolTable local)
{
    if (!t) return;
    if (t->leaf) return;

    if (t->symbolname && strcmp(t->symbolname, "function_value_parameter") == 0) {
        /* kids[0] = IDENT:name,  kids[1] = COLON,  kids[2] = full_type */
        char *pname = NULL;
        char *ptype = NULL;
        if (t->nkids >= 1 && t->kids[0] && t->kids[0]->leaf &&
            t->kids[0]->leaf->category == IDENT)
            pname = t->kids[0]->leaf->text;
        if (t->nkids >= 3 && t->kids[2])
            ptype = extract_type(t->kids[2]);

        if (pname) {
            int ln = (t->kids[0] && t->kids[0]->leaf) ? t->kids[0]->leaf->lineno : 0;
            char *fn = (t->kids[0] && t->kids[0]->leaf) ? t->kids[0]->leaf->filename : NULL;
            insertsym(local, pname, ptype, 0, ln, fn);
        }
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
        char *fname = NULL;
        int   fline = 0;
        char *ffile = NULL;

        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf &&
            t->kids[1]->leaf->category == IDENT) {
            fname = t->kids[1]->leaf->text;
            fline = t->kids[1]->leaf->lineno;
            ffile = t->kids[1]->leaf->filename;
        }

        /* Insert function name into enclosing (global) scope */
        if (fname)
            insertsym(current, fname, "Function", 0, fline, ffile);

        /* Build local scope: parent = global so lookups chain upward */
        char scope_label[256];
        snprintf(scope_label, sizeof(scope_label), "func %s",
                 fname ? fname : "?");
        SymbolTable local = mksymtab(SYM_NBUCKETS, scope_label, current);
        register_scope(local);

        /* Insert parameters */
        if (t->nkids >= 3 && t->kids[2])
            insert_params(t->kids[2], local);

        /* Find and scan the body under the local scope */
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
        /*
         * 4-kid: VAL|VAR  IDENT  opt_type_annotation  opt_initializer
         * 5-kid: CONST    VAL    IDENT  opt_type_annotation  opt_initializer
         */
        int is_const = 0;
        int name_idx = 1;

        /* Detect CONST VAL form */
        if (t->nkids >= 1 && t->kids[0] && t->kids[0]->leaf) {
            int cat = t->kids[0]->leaf->category;
            if (cat == CONST) { is_const = 1; name_idx = 2; }
        }

        char *vname = NULL;
        char *vtype = NULL;
        int   vline = 0;
        char *vfile = NULL;

        if (name_idx < t->nkids && t->kids[name_idx] &&
            t->kids[name_idx]->leaf &&
            t->kids[name_idx]->leaf->category == IDENT) {
            vname = t->kids[name_idx]->leaf->text;
            vline = t->kids[name_idx]->leaf->lineno;
            vfile = t->kids[name_idx]->leaf->filename;
        }

        /* Type annotation is the kid after the name (if present) */
        int type_idx = name_idx + 1;
        if (type_idx < t->nkids && t->kids[type_idx] &&
            t->kids[type_idx]->symbolname &&
            strcmp(t->kids[type_idx]->symbolname, "optional_type_annotation") == 0) {
            vtype = extract_type(t->kids[type_idx]);
        }

        if (vname)
            insertsym(current, vname, vtype, is_const, vline, vfile);

        /* Recurse into initializer for any nested declarations */
        for (int i = 0; i < t->nkids; i++)
            scan_node(t->kids[i], current);
        return;
    }

    /* ── for_statement: iterator variable ────────────────────────── */
    if (strcmp(name, "for_statement") == 0) {
        if (t->nkids >= 3 && t->kids[2] && t->kids[2]->leaf &&
            t->kids[2]->leaf->category == IDENT) {
            char *iname = t->kids[2]->leaf->text;
            int   iline = t->kids[2]->leaf->lineno;
            char *ifile = t->kids[2]->leaf->filename;
            /* Type annotation (9-kid form): kids[4] */
            char *itype = NULL;
            if (t->nkids == 9 && t->kids[4])
                itype = extract_type(t->kids[4]);
            insertsym(current, iname, itype, 0, iline, ifile);
        }
        /* Recurse into body (last kid) */
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
 *
 * We walk the tree again looking for IDENT leaves that appear in an
 * expression context (i.e. they are being *used*, not declared).
 * We report an error if the symbol cannot be found via lookupsym_chain.
 *
 * We skip IDENTs that are clearly declaration sites (handled in pass 1)
 * by tracking whether we are inside a declaration node.
 * ========================================================================= */

static void check_node(struct tree *t, SymbolTable current);

static void check_node(struct tree *t, SymbolTable current)
{
    if (!t) return;

    /* Leaf: check IDENT uses */
    if (t->leaf) {
        if (t->leaf->category == IDENT && t->leaf->text) {
            if (!lookupsym_chain(current, t->leaf->text)) {
                fprintf(stderr,
                        "%s:%d: error: undeclared identifier '%s'\n",
                        t->leaf->filename ? t->leaf->filename : "<unknown>",
                        t->leaf->lineno,
                        t->leaf->text);
                semantic_errors++;
            }
        }
        return;
    }

    const char *name = t->symbolname ? t->symbolname : "";

    /* For function_declaration: check body under its local scope */
    if (strcmp(name, "function_declaration") == 0) {
        /* Find the local scope we built for this function in pass 1 */
        SymbolTable local = NULL;
        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf) {
            char *fname = t->kids[1]->leaf->text;
            char label[256];
            snprintf(label, sizeof(label), "func %s", fname);
            for (int i = 0; i < nscopes; i++) {
                if (all_scopes[i]->scope_name &&
                    strcmp(all_scopes[i]->scope_name, label) == 0) {
                    local = all_scopes[i];
                    break;
                }
            }
        }
        if (!local) local = current;

        /* Skip kids[1] (function name -- it's a declaration site, not a use)
         * Skip kids[2] (parameter list -- also declaration sites)
         * Check kids[3..] (return type annotations and body) */
        for (int i = 3; i < t->nkids; i++)
            check_node(t->kids[i], local);
        return;
    }

    /* For property_declaration: skip the IDENT name itself (declaration site),
     * but check the initializer expression */
    if (strcmp(name, "property_declaration") == 0) {
        /* Name is at kids[1] (or kids[2] for const val) -- skip it.
         * Initializer is always the last kid. */
        int last = t->nkids - 1;
        if (last >= 0) check_node(t->kids[last], current);
        return;
    }

    /* For for_statement: skip the iterator IDENT (kids[2], declaration site),
     * check the range expression and body */
    if (strcmp(name, "for_statement") == 0) {
        /* kids[2] = iterator name (skip), kids[4]/[6] = range, last = body */
        for (int i = 3; i < t->nkids; i++)
            check_node(t->kids[i], current);
        return;
    }

    /* Skip import paths entirely -- identifiers there are package/class
     * names, not variable references */
    if (strcmp(name, "import_declaration") == 0 ||
        strcmp(name, "import_path") == 0 ||
        strcmp(name, "import_list") == 0)
        return;

    /* Skip type annotation nodes entirely -- IDENT there is a type name,
     * not a variable reference */
    if (strcmp(name, "optional_type_annotation") == 0 ||
        strcmp(name, "optional_return_type") == 0 ||
        strcmp(name, "type") == 0 ||
        strcmp(name, "full_type") == 0 ||
        strcmp(name, "type_args") == 0)
        return;

    /* Skip member access RHS -- in postfix_expr DOT IDENT, the IDENT
     * after the dot is a member/method name, not a variable reference.
     * postfix_expr has kids: [0]=receiver, [1]=DOT, [2]=IDENT:member
     * Same for SAFE_CALL (?.) and DOUBLE_COLON (::). */
    if (strcmp(name, "postfix_expr") == 0) {
        /* Only check the receiver (kids[0]); skip the member name (kids[2]) */
        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf) {
            int op = t->kids[1]->leaf->category;
            if (op == DOT || op == SAFE_CALL || op == DOUBLE_COLON) {
                check_node(t->kids[0], current);  /* check receiver only */
                return;
            }
        }
        /* Function call, indexing etc -- check all kids normally */
        for (int i = 0; i < t->nkids; i++)
            check_node(t->kids[i], current);
        return;
    }

    /* Default: recurse */
    for (int i = 0; i < t->nkids; i++)
        check_node(t->kids[i], current);
}

void checksyms(struct tree *t, SymbolTable current)
{
    check_node(t, current);
}

/* =========================================================================
 * Output: print all symbol tables in the required format
 * ========================================================================= */
void printsyms_all(SymbolTable global)
{
    /* Print global first, then each function scope */
    for (int i = 0; i < nscopes; i++)
        printsymtab(all_scopes[i]);
}