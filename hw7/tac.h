/*
 * Three Address Code - skeleton for CSE 423
 */
#ifndef TAC_H
#define TAC_H

struct addr {
    int region;
    union {
        int offset;
        char *name;
    } u;
};

/* Regions: */
#define R_GLOBAL 2001   /* relative to pc / global data */
#define R_LOCAL  2002   /* relative to ebp / stack frame */
#define R_CLASS  2003   /* relative to 'this' register */
#define R_LABEL  2004   /* pseudo-region for code labels */
#define R_CONST  2005   /* immediate mode constants */
#define R_NAME   2006   /* source-level names (e.g. function names) */
#define R_NONE   2007   /* unused / null address */
#define R_STRING 2008   /* string literal region */

struct instr {
    int opcode;
    struct addr dest, src1, src2;
    struct instr *next;
};

/* Opcodes */
#define O_ADD   3001
#define O_SUB   3002
#define O_MUL   3003
#define O_DIV   3004
#define O_NEG   3005
#define O_ASN   3006
#define O_ADDR  3007
#define O_LCONT 3008
#define O_SCONT 3009
#define O_GOTO  3010
#define O_BLT   3011
#define O_BLE   3012
#define O_BGT   3013
#define O_BGE   3014
#define O_BEQ   3015
#define O_BNE   3016
#define O_BIF   3017
#define O_BNIF  3018
#define O_PARM  3019
#define O_CALL  3020
#define O_RET   3021

/* Pseudo-instructions / declarations */
#define D_GLOB  3051
#define D_PROC  3052
#define D_LOCAL 3053
#define D_LABEL 3054
#define D_END   3055
#define D_PROT  3056    /* prototype declaration */

/* Helper macros to build addr structs inline */
#define ADDR_LOCAL(off)  ((struct addr){ R_LOCAL,  { .offset = (off) } })
#define ADDR_CONST(val)  ((struct addr){ R_CONST,  { .offset = (val) } })
#define ADDR_GLOBAL(off) ((struct addr){ R_GLOBAL, { .offset = (off) } })
#define ADDR_NAME(n)     ((struct addr){ R_NAME,   { .name   = (n)   } })
#define ADDR_STRING(off) ((struct addr){ R_STRING, { .offset = (off) } })
#define ADDR_NONE        ((struct addr){ R_NONE,   { .offset = 0     } })

/* API */
struct instr *gen(int op, struct addr dest, struct addr src1, struct addr src2);
struct instr *copylist(struct instr *l);
struct instr *append(struct instr *l1, struct instr *l2);
struct instr *concat(struct instr *l1, struct instr *l2);
void          tacprint(struct instr *l);

char *regionname(int i);
char *opcodename(int i);
char *pseudoname(int i);

struct addr genlabel(void);

extern int labelcounter;

#endif /* TAC_H */