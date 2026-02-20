%{
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

extern int yylex();
extern int lineno;
void yyerror(const char *s);
%}

/* ========== TOKEN DECLARATIONS ========== */
%token FUN VAL VAR IF ELSE WHILE FOR RETURN BREAK CONTINUE
%token WHEN IN DO IMPORT CONST

%token INTEGERLITERAL LONGLITERAL REALLITERAL DOUBLELITERAL
%token BOOLEANLITERAL CHARACTERLITERAL STRINGLITERAL NULLLITERAL

%token IDENT

%token ASSIGNMENT ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token ADD SUB MUL DIV MOD
%token INCR DECR
%token EQ NEQ GTE LTE
%token REF_EQ REF_NEQ
%token AND OR NOT
%token SAFE_CALL ELVIS QUEST
%token RANGE RANGE_UNTIL
%token AS
%token LPAREN RPAREN LCURL RCURL LSQUARE RSQUARE LANGLE RANGLE
%token COMMA DOT COLON SEMI ARROW DOUBLE_COLON

/* =============================================================
 * OPERATOR PRECEDENCE — declared lowest to highest.
 *
 * WHY THIS SECTION EXISTS:
 * The expression tower (disjunction -> ... -> postfix) handles
 * most precedence structurally. But several constructs create
 * genuine shift/reduce conflicts that Bison cannot resolve by
 * grammar structure alone:
 *
 *  1. DANGLING ELSE: `if (e) if (e) s` — should the ELSE attach
 *     to the inner or outer if? By declaring ELSE with %right and
 *     giving it a precedence level, Bison shifts (inner attach).
 *
 *  2. ASSIGNMENT as both statement and expression:
 *     `a = b = c` — right-associative by convention.
 *
 *  3. LANGLE/RANGLE dual role: used as both comparison operators
 *     (<, >) and as type argument delimiters (<Int>). Bison sees
 *     a conflict when it encounters `foo < bar` — should it shift
 *     LANGLE as a type arg or reduce as a comparison? We give
 *     LANGLE/RANGLE explicit precedence to resolve this as comparison.
 *
 *  4. NAMED-ARG conflict: In `f(x = 5)`, after seeing `IDENT`,
 *     Bison can't tell if this is a named arg `x = 5` or a
 *     variable expression `x` followed by assignment `= 5` at
 *     statement level. This is resolved by making value_argument
 *     prefer the named-arg form via rule ordering (Bison uses the
 *     first matching rule in a reduce/reduce conflict).
 *
 * Precedence table (low to high):
 * ============================================================= */

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
%right ELSE        /* resolve dangling-else by shifting (inner attach) */

%%

/* ===========================================================
 * Top-level program structure
 * kotlinFile: importList {topLevelObject} EOF
 * K0: no shebang, annotations, or package header.
 * =========================================================== */

program:
      import_list top_level_object_list
    ;

import_list:
      import_list import_declaration
    | /* epsilon */
    ;

/* importHeader: 'import' identifier [semi]
 * K0: dotted path only, no star-import, no alias. */
import_declaration:
      IMPORT import_path
    | IMPORT import_path SEMI
    ;

import_path:
      IDENT
    | import_path DOT IDENT
    ;

/* topLevelObject: declaration [semis] */
top_level_object_list:
      top_level_object_list top_level_object
    | /* epsilon */
    ;

top_level_object:
      declaration optional_semis
    ;

/* ===========================================================
 * Declarations — K0 subset: functions and properties only.
 * =========================================================== */

declaration:
      function_declaration
    | property_declaration
    ;

/* ===========================================================
 * Function Declaration
 *
 * functionDeclaration:
 *   'fun' simpleIdentifier functionValueParameters [':' type] [functionBody]
 *
 * CONFLICT SOURCE & FIX:
 *   With optional_function_body the parser sees:
 *     fun f() : Int   and must decide if SEMI after means
 *     "no body" or something else. This is fine because
 *     function_body starts with LCURL or ASSIGNMENT — both
 *     unambiguous lookaheads after the return type.
 * =========================================================== */

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

