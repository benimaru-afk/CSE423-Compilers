/*
 * debug_main.c - prints every token, used to debug the lexer+ASI
 * Compile: gcc lex.yy.c asi.c debug_main.c -o k0debug
 * (do NOT include k0gram.tab.c - it has its own main)
 */
#include <stdio.h>
#include "k0gram.tab.h"
#include "token.h"

extern int yylex(void);      /* the ASI wrapper in asi.c */
extern struct token yytoken;
extern int lineno;
extern FILE *yyin;
extern char *current_filename;

static const char* tokname(int t) {
    switch(t) {
        case FUN: return "FUN";
        case VAL: return "VAL";        case VAR: return "VAR";
        case IF: return "IF";          case ELSE: return "ELSE";
        case WHILE: return "WHILE";    case FOR: return "FOR";
        case RETURN: return "RETURN";  case BREAK: return "BREAK";
        case CONTINUE: return "CONTINUE"; case WHEN: return "WHEN";
        case IN: return "IN";          case DO: return "DO";
        case IMPORT: return "IMPORT";  case CONST: return "CONST";
        case AS: return "AS";
        case INTEGERLITERAL: return "INTEGERLITERAL";
        case REALLITERAL:    return "REALLITERAL";
        case STRINGLITERAL:  return "STRINGLITERAL";
        case BOOLEANLITERAL: return "BOOLEANLITERAL";
        case CHARACTERLITERAL: return "CHARLITERAL";
        case NULLLITERAL:    return "NULLLITERAL";
        case LONGLITERAL:    return "LONGLITERAL";
        case DOUBLELITERAL:  return "DOUBLELITERAL";
        case IDENT:          return "IDENT";
        case NEWLINE:        return "NEWLINE";
        case ASSIGNMENT:     return "ASSIGNMENT(=)";
        case ADD_ASSIGN:     return "ADD_ASSIGN";
        case SUB_ASSIGN:     return "SUB_ASSIGN";
        case MUL_ASSIGN:     return "MUL_ASSIGN";
        case DIV_ASSIGN:     return "DIV_ASSIGN";
        case MOD_ASSIGN:     return "MOD_ASSIGN";
        case ADD: return "ADD(+)";     case SUB: return "SUB(-)";
        case MUL: return "MUL(*)";     case DIV: return "DIV(/)";
        case MOD: return "MOD(%)";
        case INCR: return "INCR(++)";  case DECR: return "DECR(--)";
        case EQ: return "EQ(==)";      case NEQ: return "NEQ(!=)";
        case GTE: return "GTE(>=)";    case LTE: return "LTE(<=)";
        case LANGLE: return "LANGLE(<)"; case RANGLE: return "RANGLE(>)";
        case REF_EQ: return "REF_EQ(===)"; case REF_NEQ: return "REF_NEQ(!==)";
        case AND: return "AND(&&)";    case OR: return "OR(||)";
        case NOT: return "NOT(!)";
        case SAFE_CALL: return "SAFE_CALL(?.)";
        case ELVIS: return "ELVIS(?:)"; case QUEST: return "QUEST(?)";
        case RANGE: return "RANGE(..)"; case RANGE_UNTIL: return "RANGE_UNTIL(..<)";
        case LPAREN: return "LPAREN";  case RPAREN: return "RPAREN";
        case LCURL: return "LCURL({)"; case RCURL: return "RCURL(})";
        case LSQUARE: return "LSQUARE([)"; case RSQUARE: return "RSQUARE(])";
        case COMMA: return "COMMA";    case DOT: return "DOT(.)";
        case COLON: return "COLON(:)"; case SEMI: return "SEMI(;)";
        case ARROW: return "ARROW(->)"; case DOUBLE_COLON: return "DOUBLE_COLON(::)";
        case 0: return "EOF";
        default: return "UNKNOWN";
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) { fprintf(stderr, "Cannot open %s\n", argv[1]); return 1; }
        current_filename = argv[1];
    }
    int tok;
    printf("%-6s %-6s %-20s %s\n", "LINE", "TOKEN#", "TOKEN", "TEXT");
    printf("%-6s %-6s %-20s %s\n", "----", "-----", "-----", "----");
    while ((tok = yylex()) != 0) {
        printf("%-6d %-6d %-20s [%s]\n", lineno, tok, tokname(tok), yytoken.text ? yytoken.text : "");
    }
    printf("%-6d %-20s\n", lineno, "EOF");
    return 0;
}
