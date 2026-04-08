#ifndef SYMSCAN_H
#define SYMSCAN_H

#include "tree.h"
#include "symtab.h"

SymbolTable buildsyms(struct tree *t);
void        checksyms(struct tree *t, SymbolTable current);
void        printsyms_all(SymbolTable global);

#endif /* SYMSCAN_H */