#ifndef SYMSCAN_H
#define SYMSCAN_H

#include "tree.h"
#include "symtab.h"

/*
 * buildsyms() -- build all symbol tables for the program.
 *   Returns the global symbol table.
 *   Also performs redeclaration checking (via insertsym).
 */
SymbolTable buildsyms(struct tree *t);

/*
 * checksyms() -- check for undeclared variable uses.
 *   Must be called after buildsyms().
 *   Increments semantic_errors for each undeclared reference found.
 */
void checksyms(struct tree *t, SymbolTable current);

/*
 * printsyms_all() -- print all symbol tables in the required format.
 *   global is the table returned by buildsyms().
 */
void printsyms_all(SymbolTable global);

#endif /* SYMSCAN_H */