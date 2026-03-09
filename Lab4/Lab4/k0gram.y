%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "tree.h"
#include "prodrule.h"

extern int yylex(void);
extern int lineno;
extern char *current_filename;
void yyerror(const char *s);
%}

%union {
    struct tree  *treeptr;   /* for nonterminals */
}

/* ===== TOKENS ===== */
%token <treeptr> FUN VAL VAR IF ELSE WHILE FOR RETURN BREAK CONTINUE
%token <treeptr> WHEN IN DO IMPORT CONST AS

%token <treeptr> INTEGERLITERAL LONGLITERAL REALLITERAL DOUBLELITERAL
%token <treeptr> BOOLEANLITERAL CHARACTERLITERAL STRINGLITERAL NULLLITERAL

%token <treeptr> IDENT

%token <treeptr> ASSIGNMENT ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token <treeptr> ADD SUB MUL DIV MOD
%token <treeptr> INCR DECR
%token <treeptr> EQ NEQ GTE LTE LANGLE RANGLE
%token <treeptr> REF_EQ REF_NEQ
%token <treeptr> AND OR NOT
%token <treeptr> SAFE_CALL ELVIS QUEST
%token <treeptr> RANGE RANGE_UNTIL
%token <treeptr> LPAREN RPAREN LCURL RCURL LSQUARE RSQUARE
%token <treeptr> COMMA DOT COLON SEMI ARROW DOUBLE_COLON
%token <treeptr> NEWLINE

/* ===== NONTERMINAL TYPES ===== */
%type <treeptr> program
%type <treeptr> import_list import_declaration import_path
%type <treeptr> top_level_object_list top_level_object
%type <treeptr> declaration function_declaration property_declaration
%type <treeptr> optional_return_type optional_function_body
%type <treeptr> function_value_parameters function_value_parameter_list function_value_parameter
%type <treeptr> function_body
%type <treeptr> optional_type_annotation optional_initializer
%type <treeptr> type
%type <treeptr> block statements statement_list statement
%type <treeptr> loop_statement for_statement while_statement do_while_statement
%type <treeptr> optional_control_structure_body control_structure_body simple_statement
%type <treeptr> return_statement break_statement continue_statement
%type <treeptr> if_expression when_expression
%type <treeptr> when_entry_list when_entry when_condition_list when_condition
%type <treeptr> expression disjunction conjunction equality_expr comparison_expr
%type <treeptr> infix_operation elvis_expr range_expr additive_expr multiplicative_expr
%type <treeptr> as_expr prefix_expr postfix_expr
%type <treeptr> optional_value_arguments value_argument_list value_argument
%type <treeptr> primary_expr literal collection_literal collection_items

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
        { $$ = alloktree(R_PROGRAM, "program", 2, $1, $2);
          parseroot = $$; }
    ;

import_list:
      import_list import_declaration
        { $$ = alloktree(R_IMPORT_LIST, "import_list", 2, $1, $2); }
    | /* epsilon */
        { $$ = NULL; }
    ;

import_declaration:
      IMPORT import_path
        { $$ = alloktree(R_IMPORT_DECLARATION, "import_declaration", 2,
                         $1, $2); }
    | IMPORT import_path SEMI
        { $$ = alloktree(R_IMPORT_DECLARATION, "import_declaration", 3,
                         $1, $2, $3); }
    ;

import_path:
      IDENT
        { $$ = $1; }
    | import_path DOT IDENT
        { $$ = alloktree(R_IMPORT_PATH, "import_path", 3,
                         $1, $2, $3); }
    ;

top_level_object_list:
      top_level_object_list top_level_object
        { $$ = alloktree(R_TOP_LEVEL_OBJECT_LIST, "top_level_object_list", 2, $1, $2); }
    | /* epsilon */
        { $$ = NULL; }
    ;

top_level_object:
      declaration
        { $$ = $1; }
    | declaration SEMI
        { $$ = alloktree(R_TOP_LEVEL_OBJECT, "top_level_object", 2,
                         $1,  $2); }
    ;

/* ===== DECLARATIONS ===== */

declaration:
      function_declaration
        { $$ = $1; }
    | property_declaration
        { $$ = $1; }
    ;

function_declaration:
      FUN IDENT function_value_parameters optional_return_type optional_function_body
        { $$ = alloktree(R_FUNCTION_DECLARATION, "function_declaration", 5,
                         $1, $2, $3, $4, $5); }
    ;

