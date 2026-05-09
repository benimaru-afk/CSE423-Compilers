/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "k0gram.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "tree.h"
#include "symtab.h"
#include "symscan.h"
#include "prodrule.h"
#include "type.h"
#include "typecheck.h"
#include "codegen.h"
#include "x86gen.h"

int debug_tokens = 0;

extern int yylex(void);
extern int lineno;
extern char *current_filename;
void yyerror(const char *s);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "k0gram.y"
{
    struct tree  *treeptr;   /* for nonterminals */
}
/* Line 193 of yacc.c.  */
#line 268 "k0gram.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 281 "k0gram.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   450

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNRULES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    13,    17,    19,    23,
      26,    27,    29,    32,    34,    36,    42,    45,    46,    48,
      49,    52,    56,    58,    62,    66,    72,    74,    77,    82,
      87,    93,    96,    97,   100,   101,   103,   106,   108,   111,
     116,   122,   124,   128,   132,   133,   135,   138,   140,   144,
     146,   148,   150,   152,   154,   156,   158,   160,   162,   164,
     166,   174,   184,   186,   187,   193,   199,   206,   213,   215,
     217,   219,   221,   223,   225,   227,   229,   231,   233,   236,
     238,   240,   246,   254,   259,   267,   270,   271,   276,   281,
     283,   287,   289,   291,   295,   299,   303,   307,   311,   315,
     317,   321,   323,   327,   329,   333,   337,   341,   345,   347,
     351,   355,   359,   363,   365,   369,   371,   375,   377,   381,
     385,   387,   391,   395,   397,   401,   405,   409,   411,   415,
     417,   420,   423,   426,   429,   432,   434,   437,   440,   444,
     448,   452,   457,   462,   464,   465,   467,   471,   473,   477,
     479,   481,   483,   485,   487,   489,   491,   493,   495,   497,
     499,   502,   506,   508
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      75,     0,    -1,    76,    79,    -1,    76,    77,    -1,    -1,
      16,    78,    -1,    16,    78,    66,    -1,    27,    -1,    78,
      64,    27,    -1,    79,    80,    -1,    -1,    81,    -1,    81,
      66,    -1,    82,    -1,    89,    -1,     3,    27,    85,    83,
      84,    -1,    65,    93,    -1,    -1,    88,    -1,    -1,    57,
      58,    -1,    57,    86,    58,    -1,    87,    -1,    86,    63,
      87,    -1,    27,    65,    93,    -1,    27,    65,    93,    28,
     115,    -1,    95,    -1,    28,   115,    -1,     4,    27,    90,
      91,    -1,     5,    27,    90,    91,    -1,    17,     4,    27,
      90,    91,    -1,    65,    93,    -1,    -1,    28,   115,    -1,
      -1,    27,    -1,    27,    54,    -1,    27,    -1,    27,    54,
      -1,    27,    45,    94,    46,    -1,    27,    45,    94,    46,
      54,    -1,    93,    -1,    94,    63,    93,    -1,    59,    96,
      60,    -1,    -1,    97,    -1,    97,    66,    -1,    98,    -1,
      97,    66,    98,    -1,    81,    -1,    99,    -1,   109,    -1,
     110,    -1,   115,    -1,   106,    -1,   107,    -1,   108,    -1,
     100,    -1,   102,    -1,   103,    -1,     9,    57,    27,    14,
     115,    58,   101,    -1,     9,    57,    27,    65,    93,    14,
     115,    58,   101,    -1,   104,    -1,    -1,     8,    57,   115,
      58,   104,    -1,     8,    57,   115,    58,    66,    -1,    15,
      95,     8,    57,   115,    58,    -1,    15,    66,     8,    57,
     115,    58,    -1,    95,    -1,   109,    -1,   110,    -1,   105,
      -1,    99,    -1,   115,    -1,   106,    -1,   107,    -1,   108,
      -1,    10,    -1,    10,   115,    -1,    11,    -1,    12,    -1,
       6,    57,   115,    58,   104,    -1,     6,    57,   115,    58,
     104,     7,   104,    -1,    13,    59,   111,    60,    -1,    13,
      57,   115,    58,    59,   111,    60,    -1,   111,   112,    -1,
      -1,   113,    67,   104,    66,    -1,     7,    67,   104,    66,
      -1,   114,    -1,   113,    63,   114,    -1,   115,    -1,   116,
      -1,   116,    28,   115,    -1,   116,    29,   115,    -1,   116,
      30,   115,    -1,   116,    31,   115,    -1,   116,    32,   115,
      -1,   116,    33,   115,    -1,   117,    -1,   116,    50,   117,
      -1,   118,    -1,   117,    49,   118,    -1,   119,    -1,   118,
      41,   119,    -1,   118,    42,   119,    -1,   118,    47,   119,
      -1,   118,    48,   119,    -1,   120,    -1,   119,    45,   120,
      -1,   119,    46,   120,    -1,   119,    44,   120,    -1,   119,
      43,   120,    -1,   121,    -1,   120,    14,   121,    -1,   122,
      -1,   121,    53,   122,    -1,   123,    -1,   122,    55,   123,
      -1,   122,    56,   123,    -1,   124,    -1,   123,    34,   124,
      -1,   123,    35,   124,    -1,   125,    -1,   124,    36,   125,
      -1,   124,    37,   125,    -1,   124,    38,   125,    -1,   126,
      -1,   125,    18,    92,    -1,   127,    -1,    51,   126,    -1,
      35,   126,    -1,    34,   126,    -1,    39,   126,    -1,    40,
     126,    -1,   131,    -1,   127,    39,    -1,   127,    40,    -1,
     127,    64,    27,    -1,   127,    52,    27,    -1,   127,    68,
      27,    -1,   127,    61,   115,    62,    -1,   127,    57,   128,
      58,    -1,   129,    -1,    -1,   130,    -1,   129,    63,   130,
      -1,   115,    -1,    57,   115,    58,    -1,    27,    -1,   132,
      -1,    25,    -1,   133,    -1,    19,    -1,    20,    -1,    21,
      -1,    22,    -1,    23,    -1,    24,    -1,    26,    -1,    61,
      62,    -1,    61,   134,    62,    -1,   115,    -1,   134,    63,
     115,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    97,   100,   104,   107,   113,   115,   121,
     124,   128,   130,   138,   140,   145,   151,   155,   159,   162,
     166,   169,   175,   177,   183,   186,   192,   194,   200,   203,
     206,   212,   216,   220,   224,   234,   236,   244,   246,   248,
     250,   255,   257,   264,   271,   272,   274,   279,   281,   287,
     289,   291,   293,   295,   297,   299,   301,   308,   310,   312,
     317,   321,   329,   332,   336,   339,   345,   348,   354,   356,
     358,   360,   365,   367,   369,   371,   373,   380,   382,   388,
     393,   400,   403,   410,   413,   420,   423,   431,   434,   440,
     442,   448,   455,   457,   459,   461,   463,   465,   467,   472,
     474,   479,   481,   486,   488,   490,   492,   494,   499,   501,
     503,   505,   507,   512,   514,   519,   521,   526,   528,   530,
     535,   537,   539,   544,   546,   548,   550,   555,   557,   562,
     564,   566,   568,   570,   572,   577,   579,   581,   583,   585,
     587,   589,   591,   596,   599,   603,   605,   611,   618,   621,
     623,   625,   627,   632,   633,   634,   635,   636,   637,   638,
     642,   645,   651,   653
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUN", "VAL", "VAR", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "BREAK", "CONTINUE", "WHEN", "IN", "DO",
  "IMPORT", "CONST", "AS", "INTEGERLITERAL", "LONGLITERAL", "REALLITERAL",
  "DOUBLELITERAL", "BOOLEANLITERAL", "CHARACTERLITERAL", "STRINGLITERAL",
  "NULLLITERAL", "IDENT", "ASSIGNMENT", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD", "SUB", "MUL", "DIV",
  "MOD", "INCR", "DECR", "EQ", "NEQ", "GTE", "LTE", "LANGLE", "RANGLE",
  "REF_EQ", "REF_NEQ", "AND", "OR", "NOT", "SAFE_CALL", "ELVIS", "QUEST",
  "RANGE", "RANGE_UNTIL", "LPAREN", "RPAREN", "LCURL", "RCURL", "LSQUARE",
  "RSQUARE", "COMMA", "DOT", "COLON", "SEMI", "ARROW", "DOUBLE_COLON",
  "NEWLINE", "PREDEC", "PREINC", "UPLUS", "UMINUS", "$accept", "program",
  "import_list", "import_declaration", "import_path",
  "top_level_object_list", "top_level_object", "declaration",
  "function_declaration", "optional_return_type", "optional_function_body",
  "function_value_parameters", "function_value_parameter_list",
  "function_value_parameter", "function_body", "property_declaration",
  "optional_type_annotation", "optional_initializer", "type", "full_type",
  "type_args", "block", "statements", "statement_list", "statement",
  "loop_statement", "for_statement", "optional_control_structure_body",
  "while_statement", "do_while_statement", "control_structure_body",
  "simple_statement", "return_statement", "break_statement",
  "continue_statement", "if_expression", "when_expression",
  "when_entry_list", "when_entry", "when_condition_list", "when_condition",
  "expression", "disjunction", "conjunction", "equality_expr",
  "comparison_expr", "infix_operation", "elvis_expr", "range_expr",
  "additive_expr", "multiplicative_expr", "as_expr", "prefix_expr",
  "postfix_expr", "optional_value_arguments", "value_argument_list",
  "value_argument", "primary_expr", "literal", "collection_literal",
  "collection_items", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    93,
      93,    94,    94,    95,    96,    96,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     104,   104,   105,   105,   105,   105,   105,   106,   106,   107,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   115,   115,   115,   115,   115,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   122,
     123,   123,   123,   124,   124,   124,   124,   125,   125,   126,
     126,   126,   126,   126,   126,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   128,   129,   129,   130,   131,   131,
     131,   131,   131,   132,   132,   132,   132,   132,   132,   132,
     133,   133,   134,   134
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     3,     1,     3,     2,
       0,     1,     2,     1,     1,     5,     2,     0,     1,     0,
       2,     3,     1,     3,     3,     5,     1,     2,     4,     4,
       5,     2,     0,     2,     0,     1,     2,     1,     2,     4,
       5,     1,     3,     3,     0,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     9,     1,     0,     5,     5,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     5,     7,     4,     7,     2,     0,     4,     4,     1,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     1,
       2,     2,     2,     2,     2,     1,     2,     2,     3,     3,
       3,     4,     4,     1,     0,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    10,     1,     0,     3,     2,     7,     5,     0,
       0,     0,     0,     9,    11,    13,    14,     0,     6,     0,
      32,    32,     0,    12,     8,     0,    17,     0,    34,    34,
      32,     0,    20,     0,    22,     0,    19,    37,    31,     0,
      28,    29,    34,     0,    21,     0,    16,     0,    44,    15,
      18,    26,     0,    38,   153,   154,   155,   156,   157,   158,
     151,   159,   149,     0,     0,     0,     0,     0,     0,     0,
      33,    92,    99,   101,   103,   108,   113,   115,   117,   120,
     123,   127,   129,   135,   150,   152,    30,    24,    23,    27,
       0,     0,     0,    77,    79,    80,     0,     0,    49,     0,
      45,    47,    50,    57,    58,    59,    54,    55,    56,    51,
      52,    53,    41,     0,   132,   131,   133,   134,   130,     0,
     160,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,     0,   144,     0,     0,     0,     0,     0,     0,     0,
      78,     0,    86,     0,     0,    43,    46,    39,     0,   148,
     161,     0,    93,    94,    95,    96,    97,    98,   100,   102,
     104,   105,   106,   107,   112,   111,   109,   110,   114,   116,
     118,   119,   121,   122,   124,   125,   126,    35,   128,   139,
     147,     0,   143,   145,     0,   138,   140,    25,     0,     0,
       0,     0,     0,     0,     0,    48,    40,    42,   163,    36,
     142,     0,   141,     0,     0,     0,     0,     0,     0,    83,
      85,     0,    89,    91,     0,     0,   146,    68,    72,    81,
      71,    74,    75,    76,    69,    70,    73,    65,    64,     0,
       0,    86,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,    90,     0,    67,    66,    82,    60,    62,     0,
      84,    88,    87,    63,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     8,     6,    13,    98,    15,    36,
      49,    26,    33,    34,    50,    16,    28,    40,   198,    38,
     113,   237,    99,   100,   101,   238,   103,   267,   104,   105,
     268,   240,   241,   242,   243,   244,   245,   212,   230,   231,
     232,   246,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   201,   202,   203,    83,    84,    85,
     122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -210
