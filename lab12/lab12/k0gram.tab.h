/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FUN = 258,
     VAL = 259,
     VAR = 260,
     IF = 261,
     ELSE = 262,
     WHILE = 263,
     FOR = 264,
     RETURN = 265,
     BREAK = 266,
     CONTINUE = 267,
     WHEN = 268,
     IN = 269,
     DO = 270,
     IMPORT = 271,
     CONST = 272,
     AS = 273,
     INTEGERLITERAL = 274,
     LONGLITERAL = 275,
     REALLITERAL = 276,
     DOUBLELITERAL = 277,
     BOOLEANLITERAL = 278,
     CHARACTERLITERAL = 279,
     STRINGLITERAL = 280,
     NULLLITERAL = 281,
     IDENT = 282,
     ASSIGNMENT = 283,
     ADD_ASSIGN = 284,
     SUB_ASSIGN = 285,
     MUL_ASSIGN = 286,
     DIV_ASSIGN = 287,
     MOD_ASSIGN = 288,
     ADD = 289,
     SUB = 290,
     MUL = 291,
     DIV = 292,
     MOD = 293,
     INCR = 294,
     DECR = 295,
     EQ = 296,
     NEQ = 297,
     GTE = 298,
     LTE = 299,
     LANGLE = 300,
     RANGLE = 301,
     REF_EQ = 302,
     REF_NEQ = 303,
     AND = 304,
     OR = 305,
     NOT = 306,
     SAFE_CALL = 307,
     ELVIS = 308,
     QUEST = 309,
     RANGE = 310,
     RANGE_UNTIL = 311,
     LPAREN = 312,
     RPAREN = 313,
     LCURL = 314,
     RCURL = 315,
     LSQUARE = 316,
     RSQUARE = 317,
     COMMA = 318,
     DOT = 319,
     COLON = 320,
     SEMI = 321,
     ARROW = 322,
     DOUBLE_COLON = 323,
     NEWLINE = 324,
     PREDEC = 325,
     PREINC = 326,
     UPLUS = 327,
     UMINUS = 328
   };
#endif
/* Tokens.  */
#define FUN 258
#define VAL 259
#define VAR 260
#define IF 261
#define ELSE 262
#define WHILE 263
#define FOR 264
#define RETURN 265
#define BREAK 266
#define CONTINUE 267
#define WHEN 268
#define IN 269
#define DO 270
#define IMPORT 271
#define CONST 272
#define AS 273
#define INTEGERLITERAL 274
#define LONGLITERAL 275
#define REALLITERAL 276
#define DOUBLELITERAL 277
#define BOOLEANLITERAL 278
#define CHARACTERLITERAL 279
#define STRINGLITERAL 280
#define NULLLITERAL 281
#define IDENT 282
#define ASSIGNMENT 283
#define ADD_ASSIGN 284
#define SUB_ASSIGN 285
#define MUL_ASSIGN 286
#define DIV_ASSIGN 287
#define MOD_ASSIGN 288
#define ADD 289
#define SUB 290
#define MUL 291
#define DIV 292
#define MOD 293
#define INCR 294
#define DECR 295
#define EQ 296
#define NEQ 297
#define GTE 298
#define LTE 299
#define LANGLE 300
#define RANGLE 301
#define REF_EQ 302
#define REF_NEQ 303
#define AND 304
#define OR 305
#define NOT 306
#define SAFE_CALL 307
#define ELVIS 308
#define QUEST 309
#define RANGE 310
#define RANGE_UNTIL 311
#define LPAREN 312
#define RPAREN 313
#define LCURL 314
#define RCURL 315
#define LSQUARE 316
#define RSQUARE 317
#define COMMA 318
#define DOT 319
#define COLON 320
#define SEMI 321
#define ARROW 322
#define DOUBLE_COLON 323
#define NEWLINE 324
#define PREDEC 325
#define PREINC 326
#define UPLUS 327
#define UMINUS 328




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "k0gram.y"
{
    struct tree  *treeptr;   /* for nonterminals */
}
/* Line 1529 of yacc.c.  */
#line 199 "k0gram.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

