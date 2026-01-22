/* -*-bison-*- */
/* Simple wc implementation in Flex */
%option noyywrap
%option noinput
%option nounput
%{
			int rows = 0, words = 0, chars = 0;
%}

spaces_and_tabs  [ \t]+

%%

{spaces_and_tabs}		{ chars += strlen(yytext); }
\n		{ rows++; chars++; }
"//".*          { chars += strlen(yytext); }
[A-Za-z0-9]+	{ words++; chars += strlen(yytext); }
.		{ chars++; }
%%