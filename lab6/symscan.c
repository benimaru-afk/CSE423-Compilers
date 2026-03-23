#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "token.h"
#include "symtab.h"
#include "symscan.h"

/* k0gram.tab.h gives us the IDENT token code */
#include "k0gram.tab.h"

/* =========================================================================
 * PART 1 -- printsyms / printsymbol
 * ========================================================================= */

static void printsymbol(char *s)
{
    printf("%s\n", s);
    fflush(stdout);
}

/*
 * printsyms() -- walk every node; print text of every IDENT leaf.
 */
void printsyms(struct tree *t)
{
    if (!t) return;
    if (t->leaf) {
        if (t->leaf->category == IDENT)
            printsymbol(t->leaf->text);
        return;
    }
    for (int i = 0; i < t->nkids; i++)
        printsyms(t->kids[i]);
}

/* =========================================================================
 * PART 2 -- buildsyms: build symbol tables from declarations
 *
 * We match nodes by symbolname string because prodrule ints depend on
 * the exact prodrule.h in the student's tree, which may not match ours.
 *
 * Nodes we care about:
 *
 *   "function_declaration"   nkids=3..4
 *     kids[0] = FUN leaf
 *     kids[1] = IDENT:name leaf
 *     kids[2] = function_value_parameters
 *     kids[3] = block  (present when there is a body)
 *
 *   "function_value_parameter"  nkids=3 or 5
 *     kids[0] = IDENT:param_name leaf
 *
 *   "property_declaration"   nkids=4 or 5
 *     4 kids: kids[0]=VAL|VAR  kids[1]=IDENT:name
 *     5 kids: kids[0]=CONST    kids[1]=VAL    kids[2]=IDENT:name
 *
 *   "for_statement"   nkids=7 or 9  (NULL kids skipped by alloktree)
 *     kids[2] = IDENT:iterator
 * ========================================================================= */

static void scan_node(struct tree *t, SymbolTable current);

/* Walk function_value_parameters subtree, insert each param name */
static void insert_params(struct tree *t, SymbolTable local)
{
    if (!t) return;
    if (t->leaf) return;

    if (t->symbolname && strcmp(t->symbolname, "function_value_parameter") == 0) {
        /* kids[0] is always the IDENT:name leaf */
        if (t->nkids >= 1 && t->kids[0] && t->kids[0]->leaf &&
            t->kids[0]->leaf->category == IDENT) {
            insertsym(local, t->kids[0]->leaf->text);
        }
        return;
    }
    for (int i = 0; i < t->nkids; i++)
        insert_params(t->kids[i], local);
}

static void scan_node(struct tree *t, SymbolTable current)
{
    if (!t) return;
    if (t->leaf) return;          /* leaf -- handled by parent */

    const char *name = t->symbolname ? t->symbolname : "";

    /* ── function_declaration ─────────────────────────────────────── */
    if (strcmp(name, "function_declaration") == 0) {

        /* Insert function name into enclosing scope */
        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf &&
            t->kids[1]->leaf->category == IDENT) {
            insertsym(current, t->kids[1]->leaf->text);
        }

        const char *fname = (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf)
                            ? t->kids[1]->leaf->text : "?";

        SymbolTable local = mksymtab(SYM_NBUCKETS);

        /* Parameters are in kids[2] = function_value_parameters */
        if (t->nkids >= 3 && t->kids[2])
            insert_params(t->kids[2], local);

        /* Body: find the kid named "block" or "function_body" */
        for (int i = 3; i < t->nkids; i++) {
            if (!t->kids[i] || !t->kids[i]->symbolname) continue;
            const char *kn = t->kids[i]->symbolname;
            if (strcmp(kn, "block") == 0 || strcmp(kn, "function_body") == 0) {
                scan_node(t->kids[i], local);
                break;
            }
        }

        printf("Function '%s' local scope:\n", fname);
        printsymtab(local, 4);
        printf("\n");
        return;
    }

    /* ── property_declaration ─────────────────────────────────────── */
    if (strcmp(name, "property_declaration") == 0) {
        /* 4-kid form: VAL|VAR  IDENT  opt_type  opt_init   → name at [1]
         * 5-kid form: CONST VAL IDENT opt_type  opt_init   → name at [2] */
        int idx = (t->nkids == 5) ? 2 : 1;
        if (idx < t->nkids && t->kids[idx] && t->kids[idx]->leaf &&
            t->kids[idx]->leaf->category == IDENT) {
            insertsym(current, t->kids[idx]->leaf->text);
        }
        /* Recurse to catch declarations in initializer expressions */
        for (int i = 0; i < t->nkids; i++)
            scan_node(t->kids[i], current);
        return;
    }

    /* ── for_statement: iterator variable ────────────────────────── */
    if (strcmp(name, "for_statement") == 0) {
        /* kids[2] is always IDENT:iterator (alloktree skips NULLs but
         * FOR, LPAREN are always present so iterator stays at index 2) */
        if (t->nkids >= 3 && t->kids[2] && t->kids[2]->leaf &&
            t->kids[2]->leaf->category == IDENT) {
            insertsym(current, t->kids[2]->leaf->text);
        }
        /* Recurse into the body (last kid) */
        if (t->nkids > 0)
            scan_node(t->kids[t->nkids - 1], current);
        return;
    }

    /* ── default: recurse into all children ──────────────────────── */
    for (int i = 0; i < t->nkids; i++)
        scan_node(t->kids[i], current);
}

/*
 * buildsyms() -- entry point.
 */
SymbolTable buildsyms(struct tree *t)
{
    SymbolTable global = mksymtab(SYM_NBUCKETS);
    scan_node(t, global);
    printf("Global scope:\n");
    printsymtab(global, 0);
    printf("\n");
    return global;
}