optional_return_type:
      COLON type
        { $$ = alloktree(R_OPTIONAL_RETURN_TYPE, "optional_return_type", 2,
                         $1, $2); }
    | /* epsilon */
        { $$ = NULL; }
    ;

optional_function_body:
      function_body
        { $$ = $1; }
    | /* epsilon */
        { $$ = NULL; }
    ;

function_value_parameters:
      LPAREN RPAREN
        { $$ = alloktree(R_FUNCTION_VALUE_PARAMETERS, "function_value_parameters", 2,
                         $1, $2); }
    | LPAREN function_value_parameter_list RPAREN
        { $$ = alloktree(R_FUNCTION_VALUE_PARAMETERS, "function_value_parameters", 3,
                         $1, $2, $3); }
    ;

function_value_parameter_list:
      function_value_parameter
        { $$ = $1; }
    | function_value_parameter_list COMMA function_value_parameter
        { $$ = alloktree(R_FUNCTION_VALUE_PARAM_LIST, "function_value_parameter_list", 3,
                         $1, $2, $3); }
    ;

function_value_parameter:
      IDENT COLON type
        { $$ = alloktree(R_FUNCTION_VALUE_PARAMETER, "function_value_parameter", 3,
                         $1, $2, $3); }
    | IDENT COLON type ASSIGNMENT expression
        { $$ = alloktree(R_FUNCTION_VALUE_PARAMETER, "function_value_parameter", 5,
                         $1, $2, $3, $4, $5); }
    ;

function_body:
      block
        { $$ = $1; }
    | ASSIGNMENT expression
        { $$ = alloktree(R_FUNCTION_BODY, "function_body", 2,
                         $1, $2); }
    ;

property_declaration:
      VAL IDENT optional_type_annotation optional_initializer
        { $$ = alloktree(R_PROPERTY_DECLARATION, "property_declaration", 4,
                         $1, $2, $3, $4); }
    | VAR IDENT optional_type_annotation optional_initializer
        { $$ = alloktree(R_PROPERTY_DECLARATION, "property_declaration", 4,
                         $1, $2, $3, $4); }
    | CONST VAL IDENT optional_type_annotation optional_initializer
        { $$ = alloktree(R_PROPERTY_DECLARATION, "property_declaration", 5,
                         $1, $2, $3, $4, $5); }
    ;

optional_type_annotation:
      COLON type
        { $$ = alloktree(R_OPTIONAL_TYPE_ANNOTATION, "optional_type_annotation", 2,
                         $1, $2); }
    | /* epsilon */
        { $$ = NULL; }
    ;

optional_initializer:
      ASSIGNMENT expression
        { $$ = alloktree(R_OPTIONAL_INITIALIZER, "optional_initializer", 2,
                         $1, $2); }
    | /* epsilon */
        { $$ = NULL; }
    ;

/* ===== TYPES ===== */

type:
      IDENT
        { $$ = $1; }
    | IDENT QUEST
        { $$ = alloktree(R_TYPE, "type", 2, $1, $2); }
    ;

/* ===== BLOCK AND STATEMENTS ===== */

block:
      LCURL statements RCURL
        { $$ = alloktree(R_BLOCK, "block", 3,
                         $1, $2, $3); }
    ;

statements:
      /* epsilon */
        { $$ = NULL; }
    | statement_list
        { $$ = $1; }
    | statement_list SEMI
        { $$ = alloktree(R_STATEMENTS, "statements", 2, $1, $2); }
    ;

statement_list:
      statement
        { $$ = $1; }
    | statement_list SEMI statement
        { $$ = alloktree(R_STATEMENT_LIST, "statement_list", 3,
                         $1, $2, $3); }
    ;

statement:
      declaration
        { $$ = $1; }
    | loop_statement
        { $$ = $1; }
    | if_expression
        { $$ = $1; }
    | when_expression
        { $$ = $1; }
    | expression
        { $$ = $1; }
    | return_statement
        { $$ = $1; }
    | break_statement
        { $$ = $1; }
    | continue_statement
        { $$ = $1; }
    ;

/* ===== LOOPS ===== */

loop_statement:
      for_statement
        { $$ = $1; }
    | while_statement
        { $$ = $1; }
    | do_while_statement
        { $$ = $1; }
    ;

