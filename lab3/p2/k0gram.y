%{
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

extern int yylex();
extern int lineno;
void yyerror(const char *s);
%}

/* ========== TOKEN DECLARATIONS ========== */
/* Keywords */
%token FUN VAL VAR IF ELSE WHILE FOR RETURN BREAK CONTINUE
%token WHEN IN DO IMPORT CONST

/* Literals */
%token INTEGERLITERAL LONGLITERAL REALLITERAL DOUBLELITERAL
%token BOOLEANLITERAL CHARACTERLITERAL STRINGLITERAL NULLLITERAL

/* Identifiers */
%token IDENT

/* Assignment operators */
%token ASSIGNMENT ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

/* Arithmetic operators */
%token ADD SUB MUL DIV MOD

/* Increment/Decrement */
%token INCR DECR

/* Comparison operators */
%token EQ NEQ GTE LTE

/* Referential equality */
%token REF_EQ REF_NEQ

/* Logical operators */
%token AND OR NOT

/* Null-safe operators */
%token SAFE_CALL ELVIS QUEST

/* Range operators */
%token RANGE RANGE_UNTIL

/* Type cast */
%token AS

/* Delimiters */
%token LPAREN RPAREN LCURL RCURL LSQUARE RSQUARE LANGLE RANGLE
%token COMMA DOT COLON SEMI ARROW DOUBLE_COLON

%%

/* ===========================================================
 * Top-level program structure
 *
 * Kotlin spec:
 *   kotlinFile: [shebangLine] {NL} {fileAnnotation} packageHeader
 *               importList {topLevelObject} EOF
 *
 * K0 simplification: no shebang, no annotations, no package.
 * importList is zero-or-more ({importHeader}), so it can be
 * empty on its own — no need for a separate optional wrapper.
 * =========================================================== */

program:
      import_list top_level_object_list
    ;

/* importList: {importHeader}  -- zero or more */
import_list:
      import_list import_declaration
    | /* epsilon */
    ;

/* importHeader: 'import' identifier [('.' '*') | importAlias] [semi]
 * K0 subset: plain dotted path, no star-import, no alias.
 * FIX: original had `optional_semi` which was never defined.
 *      Inlined the two alternatives (with/without SEMI) here. */
import_declaration:
      IMPORT import_path
    | IMPORT import_path SEMI
    ;

/* identifier: simpleIdentifier {{NL} '.' simpleIdentifier} */
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
 * Declarations
 *
 * Kotlin spec:
 *   declaration: classDeclaration | objectDeclaration
 *              | functionDeclaration | propertyDeclaration | typeAlias
 *
 * K0 subset: functionDeclaration and propertyDeclaration only.
 * =========================================================== */

declaration:
      function_declaration
    | property_declaration
    ;

/* ===========================================================
 * Function Declaration
 *
 * Kotlin spec:
 *   functionDeclaration:
 *     [modifiers] 'fun' [{NL} typeParameters]
 *     [{NL} receiverType {NL} '.'] {NL} simpleIdentifier {NL}
 *     functionValueParameters
 *     [{NL} ':' {NL} type] [{NL} typeConstraints] [{NL} functionBody]
 *
 * K0 subset: no modifiers, no type parameters, no receiver.
 * FIX: original required function_body; spec says it is optional
 *      ([{NL} functionBody]). Wrapped in optional_function_body.
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

/* functionValueParameters:
 *   '(' [{NL}] [functionValueParameter {{NL} ',' {NL} functionValueParameter}
 *               [{NL} ',']] [{NL}] ')'
 * K0: no trailing comma support (simplification). */
function_value_parameters:
      LPAREN RPAREN
    | LPAREN function_value_parameter_list RPAREN
    ;

function_value_parameter_list:
      function_value_parameter
    | function_value_parameter_list COMMA function_value_parameter
    ;

/* functionValueParameter: [parameterModifiers] parameter [{NL} '=' {NL} expression]
 * parameter: simpleIdentifier ':' type
 * K0: no parameterModifiers. */