static const yytype_int16 yypact[] =
{
    -210,    28,    74,  -210,    43,  -210,    78,  -210,    27,    75,
      76,    80,   116,  -210,    60,  -210,  -210,   101,  -210,    81,
      79,    79,   104,  -210,  -210,   -14,    86,   112,   125,   125,
      79,    90,  -210,    14,  -210,   112,    -2,     5,  -210,   389,
    -210,  -210,   125,   112,  -210,   143,  -210,   389,   137,  -210,
    -210,  -210,   112,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,   389,   389,   389,   389,   389,   389,   345,
    -210,   173,   126,    19,    66,   160,   130,    50,   -18,    38,
     166,  -210,    40,  -210,  -210,  -210,  -210,   157,  -210,  -210,
     140,   142,   150,   389,  -210,  -210,    37,   -17,  -210,   127,
     134,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,    -5,  -210,  -210,  -210,  -210,  -210,   151,
    -210,  -210,    53,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   181,  -210,
    -210,   183,   389,   389,   184,   185,   389,   389,   389,   186,
    -210,   389,  -210,   207,   208,  -210,   137,   163,   112,  -210,
    -210,   389,  -210,  -210,  -210,  -210,  -210,  -210,   126,    19,
      66,    66,    66,    66,   160,   160,   160,   160,   130,    50,
     -18,   -18,    38,    38,   166,   166,   166,   164,  -210,  -210,
    -210,   161,   167,  -210,   170,  -210,  -210,  -210,   175,   176,
     -10,   187,   259,   189,   190,  -210,  -210,  -210,  -210,  -210,
    -210,   389,  -210,   216,    12,   389,   112,   193,   177,  -210,
    -210,     1,  -210,  -210,   389,   389,  -210,  -210,  -210,   241,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,   191,
     239,  -210,   216,   389,   216,   196,   199,   216,   216,   389,
     302,   192,  -210,   194,  -210,  -210,  -210,  -210,  -210,   201,
    -210,  -210,  -210,   216,  -210
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,  -210,  -210,  -210,  -210,  -210,  -210,   255,  -210,  -210,
    -210,  -210,  -210,   217,  -210,  -210,    35,    11,  -210,   -33,
    -210,   -35,  -210,  -210,    97,   -45,  -210,    -9,  -210,  -210,
    -209,  -210,   -43,   -42,   -41,   -37,   -36,    17,  -210,  -210,
      16,   -39,  -210,   136,   141,    47,    54,   131,   132,    -8,
      -7,   -47,   102,  -210,  -210,  -210,    55,  -210,  -210,  -210,
    -210
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      70,    51,    46,   102,   225,   106,   107,   108,    89,   111,
      87,   109,   110,    31,   239,   248,   143,   144,    90,   112,
      91,    92,    93,    94,    95,    96,    47,    97,     3,   119,
     121,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      41,   167,    48,   261,    32,   263,    63,    64,   266,   163,
      52,    65,    66,    86,   160,   226,    29,    48,   168,    53,
     131,   132,   164,    67,   253,    42,   133,   134,   254,    68,
       7,    48,    44,    69,   145,   146,   147,    45,   247,   149,
     150,     9,    10,    11,   172,   173,   174,   175,   176,   177,
       4,    17,   151,    18,   161,    12,   162,   152,   194,   195,
     196,   153,    19,    20,   154,   141,   142,    21,   155,   135,
     136,   137,   138,   200,   204,   170,   171,   207,   208,   209,
      22,   102,   211,   106,   107,   108,    23,   111,    24,   109,
     110,    30,   218,   190,   191,   217,   192,   193,    25,    37,
       9,    10,    11,    90,    27,    91,    92,    93,    94,    95,
      96,    35,    97,    39,    12,    43,    54,    55,    56,    57,
      58,    59,    60,    61,    62,   114,   115,   116,   117,   118,
      31,    63,    64,   233,   139,   130,    65,    66,   180,   181,
     182,   183,   200,   140,   148,   156,   249,   165,    67,   184,
     185,   186,   187,   250,    68,   255,   256,   157,    69,   158,
     166,   123,   124,   125,   126,   127,   128,   159,   197,   169,
     199,   205,   206,   210,   233,   213,   214,   216,   219,   220,
     269,   233,    90,   129,    91,    92,    93,    94,    95,    96,
     221,    97,   222,   223,   224,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   252,   227,   234,   235,   257,   258,
      63,    64,   251,   259,   264,    65,    66,   265,   271,   273,
     272,    14,    88,   215,   274,   178,   228,    67,   260,   262,
     188,   179,   189,    68,     0,    48,   236,    69,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,    63,    64,     0,     0,     0,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
      67,     0,     0,     0,     0,     0,    68,     0,     0,   229,
      69,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,    63,    64,     0,     0,
       0,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,     0,     0,     0,    68,
       0,     0,   270,    69,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
       0,     0,    68,     0,     0,     0,    69,   120,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,    63,    64,     0,     0,     0,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,    68,     0,     0,     0,
      69
};