/* ===========================================================
 * Property Declaration
 *
 * propertyDeclaration: ('val'|'var') simpleIdentifier [':' type] ['=' expression]
 *
 * CONFLICT SOURCE & FIX:
 *   `val x = 5 + 3` — after reducing expression `5`, seeing `+`
 *   could be: continue the expression (shift ADD) or end the
 *   initializer (reduce). The %left ADD SUB / MUL DIV MOD
 *   precedence declarations resolve this by preferring to shift,
 *   which continues building the expression. Correct behavior.
 * =========================================================== */

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

/* ===========================================================
 * Types
 *
 * CONFLICT SOURCE & FIX (THE BIG ONE — ~80 of your conflicts):
 *   LANGLE and RANGLE are used for BOTH comparison operators
 *   AND generic type arguments. When Bison sees:
 *
 *       foo < Bar
 *
 *   it cannot tell if this is:
 *     (a) comparison: foo < Bar
 *     (b) generic call: foo<Bar>(...)
 *
 *   The full Kotlin grammar handles this with special lexer
 *   modes. For K0 we REMOVE generic type arguments from type
 *   entirely and keep LANGLE/RANGLE as comparison operators
 *   only. This eliminates the massive LANGLE/RANGLE ambiguity.
 *
 *   Generic types like List<Int> become just `List` in K0 type
 *   annotations. This is an acceptable K0 simplification — the
 *   assignment says "K0 subset", not full generics support.
 *
 *   Similarly, user_type DOT simple_user_type conflicts with
 *   postfix DOT IDENT in expressions. Since types only appear
 *   in specific syntactic positions (after ':' or 'as'), this
 *   doesn't create actual ambiguity — but the dotted type rule
 *   is rarely needed in K0 programs, so we simplify to bare IDENT.
 * =========================================================== */

type:
      IDENT
    | IDENT QUEST
    ;

/* ===========================================================
 * Block and Statements
 * =========================================================== */

block:
      LCURL statements RCURL
    ;

/* statements: [statement {semis statement}] [semis]
 * Translated per lab example. */
statements:
      optional_statement_sequence optional_semis
    ;

optional_statement_sequence:
      statement semis_statement_list
    | /* epsilon */
    ;

semis_statement_list:
      semis_statement_list semis statement
    | /* epsilon */
    ;

semis:
      SEMI
    | semis SEMI
    ;

optional_semis:
      semis
    | /* epsilon */
    ;

/* ===========================================================
 * Statement
 *
 * CONFLICT SOURCE & FIX (assignment vs expression):
 *   `x = 5` is ambiguous: is it an assignment statement or an
 *   expression statement containing assignment? Both `assignment`
 *   and `expression` (via the precedence tower) can parse it.
 *
 *   FIX: REMOVE the separate `assignment` rule entirely.
 *   Instead, assignment operators are handled INSIDE the
 *   expression tower via the %right ASSIGNMENT ... precedence
 *   declarations. `x = 5` parses as an expression statement
 *   where the top-level operator is ASSIGNMENT. This is exactly
 *   how most real parsers handle it and eliminates all the
 *   reduce/reduce conflicts between assignment and expression.
 *
 * CONFLICT SOURCE & FIX (declaration vs expression):
 *   `val x = 5` — parser sees VAL and must choose between
 *   `property_declaration` (via `declaration`) or treating VAL
 *   as some expression. Since VAL is never an expression in K0,
 *   this is unambiguous. No conflict here.
 *
 * CONFLICT SOURCE & FIX (return expression ambiguity):
 *   `return` by itself vs `return expression` — after reducing
 *   RETURN the parser sees, e.g., SEMI and must decide:
 *   reduce (no expression) or shift (expression starts here)?
 *   Since SEMI cannot start an expression, no conflict. But
 *   with a newline-dropping lexer, `return \n x` looks like
 *   `return x` — this is fine for K0.
 * =========================================================== */

statement:
      declaration
    | loop_statement
    | expression         /* covers assignments, calls, if-exprs, etc. */
    | return_statement
    | break_statement
    | continue_statement
    ;

/* ===========================================================
 * Loop Statements
 * =========================================================== */