function_value_parameter:
      IDENT COLON type
    | IDENT COLON type ASSIGNMENT expression
    ;

/* functionBody: block | ('=' {NL} expression) */
function_body:
      block
    | ASSIGNMENT expression
    ;

/* ===========================================================
 * Property Declaration
 *
 * Kotlin spec:
 *   propertyDeclaration:
 *     [modifiers] ('val' | 'var')
 *     [{NL} typeParameters] [{NL} receiverType {NL} '.']
 *     ({NL} (multiVariableDeclaration | variableDeclaration))
 *     [{NL} typeConstraints]
 *     [{NL} (('=' {NL} expression) | propertyDelegate)]
 *     ... getters/setters ...
 *
 * K0 subset: no modifiers, type params, receiver, destructuring,
 * delegates, or getters/setters.
 * NOTE: CONST is a propertyModifier in the spec, not a keyword
 * prefix. Kept as a K0 convenience since CONST is in our token set.
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
 * Kotlin spec:
 *   type: [typeModifiers] (functionType | parenthesizedType
 *          | nullableType | typeReference | definitelyNonNullableType)
 *   typeReference: userType | 'dynamic'
 *   nullableType:  (typeReference | parenthesizedType) {NL} (quest {quest})
 *   userType: simpleUserType {{NL} '.' {NL} simpleUserType}
 *   simpleUserType: simpleIdentifier [{NL} typeArguments]
 *
 * K0 subset: named types (userType) and nullable variants.
 * FIX: original only allowed a bare IDENT for the type base.
 *      Kotlin's userType allows dotted names (e.g. kotlin.String)
 *      and generic parameters (e.g. List<Int>). Added proper
 *      user_type and simple_user_type rules.
 * =========================================================== */

type:
      user_type
    | user_type QUEST
    ;

user_type:
      simple_user_type
    | user_type DOT simple_user_type
    ;

simple_user_type:
      IDENT
    | IDENT LANGLE type_argument_list RANGLE
    ;

type_argument_list:
      type
    | type_argument_list COMMA type
    ;

/* ===========================================================
 * Block: '{' {NL} statements {NL} '}'
 * Unchanged and correct.
 * =========================================================== */

block:
      LCURL statements RCURL
    ;

/* ===========================================================
 * Statements
 *
 * Kotlin spec: statements: [statement {semis statement}] [semis]
 *
 * Translation per lab example — unchanged and correct.
 * =========================================================== */

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

/* semis: ';' | NL {';' | NL}
 * K0: lexer drops NL tokens, so semis = one or more SEMI. */
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
 * Kotlin spec:
 *   statement: {label | annotation}
 *              (declaration | assignment | loopStatement | expression)
 *
 * K0: no labels, no annotations.
 * NOTE: return/break/continue are jumpExpressions under the
 * spec (primaryExpression -> jumpExpression). They are kept as
 * statement-level rules in K0 because our expression tower does
 * not model jumpExpression, avoiding grammar complexity.
 * =========================================================== */

statement:
      declaration
    | assignment
    | loop_statement
    | expression
    | return_statement
    | break_statement
    | continue_statement
    ;

/* ===========================================================
 * Assignment
 *
 * Kotlin spec:
 *   assignment:
 *     ((directlyAssignableExpression '=') |
 *      (assignableExpression assignmentAndOperator)) {NL} expression
 *
 * K0 simplification: LHS modeled as a full expression.
 * This allows some illegal forms but avoids duplicating the
 * entire postfix/prefix expression tower for assignable subsets.
 * =========================================================== */

assignment:
      expression ASSIGNMENT expression
    | expression ADD_ASSIGN expression
    | expression SUB_ASSIGN expression
    | expression MUL_ASSIGN expression
    | expression DIV_ASSIGN expression
    | expression MOD_ASSIGN expression
    ;

/* ===========================================================
 * Loop Statements
 * =========================================================== */

loop_statement:
      for_statement
    | while_statement
    | do_while_statement
    ;

