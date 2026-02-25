%{
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

extern int yylex(void);
extern int lineno;
void yyerror(const char *s);
%}

/* ===== TOKENS (from token.h / ytab.h) ===== */
%token FUN VAL VAR IF ELSE WHILE FOR RETURN BREAK CONTINUE
%token WHEN IN DO IMPORT CONST AS

%token INTEGERLITERAL LONGLITERAL REALLITERAL DOUBLELITERAL
%token BOOLEANLITERAL CHARACTERLITERAL STRINGLITERAL NULLLITERAL

%token IDENT

%token ASSIGNMENT ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token ADD SUB MUL DIV MOD
%token INCR DECR
%token EQ NEQ GTE LTE LANGLE RANGLE
%token REF_EQ REF_NEQ
%token AND OR NOT
%token SAFE_CALL ELVIS QUEST
%token RANGE RANGE_UNTIL
%token LPAREN RPAREN LCURL RCURL LSQUARE RSQUARE
%token COMMA DOT COLON SEMI ARROW DOUBLE_COLON
%token NEWLINE

/* ===== PRECEDENCE (low to high) ===== */
%right ASSIGNMENT ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left  OR
%left  AND
%left  EQ NEQ REF_EQ REF_NEQ
%left  LANGLE RANGLE LTE GTE
%left  IN
%right ELVIS
%left  RANGE RANGE_UNTIL
%left  ADD SUB
%left  MUL DIV MOD
%left  AS
%right NOT UMINUS UPLUS PREINC PREDEC
%left  INCR DECR DOT SAFE_CALL DOUBLE_COLON LSQUARE LPAREN
%right ELSE

%%

/* ===== TOP LEVEL ===== */

program:
      import_list top_level_object_list
    ;

import_list:
      import_list import_declaration
    | /* epsilon */
    ;

import_declaration:
      IMPORT import_path
    | IMPORT import_path SEMI
    ;

import_path:
      IDENT
    | import_path DOT IDENT
    ;

top_level_object_list:
      top_level_object_list top_level_object
    | /* epsilon */
    ;

top_level_object:
      declaration
    | declaration SEMI
    ;

/* ===== DECLARATIONS ===== */

declaration:
      function_declaration
    | property_declaration
    ;

/* functionDeclaration: 'fun' simpleIdentifier functionValueParameters [':' type] [functionBody] */
function_declaration:
      FUN IDENT function_value_parameters optional_return_type optional_function_body
    ;

optional_return_type:
      COLON type
    | /* epsilon */
    ;

optional_function_body:
      function_body
    | /* epsilon */
    ;

function_value_parameters:
      LPAREN RPAREN
    | LPAREN function_value_parameter_list RPAREN
    ;

function_value_parameter_list:
      function_value_parameter
    | function_value_parameter_list COMMA function_value_parameter
    ;

function_value_parameter:
      IDENT COLON type
    | IDENT COLON type ASSIGNMENT expression
    ;

function_body:
      block
    | ASSIGNMENT expression
    ;

/* propertyDeclaration: ('val'|'var') simpleIdentifier [':' type] ['=' expression] */
property_declaration:
      VAL IDENT optional_type_annotation optional_initializer
    | VAR IDENT optional_type_annotation optional_initializer
    | CONST VAL IDENT optional_type_annotation optional_initializer
    ;

optional_type_annotation:
      COLON type
    | /* epsilon */
    ;

optional_initializer:
      ASSIGNMENT expression
    | /* epsilon */
    ;

/* ===== TYPES (K0 subset: bare identifier only, no generics) ===== */

type:
      IDENT
    | IDENT QUEST
    ;

/* ===== BLOCK AND STATEMENTS ===== */

block:
      LCURL statements RCURL
    ;

/*
 * statements: zero or more statements separated by SEMIs,
 * with an optional trailing SEMI.
 *
 * Keeping the trailing SEMI separate from the recursive list
 * avoids the shift/reduce conflict that caused the original
 * parse failure on hello.kt.
 */
statements:
      /* epsilon */
    | statement_list
    | statement_list SEMI
    ;

statement_list:
      statement
    | statement_list SEMI statement
    ;

/* statement: declaration | loopStatement | expression | jump */
statement:
      declaration
    | loop_statement
    | expression
    | return_statement
    | break_statement
    | continue_statement
    ;

/* ===== LOOPS ===== */

loop_statement:
      for_statement
    | while_statement
    | do_while_statement
    ;

for_statement:
      FOR LPAREN IDENT IN expression RPAREN optional_control_structure_body
    | FOR LPAREN IDENT COLON type IN expression RPAREN optional_control_structure_body
    ;

optional_control_structure_body:
      control_structure_body
    | /* epsilon */
    ;

while_statement:
      WHILE LPAREN expression RPAREN control_structure_body
    | WHILE LPAREN expression RPAREN SEMI
    ;

do_while_statement:
      DO optional_control_structure_body WHILE LPAREN expression RPAREN
    ;