for_statement:
      FOR LPAREN IDENT IN expression RPAREN optional_control_structure_body
        { $$ = alloktree(R_FOR_STATEMENT, "for_statement", 7,
                         $1, $2, $3,
                         $4, $5, $6, $7); }
    | FOR LPAREN IDENT COLON type IN expression RPAREN optional_control_structure_body
        { $$ = alloktree(R_FOR_STATEMENT, "for_statement", 9,
                         $1, $2, $3,
                         $4, $5, $6, $7,
                         $8, $9); }
    ;

optional_control_structure_body:
      control_structure_body
        { $$ = $1; }
    | /* epsilon */
        { $$ = NULL; }
    ;

while_statement:
      WHILE LPAREN expression RPAREN control_structure_body
        { $$ = alloktree(R_WHILE_STATEMENT, "while_statement", 5,
                         $1,  $2, $3,  $4, $5); }
    | WHILE LPAREN expression RPAREN SEMI
        { $$ = alloktree(R_WHILE_STATEMENT, "while_statement", 5,
                         $1,  $2, $3,  $4,  $5); }
    ;

do_while_statement:
      DO block WHILE LPAREN expression RPAREN
        { $$ = alloktree(R_DO_WHILE_STATEMENT, "do_while_statement", 6,
                          $1, $2, $3, $4, $5, $6); }
    | DO SEMI WHILE LPAREN expression RPAREN
        { $$ = alloktree(R_DO_WHILE_STATEMENT, "do_while_statement", 6,
                          $1, $2, $3, $4, $5, $6); }
    ;

control_structure_body:
      block
        { $$ = $1; }
    | if_expression
        { $$ = $1; }
    | when_expression
        { $$ = $1; }
    | simple_statement
        { $$ = $1; }
    ;

simple_statement:
      loop_statement
        { $$ = $1; }
    | expression
        { $$ = $1; }
    | return_statement
        { $$ = $1; }
    | break_statement
        { $$ = $1; }
    | continue_statement
        { $$ = $1; }
    ;

/* ===== JUMP STATEMENTS ===== */

return_statement:
      RETURN
        { $$ =  $1; }
    | RETURN expression
        { $$ = alloktree(R_RETURN_STATEMENT, "return_statement", 2,
                         $1, $2); }
    ;

break_statement:
      BREAK
        { $$ =  $1; }
    ;

continue_statement:
      CONTINUE
        { $$ =  $1; }
    ;

/* ===== IF / WHEN ===== */

if_expression:
      IF LPAREN expression RPAREN control_structure_body  %prec ELSE
        { $$ = alloktree(R_IF_EXPRESSION, "if_expression", 5,
                          $1,  $2, $3,  $4, $5); }
    | IF LPAREN expression RPAREN control_structure_body ELSE control_structure_body
        { $$ = alloktree(R_IF_EXPRESSION, "if_expression", 7,
                          $1,  $2, $3,  $4,
                         $5,  $6, $7); }
    ;

when_expression:
      WHEN LCURL when_entry_list RCURL
        { $$ = alloktree(R_WHEN_EXPRESSION, "when_expression", 4,
                          $1,  $2, $3,  $4); }
    | WHEN LPAREN expression RPAREN LCURL when_entry_list RCURL
        { $$ = alloktree(R_WHEN_EXPRESSION, "when_expression", 7,
                          $1,  $2, $3,  $4,
                          $5, $6,  $7); }
    ;

when_entry_list:
      when_entry_list when_entry
        { $$ = alloktree(R_WHEN_ENTRY_LIST, "when_entry_list", 2, $1, $2); }
    | /* epsilon */
        { $$ = NULL; }
    ;

/* when_entry: SEMI required after body.
 * Without it, tokens like IDENT/literals after the body are ambiguous
 * between "continue body expression" and "start next entry condition".
 * ASI always emits SEMI after when-entry bodies, so this is safe.    */
when_entry:
      when_condition_list ARROW control_structure_body SEMI
        { $$ = alloktree(R_WHEN_ENTRY, "when_entry", 4,
                         $1,  $2, $3,  $4); }
    | ELSE ARROW control_structure_body SEMI
        { $$ = alloktree(R_WHEN_ENTRY, "when_entry", 4,
                          $1,  $2, $3,  $4); }
    ;

when_condition_list:
      when_condition
        { $$ = $1; }
    | when_condition_list COMMA when_condition
        { $$ = alloktree(R_WHEN_CONDITION_LIST, "when_condition_list", 3,
                         $1,  $2, $3); }
    ;

