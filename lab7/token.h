#ifndef TOKEN_H
#define TOKEN_H

struct token {
   int category;      /* token code from ytab.h */
   char *text;        /* the actual lexeme */
   int lineno;        /* line number */
   char *filename;    /* source filename */
   int ival;          /* for integers */
   double dval;       /* for reals */
   char *sval;        /* for strings (unescaped) */
};

struct tokenlist {
   struct token *t;
   struct tokenlist *next;
};

/* Global variable to hold current token info */
extern struct token yytoken;

#endif