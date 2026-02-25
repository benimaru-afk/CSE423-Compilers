#ifndef TREE_H
#define TREE_H

#include "token.h"

/*
 * tree.h - Syntax tree node definition for K0 parser
 */

#define MAX_KIDS 9

struct tree {
    int prodrule;           /* production rule number (from prodrule.h) */
    char *symbolname;       /* human-readable name of the nonterminal */
    int nkids;              /* number of children (0 = leaf) */
    struct tree *kids[MAX_KIDS];
    struct token *leaf;     /* non-NULL only when nkids == 0 */
};

/* Allocate a new interior node with nkids children */
struct tree *alloktree(int prodrule, char *symbolname, int nkids, ...);

/* Allocate a leaf node wrapping a token */
struct tree *leafnode(struct token *t);

/* Print the tree (call with depth=0) */
void treeprint(struct tree *t, int depth);

/* Free the entire tree */
void treefree(struct tree *t);

/* Global parse tree root - assigned from start symbol action */
extern struct tree *parseroot;

#endif /* TREE_H */
