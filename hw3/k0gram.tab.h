/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_K0GRAM_TAB_H_INCLUDED
# define YY_YY_K0GRAM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FUN = 258,                     /* FUN  */
    VAL = 259,                     /* VAL  */
    VAR = 260,                     /* VAR  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    WHILE = 263,                   /* WHILE  */
    FOR = 264,                     /* FOR  */
    RETURN = 265,                  /* RETURN  */
    BREAK = 266,                   /* BREAK  */
    CONTINUE = 267,                /* CONTINUE  */
    WHEN = 268,                    /* WHEN  */
    IN = 269,                      /* IN  */
    DO = 270,                      /* DO  */
    IMPORT = 271,                  /* IMPORT  */
    CONST = 272,                   /* CONST  */
    AS = 273,                      /* AS  */
    INTEGERLITERAL = 274,          /* INTEGERLITERAL  */
    LONGLITERAL = 275,             /* LONGLITERAL  */
    REALLITERAL = 276,             /* REALLITERAL  */
    DOUBLELITERAL = 277,           /* DOUBLELITERAL  */
    BOOLEANLITERAL = 278,          /* BOOLEANLITERAL  */
    CHARACTERLITERAL = 279,        /* CHARACTERLITERAL  */
    STRINGLITERAL = 280,           /* STRINGLITERAL  */
    NULLLITERAL = 281,             /* NULLLITERAL  */
    IDENT = 282,                   /* IDENT  */
    ASSIGNMENT = 283,              /* ASSIGNMENT  */
    ADD_ASSIGN = 284,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 285,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 286,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 287,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 288,              /* MOD_ASSIGN  */
    ADD = 289,                     /* ADD  */
    SUB = 290,                     /* SUB  */
    MUL = 291,                     /* MUL  */
    DIV = 292,                     /* DIV  */
    MOD = 293,                     /* MOD  */
    INCR = 294,                    /* INCR  */
    DECR = 295,                    /* DECR  */
    EQ = 296,                      /* EQ  */
    NEQ = 297,                     /* NEQ  */
    GTE = 298,                     /* GTE  */
    LTE = 299,                     /* LTE  */
    LANGLE = 300,                  /* LANGLE  */
    RANGLE = 301,                  /* RANGLE  */
    REF_EQ = 302,                  /* REF_EQ  */
    REF_NEQ = 303,                 /* REF_NEQ  */
    AND = 304,                     /* AND  */
    OR = 305,                      /* OR  */
    NOT = 306,                     /* NOT  */
    SAFE_CALL = 307,               /* SAFE_CALL  */
    ELVIS = 308,                   /* ELVIS  */
    QUEST = 309,                   /* QUEST  */
    RANGE = 310,                   /* RANGE  */
    RANGE_UNTIL = 311,             /* RANGE_UNTIL  */
    LPAREN = 312,                  /* LPAREN  */
    RPAREN = 313,                  /* RPAREN  */
    LCURL = 314,                   /* LCURL  */
    RCURL = 315,                   /* RCURL  */
    LSQUARE = 316,                 /* LSQUARE  */
    RSQUARE = 317,                 /* RSQUARE  */
    COMMA = 318,                   /* COMMA  */
    DOT = 319,                     /* DOT  */
    COLON = 320,                   /* COLON  */
    SEMI = 321,                    /* SEMI  */
    ARROW = 322,                   /* ARROW  */
    DOUBLE_COLON = 323,            /* DOUBLE_COLON  */
    NEWLINE = 324,                 /* NEWLINE  */
    UMINUS = 325,                  /* UMINUS  */
    UPLUS = 326,                   /* UPLUS  */
    PREINC = 327,                  /* PREINC  */
    PREDEC = 328                   /* PREDEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "k0gram.y"

    struct tree  *tval;   /* for nonterminals */
    struct token *tok;    /* for terminals    */

#line 142 "k0gram.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_K0GRAM_TAB_H_INCLUDED  */
