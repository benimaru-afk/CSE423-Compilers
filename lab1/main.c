#include <stdio.h>
#include <string.h>
#include "lex.yy.h"

int main (int argc, char **argv) {
	FILE *file;

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
	yylex();
	fclose(file);

	printf("rows=%d words=%d chars=%d\n", rows, words, chars);
	return 0;
}