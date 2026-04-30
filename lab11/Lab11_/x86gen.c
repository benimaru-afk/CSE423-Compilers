/*
 * x86gen.c -- Lab 11: starter x86-64 code generation from TAC
 *
 * This file is deliberately written as a small, readable translation table
 * from the compiler's TAC instructions to the x86-64 patterns studied with
 * gcc -S.  It handles the core instructions needed by the Lab 10 examples:
 * locals, constants, string addresses, arithmetic, branches, params, calls,
 * returns, labels, and procedure prologue/epilogue.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tac.h"
#include "codegen.h"
#include "x86gen.h"

#define MAX_PARAMS 64

static struct addr pending_params[MAX_PARAMS];
static int pending_count = 0;
static int current_frame_size = 128;
static char current_end_label[128] = ".Lend_main";

static const char *base_name(const char *path)
{
    const char *base = path;
    const char *slash = strrchr(path, '/');
    if (slash) base = slash + 1;
    const char *backslash = strrchr(base, '\\');
    if (backslash) base = backslash + 1;
    return base;
}

static void output_name(char *out, size_t n, const char *src_filename, const char *ext)
{
    const char *base = base_name(src_filename);
    snprintf(out, n, "%s", base);
    char *dot = strrchr(out, '.');
    if (dot) *dot = '\0';
    strncat(out, ext, n - strlen(out) - 1);
}

static int local_offset(struct addr a)
{
    /* TAC uses loc:0, loc:8, ...; x86 stack slots live below rbp. */
    return -(a.u.offset + 8);
}

static void emit_operand(FILE *f, struct addr a)
{
    switch (a.region) {
        case R_LOCAL:
            fprintf(f, "%d(%%rbp)", local_offset(a));
            break;
        case R_CONST:
            fprintf(f, "$%d", a.u.offset);
            break;
        case R_GLOBAL:
            fprintf(f, "global_%d(%%rip)", a.u.offset);
            break;
        case R_STRING:
            fprintf(f, ".LC%d(%%rip)", a.u.offset);
            break;
        case R_LABEL:
            fprintf(f, "lab%d", a.u.offset);
            break;
        case R_NAME:
            fprintf(f, "%s", a.u.name ? a.u.name : "?");
            break;
        default:
            fprintf(f, "$0");
            break;
    }
}

static void load_rax(FILE *f, struct addr a)
{
    if (a.region == R_CONST) {
        fprintf(f, "\tmovq\t$%d, %%rax\n", a.u.offset);
    } else if (a.region == R_STRING) {
        fprintf(f, "\tleaq\t.LC%d(%%rip), %%rax\n", a.u.offset);
    } else if (a.region == R_LOCAL || a.region == R_GLOBAL) {
        fprintf(f, "\tmovq\t");
        emit_operand(f, a);
        fprintf(f, ", %%rax\n");
    } else if (a.region == R_NAME) {
        fprintf(f, "\tleaq\t%s(%%rip), %%rax\n", a.u.name ? a.u.name : "?");
    } else {
        fprintf(f, "\tmovq\t$0, %%rax\n");
    }
}

static void load_reg(FILE *f, const char *reg, struct addr a)
{
    if (a.region == R_CONST) {
        fprintf(f, "\tmovq\t$%d, %s\n", a.u.offset, reg);
    } else if (a.region == R_STRING) {
        fprintf(f, "\tleaq\t.LC%d(%%rip), %s\n", a.u.offset, reg);
    } else if (a.region == R_LOCAL || a.region == R_GLOBAL) {
        fprintf(f, "\tmovq\t");
        emit_operand(f, a);
        fprintf(f, ", %s\n", reg);
    } else if (a.region == R_NAME) {
        fprintf(f, "\tleaq\t%s(%%rip), %s\n", a.u.name ? a.u.name : "?", reg);
    } else {
        fprintf(f, "\tmovq\t$0, %s\n", reg);
    }
}

static void store_rax(FILE *f, struct addr dest)
{
    if (dest.region == R_LOCAL || dest.region == R_GLOBAL) {
        fprintf(f, "\tmovq\t%%rax, ");
        emit_operand(f, dest);
        fprintf(f, "\n");
    }
}

static void emit_cmp_and_jump(FILE *f, int opcode, struct addr dest, struct addr left, struct addr right)
{
    load_rax(f, left);
    if (right.region == R_NONE || right.region == 0) {
        fprintf(f, "\tcmpq\t$0, %%rax\n");
    } else if (right.region == R_CONST) {
        fprintf(f, "\tcmpq\t$%d, %%rax\n", right.u.offset);
    } else {
        fprintf(f, "\tcmpq\t");
        emit_operand(f, right);
        fprintf(f, ", %%rax\n");
    }

    const char *j = "jne";
    const char *set = "setne";
    switch (opcode) {
        case O_BLT:  j = "jl";  set = "setl";  break;
        case O_BLE:  j = "jle"; set = "setle"; break;
        case O_BGT:  j = "jg";  set = "setg";  break;
        case O_BGE:  j = "jge"; set = "setge"; break;
        case O_BEQ:  j = "je";  set = "sete";  break;
        case O_BNE:  j = "jne"; set = "setne"; break;
        case O_BIF:  j = "jne"; set = "setne"; break;
        case O_BNIF: j = "je";  set = "sete";  break;
    }

    if (dest.region == R_LABEL) {
        fprintf(f, "\t%s\tlab%d\n", j, dest.u.offset);
    } else {
        /* Some current TAC uses BLT/BEQ/etc. as boolean-producing ops:
         *     blt loc:8, loc:0, const:10
         * Store 0/1 into the destination local/global in that case. */
        fprintf(f, "\t%s\t%%al\n", set);
        fprintf(f, "\tmovzbq\t%%al, %%rax\n");
        store_rax(f, dest);
    }
}