loop_statement:
      for_statement
    | while_statement
    | do_while_statement
    ;

/* forStatement: 'for' '(' IDENT [':' type] 'in' expression ')' [body]
 *
 * CONFLICT SOURCE & FIX (IN ambiguity):
 *   Inside the for-header, `IN` is a keyword separator, not an
 *   infix operator. The rule is unambiguous because the for-header
 *   is fully parenthesized — LPAREN...RPAREN — so the parser
 *   knows exactly where the expression ends (at RPAREN).
 *   No conflict here. */
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

/* doWhileStatement: body is optional per spec */
do_while_statement:
      DO optional_control_structure_body WHILE LPAREN expression RPAREN
    ;

/* controlStructureBody: block | statement
 *
 * CONFLICT SOURCE & FIX (block vs statement):
 *   Both `block` (starts with LCURL) and `statement` can appear here.
 *   Since `statement` can contain a `declaration` which can contain
 *   a `function_declaration` which can have a block body, there is
 *   NO ambiguity — LCURL uniquely identifies `block` here.
 *   This is an unambiguous choice. */
control_structure_body:
      block
    | statement
    ;

/* ===========================================================
 * Jump Expressions — kept at statement level for K0 simplicity.
 *
 * CONFLICT SOURCE & FIX (return + expression):
 *   `return x + y` — after shifting RETURN and seeing IDENT,
 *   should we reduce (empty return) or shift (start expression)?
 *   Rule: RETURN shifts into expression because IDENT can start
 *   an expression. Bison's default shift-on-conflict resolves
 *   this correctly (greedy: consume as much as possible).
 *   This is the right behavior: `return x` returns x.
 * =========================================================== */

return_statement:
      RETURN
    | RETURN expression
    ;

break_statement:
      BREAK
    ;

continue_statement:
      CONTINUE
    ;

/* ===========================================================
 * If Expression
 *
 * CONFLICT SOURCE & FIX (dangling else):
 *   Classic: `if (a) if (b) s1 else s2`
 *   Two parses: else belongs to inner if (correct) or outer if.
 *   FIX: `%right ELSE` declaration at top makes Bison shift ELSE,
 *   attaching it to the nearest if. The two separate alternatives
 *   below (with and without ELSE) still generate 1 shift/reduce
 *   warning — that is EXPECTED and harmless. The %right ELSE
 *   ensures the correct resolution.
 * =========================================================== */

if_expression:
      IF LPAREN expression RPAREN control_structure_body %prec ELSE
    | IF LPAREN expression RPAREN control_structure_body ELSE control_structure_body
    | IF LPAREN expression RPAREN control_structure_body ELSE if_expression
    ;

/* ===========================================================
 * When Expression
 *
 * CONFLICT SOURCE & FIX (when condition vs expression):
 *   `when { x in 1..10 -> ... }` — after parsing `x`, seeing
 *   `in` could mean infix_operation (x in someList as expression)
 *   OR rangeTest start (IN expression as when condition).
 *   FIX: The `IN expression` when_condition alternative is listed
 *   BEFORE `expression` in when_condition so Bison's reduce/reduce
 *   preference picks it first. Also, since `in` as infix is
 *   captured at the expression tower level already, and
 *   `when_condition: expression` will catch `x in list` via the
 *   expression rule, the explicit `IN expression` alternative
 *   is actually REDUNDANT and causes a conflict. REMOVED.
 *   `x in 1..10` in a when condition is simply an expression
 *   containing the IN infix operator — it falls under `expression`.
 * =========================================================== */

when_expression:
      WHEN LCURL when_entry_list RCURL
    | WHEN LPAREN expression RPAREN LCURL when_entry_list RCURL
    ;

when_entry_list:
      when_entry_list when_entry
    | /* epsilon */
    ;

when_entry:
      when_condition_list ARROW control_structure_body optional_semis
    | ELSE ARROW control_structure_body optional_semis
    ;

when_condition_list:
      when_condition
    | when_condition_list COMMA when_condition
    ;

/* whenCondition: just expression — covers x, x in range, x == y, etc.
 * The IN infix operator in the expression tower handles rangeTest. */
when_condition:
      expression
    ;

