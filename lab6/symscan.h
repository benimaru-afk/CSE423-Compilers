#ifndef SYMSCAN_H
#define SYMSCAN_H

#include "tree.h"
#include "symtab.h"

/*
 * printsyms() -- Part 1 of the lab.
 *   Walk the tree and call printsymbol() for every IDENT leaf.
 */
void printsyms(struct tree *t);

/*
 * buildsyms() -- Part 2 of the lab.
 *   Walk the tree, create a SymbolTable for each scope (function body,
 *   top level), and insert declared names into the appropriate table.
 *   Returns the top-level (global) symbol table.
 */
SymbolTable buildsyms(struct tree *t);

#endif /* SYMSCAN_H */