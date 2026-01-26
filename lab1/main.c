#include <stdio.h>
#include <string.h>
#include "lex.yy.h"

extern int rows, words, chars;
extern char *yytext;  /* Add this line! */

int main (int argc, char **argv) {
	FILE *file;
	int token;

	if (argc < 2){
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	file = fopen(argv[1], "r");
	if (!file){
		fprintf(stderr, "Error: Cannot open file as '%s' \n", argv[1]);
		return 1;
	}

	yyin = file;
	
	/* Call yylex() in a while loop and print each word */
	while ((token = yylex()) != 0) {
		printf("token=%d yytext=\"%s\"\n", token, yytext);
	}
	
	fclose(file);

	printf("rows=%d words=%d chars=%d\n", rows, words, chars);
	return 0;
}