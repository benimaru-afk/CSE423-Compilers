/*
 * lab9main.c -- Lab 9: Hardwired TAC for the hello-world-with-variable program
 *
 * Kotlin source being represented:
 *   fun main() {
 *       var i : Int = 5;
 *       i = i * i + 1;
 *       println("Variable i is $i.");
 *   }
 *
 * Target TAC:
 *   .string 8
 *       Variable i is %d.\000
 *   .code
 *   proc main,0,32
 *       ASN     loc:0,  const:5        ; i = 5
 *       MUL     loc:8,  loc:0, loc:0   ; t1 = i * i
 *       ADD     loc:16, loc:8, const:1 ; t2 = t1 + 1
 *       ASN     loc:0,  loc:16         ; i = t2
 *       PARM    loc:0                  ; push param 2 (i)
 *       PARM    str:0                  ; push param 1 ("Variable i is %d")
 *       CALL    printf, 2, loc:24      ; t5 = printf(...)
 *       RETURN
 *   end main
 *
 * Memory layout (locals, 8-byte slots):
 *   loc:0  = i       (Int, 8 bytes)
 *   loc:8  = t1      (i * i)
 *   loc:16 = t2      (t1 + 1)
 *   loc:24 = t5      (return value of printf)
 */

#include <stdio.h>
#include <stdlib.h>
#include "tac.h"

int main(void)
{
    /* ── String region header ────────────────────────────────────────── */
    printf(".string 8\n");
    printf("\tVariable i is %%d.\\000\n");
    printf(".code\n");

    /* ── Build the TAC instruction list ─────────────────────────────── */
    struct instr *code = NULL;

    /* proc main, 0 params, 32 bytes frame */
    struct instr *proc = gen(D_PROC,
                             ADDR_NAME("main"),
                             ADDR_CONST(0),    /* nparams */
                             ADDR_CONST(32));  /* frame size */
    code = append(code, proc);

    /* ASN loc:0, const:5     ; i = 5 */
    code = append(code, gen(O_ASN,
                            ADDR_LOCAL(0),
                            ADDR_CONST(5),
                            ADDR_NONE));

    /* MUL loc:8, loc:0, loc:0   ; t1 = i * i */
    code = append(code, gen(O_MUL,
                            ADDR_LOCAL(8),
                            ADDR_LOCAL(0),
                            ADDR_LOCAL(0)));

    /* ADD loc:16, loc:8, const:1  ; t2 = t1 + 1 */
    code = append(code, gen(O_ADD,
                            ADDR_LOCAL(16),
                            ADDR_LOCAL(8),
                            ADDR_CONST(1)));

    /* ASN loc:0, loc:16     ; i = t2 */
    code = append(code, gen(O_ASN,
                            ADDR_LOCAL(0),
                            ADDR_LOCAL(16),
                            ADDR_NONE));

    /* PARM loc:0            ; push param 2 (i) -- pushed right to left */
    code = append(code, gen(O_PARM,
                            ADDR_NONE,
                            ADDR_LOCAL(0),
                            ADDR_NONE));

    /* PARM str:0            ; push param 1 ("Variable i is %d") */
    code = append(code, gen(O_PARM,
                            ADDR_NONE,
                            ADDR_STRING(0),
                            ADDR_NONE));

    /* CALL printf, 2, loc:24  ; t5 = printf(...) */
    code = append(code, gen(O_CALL,
                            ADDR_NAME("printf"),
                            ADDR_CONST(2),    /* nargs */
                            ADDR_LOCAL(24))); /* result temp */

    /* RETURN */
    code = append(code, gen(O_RET,
                            ADDR_NONE,
                            ADDR_NONE,
                            ADDR_NONE));

    /* end main */
    code = append(code, gen(D_END,
                            ADDR_NAME("main"),
                            ADDR_NONE,
                            ADDR_NONE));

    /* ── Print the list ─────────────────────────────────────────────── */
    tacprint(code);

    return 0;
}