/* forStatement:
 *   'for' {NL} '(' {annotation} (variableDeclaration | multiVariableDeclaration)
 *   'in' expression ')' {NL} [controlStructureBody]
 *
 * FIX: spec says body is OPTIONAL ([controlStructureBody]).
 *      Original required it. Added optional_control_structure_body. */
for_statement:
      FOR LPAREN IDENT IN expression RPAREN optional_control_structure_body
    | FOR LPAREN IDENT COLON type IN expression RPAREN optional_control_structure_body
    ;

optional_control_structure_body:
      control_structure_body
    | /* epsilon */
    ;

/* whileStatement:
 *   'while' {NL} '(' expression ')' {NL} (controlStructureBody | ';')
 * Correct in original. */
while_statement:
      WHILE LPAREN expression RPAREN control_structure_body
    | WHILE LPAREN expression RPAREN SEMI
    ;

/* doWhileStatement:
 *   'do' {NL} [controlStructureBody] {NL} 'while' {NL} '(' expression ')'
 *
 * FIX: spec says body is OPTIONAL. Original required it. Fixed. */
do_while_statement:
      DO optional_control_structure_body WHILE LPAREN expression RPAREN
    ;

/* controlStructureBody: block | statement
 * Correct in original. */
control_structure_body:
      block
    | statement
    ;

/* ===========================================================
 * Jump Expressions (return / break / continue)
 *
 * Kotlin spec jumpExpression:
 *   ('throw' {NL} expression)
 *   | (('return' | RETURN_AT) [expression])
 *   | 'continue' | CONTINUE_AT | 'break' | BREAK_AT
 *
 * K0: no throw, no label suffixes (_AT variants).
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
 * Kotlin spec:
 *   ifExpression:
 *     'if' {NL} '(' {NL} expression {NL} ')' {NL}
 *     (controlStructureBody
 *      | ([controlStructureBody] {NL} [';'] {NL} 'else' {NL}
 *         (controlStructureBody | ';'))
 *      | ';')
 *
 * K0: require then-body; else-if chaining supported.
 * Dangling-else resolved by Bison's default shift preference
 * (attaches else to nearest if) — matches Kotlin semantics.
 * =========================================================== */

if_expression:
      IF LPAREN expression RPAREN control_structure_body
    | IF LPAREN expression RPAREN control_structure_body ELSE control_structure_body
    | IF LPAREN expression RPAREN control_structure_body ELSE if_expression
    ;

/* ===========================================================
 * When Expression
 *
 * Kotlin spec:
 *   whenExpression: 'when' {NL} [whenSubject] {NL}
 *                   '{' {NL} {whenEntry {NL}} {NL} '}'
 *   whenSubject: '(' [{annotation} {NL} 'val' {NL} variableDeclaration {NL} '='] expression ')'
 *   whenEntry:
 *     (whenCondition {{NL} ',' {NL} whenCondition} [{NL} ',']
 *      {NL} '->' {NL} controlStructureBody [semi])
 *     | ('else' {NL} '->' {NL} controlStructureBody [semi])
 *   whenCondition: expression | rangeTest | typeTest
 *   rangeTest: inOperator {NL} expression  -- inOperator: 'in' | '!in'
 *
 * FIX 1: old grammar used `statement` as the body of a when entry;
 *         spec uses controlStructureBody. Fixed.
 * FIX 2: old grammar only allowed expression in when_condition.
 *         Added IN expression (rangeTest). No IS token so typeTest omitted.
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

/* whenCondition: expression | rangeTest
 * FIX: added IN expression alternative for rangeTest. */
when_condition:
      expression
    | IN expression
    ;