static const yytype_int16 yycheck[] =
{
      39,    36,    35,    48,    14,    48,    48,    48,    47,    48,
      43,    48,    48,    27,   223,   224,    34,    35,     6,    52,
       8,     9,    10,    11,    12,    13,    28,    15,     0,    68,
      69,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      29,    46,    59,   252,    58,   254,    34,    35,   257,    66,
      45,    39,    40,    42,    93,    65,    21,    59,    63,    54,
      41,    42,    97,    51,    63,    30,    47,    48,    67,    57,
      27,    59,    58,    61,    36,    37,    38,    63,    66,    39,
      40,     3,     4,     5,   123,   124,   125,   126,   127,   128,
      16,    64,    52,    66,    57,    17,    59,    57,   145,   146,
     147,    61,    27,    27,    64,    55,    56,    27,    68,    43,
      44,    45,    46,   152,   153,    62,    63,   156,   157,   158,
       4,   166,   161,   166,   166,   166,    66,   166,    27,   166,
     166,    27,   171,   141,   142,   168,   143,   144,    57,    27,
       3,     4,     5,     6,    65,     8,     9,    10,    11,    12,
      13,    65,    15,    28,    17,    65,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    63,    64,    65,    66,    67,
      27,    34,    35,   212,    14,    49,    39,    40,   131,   132,
     133,   134,   221,    53,    18,    28,   225,    60,    51,   135,
     136,   137,   138,   226,    57,   234,   235,    57,    61,    57,
      66,    28,    29,    30,    31,    32,    33,    57,    27,    58,
      27,    27,    27,    27,   253,     8,     8,    54,    54,    58,
     259,   260,     6,    50,     8,     9,    10,    11,    12,    13,
      63,    15,    62,    58,    58,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    67,    58,    57,    57,     7,    58,
      34,    35,    59,    14,    58,    39,    40,    58,    66,    58,
      66,     6,    45,   166,   273,   129,     7,    51,   251,   253,
     139,   130,   140,    57,    -1,    59,   221,    61,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    60,
      61,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    60,    61,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    61,    62,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,    76,     0,    16,    77,    79,    27,    78,     3,
       4,     5,    17,    80,    81,    82,    89,    64,    66,    27,
      27,    27,     4,    66,    27,    57,    85,    65,    90,    90,
      27,    27,    58,    86,    87,    65,    83,    27,    93,    28,
      91,    91,    90,    65,    58,    63,    93,    28,    59,    84,
      88,    95,    45,    54,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    34,    35,    39,    40,    51,    57,    61,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   131,   132,   133,    91,    93,    87,   115,
       6,     8,     9,    10,    11,    12,    13,    15,    81,    96,
      97,    98,    99,   100,   102,   103,   106,   107,   108,   109,
     110,   115,    93,    94,   126,   126,   126,   126,   126,   115,
      62,   115,   134,    28,    29,    30,    31,    32,    33,    50,
      49,    41,    42,    47,    48,    43,    44,    45,    46,    14,
      53,    55,    56,    34,    35,    36,    37,    38,    18,    39,
      40,    52,    57,    61,    64,    68,    28,    57,    57,    57,
     115,    57,    59,    66,    95,    60,    66,    46,    63,    58,
      62,    63,   115,   115,   115,   115,   115,   115,   117,   118,
     119,   119,   119,   119,   120,   120,   120,   120,   121,   122,
     123,   123,   124,   124,   125,   125,   125,    27,    92,    27,
     115,   128,   129,   130,   115,    27,    27,   115,   115,   115,
      27,   115,   111,     8,     8,    98,    54,    93,   115,    54,
      58,    63,    62,    58,    58,    14,    65,    58,     7,    60,
     112,   113,   114,   115,    57,    57,   130,    95,    99,   104,
     105,   106,   107,   108,   109,   110,   115,    66,   104,   115,
      93,    59,    67,    63,    67,   115,   115,     7,    58,    14,
     111,   104,   114,   104,    58,    58,   104,   101,   104,   115,
      60,    66,    66,    58,   101
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 92 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PROGRAM, "program", 2, (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr));
          parseroot = (yyval.treeptr); ;}
    break;

  case 3:
