#ifndef SYMSCAN_H
#define SYMSCAN_H

#include "tree.h"
#include "symtab.h"

/* Scope registry -- also used by typecheck.c */
#define MAX_SCOPES 512
extern SymbolTable all_scopes[];
extern int         nscopes;

SymbolTable buildsyms(struct tree *t);
void        checksyms(struct tree *t, SymbolTable current);
void        printsyms_all(SymbolTable global);

#endif /* SYMSCAN_H */