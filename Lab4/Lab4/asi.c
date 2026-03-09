/*
 * asi.c — Automatic Semicolon Insertion wrapper
 *
 * Emit SEMI after newline if previous token can end a statement.
 * Suppress SEMI if next token is '{'.
 *
 * RCURL special rule (per Kotlin spec):
 *   '}' triggers SEMI on newline UNLESS the next real token is 'while'
 *   (which means we're closing a do-while body, not a standalone block).
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

extern YYSTYPE yylval;

static int last_tok = 0;
static int buffered_tok = 0;
static struct token buffered_yytoken;
static YYSTYPE buffered_yylval;

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
        case RPAREN: case RSQUARE:
        case RCURL:   /* handled specially below */
            return 1;
        default:
            return 0;
    }
}

int yylex(void) {
    /* Return buffered token */
    if (buffered_tok) {
        int t = buffered_tok;
        buffered_tok = 0;
        yytoken = buffered_yytoken;
        yylval  = buffered_yylval;
        last_tok = t;
        return t;
    }

    int tok = flex_yylex();

    if (tok == NEWLINE) {
        if (!can_end_statement(last_tok)) {
            /* skip all newlines */
            while (tok == NEWLINE)
                tok = flex_yylex();
            /* fall through */
        } else {
            /* consume all consecutive newlines */
            int next = flex_yylex();
            while (next == NEWLINE)
                next = flex_yylex();

            /* suppress SEMI before '{' */
            if (next == LCURL) {
                last_tok = LCURL;
                return LCURL;
            }

            /* RCURL special case: suppress SEMI if next token is WHILE
             * (this is a do { } while(...) — the WHILE is the terminator,
             * not the start of a new statement)                          */
            if (last_tok == RCURL && next == WHILE) {
                last_tok = WHILE;
                return WHILE;
            }

            /* buffer next token and emit SEMI */
            buffered_tok     = next;
            buffered_yytoken = yytoken;
            buffered_yylval  = yylval;

            semi_token.category = SEMI;
            semi_token.text     = ";";
            semi_token.lineno   = lineno;
            semi_token.filename = current_filename;
            yytoken = semi_token;
            struct token *st = malloc(sizeof(struct token));
            *st = semi_token;
            yylval.treeptr = leafnode(st);
            last_tok = SEMI;
            return SEMI;
        }
    }

    last_tok = tok;
    return tok;
}