#line 98 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_IMPORT_LIST, "import_list", 2, (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 4:
#line 100 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 5:
#line 105 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_IMPORT_DECLARATION, "import_declaration", 2,
                         (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 6:
#line 108 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_IMPORT_DECLARATION, "import_declaration", 3,
                         (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 7:
#line 114 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 8:
#line 116 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_IMPORT_PATH, "import_path", 3,
                         (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 9:
#line 122 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_TOP_LEVEL_OBJECT_LIST, "top_level_object_list", 2, (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 10:
#line 124 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 11:
#line 129 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 12:
#line 131 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_TOP_LEVEL_OBJECT, "top_level_object", 2,
                         (yyvsp[(1) - (2)].treeptr),  (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 13:
#line 139 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 14:
#line 141 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 15:
#line 146 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_FUNCTION_DECLARATION, "function_declaration", 5,
                         (yyvsp[(1) - (5)].treeptr), (yyvsp[(2) - (5)].treeptr), (yyvsp[(3) - (5)].treeptr), (yyvsp[(4) - (5)].treeptr), (yyvsp[(5) - (5)].treeptr)); ;}
    break;

  case 16:
#line 152 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_OPTIONAL_RETURN_TYPE, "optional_return_type", 2,
                         (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 17:
#line 155 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 18:
#line 160 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 19:
#line 162 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 20:
#line 167 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAMETERS, "function_value_parameters", 2,
                         (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 21:
#line 170 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAMETERS, "function_value_parameters", 3,
                         (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 22:
#line 176 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 23:
#line 178 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAM_LIST, "function_value_parameter_list", 3,
                         (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 24:
#line 184 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAMETER, "function_value_parameter", 3,
                         (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 25:
#line 187 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAMETER, "function_value_parameter", 5,
                         (yyvsp[(1) - (5)].treeptr), (yyvsp[(2) - (5)].treeptr), (yyvsp[(3) - (5)].treeptr), (yyvsp[(4) - (5)].treeptr), (yyvsp[(5) - (5)].treeptr)); ;}
    break;

  case 26:
#line 193 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 27:
#line 195 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_FUNCTION_BODY, "function_body", 2,
                         (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 28:
#line 201 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PROPERTY_DECLARATION, "property_declaration", 4,
                         (yyvsp[(1) - (4)].treeptr), (yyvsp[(2) - (4)].treeptr), (yyvsp[(3) - (4)].treeptr), (yyvsp[(4) - (4)].treeptr)); ;}
    break;

  case 29:
#line 204 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PROPERTY_DECLARATION, "property_declaration", 4,
                         (yyvsp[(1) - (4)].treeptr), (yyvsp[(2) - (4)].treeptr), (yyvsp[(3) - (4)].treeptr), (yyvsp[(4) - (4)].treeptr)); ;}
    break;

  case 30:
#line 207 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PROPERTY_DECLARATION, "property_declaration", 5,
                         (yyvsp[(1) - (5)].treeptr), (yyvsp[(2) - (5)].treeptr), (yyvsp[(3) - (5)].treeptr), (yyvsp[(4) - (5)].treeptr), (yyvsp[(5) - (5)].treeptr)); ;}
    break;

  case 31:
