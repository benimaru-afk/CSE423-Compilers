/*
 * tac.c -- Three Address Code support for CSE 423
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"

/* ── Region / opcode name tables ─────────────────────────────────────────── */

/* Indexed by (region - R_GLOBAL) */
char *regionnames[] = {
    "global", "loc", "class", "lab", "const", "str", "none"
};
char *regionname(int i)
{
    if (i < R_GLOBAL || i > R_STRING) return "?";
    return regionnames[i - R_GLOBAL];
}

/* Indexed by (opcode - O_ADD) */
char *opcodenames[] = {
    "ADD", "SUB", "MUL", "DIV", "NEG", "ASN", "ADDR", "LCONT", "SCONT",
    "GOTO", "BLT", "BLE", "BGT", "BGE", "BEQ", "BNE", "BIF", "BNIF",
    "PARM", "CALL", "RETURN"
};
char *opcodename(int i)
{
    if (i < O_ADD || i > O_RET) return "?OP?";
    return opcodenames[i - O_ADD];
}

/* Indexed by (pseudo - D_GLOB) */
char *pseudonames[] = {
    "glob", "proc", "loc", "lab", "end", "prot"
};
char *pseudoname(int i)
{
    if (i < D_GLOB || i > D_PROT) return "?PS?";
    return pseudonames[i - D_GLOB];
}

/* ── Label counter ────────────────────────────────────────────────────────── */
int labelcounter = 0;

struct addr genlabel(void)
{
    struct addr a;
    a.region   = R_LABEL;
    a.u.offset = labelcounter++;
    return a;
}

/* ── Instruction constructors ─────────────────────────────────────────────── */

struct instr *gen(int op, struct addr dest, struct addr src1, struct addr src2)
{
    struct instr *rv = malloc(sizeof(struct instr));
    if (!rv) { fprintf(stderr, "gen: out of memory\n"); exit(4); }
    rv->opcode = op;
    rv->dest   = dest;
    rv->src1   = src1;
    rv->src2   = src2;
    rv->next   = NULL;
    return rv;
}

struct instr *copylist(struct instr *l)
{
    if (!l) return NULL;
    struct instr *copy = gen(l->opcode, l->dest, l->src1, l->src2);
    copy->next = copylist(l->next);
    return copy;
}

struct instr *append(struct instr *l1, struct instr *l2)
{
    if (!l1) return l2;
    struct instr *tmp = l1;
    while (tmp->next) tmp = tmp->next;
    tmp->next = l2;
    return l1;
}

struct instr *concat(struct instr *l1, struct instr *l2)
{
    return append(copylist(l1), l2);
}

/* ── Address printer ──────────────────────────────────────────────────────── */

static void print_addr(struct addr a)
{
    switch (a.region) {
        case R_LOCAL:  printf("loc:%d",    a.u.offset); break;
        case R_GLOBAL: printf("global:%d", a.u.offset); break;
        case R_CONST:  printf("const:%d",  a.u.offset); break;
        case R_LABEL:  printf("lab:%d",    a.u.offset); break;
        case R_NAME:   printf("%s",         a.u.name ? a.u.name : "?"); break;
        case R_STRING: printf("str:%d",    a.u.offset); break;
        case R_CLASS:  printf("class:%d",  a.u.offset); break;
        case R_NONE:   /* print nothing */               break;
        default:       printf("?:%d",      a.u.offset); break;
    }
}

/* ── tacprint: print the full linked list ─────────────────────────────────── */

void tacprint(struct instr *l)
{
    while (l) {
        int op = l->opcode;

        /* ── Pseudo-instructions ──────────────────────── */
        if (op == D_PROC) {
            printf("proc %s", l->dest.u.name ? l->dest.u.name : "?");
            if (l->src1.region != R_NONE) {
                printf(",%d", l->src1.u.offset);   /* nparams */
            }
            if (l->src2.region != R_NONE) {
                printf(",%d", l->src2.u.offset);   /* frame size */
            }
            printf("\n");
            l = l->next; continue;
        }
        if (op == D_END) {
            printf("end %s\n",
                   l->dest.u.name ? l->dest.u.name : "");
            l = l->next; continue;
        }
        if (op == D_GLOB) {
            printf("glob ");
            print_addr(l->dest);
            printf("\n");
            l = l->next; continue;
        }
        if (op == D_LABEL) {
            printf("lab:%d:\n", l->dest.u.offset);
            l = l->next; continue;
        }

        /* ── RETURN ───────────────────────────────────── */
        if (op == O_RET) {
            printf("\tRETURN");
            if (l->src1.region != R_NONE) {
                printf("\t"); print_addr(l->src1);
            }
            printf("\n");
            l = l->next; continue;
        }

        /* ── CALL: dest = name, src1 = nargs, src2 = result ── */
        if (op == O_CALL) {
            printf("\tCALL\t");
            print_addr(l->dest);                    /* function name */
            printf(",%d,", l->src1.u.offset);       /* nargs */
            print_addr(l->src2);                    /* result location */
            printf("\n");
            l = l->next; continue;
        }

        /* ── PARM: src1 only ─────────────────────────── */
        if (op == O_PARM) {
            printf("\tPARM\t");
            print_addr(l->src1);
            printf("\n");
            l = l->next; continue;
        }

        /* ── GOTO ────────────────────────────────────── */
        if (op == O_GOTO) {
            printf("\tGOTO\t");
            print_addr(l->dest);
            printf("\n");
            l = l->next; continue;
        }

        /* ── Unary: NEG, ASN (dest, src1) ───────────── */
        if (op == O_NEG || op == O_ASN) {
            printf("\t%-8s", opcodename(op));
            print_addr(l->dest);
            printf(",");
            print_addr(l->src1);
            printf("\n");
            l = l->next; continue;
        }

        /* ── Branch ops: dest=label, src1, src2 ─────── */
        if (op >= O_BLT && op <= O_BNIF) {
            printf("\t%-8s", opcodename(op));
            print_addr(l->dest);   /* label */
            if (l->src1.region != R_NONE) {
                printf(","); print_addr(l->src1);
            }
            if (l->src2.region != R_NONE) {
                printf(","); print_addr(l->src2);
            }
            printf("\n");
            l = l->next; continue;
        }

        /* ── Default: binary ops (dest, src1, src2) ─── */
        printf("\t%-8s", opcodename(op));
        print_addr(l->dest);
        printf(",");
        print_addr(l->src1);
        if (l->src2.region != R_NONE) {
            printf(",");
            print_addr(l->src2);
        }
        printf("\n");

        l = l->next;
    }
}