/* controlStructureBody: block | simple_statement (NOT declaration) */
control_structure_body:
      block
    | simple_statement
    ;

simple_statement:
      loop_statement
    | expression
    | return_statement
    | break_statement
    | continue_statement
    ;

/* ===== JUMP STATEMENTS ===== */

return_statement:
      RETURN
    | RETURN expression
    ;

break_statement:    BREAK    ;
continue_statement: CONTINUE ;

/* ===== IF / WHEN ===== */

if_expression:
      IF LPAREN expression RPAREN control_structure_body                                    %prec ELSE
    | IF LPAREN expression RPAREN control_structure_body ELSE control_structure_body
    | IF LPAREN expression RPAREN control_structure_body ELSE if_expression
    ;

when_expression:
      WHEN LCURL when_entry_list RCURL
    | WHEN LPAREN expression RPAREN LCURL when_entry_list RCURL
    ;

when_entry_list:
      when_entry_list when_entry
    | /* epsilon */
    ;

when_entry:
      when_condition_list ARROW control_structure_body
    | when_condition_list ARROW control_structure_body SEMI
    | ELSE ARROW control_structure_body
    | ELSE ARROW control_structure_body SEMI
    ;

when_condition_list:
      when_condition
    | when_condition_list COMMA when_condition
    ;

when_condition:
      expression
    ;

/* ===== EXPRESSIONS ===== */

expression:
      disjunction
    | expression ASSIGNMENT expression  %prec ASSIGNMENT
    | expression ADD_ASSIGN  expression %prec ASSIGNMENT
    | expression SUB_ASSIGN  expression %prec ASSIGNMENT
    | expression MUL_ASSIGN  expression %prec ASSIGNMENT
    | expression DIV_ASSIGN  expression %prec ASSIGNMENT
    | expression MOD_ASSIGN  expression %prec ASSIGNMENT
    ;

disjunction:
      conjunction
    | disjunction OR conjunction
    ;

conjunction:
      equality_expr
    | conjunction AND equality_expr
    ;

equality_expr:
      comparison_expr
    | equality_expr EQ      comparison_expr
    | equality_expr NEQ     comparison_expr
    | equality_expr REF_EQ  comparison_expr
    | equality_expr REF_NEQ comparison_expr
    ;

comparison_expr:
      infix_operation
    | comparison_expr LANGLE infix_operation
    | comparison_expr RANGLE infix_operation
    | comparison_expr LTE    infix_operation
    | comparison_expr GTE    infix_operation
    ;

infix_operation:
      elvis_expr
    | infix_operation IN elvis_expr
    ;

elvis_expr:
      range_expr
    | elvis_expr ELVIS range_expr
    ;

range_expr:
      additive_expr
    | range_expr RANGE       additive_expr
    | range_expr RANGE_UNTIL additive_expr
    ;

additive_expr:
      multiplicative_expr
    | additive_expr ADD multiplicative_expr
    | additive_expr SUB multiplicative_expr
    ;

multiplicative_expr:
      as_expr
    | multiplicative_expr MUL as_expr
    | multiplicative_expr DIV as_expr
    | multiplicative_expr MOD as_expr
    ;

as_expr:
      prefix_expr
    | as_expr AS type
    ;

prefix_expr:
      postfix_expr
    | NOT  prefix_expr
    | SUB  prefix_expr  %prec UMINUS
    | ADD  prefix_expr  %prec UPLUS
    | INCR prefix_expr  %prec PREINC
    | DECR prefix_expr  %prec PREDEC
    ;

postfix_expr:
      primary_expr
    | postfix_expr INCR
    | postfix_expr DECR
    | postfix_expr DOT          IDENT
    | postfix_expr SAFE_CALL    IDENT
    | postfix_expr DOUBLE_COLON IDENT
    | postfix_expr LSQUARE expression RSQUARE
    | postfix_expr LPAREN optional_value_arguments RPAREN
    ;

optional_value_arguments:
      value_argument_list
    | /* epsilon */
    ;

value_argument_list:
      value_argument
    | value_argument_list COMMA value_argument
    ;

value_argument:
      IDENT ASSIGNMENT expression
    | expression
    ;

/* ===== PRIMARY EXPRESSIONS ===== */

primary_expr:
      LPAREN expression RPAREN
    | IDENT
    | literal
    | STRINGLITERAL
    | collection_literal
    | if_expression
    | when_expression
    ;

literal:
      INTEGERLITERAL
    | LONGLITERAL
    | REALLITERAL
    | DOUBLELITERAL
    | BOOLEANLITERAL
    | CHARACTERLITERAL
    | NULLLITERAL
    ;

collection_literal:
      LSQUARE RSQUARE
    | LSQUARE collection_items RSQUARE
    ;

collection_items:
      expression
    | collection_items COMMA expression
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", lineno, s);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        extern FILE *yyin;
        extern char *current_filename;
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file: %s\n", argv[1]);
            return 1;
        }
        current_filename = argv[1];
    }
    return yyparse();
}