when_condition:
      expression
        { $$ = $1; }
    ;

/* ===== EXPRESSIONS ===== */

expression:
      disjunction
        { $$ = $1; }
    | disjunction ASSIGNMENT expression %prec ASSIGNMENT
        { $$ = alloktree(R_EXPRESSION, "expression", 3, $1, $2, $3); }
    | disjunction ADD_ASSIGN expression %prec ASSIGNMENT
        { $$ = alloktree(R_EXPRESSION, "expression", 3, $1, $2, $3); }
    | disjunction SUB_ASSIGN expression %prec ASSIGNMENT
        { $$ = alloktree(R_EXPRESSION, "expression", 3, $1, $2, $3); }
    | disjunction MUL_ASSIGN expression %prec ASSIGNMENT
        { $$ = alloktree(R_EXPRESSION, "expression", 3, $1, $2, $3); }
    | disjunction DIV_ASSIGN expression %prec ASSIGNMENT
        { $$ = alloktree(R_EXPRESSION, "expression", 3, $1, $2, $3); }
    | disjunction MOD_ASSIGN expression %prec ASSIGNMENT
        { $$ = alloktree(R_EXPRESSION, "expression", 3, $1, $2, $3); }
    ;

disjunction:
      conjunction
        { $$ = $1; }
    | disjunction OR conjunction
        { $$ = alloktree(R_DISJUNCTION, "disjunction", 3, $1,  $2, $3); }
    ;

conjunction:
      equality_expr
        { $$ = $1; }
    | conjunction AND equality_expr
        { $$ = alloktree(R_CONJUNCTION, "conjunction", 3, $1,  $2, $3); }
    ;

equality_expr:
      comparison_expr
        { $$ = $1; }
    | equality_expr EQ      comparison_expr
        { $$ = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, $1,  $2, $3); }
    | equality_expr NEQ     comparison_expr
        { $$ = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, $1,  $2, $3); }
    | equality_expr REF_EQ  comparison_expr
        { $$ = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, $1,  $2, $3); }
    | equality_expr REF_NEQ comparison_expr
        { $$ = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, $1,  $2, $3); }
    ;

comparison_expr:
      infix_operation
        { $$ = $1; }
    | comparison_expr LANGLE infix_operation
        { $$ = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, $1,  $2, $3); }
    | comparison_expr RANGLE infix_operation
        { $$ = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, $1,  $2, $3); }
    | comparison_expr LTE    infix_operation
        { $$ = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, $1,  $2, $3); }
    | comparison_expr GTE    infix_operation
        { $$ = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, $1,  $2, $3); }
    ;

infix_operation:
      elvis_expr
        { $$ = $1; }
    | infix_operation IN elvis_expr
        { $$ = alloktree(R_INFIX_OPERATION, "infix_operation", 3, $1,  $2, $3); }
    ;

elvis_expr:
      range_expr
        { $$ = $1; }
    | elvis_expr ELVIS range_expr
        { $$ = alloktree(R_ELVIS_EXPR, "elvis_expr", 3, $1,  $2, $3); }
    ;

range_expr:
      additive_expr
        { $$ = $1; }
    | range_expr RANGE       additive_expr
        { $$ = alloktree(R_RANGE_EXPR, "range_expr", 3, $1,  $2, $3); }
    | range_expr RANGE_UNTIL additive_expr
        { $$ = alloktree(R_RANGE_EXPR, "range_expr", 3, $1,  $2, $3); }
    ;

additive_expr:
      multiplicative_expr
        { $$ = $1; }
    | additive_expr ADD multiplicative_expr
        { $$ = alloktree(R_ADDITIVE_EXPR, "additive_expr", 3, $1,  $2, $3); }
    | additive_expr SUB multiplicative_expr
        { $$ = alloktree(R_ADDITIVE_EXPR, "additive_expr", 3, $1,  $2, $3); }
    ;

multiplicative_expr:
      as_expr
        { $$ = $1; }
    | multiplicative_expr MUL as_expr
        { $$ = alloktree(R_MULTIPLICATIVE_EXPR, "multiplicative_expr", 3, $1,  $2, $3); }
    | multiplicative_expr DIV as_expr
        { $$ = alloktree(R_MULTIPLICATIVE_EXPR, "multiplicative_expr", 3, $1,  $2, $3); }
    | multiplicative_expr MOD as_expr
        { $$ = alloktree(R_MULTIPLICATIVE_EXPR, "multiplicative_expr", 3, $1,  $2, $3); }
    ;

