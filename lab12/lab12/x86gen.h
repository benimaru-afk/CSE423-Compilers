#ifndef X86GEN_H
#define X86GEN_H

#include "tac.h"

/*
 * output_x86() -- Lab 11 starter x86-64 final-code generator.
 *
 * This translates the subset of TAC currently produced by the compiler into
 * GNU as / gcc-compatible x86-64 assembly.  It is intentionally simple and
 * close to the reverse-engineering patterns from gcc -S.
 */
void output_x86(struct instr *code, const char *src_filename);

#endif /* X86GEN_H */
