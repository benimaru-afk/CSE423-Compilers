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


"as"                { make_token(AS); return AS; }
"break"             { make_token(BREAK); return BREAK; }
"const"             { make_token(CONST); return CONST; }
"continue"          { make_token(CONTINUE); return CONTINUE; }
"do"                { make_token(DO); return DO; }
"else"              { make_token(ELSE); return ELSE; }
"for"               { make_token(FOR); return FOR; }
"fun"               { make_token(FUN); return FUN; }
"if"                { make_token(IF); return IF; }
"import"            { make_token(IMPORT); return IMPORT; }
"in"                { make_token(IN); return IN; }
"null"              { make_token(NULLLITERAL); return NULLLITERAL; }
"return"            { make_token(RETURN); return RETURN; }
"val"               { make_token(VAL); return VAL; }
"var"               { make_token(VAR); return VAR; }
"when"              { make_token(WHEN); return WHEN; }
"while"             { make_token(WHILE); return WHILE; }


"true"|"false"      { make_token(BOOLEANLITERAL); return BOOLEANLITERAL; }

"==="               { make_token(REF_EQ); return REF_EQ; }
"!=="               { make_token(REF_NEQ); return REF_NEQ; }
"..<"               { make_token(RANGE_UNTIL); return RANGE_UNTIL; }

"++"                { make_token(INCR); return INCR; }
"--"                { make_token(DECR); return DECR; }
"+="                { make_token(ADD_ASSIGN); return ADD_ASSIGN; }
"-="                { make_token(SUB_ASSIGN); return SUB_ASSIGN; }
"*="                { make_token(MUL_ASSIGN); return MUL_ASSIGN; }
"/="                { make_token(DIV_ASSIGN); return DIV_ASSIGN; }
"%="                { make_token(MOD_ASSIGN); return MOD_ASSIGN; }
"=="                { make_token(EQ); return EQ; }
"!="                { make_token(NEQ); return NEQ; }
"<="                { make_token(LTE); return LTE; }
">="                { make_token(GTE); return GTE; }
"&&"                { make_token(AND); return AND; }
"||"                { make_token(OR); return OR; }
"?."                { make_token(SAFE_CALL); return SAFE_CALL; }
"?:"                { make_token(ELVIS); return ELVIS; }
".."                { make_token(RANGE); return RANGE; }
"->"                { make_token(ARROW); return ARROW; }
"::"                { make_token(DOUBLE_COLON); return DOUBLE_COLON; }

"+"                 { make_token(ADD); return ADD; }
"-"                 { make_token(SUB); return SUB; }
"*"                 { make_token(MUL); return MUL; }
"/"                 { make_token(DIV); return DIV; }
"%"                 { make_token(MOD); return MOD; }
"!"                 { make_token(NOT); return NOT; }
"="                 { make_token(ASSIGNMENT); return ASSIGNMENT; }
"<"                 { make_token(LANGLE); return LANGLE; }  /* Also serves as LT */
">"                 { make_token(RANGLE); return RANGLE; }  /* Also serves as GT */
"?"                 { make_token(QUEST); return QUEST; }

"("                 { make_token(LPAREN); return LPAREN; }
")"                 { make_token(RPAREN); return RPAREN; }
"{"                 { make_token(LCURL); return LCURL; }
"}"                 { make_token(RCURL); return RCURL; }
"["                 { make_token(LSQUARE); return LSQUARE; }
"]"                 { make_token(RSQUARE); return RSQUARE; }
","                 { make_token(COMMA); return COMMA; }
"."                 { make_token(DOT); return DOT; }
":"                 { make_token(COLON); return COLON; }
";"                 { make_token(SEMI); return SEMI; }

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

"\'"([^'\n\\]|\\.)"\'"  {
                      make_token(CHARACTERLITERAL);
                      /* TODO: handle character value */
                      return CHARACTERLITERAL;
                    }

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
                case 'r': result[j++] = '\r'; i++; break;
                case 'b': result[j++] = '\b'; i++; break;
                case 'f': result[j++] = '\f'; i++; break;
                case '\\': result[j++] = '\\'; i++; break;
                case '"': result[j++] = '"'; i++; break;
                case '\'': result[j++] = '\''; i++; break;
                default: result[j++] = str[i];
            }
        } else {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    return result;
}