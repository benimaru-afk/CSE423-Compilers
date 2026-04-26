#ifndef PRODRULE_H
#define PRODRULE_H

/*
 * prodrule.h - production rule numbers for K0 syntax tree nodes
 * Each interior node in the parse tree stores one of these codes.
 */

/* Top level */
#define R_PROGRAM                    1
#define R_IMPORT_LIST                2
#define R_IMPORT_DECLARATION         3
#define R_IMPORT_PATH                4
#define R_TOP_LEVEL_OBJECT_LIST      5
#define R_TOP_LEVEL_OBJECT           6

/* Declarations */
#define R_DECLARATION                7
#define R_FUNCTION_DECLARATION       8
#define R_OPTIONAL_RETURN_TYPE       9
#define R_OPTIONAL_FUNCTION_BODY    10
#define R_FUNCTION_VALUE_PARAMETERS 11
#define R_FUNCTION_VALUE_PARAM_LIST 12
#define R_FUNCTION_VALUE_PARAMETER  13
#define R_FUNCTION_BODY             14
#define R_PROPERTY_DECLARATION      15
#define R_OPTIONAL_TYPE_ANNOTATION  16
#define R_OPTIONAL_INITIALIZER      17

/* Types */
#define R_TYPE                      18

/* Block and statements */
#define R_BLOCK                     19
#define R_STATEMENTS                20
#define R_STATEMENT_LIST            21
#define R_STATEMENT                 22

/* Loops */
#define R_LOOP_STATEMENT            23
#define R_FOR_STATEMENT             24
#define R_OPTIONAL_CSB              25
#define R_WHILE_STATEMENT           26
#define R_DO_WHILE_STATEMENT        27
#define R_CONTROL_STRUCTURE_BODY    28
#define R_SIMPLE_STATEMENT          29

/* Jump statements */
#define R_RETURN_STATEMENT          30
#define R_BREAK_STATEMENT           31
#define R_CONTINUE_STATEMENT        32

/* If / When */
#define R_IF_EXPRESSION             33
#define R_WHEN_EXPRESSION           34
#define R_WHEN_ENTRY_LIST           35
#define R_WHEN_ENTRY                36
#define R_WHEN_CONDITION_LIST       37
#define R_WHEN_CONDITION            38

/* Expressions */
#define R_EXPRESSION                39
#define R_DISJUNCTION               40
#define R_CONJUNCTION               41
#define R_EQUALITY_EXPR             42
#define R_COMPARISON_EXPR           43
#define R_INFIX_OPERATION           44
#define R_ELVIS_EXPR                45
#define R_RANGE_EXPR                46
#define R_ADDITIVE_EXPR             47
#define R_MULTIPLICATIVE_EXPR       48
#define R_AS_EXPR                   49
#define R_PREFIX_EXPR               50
#define R_POSTFIX_EXPR              51
#define R_OPTIONAL_VALUE_ARGS       52
#define R_VALUE_ARGUMENT_LIST       53
#define R_VALUE_ARGUMENT            54

/* Primary expressions */
#define R_PRIMARY_EXPR              55
#define R_LITERAL                   56
#define R_COLLECTION_LITERAL        57
#define R_COLLECTION_ITEMS          58

#endif /* PRODRULE_H */
