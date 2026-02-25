/*
 * asi.c — Automatic Semicolon Insertion wrapper
 *
 * The parser calls yylex(). The real flex scanner is flex_yylex()
 * (renamed via YY_DECL in k0lex.l). This wrapper intercepts NEWLINE
 * tokens and converts them to SEMI where appropriate.
 *
 * Rules (from Kotlin spec):
 *   Emit SEMI after a newline if the previous token can end a statement.
 *   Suppress that SEMI if the next real token is '{'.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "k0gram.tab.h"
#include "token.h"
#include "tree.h"

extern int flex_yylex(void);
extern struct token yytoken;
extern int lineno;
extern char *current_filename;

/* yylval is declared by bison in k0gram.tab.c; we just need the type */
extern YYSTYPE yylval;

static int last_tok = 0;
static int buffered_tok = 0;
static struct token buffered_yytoken;
static YYSTYPE buffered_yylval;

/* Synthetic SEMI token — static so leafnode can point at it safely */
static struct token semi_token;

static int can_end_statement(int tok) {
    switch (tok) {
        case IDENT:
        case INTEGERLITERAL: case LONGLITERAL:
        case REALLITERAL:    case DOUBLELITERAL:
        case BOOLEANLITERAL: case CHARACTERLITERAL:
        case STRINGLITERAL:  case NULLLITERAL:
        case RETURN: case BREAK: case CONTINUE:
        case INCR:   case DECR:
        case RPAREN: case RSQUARE: case RCURL:
            return 1;
        default:
            return 0;
    }
}

int yylex(void) {
    /* Step 1: return buffered token, restoring both yytoken and yylval */
    if (buffered_tok) {
        int t = buffered_tok;
        buffered_tok = 0;
        yytoken = buffered_yytoken;
        yylval  = buffered_yylval;
        last_tok = t;
        return t;
    }

    int tok = flex_yylex();

    /* Step 2: handle NEWLINEs, possibly emitting a SEMI */
    if (tok == NEWLINE) {
        if (!can_end_statement(last_tok)) {
            /* skip all consecutive newlines */
            while (tok == NEWLINE)
                tok = flex_yylex();
            /* fall through to return tok normally */
        } else {
            /* skip remaining consecutive newlines */
            int next = flex_yylex();
            while (next == NEWLINE)
                next = flex_yylex();

            /* suppress SEMI before '{' */
            if (next == LCURL) {
                last_tok = LCURL;
                /* yylval.tok was already set by flex_yylex via make_token */
                return LCURL;
            }

            /* buffer the next token with its full context */
            buffered_tok    = next;
            buffered_yytoken = yytoken;
            buffered_yylval  = yylval;

            /* build and return a synthetic SEMI */
            semi_token.category = SEMI;
            semi_token.text     = ";";
            semi_token.lineno   = lineno;
            semi_token.filename = current_filename;
            yytoken = semi_token;
            struct token *st = malloc(sizeof(struct token));
            *st = semi_token;
            yylval.tok = st;
            last_tok = SEMI;
            return SEMI;
        }
    }

    last_tok = tok;
    return tok;
}