/* ===========================================================
 * Expression Tower
 *
 * Kotlin spec precedence levels (low -> high):
 *   disjunction        (||)
 *   conjunction        (&&)
 *   equality           (==, !=, ===, !==)
 *   comparison         (<, >, <=, >=)
 *   infixOperation     (in, !in, is, !is)
 *   elvisExpression    (?:)
 *   infixFunctionCall  (named infix -- K0: skipped)
 *   rangeExpression    (.., ..<)
 *   additiveExpression (+, -)
 *   multiplicativeExpression (*, /, %)
 *   asExpression       (as, as?)
 *   prefixUnary        (!, -, +, ++, --)
 *   postfixUnary       (++, --, suffixes)
 *   primaryExpression
 *
 * FIX 1: MISSING elvisExpression level (ELVIS / ?:). Added between
 *         infixOperation and rangeExpression.
 * FIX 2: MISSING infixOperation level for 'in' in expressions
 *         (e.g. "x in list"). Added between comparison and elvis.
 * FIX 3: AS was incorrectly placed inside postfix_expr. Per spec
 *         asExpression sits above prefixUnary but below multiplicative.
 *         Moved to its own as_expr level.
 * =========================================================== */

expression:
      disjunction
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

/* infixOperation: elvisExpression {(inOperator elvisExpression) | (isOperator type)}
 * K0: 'in' only; no IS token defined. */
infix_operation:
      elvis_expr
    | infix_operation IN elvis_expr
    ;

/* elvisExpression: infixFunctionCall {{NL} '?:' infixFunctionCall}
 * K0: no named infix calls, so goes straight to range_expr. */
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

/* asExpression: prefixUnaryExpression {{NL} asOperator {NL} type}
 * asOperator: 'as' | 'as?'  -- K0: 'as' only.
 * FIX: moved from inside postfix_expr to its own level here. */
as_expr:
      prefix_expr
    | as_expr AS type
    ;

prefix_expr:
      postfix_expr
    | NOT  prefix_expr
    | SUB  prefix_expr
    | ADD  prefix_expr
    | INCR prefix_expr
    | DECR prefix_expr
    ;

/* postfixUnaryExpression: primaryExpression {postfixUnarySuffix}
 * postfixUnarySuffix: postfixUnaryOperator | typeArguments
 *                   | callSuffix | indexingSuffix | navigationSuffix
 *
 * callSuffix: [typeArguments] (([valueArguments] annotatedLambda) | valueArguments)
 * indexingSuffix: '[' expression {',' expression} ']'
 * navigationSuffix: ('.' | '?.' | '::') (simpleIdentifier | ...)
 *
 * FIX: removed AS from here (moved to as_expr level).
 * FIX: added DOUBLE_COLON navigation (callable references like Foo::bar).
 * =========================================================== */
postfix_expr:
      primary_expr
    | postfix_expr INCR
    | postfix_expr DECR
    | postfix_expr DOT        IDENT
    | postfix_expr SAFE_CALL  IDENT
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

/* valueArgument: [annotation] {NL} [simpleIdentifier {NL} '=' {NL}] ['*'] {NL} expression
 * K0: plain expression, or named argument (IDENT '=' expression). */
value_argument:
      expression
    | IDENT ASSIGNMENT expression
    ;

/* ===========================================================
 * Primary Expressions
 *
 * Kotlin spec:
 *   primaryExpression:
 *     parenthesizedExpression | simpleIdentifier | literalConstant
 *     | stringLiteral | callableReference | functionLiteral
 *     | objectLiteral | collectionLiteral | thisExpression
 *     | superExpression | ifExpression | whenExpression
 *     | tryExpression | jumpExpression
 *
 * K0 subset: parenthesized, identifier, literals, string,
 * collectionLiteral, ifExpression, whenExpression.
 *
 * FIX: collectionLiteral ([expr, ...]) was MISSING. Added.
 * FIX: string_template renamed to inline STRINGLITERAL to
 *      match spec's stringLiteral (no interpolation in K0).
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

/* literalConstant: BooleanLiteral | IntegerLiteral | CharacterLiteral
 *                | RealLiteral | 'null' | LongLiteral | ...
 * Maps to K0 literal tokens. */
literal:
      INTEGERLITERAL
    | LONGLITERAL
    | REALLITERAL
    | DOUBLELITERAL
    | BOOLEANLITERAL
    | CHARACTERLITERAL
    | NULLLITERAL
    ;

/* collectionLiteral: '[' {NL} [expression {{NL} ',' {NL} expression} [{NL} ',']] {NL} ']'
 * K0: no trailing comma. */
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