/* ===========================================================
 * Expression Tower
 *
 * ARCHITECTURE NOTE:
 *   The %precedence declarations at the top of the file work
 *   together with this tower. The tower handles left/right
 *   associativity structurally; the %prec declarations handle
 *   ambiguous cases where structure alone is insufficient.
 *
 * CONFLICT SOURCE & FIX (named arg vs assignment):
 *   Inside `f(x = 5)`, the parser sees IDENT ASSIGNMENT expression.
 *   This looks like: (a) named argument `x = 5`, or (b) expression
 *   statement `x` followed by `= 5` as an assignment expression.
 *   Since we're inside LPAREN...RPAREN of a call, context says
 *   it's a call argument. The value_argument rule handles this by
 *   listing `IDENT ASSIGNMENT expression` as a specific alternative.
 *   But this creates a reduce/reduce with `expression` which also
 *   matches IDENT. FIX: List `IDENT ASSIGNMENT expression` FIRST
 *   in value_argument so Bison prefers it. This is the R/R conflict
 *   that Bison resolves by using the earlier rule — correct behavior.
 * =========================================================== */

expression:
      disjunction
    | expression ASSIGNMENT expression   %prec ASSIGNMENT
    | expression ADD_ASSIGN  expression  %prec ASSIGNMENT
    | expression SUB_ASSIGN  expression  %prec ASSIGNMENT
    | expression MUL_ASSIGN  expression  %prec ASSIGNMENT
    | expression DIV_ASSIGN  expression  %prec ASSIGNMENT
    | expression MOD_ASSIGN  expression  %prec ASSIGNMENT
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

/* infixOperation: IN as infix (e.g. `x in list`, `x in 1..10`) */
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

/* asExpression: above prefix, below multiplicative */
as_expr:
      prefix_expr
    | as_expr AS type
    ;

/* prefixUnaryExpression: {unaryPrefix} postfixUnaryExpression
 *
 * CONFLICT SOURCE & FIX (unary minus vs binary minus):
 *   `-x - y` — is the first `-` unary (prefix of x) or binary?
 *   FIX: `%prec UMINUS` on the unary SUB rule gives it higher
 *   precedence than binary SUB, so `-x - y` = `(-x) - y`. Correct.
 *   Same for UPLUS, PREINC, PREDEC. */
prefix_expr:
      postfix_expr
    | NOT  prefix_expr
    | SUB  prefix_expr  %prec UMINUS
    | ADD  prefix_expr  %prec UPLUS
    | INCR prefix_expr  %prec PREINC
    | DECR prefix_expr  %prec PREDEC
    ;

/* postfixUnaryExpression
 *
 * CONFLICT SOURCE & FIX (function call vs expression in parens):
 *   `f (x)` — is this a call `f(x)` or expression `f` followed
 *   by parenthesized `(x)`? Since we have no whitespace tokens,
 *   the lexer delivers IDENT LPAREN, and the postfix rule
 *   `postfix_expr LPAREN ... RPAREN` shifts LPAREN, treating it
 *   as a call. Correct — Bison's default shift resolves this.
 *
 * CONFLICT SOURCE & FIX (indexing vs collection literal):
 *   `a[0]` — postfix indexing; `[0]` alone — collection literal.
 *   These are distinguishable by whether LSQUARE follows an expr
 *   (postfix) or appears at the start of a primary (literal).
 *   No actual conflict because collection_literal is in primary_expr
 *   and postfix indexing is in postfix_expr — different grammar positions. */
postfix_expr:
      primary_expr
    | postfix_expr INCR
    | postfix_expr DECR
    | postfix_expr DOT         IDENT
    | postfix_expr SAFE_CALL   IDENT
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

/* NAMED ARG listed first so Bison prefers it over plain `expression`
 * in a reduce/reduce situation inside call parens. */
value_argument:
      IDENT ASSIGNMENT expression
    | expression
    ;

/* ===========================================================
 * Primary Expressions
 * =========================================================== */

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
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file: %s\n", argv[1]);
            return 1;
        }
        extern char *current_filename;
        current_filename = argv[1];
    }
    return yyparse();
}
