/* -*-bison-*- */
/* Simple wc implementation in Flex */
%option noyywrap
%option noinput
%option nounput
%{
			int rows = 0, words = 0, chars = 0;
%}

%%

[\t\f\v\r ]+        { }
\n                  { rows++; }
"//".*              { }
"/*"([^*]|\*+[^*/])*\*+"/"  { }

"class"             { words++; chars += strlen(yytext); return 258; }
"fun"               { words++; chars += strlen(yytext); return 259; }
"var"               { words++; chars += strlen(yytext); return 260; }
"val"               { words++; chars += strlen(yytext); return 261; }
"if"                { words++; chars += strlen(yytext); return 262; }
"else"              { words++; chars += strlen(yytext); return 263; }
"while"             { words++; chars += strlen(yytext); return 264; }
"return"            { words++; chars += strlen(yytext); return 265; }
"print"             { words++; chars += strlen(yytext); return 266; }

"abstract"|"annotation"|"as"|"break"|"by"|"catch"|"companion"|"const"|"constructor"|"continue"|"crossinline"|"data"|"do"|"dynamic"|"enum"|"external"|"false"|"final"|"finally"|"for"|"get"|"import"|"in"|"infix"|"init"|"inline"|"inner"|"interface"|"internal"|"is"|"lateinit"|"noinline"|"null"|"object"|"open"|"operator"|"out"|"override"|"package"|"private"|"protected"|"public"|"reified"|"sealed"|"set"|"super"|"suspend"|"tailrec"|"this"|"throw"|"true"|"try"|"typealias"|"typeof"|"vararg"|"when" {
    fprintf(stderr, "Error: Kotlin reserved word '%s' not allowed in k0\n", yytext);
    exit(1);
}

"..<"               { chars += strlen(yytext); return 314; }
"?:"                { chars += strlen(yytext); return 310; }
"?."                { chars += strlen(yytext); return 311; }
"!!"                { chars += strlen(yytext); return 312; }
".."                { chars += strlen(yytext); return 313; }
"->"                { chars += strlen(yytext); return 315; }

"=="                { chars += strlen(yytext); return 270; }
"!="                { chars += strlen(yytext); return 271; }
"<="                { chars += strlen(yytext); return 272; }
">="                { chars += strlen(yytext); return 273; }
"&&"                { chars += strlen(yytext); return 274; }
"||"                { chars += strlen(yytext); return 275; }
"++"                { chars += strlen(yytext); return 276; }
"--"                { chars += strlen(yytext); return 277; }

"+"                 { chars += strlen(yytext); return 280; }
"-"                 { chars += strlen(yytext); return 281; }
"*"                 { chars += strlen(yytext); return 282; }
"/"                 { chars += strlen(yytext); return 283; }
"%"                 { chars += strlen(yytext); return 284; }
"="                 { chars += strlen(yytext); return 285; }
"<"                 { chars += strlen(yytext); return 286; }
">"                 { chars += strlen(yytext); return 287; }
"!"                 { chars += strlen(yytext); return 288; }
"?"                 { chars += strlen(yytext); return 289; }

"("                 { chars += strlen(yytext); return 290; }
")"                 { chars += strlen(yytext); return 291; }
"{"                 { chars += strlen(yytext); return 292; }
"}"                 { chars += strlen(yytext); return 293; }
"["                 { chars += strlen(yytext); return 294; }
"]"                 { chars += strlen(yytext); return 295; }
","                 { chars += strlen(yytext); return 296; }
";"                 { chars += strlen(yytext); return 297; }
":"                 { chars += strlen(yytext); return 298; }
"."                 { chars += strlen(yytext); return 299; }

\"\"\"([^"]|"[^"]|""[^"])*\"\"\"  { words++; chars += strlen(yytext); return 304; }
\"([^\"\\]|\\.)*\"  { words++; chars += strlen(yytext); return 302; }
'([^'\\]|\\.)'      { words++; chars += strlen(yytext); return 303; }

0[xX][0-9a-fA-F_]+[lL]?              { words++; chars += strlen(yytext); return 305; }
0[bB][01_]+[lL]?                     { words++; chars += strlen(yytext); return 306; }
[0-9][0-9_]*[lL]                     { words++; chars += strlen(yytext); return 307; }
[0-9][0-9_]*\.[0-9_]+[fF]            { words++; chars += strlen(yytext); return 308; }
[0-9][0-9_]*\.[0-9_]+                { words++; chars += strlen(yytext); return 301; }
[0-9][0-9_]*                         { words++; chars += strlen(yytext); return 300; }

@[A-Za-z_][A-Za-z0-9_]*              { words++; chars += strlen(yytext); return 320; }

[A-Za-z_][A-Za-z0-9_]*               { words++; chars += strlen(yytext); return 257; }

.                   { chars++; }

%%