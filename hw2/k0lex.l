%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ytab.h"
#include "token.h"

struct token yytoken;
int lineno = 1;
char *current_filename = "stdin";

void make_token(int category);
char* unescape_string(char *str);
%}

%option noyywrap

%%

"\n"                { lineno++; }
[\t\f\v\r ]+        { /* ignore whitespace */ }
"//".*              { /* line comment */ }

"fun"               { make_token(FUN); return FUN; }
"var"               { make_token(VAR); return VAR; }
"while"             { make_token(WHILE); return WHILE; }
"if"                { make_token(IF); return IF; }
"return"            { make_token(RETURN); return RETURN; }
"null"              { make_token(NULLLITERAL); return NULLLITERAL; }
"true"|"false"      { make_token(BOOLEANLITERAL); return BOOLEANLITERAL; }

[a-zA-Z_][a-zA-Z0-9_]*  { make_token(IDENT); return IDENT; }

[0-9]+              { 
                      make_token(INTEGERLITERAL);
                      yytoken.ival = atoi(yytext);
                      return INTEGERLITERAL;
                    }

[0-9]+"."[0-9]+     {
                      make_token(REALLITERAL);
                      yytoken.dval = atof(yytext);
                      return REALLITERAL;
                    }

"\""([^"\n\\]|\\.)*"\""  {
                      make_token(STRINGLITERAL);
                      yytoken.sval = unescape_string(yytext);
                      return STRINGLITERAL;
                    }

"("                 { make_token(LPAREN); return LPAREN; }
")"                 { make_token(RPAREN); return RPAREN; }
"{"                 { make_token(LCURL); return LCURL; }
"}"                 { make_token(RCURL); return RCURL; }
"<"                 { make_token(LANGLE); return LANGLE; }
">"                 { make_token(RANGLE); return RANGLE; }
":"                 { make_token(COLON); return COLON; }
";"                 { make_token(SEMI); return SEMI; }
"="                 { make_token(ASSIGNMENT); return ASSIGNMENT; }
","                 { make_token(COMMA); return COMMA; }
"."                 { make_token(DOT); return DOT; }
"?"                 { make_token(QUEST); return QUEST; }

.                   { 
                      fprintf(stderr, "Error: unexpected character '%s' at line %d\n", 
                              yytext, lineno);
                      exit(1);
                    }



%%

void make_token(int category) {
    yytoken.category = category;
    yytoken.text = strdup(yytext);
    yytoken.lineno = lineno;
    yytoken.filename = current_filename;
}

char* unescape_string(char *str) {
    /* Remove quotes and handle escape sequences */
    int len = strlen(str);
    char *result = malloc(len);
    int j = 0;
    
    for (int i = 1; i < len - 1; i++) {  /* Skip opening/closing quotes */
        if (str[i] == '\\' && i + 1 < len - 1) {
            switch(str[i+1]) {
                case 'n': result[j++] = '\n'; i++; break;
                case 't': result[j++] = '\t'; i++; break;
                case '\\': result[j++] = '\\'; i++; break;
                case '"': result[j++] = '"'; i++; break;
                default: result[j++] = str[i];
            }
        } else {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    return result;
}