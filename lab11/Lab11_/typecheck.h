#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "tree.h"
#include "symtab.h"
#include "type.h"

/*
 * typecheck() -- HW5 semantic analysis pass.
 *
 * Walks the tree AFTER buildsyms() and checksyms() have run.
 * Checks:
 *   - Operator operand type compatibility
 *   - Assignment type compatibility
 *   - Mutability: assignment to val/const is an error
 *   - Nullability: assigning nullable to non-nullable is an error
 *   - Function call argument count
 *
 * Increments semantic_errors for every violation found.
 * Returns the inferred typeptr for the subtree (used recursively).
 */
typeptr typecheck(struct tree *t, SymbolTable current);

#endif /* TYPECHECK_H */