#line 213 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_OPTIONAL_TYPE_ANNOTATION, "optional_type_annotation", 2,
                         (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 32:
#line 216 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 33:
#line 221 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_OPTIONAL_INITIALIZER, "optional_initializer", 2,
                         (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 34:
#line 224 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 35:
#line 235 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 36:
#line 237 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_TYPE, "type", 2, (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 37:
#line 245 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 38:
#line 247 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_TYPE, "type", 2, (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 39:
#line 249 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_TYPE, "type", 4, (yyvsp[(1) - (4)].treeptr), (yyvsp[(2) - (4)].treeptr), (yyvsp[(3) - (4)].treeptr), (yyvsp[(4) - (4)].treeptr)); ;}
    break;

  case 40:
#line 251 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_TYPE, "type", 5, (yyvsp[(1) - (5)].treeptr), (yyvsp[(2) - (5)].treeptr), (yyvsp[(3) - (5)].treeptr), (yyvsp[(4) - (5)].treeptr), (yyvsp[(5) - (5)].treeptr)); ;}
    break;

  case 41:
#line 256 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 42:
#line 258 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_TYPE, "type_args", 3, (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 43:
#line 265 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_BLOCK, "block", 3,
                         (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 44:
#line 271 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 45:
#line 273 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 46:
#line 275 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_STATEMENTS, "statements", 2, (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 47:
#line 280 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 48:
#line 282 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_STATEMENT_LIST, "statement_list", 3,
                         (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 49:
#line 288 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 50:
#line 290 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 51:
#line 292 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 52:
#line 294 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 53:
#line 296 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 54:
#line 298 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 55:
#line 300 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 56:
#line 302 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 57:
#line 309 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 58:
#line 311 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 59:
#line 313 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 60:
#line 318 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_FOR_STATEMENT, "for_statement", 7,
                         (yyvsp[(1) - (7)].treeptr), (yyvsp[(2) - (7)].treeptr), (yyvsp[(3) - (7)].treeptr),
                         (yyvsp[(4) - (7)].treeptr), (yyvsp[(5) - (7)].treeptr), (yyvsp[(6) - (7)].treeptr), (yyvsp[(7) - (7)].treeptr)); ;}
    break;

  case 61:
#line 322 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_FOR_STATEMENT, "for_statement", 9,
                         (yyvsp[(1) - (9)].treeptr), (yyvsp[(2) - (9)].treeptr), (yyvsp[(3) - (9)].treeptr),
                         (yyvsp[(4) - (9)].treeptr), (yyvsp[(5) - (9)].treeptr), (yyvsp[(6) - (9)].treeptr), (yyvsp[(7) - (9)].treeptr),
                         (yyvsp[(8) - (9)].treeptr), (yyvsp[(9) - (9)].treeptr)); ;}
    break;

  case 62:
