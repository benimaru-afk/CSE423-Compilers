#ifndef K0_OPERATORS_H
#define K0_OPERATORS_H

/* K0 Operator Codes
 * Enum codes for all supported Kotlin operators in k0
 */

enum K0Operator {
    // Assignment operators
    OP_ASSIGN = 400,
    OP_ADD_ASSIGN,
    OP_SUB_ASSIGN,

    // Binary arithmetic operators
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,

    // Unary increment/decrement (postfix only)
    OP_POST_INC,
    OP_POST_DEC,

    // Unary negation (prefix)
    OP_NEGATE,

    // Binary comparison operators
    OP_EQ,
    OP_NEQ,
    OP_GT,
    OP_LT,
    OP_GTE,
    OP_LTE,

    // Referential equality
    OP_REF_EQ,
    OP_REF_NEQ,

    // Logical operators
    OP_LOGICAL_AND,
    OP_LOGICAL_OR,
    OP_LOGICAL_NOT,

    // Non-null assertion
    OP_ASSERT_NON_NULL,

    // Member access operators
    OP_SUBSCRIPT,
    OP_DOT,

    // Null-safe operators
    OP_SAFE_CALL,
    OP_ELVIS,
    OP_NULLABLE,

    // Range operators
    OP_RANGE_INCLUSIVE,
    OP_RANGE_EXCLUSIVE,

    // Type cast operator
    OP_TYPECAST
};

#endif /* K0_OPERATORS_H */11

#ifndef KOTLIN_KEYWORDS_H
#define KOTLIN_KEYWORDS_H

enum KotlinKeyword {
    KW_BREAK = 500,
    KW_CONTINUE,
    KW_DO,
    KW_ELSE,
    KW_FALSE,
    KW_FOR,
    KW_FUN,
    KW_IF,
    KW_IN,
    KW_NULL,
    KW_RETURN,
    KW_TRUE,
    KW_VAL,
    KW_VAR,
    KW_WHEN,
    KW_WHILE,
    KW_IMPORT,
    KW_CONST
};

#endif

#ifndef K0_TOKENS_H
#define K0_TOKENS_H

/* K0 Token Codes
 * Enum codes for all Kotlin tokens in k0 (literals, identifiers, keywords, etc.)
 */

enum K0Token {
    // Literals
    TOK_INT_LITERAL = 600,
    TOK_LONG_LITERAL,
    TOK_FLOAT_LITERAL,
    TOK_DOUBLE_LITERAL,
    TOK_CHAR_LITERAL,
    TOK_STRING_LITERAL,
    TOK_MULTILINE_STRING_LITERAL,
    TOK_BOOLEAN_LITERAL,
    TOK_NULL_LITERAL,

    // Identifiers
    TOK_IDENTIFIER,

    // Keywords
    TOK_KW_FUN,
    TOK_KW_VAL,
    TOK_KW_VAR,
    TOK_KW_IF,
    TOK_KW_ELSE,
    TOK_KW_WHILE,
    TOK_KW_FOR,
    TOK_KW_RETURN,
    TOK_KW_BREAK,
    TOK_KW_CONTINUE,
    TOK_KW_CLASS,
    TOK_KW_OBJECT,
    TOK_KW_INTERFACE,
    TOK_KW_WHEN,
    TOK_KW_IN,
    TOK_KW_IS,
    TOK_KW_AS,
    TOK_KW_TRUE,
    TOK_KW_FALSE,
    TOK_KW_NULL,

    // Delimiters and punctuation
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_LBRACKET,
    TOK_RBRACKET,
    TOK_COMMA,
    TOK_SEMICOLON,
    TOK_COLON,
    TOK_DOUBLE_COLON,
    TOK_ARROW,

    // Special tokens
    TOK_EOF,
    TOK_NEWLINE,
    TOK_COMMENT,
    TOK_WHITESPACE,

    // Errors
    TOK_ERROR,
    TOK_ERROR_UNSUPPORTED_INT_FORMAT,
    TOK_ERROR_UNSIGNED_INT,
    TOK_ERROR_UNSUPPORTED_REAL_FORMAT,
    TOK_ERROR_MULTICHAR_LITERAL,
    TOK_ERROR_INVALID_ESCAPE,
    TOK_ERROR_UNTERMINATED_STRING,
    TOK_ERROR_UNTERMINATED_CHAR
};

#endif /* K0_TOKENS_H */