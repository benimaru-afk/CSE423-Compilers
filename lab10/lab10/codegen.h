#ifndef CODEGEN_H
#define CODEGEN_H

#include "tree.h"
#include "symtab.h"
#include "tac.h"

/*
 * codegen() -- HW6: generate 3-address intermediate code from the parse tree.
 *
 * Walks the tree after all semantic passes have succeeded.
 * Returns a linked list of TAC instructions for the subtree.
 * Also sets t->place on expression nodes with the address of their result.
 *
 * output_ic() -- write the .ic file for a given source file path.
 */
void          assign_first(struct tree *t);
void          assign_follow(struct tree *t);
void          assign_bool_labels(struct tree *t);
struct instr *codegen(struct tree *t, SymbolTable current);
void          output_ic(struct instr *code, const char *src_filename);

/* String constant region management */
void   add_string_const(const char *s);
int    string_const_offset(const char *s);
int    string_region_size(void);
void   print_string_region(FILE *f);

/* Temporary variable allocator -- returns next available LOCAL offset */
int    new_temp(void);
void   reset_temps(int start_offset);

/* Global data region */
struct instr *global_data_code(void);

#endif /* CODEGEN_H */