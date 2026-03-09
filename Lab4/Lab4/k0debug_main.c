#include <stdio.h>
#include "k0gram.tab.h"
#include "token.h"
#include "tree.h"
extern int yylex(void);
extern struct token yytoken;
YYSTYPE yylval;
int main(int argc, char *argv[]) {
    extern FILE *yyin;
    extern char *current_filename;
    if (argc > 1) { yyin = fopen(argv[1], "r"); current_filename = argv[1]; }
    int tok;
    while ((tok = yylex()) != 0)
        printf("line %-3d tok %-4d  %s\n", yytoken.lineno, tok, yytoken.text);
    return 0;
}
