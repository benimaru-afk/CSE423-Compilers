#include <stdio.h>
#include <stdlib.h>
#include "ns.tab.h"

extern FILE *yyin;
extern int yyparse(void);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }
    yyin = file;
    int result = yyparse();
    printf("yyparse returns %d\n", result);
    fclose(file);
    return 0;
}

int yyerror(char *s) {
   fprintf(stderr, "%s\n", s); exit(1);
}