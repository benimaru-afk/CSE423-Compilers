#ifndef lex_yy_h
#define lex_yy_h

#include <stdio.h>

/* External variables from lex.yy.c */
extern int rows, words, chars;
extern FILE *yyin;

/* Function from lex.yy.c */
extern int yylex(void);

#endif