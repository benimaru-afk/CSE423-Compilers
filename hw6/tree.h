#ifndef TREE_H
#define TREE_H

/* =========================================================
 * tree.h — Parse tree node definition for the K0 compiler
 * ========================================================= */

#include "token.h"
#include "tac.h"   /* for struct addr (place field) */

/* forward-declare SymbolTable so tree.h doesn't need symtab.h
   (avoids a circular include if symtab.h ever includes tree.h) */
struct sym_table;

#define MAXKIDS  9     /* max children per interior node  */
#define MAX_KIDS 9     /* alias used in tree.c             */

/* forward-declare typeinfo to avoid pulling in all of type.h here */
struct typeinfo;

struct tree {
    int           prodrule;        /* R_* constant from prodrule.h  */
    char         *symbolname;      /* nonterminal name (for printing)*/
    int           nkids;           /* number of children            */
    struct tree  *kids[MAXKIDS];   /* child pointers                */
    struct token *leaf;            /* non-NULL if this is a leaf    */
    struct sym_table *stab;        /* symbol table for this scope   */
    struct typeinfo  *type;        /* type annotation (lab 7)       */
    struct addr       place;       /* for codegen: address of result of this subtree */
};

/* the root of the most recently parsed tree */
extern struct tree *parseroot;

/* constructor functions */
struct tree *alloktree(int prodrule, char *symbolname, int nkids, ...);
struct tree *leafnode(struct token *t);

/* printing */
void treeprint(struct tree *t, int depth);
void printnode(struct tree *t);

/* cleanup */
void treefree(struct tree *t);

#endif /* TREE_H */