#line 330 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 63:
#line 332 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 64:
#line 337 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_WHILE_STATEMENT, "while_statement", 5,
                         (yyvsp[(1) - (5)].treeptr),  (yyvsp[(2) - (5)].treeptr), (yyvsp[(3) - (5)].treeptr),  (yyvsp[(4) - (5)].treeptr), (yyvsp[(5) - (5)].treeptr)); ;}
    break;

  case 65:
#line 340 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_WHILE_STATEMENT, "while_statement", 5,
                         (yyvsp[(1) - (5)].treeptr),  (yyvsp[(2) - (5)].treeptr), (yyvsp[(3) - (5)].treeptr),  (yyvsp[(4) - (5)].treeptr),  (yyvsp[(5) - (5)].treeptr)); ;}
    break;

  case 66:
#line 346 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_DO_WHILE_STATEMENT, "do_while_statement", 6,
                          (yyvsp[(1) - (6)].treeptr), (yyvsp[(2) - (6)].treeptr), (yyvsp[(3) - (6)].treeptr), (yyvsp[(4) - (6)].treeptr), (yyvsp[(5) - (6)].treeptr), (yyvsp[(6) - (6)].treeptr)); ;}
    break;

  case 67:
#line 349 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_DO_WHILE_STATEMENT, "do_while_statement", 6,
                          (yyvsp[(1) - (6)].treeptr), (yyvsp[(2) - (6)].treeptr), (yyvsp[(3) - (6)].treeptr), (yyvsp[(4) - (6)].treeptr), (yyvsp[(5) - (6)].treeptr), (yyvsp[(6) - (6)].treeptr)); ;}
    break;

  case 68:
#line 355 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 69:
#line 357 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 70:
#line 359 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 71:
#line 361 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 72:
#line 366 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 73:
#line 368 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 74:
#line 370 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 75:
#line 372 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 76:
#line 374 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 77:
#line 381 "k0gram.y"
    { (yyval.treeptr) =  (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 78:
#line 383 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_RETURN_STATEMENT, "return_statement", 2,
                         (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 79:
#line 389 "k0gram.y"
    { (yyval.treeptr) =  (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 80:
#line 394 "k0gram.y"
    { (yyval.treeptr) =  (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 81:
#line 401 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_IF_EXPRESSION, "if_expression", 5,
                          (yyvsp[(1) - (5)].treeptr),  (yyvsp[(2) - (5)].treeptr), (yyvsp[(3) - (5)].treeptr),  (yyvsp[(4) - (5)].treeptr), (yyvsp[(5) - (5)].treeptr)); ;}
    break;

  case 82:
#line 404 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_IF_EXPRESSION, "if_expression", 7,
                          (yyvsp[(1) - (7)].treeptr),  (yyvsp[(2) - (7)].treeptr), (yyvsp[(3) - (7)].treeptr),  (yyvsp[(4) - (7)].treeptr),
                         (yyvsp[(5) - (7)].treeptr),  (yyvsp[(6) - (7)].treeptr), (yyvsp[(7) - (7)].treeptr)); ;}
    break;

  case 83:
#line 411 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_WHEN_EXPRESSION, "when_expression", 4,
                          (yyvsp[(1) - (4)].treeptr),  (yyvsp[(2) - (4)].treeptr), (yyvsp[(3) - (4)].treeptr),  (yyvsp[(4) - (4)].treeptr)); ;}
    break;

  case 84:
#line 414 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_WHEN_EXPRESSION, "when_expression", 7,
                          (yyvsp[(1) - (7)].treeptr),  (yyvsp[(2) - (7)].treeptr), (yyvsp[(3) - (7)].treeptr),  (yyvsp[(4) - (7)].treeptr),
                          (yyvsp[(5) - (7)].treeptr), (yyvsp[(6) - (7)].treeptr),  (yyvsp[(7) - (7)].treeptr)); ;}
    break;

  case 85:
#line 421 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_WHEN_ENTRY_LIST, "when_entry_list", 2, (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 86:
#line 423 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 87:
#line 432 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_WHEN_ENTRY, "when_entry", 4,
                         (yyvsp[(1) - (4)].treeptr),  (yyvsp[(2) - (4)].treeptr), (yyvsp[(3) - (4)].treeptr),  (yyvsp[(4) - (4)].treeptr)); ;}
    break;

  case 88:
#line 435 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_WHEN_ENTRY, "when_entry", 4,
                          (yyvsp[(1) - (4)].treeptr),  (yyvsp[(2) - (4)].treeptr), (yyvsp[(3) - (4)].treeptr),  (yyvsp[(4) - (4)].treeptr)); ;}
    break;

  case 89:
#line 441 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 90:
#line 443 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_WHEN_CONDITION_LIST, "when_condition_list", 3,
                         (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 91:
#line 449 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 92:
#line 456 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 93:
#line 458 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 94:
#line 460 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 95:
#line 462 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 96:
#line 464 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 97:
#line 466 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 98:
#line 468 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 99:
#line 473 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 100:
#line 475 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_DISJUNCTION, "disjunction", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 101:
#line 480 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 102:
#line 482 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_CONJUNCTION, "conjunction", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 103:
#line 487 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 104:
#line 489 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 105:
#line 491 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 106:
#line 493 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 107:
#line 495 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 108:
#line 500 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 109:
#line 502 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 110:
#line 504 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 111:
#line 506 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 112:
#line 508 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 113:
#line 513 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 114:
#line 515 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_INFIX_OPERATION, "infix_operation", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 115:
#line 520 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 116:
#line 522 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_ELVIS_EXPR, "elvis_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 117:
#line 527 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 118:
#line 529 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_RANGE_EXPR, "range_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 119:
#line 531 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_RANGE_EXPR, "range_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 120:
#line 536 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 121:
#line 538 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_ADDITIVE_EXPR, "additive_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 122:
#line 540 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_ADDITIVE_EXPR, "additive_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 123:
#line 545 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 124:
#line 547 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_MULTIPLICATIVE_EXPR, "multiplicative_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 125:
#line 549 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_MULTIPLICATIVE_EXPR, "multiplicative_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 126:
#line 551 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_MULTIPLICATIVE_EXPR, "multiplicative_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 127:
#line 556 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 128:
#line 558 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_AS_EXPR, "as_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 129:
#line 563 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 130:
#line 565 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 131:
#line 567 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 132:
#line 569 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 133:
#line 571 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 134:
#line 573 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[(1) - (2)].treeptr), (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 135:
#line 578 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 136:
#line 580 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 2, (yyvsp[(1) - (2)].treeptr),  (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 137:
#line 582 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 2, (yyvsp[(1) - (2)].treeptr),  (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 138:
#line 584 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr),  (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 139:
#line 586 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr),  (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 140:
#line 588 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 3, (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr),  (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 141:
#line 590 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 4, (yyvsp[(1) - (4)].treeptr),  (yyvsp[(2) - (4)].treeptr), (yyvsp[(3) - (4)].treeptr),  (yyvsp[(4) - (4)].treeptr)); ;}
    break;

  case 142:
#line 592 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 4, (yyvsp[(1) - (4)].treeptr),  (yyvsp[(2) - (4)].treeptr), (yyvsp[(3) - (4)].treeptr),  (yyvsp[(4) - (4)].treeptr)); ;}
    break;

  case 143:
#line 597 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 144:
#line 599 "k0gram.y"
    { (yyval.treeptr) = NULL; ;}
    break;

  case 145:
#line 604 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 146:
#line 606 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_VALUE_ARGUMENT_LIST, "value_argument_list", 3,
                         (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 147:
#line 612 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 148:
#line 619 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_PRIMARY_EXPR, "primary_expr", 3,
                          (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr),  (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 149:
#line 622 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 150:
#line 624 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 151:
#line 626 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 152:
#line 628 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 153:
#line 632 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 154:
#line 633 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 155:
#line 634 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 156:
#line 635 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 157:
#line 636 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 158:
#line 637 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 159:
#line 638 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 160:
#line 643 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_COLLECTION_LITERAL, "collection_literal", 2,
                          (yyvsp[(1) - (2)].treeptr),  (yyvsp[(2) - (2)].treeptr)); ;}
    break;

  case 161:
#line 646 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_COLLECTION_LITERAL, "collection_literal", 3,
                          (yyvsp[(1) - (3)].treeptr), (yyvsp[(2) - (3)].treeptr),  (yyvsp[(3) - (3)].treeptr)); ;}
    break;

  case 162:
#line 652 "k0gram.y"
    { (yyval.treeptr) = (yyvsp[(1) - (1)].treeptr); ;}
    break;

  case 163:
#line 654 "k0gram.y"
    { (yyval.treeptr) = alloktree(R_COLLECTION_ITEMS, "collection_items", 3,
                         (yyvsp[(1) - (3)].treeptr),  (yyvsp[(2) - (3)].treeptr), (yyvsp[(3) - (3)].treeptr)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2653 "k0gram.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 658 "k0gram.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s:%d: syntax error: %s\n",
            current_filename ? current_filename : "stdin", lineno, s);
}

int main(int argc, char *argv[]) {
    extern FILE *yyin;

    /* ── Parse command-line flags ──────────────────────────────────── */
    int do_tree   = 0;
    int do_symtab = 0;
    int do_dot    = 0;
    int first_file = -1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-tree")   == 0) { do_tree = 1; debug_tokens = 1; continue; }
        if (strcmp(argv[i], "-symtab") == 0) { do_symtab = 1; continue; }
        if (strcmp(argv[i], "-dot")    == 0) { do_dot = 1; continue; }
        if (first_file < 0) first_file = i;
    }

    if (first_file < 0) {
        fprintf(stderr, "usage: k0 [-tree] [-symtab] [-dot] <file.kt>\n");
        return 1;
    }

    /* ── Process each source file ──────────────────────────────────── */
    int exit_status = 0;

    for (int i = first_file; i < argc; i++) {
        if (argv[i][0] == '-') continue;

        printf("%s\n", argv[i]);

        yyin = fopen(argv[i], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file: %s\n", argv[i]);
            exit_status = 1;
            continue;
        }
        current_filename = argv[i];
        parseroot = NULL;

        int result = yyparse();

        if (result != 0) {
            fclose(yyin);
            if (exit_status < 2) exit_status = 2;
            continue;
        }

        if (!parseroot) { fclose(yyin); continue; }

        if (do_tree)
            treeprint(parseroot, 0);

        SymbolTable global = buildsyms(parseroot);
        checksyms(parseroot, global);
        typecheck(parseroot, global);

        if (semantic_errors > 0) {
            if (exit_status < 3) exit_status = 3;
        } else {
            /* Generate intermediate code */
            assign_first(parseroot);
            parseroot->follow = genlabel();
            parseroot->has_follow = 1;
            assign_follow(parseroot);
            assign_bool_labels(parseroot);
            struct instr *ic = codegen(parseroot, global);
            if (do_dot) {
                char dotname[1024];
                snprintf(dotname, sizeof(dotname), "%s.dot", argv[i]);
                treedot(parseroot, ic, dotname);
                printf("Wrote %s\n", dotname);
            }
            output_ic(ic, argv[i]);
            output_x86(ic, argv[i]);

            if (do_symtab)
                printsyms_all(global);
            else
                printf("No errors\n");
        }

        treefree(parseroot);
        fclose(yyin);
    }

    return exit_status;
}