static void emit_rodata(FILE *f)
{
    print_x86_string_region(f);
}

void output_x86(struct instr *code, const char *src_filename)
{
    char outname[512];
    output_name(outname, sizeof(outname), src_filename, ".s");

    FILE *f = fopen(outname, "w");
    if (!f) {
        fprintf(stderr, "x86gen: cannot open %s for writing\n", outname);
        return;
    }

    fprintf(f, "\t.file\t\"%s\"\n", base_name(src_filename));
    emit_rodata(f);

    /* Pre-scan: collect unique R_GLOBAL offsets and emit .comm declarations */
    int seen_globals[256];
    int nglobals = 0;
    for (struct instr *l = code; l; l = l->next) {
        struct addr *ops[3] = { &l->dest, &l->src1, &l->src2 };
        for (int i = 0; i < 3; i++) {
            if (ops[i]->region != R_GLOBAL) continue;
            int off = ops[i]->u.offset;
            int found = 0;
            for (int j = 0; j < nglobals; j++)
                if (seen_globals[j] == off) { found = 1; break; }
            if (!found && nglobals < 256)
                seen_globals[nglobals++] = off;
        }
    }
    if (nglobals > 0) {
        fprintf(f, "\t.bss\n");
        for (int i = 0; i < nglobals; i++)
            fprintf(f, "\t.comm\tglobal_%d, 8, 8\n", seen_globals[i]);
    }

    fprintf(f, "\t.text\n");

    pending_count = 0;

    for (struct instr *l = code; l; l = l->next) {
        int op = l->opcode;

        if (op == D_PROC) {
            const char *fname = l->dest.u.name ? l->dest.u.name : "main";
            int requested = (l->src2.region == R_CONST) ? l->src2.u.offset : 128;
            current_frame_size = ((requested + 15) / 16) * 16;
            snprintf(current_end_label, sizeof(current_end_label), ".Lend_%s", fname);

            fprintf(f, "\t.globl\t%s\n", fname);
            fprintf(f, "\t.type\t%s, @function\n", fname);
            fprintf(f, "%s:\n", fname);
            fprintf(f, "\tpushq\t%%rbp\n");
            fprintf(f, "\tmovq\t%%rsp, %%rbp\n");
            if (current_frame_size > 0)
                fprintf(f, "\tsubq\t$%d, %%rsp\n", current_frame_size);
            continue;
        }

        if (op == D_END) {
            const char *fname = l->dest.u.name ? l->dest.u.name : "main";
            fprintf(f, "%s:\n", current_end_label);
            fprintf(f, "\tleave\n");
            fprintf(f, "\tret\n");
            fprintf(f, "\t.size\t%s, .-%s\n", fname, fname);
            continue;
        }

        if (op == D_LABEL) {
            fprintf(f, "lab%d:\n", l->dest.u.offset);
            continue;
        }

        if (op == O_GOTO) {
            fprintf(f, "\tjmp\tlab%d\n", l->dest.u.offset);
            continue;
        }

        if (op == O_ASN) {
            load_rax(f, l->src1);
            store_rax(f, l->dest);
            continue;
        }

        if (op == O_ADDR) {
            if (l->src1.region == R_STRING)
                fprintf(f, "\tleaq\t.LC%d(%%rip), %%rax\n", l->src1.u.offset);
            else
                load_rax(f, l->src1);
            store_rax(f, l->dest);
            continue;
        }

        if (op == O_NEG) {
            load_rax(f, l->src1);
            fprintf(f, "\tnegq\t%%rax\n");
            store_rax(f, l->dest);
            continue;
        }

        if (op == O_ADD || op == O_SUB || op == O_MUL || op == O_DIV) {
            load_rax(f, l->src1);
            load_reg(f, "%rdx", l->src2);
            if (op == O_ADD) fprintf(f, "\taddq\t%%rdx, %%rax\n");
            if (op == O_SUB) fprintf(f, "\tsubq\t%%rdx, %%rax\n");
            if (op == O_MUL) fprintf(f, "\timulq\t%%rdx, %%rax\n");
            if (op == O_DIV) {
                fprintf(f, "\tcqto\n");
                fprintf(f, "\tidivq\t%%rdx\n");
            }
            store_rax(f, l->dest);
            continue;
        }

        if (op >= O_BLT && op <= O_BNIF) {
            emit_cmp_and_jump(f, op, l->dest, l->src1, l->src2);
            continue;
        }

        if (op == O_PARM) {
            if (pending_count < MAX_PARAMS)
                pending_params[pending_count++] = l->src1;
            continue;
        }

        if (op == O_CALL) {
            const char *regs[] = { "%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9" };
            int nargs = l->src1.u.offset;
            int reg_args = nargs < 6 ? nargs : 6;

            /* TAC emits parms right-to-left.  Reverse them into ABI order. */
            for (int i = 0; i < reg_args; i++) {
                int source_index = pending_count - 1 - i;
                if (source_index >= 0)
                    load_reg(f, regs[i], pending_params[source_index]);
            }

            fprintf(f, "\tmovl\t$0, %%eax\n"); /* varargs ABI rule for printf */
            fprintf(f, "\tcall\t%s@PLT\n", l->dest.u.name ? l->dest.u.name : "?");
            store_rax(f, l->src2);
            pending_count = 0;
            continue;
        }

        if (op == O_RET) {
            if (l->src1.region != R_NONE)
                load_rax(f, l->src1);
            fprintf(f, "\tjmp\t%s\n", current_end_label);
            continue;
        }
    }

    fprintf(f, "\t.section\t.note.GNU-stack,\"\",@progbits\n");
    fclose(f);
    printf("wrote %s\n", outname);
}