as_expr:
      prefix_expr
        { $$ = $1; }
    | as_expr AS type
        { $$ = alloktree(R_AS_EXPR, "as_expr", 3, $1,  $2, $3); }
    ;

prefix_expr:
      postfix_expr
        { $$ = $1; }
    | NOT  prefix_expr
        { $$ = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  $1, $2); }
    | SUB  prefix_expr  %prec UMINUS
        { $$ = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  $1, $2); }
    | ADD  prefix_expr  %prec UPLUS
        { $$ = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  $1, $2); }
    | INCR prefix_expr  %prec PREINC
        { $$ = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  $1, $2); }
    | DECR prefix_expr  %prec PREDEC
        { $$ = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  $1, $2); }
    ;

postfix_expr:
      primary_expr
        { $$ = $1; }
    | postfix_expr INCR
        { $$ = alloktree(R_POSTFIX_EXPR, "postfix_expr", 2, $1,  $2); }
    | postfix_expr DECR
        { $$ = alloktree(R_POSTFIX_EXPR, "postfix_expr", 2, $1,  $2); }
    | postfix_expr DOT IDENT
        { $$ = alloktree(R_POSTFIX_EXPR, "postfix_expr", 3, $1,  $2,  $3); }
    | postfix_expr SAFE_CALL IDENT
        { $$ = alloktree(R_POSTFIX_EXPR, "postfix_expr", 3, $1,  $2,  $3); }
    | postfix_expr DOUBLE_COLON IDENT
        { $$ = alloktree(R_POSTFIX_EXPR, "postfix_expr", 3, $1,  $2,  $3); }
    | postfix_expr LSQUARE expression RSQUARE
        { $$ = alloktree(R_POSTFIX_EXPR, "postfix_expr", 4, $1,  $2, $3,  $4); }
    | postfix_expr LPAREN optional_value_arguments RPAREN
        { $$ = alloktree(R_POSTFIX_EXPR, "postfix_expr", 4, $1,  $2, $3,  $4); }
    ;

optional_value_arguments:
      value_argument_list
        { $$ = $1; }
    | /* epsilon */
        { $$ = NULL; }
    ;

value_argument_list:
      value_argument
        { $$ = $1; }
    | value_argument_list COMMA value_argument
        { $$ = alloktree(R_VALUE_ARGUMENT_LIST, "value_argument_list", 3,
                         $1,  $2, $3); }
    ;

value_argument:
      expression
        { $$ = $1; }
    ;

/* ===== PRIMARY EXPRESSIONS ===== */

primary_expr:
      LPAREN expression RPAREN
        { $$ = alloktree(R_PRIMARY_EXPR, "primary_expr", 3,
                          $1, $2,  $3); }
    | IDENT
        { $$ = $1; }
    | literal
        { $$ = $1; }
    | STRINGLITERAL
        { $$ = $1; }
    | collection_literal
        { $$ = $1; }
    ;

literal:
      INTEGERLITERAL   { $$ = $1; }
    | LONGLITERAL      { $$ = $1; }
    | REALLITERAL      { $$ = $1; }
    | DOUBLELITERAL    { $$ = $1; }
    | BOOLEANLITERAL   { $$ = $1; }
    | CHARACTERLITERAL { $$ = $1; }
    | NULLLITERAL      { $$ = $1; }
    ;

collection_literal:
      LSQUARE RSQUARE
        { $$ = alloktree(R_COLLECTION_LITERAL, "collection_literal", 2,
                          $1,  $2); }
    | LSQUARE collection_items RSQUARE
        { $$ = alloktree(R_COLLECTION_LITERAL, "collection_literal", 3,
                          $1, $2,  $3); }
    ;

collection_items:
      expression
        { $$ = $1; }
    | collection_items COMMA expression
        { $$ = alloktree(R_COLLECTION_ITEMS, "collection_items", 3,
                         $1,  $2, $3); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "%s:%d: syntax error: %s\n",
            current_filename ? current_filename : "stdin", lineno, s);
}

int main(int argc, char *argv[]) {
    extern FILE *yyin;

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file: %s\n", argv[1]);
            return 1;
        }
        current_filename = argv[1];
    }

    int result = yyparse();
    if (result == 0 && parseroot != NULL) {
        treeprint(parseroot, 0);
        treefree(parseroot);
    }
    return result == 0 ? 0 : 2;
}
