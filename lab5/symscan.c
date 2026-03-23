#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "token.h"
#include "prodrule.h"
#include "symtab.h"
#include "symscan.h"

/* Token category for IDENT -- matches k0gram.tab.h */
#ifndef IDENT
#include "k0gram.tab.h"
#endif

/* ═══════════════════════════════════════════════════════════════════════════
 * PART 1 -- printsyms / printsymbol
 * ═══════════════════════════════════════════════════════════════════════════ */

static void printsymbol(char *s)
{
    printf("%s\n", s);
    fflush(stdout);
}

/*
 * printsyms() -- recursive tree walk.
 * For every leaf whose category is IDENT, print the symbol.
 * For every interior node, recurse into all children.
 */
void printsyms(struct tree *t)
{
    if (!t) return;

    /* Leaf node: check if it is an identifier */
    if (t->leaf) {
        if (t->leaf->category == IDENT)
            printsymbol(t->leaf->text);
        return;
    }

    /* Interior node: recurse into all children */
    for (int i = 0; i < t->nkids; i++)
        printsyms(t->kids[i]);
}

/* ═══════════════════════════════════════════════════════════════════════════
 * PART 2 -- buildsyms: populate symbol tables from declarations
 *
 * Scoping rules for K0:
 *   - One global symbol table (top-level functions, const vals)
 *   - One local symbol table per function body (parameters + var/val decls)
 *   - for-loop iterator variables go into the loop body's scope
 *
 * Tree shapes we care about (from k0gram.y):
 *
 *   function_declaration (R_FUNCTION_DECLARATION, 5 kids):
 *     [0] FUN  [1] IDENT:name  [2] function_value_parameters
 *     [3] optional_return_type  [4] optional_function_body
 *
 *   function_value_parameter (R_FUNCTION_VALUE_PARAMETER, 3 or 5 kids):
 *     [0] IDENT:name  [1] COLON  [2] full_type  ([3] = [4] default)
 *
 *   property_declaration (R_PROPERTY_DECLARATION, 4 or 5 kids):
 *     4 kids: [0] VAL|VAR  [1] IDENT:name  [2] opt_type  [3] opt_init
 *     5 kids: [0] CONST    [1] VAL         [2] IDENT:name ...
 *
 *   for_statement (R_FOR_STATEMENT, 7 or 9 kids):
 *     7 kids: [0]FOR [1]( [2]IDENT:iter [3]IN [4]expr [5]) [6]body
 *     9 kids: [0]FOR [1]( [2]IDENT:iter [3]: [4]type [5]IN [6]expr [7]) [8]body
 * ═══════════════════════════════════════════════════════════════════════════ */

/* Forward declaration */
static void scan_node(struct tree *t, SymbolTable current);

/*
 * insert_function_params()
 *   Walk the function_value_parameters subtree and insert each
 *   parameter name into the given (local) symbol table.
 */
static void insert_function_params(struct tree *params, SymbolTable local)
{
    if (!params) return;

    /* function_value_parameters has either 2 kids (empty: LPAREN RPAREN)
       or 3 kids (LPAREN param_list RPAREN).  Recurse to find all
       function_value_parameter nodes.                                    */
    if (params->leaf) return;   /* leaf -- nothing to do */

    if (params->prodrule == R_FUNCTION_VALUE_PARAMETER) {
        /* kid[0] is always IDENT:name */
        if (params->nkids >= 1 && params->kids[0] &&
            params->kids[0]->leaf &&
            params->kids[0]->leaf->category == IDENT) {
            insertsym(local, params->kids[0]->leaf->text);
        }
        return;
    }

    /* Otherwise keep recursing (handles param_list chains) */
    for (int i = 0; i < params->nkids; i++)
        insert_function_params(params->kids[i], local);
}

/*
 * scan_node()
 *   The main traversal.  'current' is the symbol table in scope at this node.
 */
static void scan_node(struct tree *t, SymbolTable current)
{
    if (!t) return;

    /* ── Leaf: nothing to insert (declarations are handled by parent) ── */
    if (t->leaf) return;

    switch (t->prodrule) {

    /* ── Function declaration ────────────────────────────────────────── */
    case R_FUNCTION_DECLARATION: {
        /*
         * kid layout: FUN  IDENT:name  fn_value_parameters
         *             optional_return_type  optional_function_body
         * Index:       0      1               2
         *                                              3               4
         */
        /* Insert function name into the enclosing (global) scope */
        if (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf &&
            t->kids[1]->leaf->category == IDENT) {
            insertsym(current, t->kids[1]->leaf->text);
        }

        /* Create a local scope for the function body */
        SymbolTable local = mksymtab(SYM_NBUCKETS);

        /* Insert parameters into the local scope */
        if (t->nkids >= 3)
            insert_function_params(t->kids[2], local);

        /* Scan the body (kid[4] = optional_function_body) under local scope */
        if (t->nkids >= 5)
            scan_node(t->kids[4], local);

        /* Print the local scope */
        printf("Function '%s' local scope:\n",
               (t->nkids >= 2 && t->kids[1] && t->kids[1]->leaf)
                   ? t->kids[1]->leaf->text : "?");
        printsymtab(local, 4);
        printf("\n");
        return;   /* don't fall through to the generic child loop */
    }

    /* ── Property declaration (var / val / const val) ────────────────── */
    case R_PROPERTY_DECLARATION: {
        /*
         * 4-kid form: VAL|VAR  IDENT:name  opt_type  opt_init
         * 5-kid form: CONST    VAL         IDENT:name  opt_type  opt_init
         */
        int name_idx = (t->nkids == 5) ? 2 : 1;
        if (name_idx < t->nkids && t->kids[name_idx] &&
            t->kids[name_idx]->leaf &&
            t->kids[name_idx]->leaf->category == IDENT) {
            insertsym(current, t->kids[name_idx]->leaf->text);
        }
        /* Still recurse into optional_initializer for nested declarations */
        for (int i = 0; i < t->nkids; i++)
            scan_node(t->kids[i], current);
        return;
    }

    /* ── For statement -- iterator variable ─────────────────────────── */
    case R_FOR_STATEMENT: {
        /*
         * 7-kid: FOR ( IDENT:iter IN expr ) body
         * idx:    0  1    2       3  4   5   6
         * 9-kid: FOR ( IDENT:iter : type IN expr ) body
         * idx:    0  1    2       3  4    5  6  7  8
         */
        if (t->nkids >= 3 && t->kids[2] && t->kids[2]->leaf &&
            t->kids[2]->leaf->category == IDENT) {
            insertsym(current, t->kids[2]->leaf->text);
        }
        /* Recurse into the loop body */
        int body_idx = (t->nkids == 9) ? 8 : 6;
        if (body_idx < t->nkids)
            scan_node(t->kids[body_idx], current);
        return;
    }

    /* ── Default: recurse into all children ─────────────────────────── */
    default:
        for (int i = 0; i < t->nkids; i++)
            scan_node(t->kids[i], current);
        break;
    }
}

/*
 * buildsyms() -- entry point.
 *   Creates the global symbol table, kicks off the traversal,
 *   prints the global table, and returns it.
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