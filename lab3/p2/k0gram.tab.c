/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "k0gram.y"

#include <stdio.h>
#include <stdlib.h>
#include "token.h"

extern int yylex();
extern int lineno;
void yyerror(const char *s);

#line 81 "k0gram.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "k0gram.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FUN = 3,                        /* FUN  */
  YYSYMBOL_VAL = 4,                        /* VAL  */
  YYSYMBOL_VAR = 5,                        /* VAR  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 12,                  /* CONTINUE  */
  YYSYMBOL_WHEN = 13,                      /* WHEN  */
  YYSYMBOL_IN = 14,                        /* IN  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_IMPORT = 16,                    /* IMPORT  */
  YYSYMBOL_CONST = 17,                     /* CONST  */
  YYSYMBOL_INTEGERLITERAL = 18,            /* INTEGERLITERAL  */
  YYSYMBOL_LONGLITERAL = 19,               /* LONGLITERAL  */
  YYSYMBOL_REALLITERAL = 20,               /* REALLITERAL  */
  YYSYMBOL_DOUBLELITERAL = 21,             /* DOUBLELITERAL  */
  YYSYMBOL_BOOLEANLITERAL = 22,            /* BOOLEANLITERAL  */
  YYSYMBOL_CHARACTERLITERAL = 23,          /* CHARACTERLITERAL  */
  YYSYMBOL_STRINGLITERAL = 24,             /* STRINGLITERAL  */
  YYSYMBOL_NULLLITERAL = 25,               /* NULLLITERAL  */
  YYSYMBOL_IDENT = 26,                     /* IDENT  */
  YYSYMBOL_ASSIGNMENT = 27,                /* ASSIGNMENT  */
  YYSYMBOL_ADD_ASSIGN = 28,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 29,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 30,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 31,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 32,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD = 33,                       /* ADD  */
  YYSYMBOL_SUB = 34,                       /* SUB  */
  YYSYMBOL_MUL = 35,                       /* MUL  */
  YYSYMBOL_DIV = 36,                       /* DIV  */
  YYSYMBOL_MOD = 37,                       /* MOD  */
  YYSYMBOL_INCR = 38,                      /* INCR  */
  YYSYMBOL_DECR = 39,                      /* DECR  */
  YYSYMBOL_EQ = 40,                        /* EQ  */
  YYSYMBOL_NEQ = 41,                       /* NEQ  */
  YYSYMBOL_GTE = 42,                       /* GTE  */
  YYSYMBOL_LTE = 43,                       /* LTE  */
  YYSYMBOL_REF_EQ = 44,                    /* REF_EQ  */
  YYSYMBOL_REF_NEQ = 45,                   /* REF_NEQ  */
  YYSYMBOL_AND = 46,                       /* AND  */
  YYSYMBOL_OR = 47,                        /* OR  */
  YYSYMBOL_NOT = 48,                       /* NOT  */
  YYSYMBOL_SAFE_CALL = 49,                 /* SAFE_CALL  */
  YYSYMBOL_ELVIS = 50,                     /* ELVIS  */
  YYSYMBOL_QUEST = 51,                     /* QUEST  */
  YYSYMBOL_RANGE = 52,                     /* RANGE  */
  YYSYMBOL_RANGE_UNTIL = 53,               /* RANGE_UNTIL  */
  YYSYMBOL_AS = 54,                        /* AS  */
  YYSYMBOL_LPAREN = 55,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 56,                    /* RPAREN  */
  YYSYMBOL_LCURL = 57,                     /* LCURL  */
  YYSYMBOL_RCURL = 58,                     /* RCURL  */
  YYSYMBOL_LSQUARE = 59,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 60,                   /* RSQUARE  */
  YYSYMBOL_LANGLE = 61,                    /* LANGLE  */
  YYSYMBOL_RANGLE = 62,                    /* RANGLE  */
  YYSYMBOL_COMMA = 63,                     /* COMMA  */
  YYSYMBOL_DOT = 64,                       /* DOT  */
  YYSYMBOL_COLON = 65,                     /* COLON  */
  YYSYMBOL_SEMI = 66,                      /* SEMI  */
  YYSYMBOL_ARROW = 67,                     /* ARROW  */
  YYSYMBOL_DOUBLE_COLON = 68,              /* DOUBLE_COLON  */
  YYSYMBOL_UMINUS = 69,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 70,                     /* UPLUS  */
  YYSYMBOL_PREINC = 71,                    /* PREINC  */
  YYSYMBOL_PREDEC = 72,                    /* PREDEC  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_program = 74,                   /* program  */
  YYSYMBOL_import_list = 75,               /* import_list  */
  YYSYMBOL_import_declaration = 76,        /* import_declaration  */
  YYSYMBOL_import_path = 77,               /* import_path  */
  YYSYMBOL_top_level_object_list = 78,     /* top_level_object_list  */
  YYSYMBOL_top_level_object = 79,          /* top_level_object  */
  YYSYMBOL_declaration = 80,               /* declaration  */
  YYSYMBOL_function_declaration = 81,      /* function_declaration  */
  YYSYMBOL_optional_return_type = 82,      /* optional_return_type  */
  YYSYMBOL_optional_function_body = 83,    /* optional_function_body  */
  YYSYMBOL_function_value_parameters = 84, /* function_value_parameters  */
  YYSYMBOL_function_value_parameter_list = 85, /* function_value_parameter_list  */
  YYSYMBOL_function_value_parameter = 86,  /* function_value_parameter  */
  YYSYMBOL_function_body = 87,             /* function_body  */
  YYSYMBOL_property_declaration = 88,      /* property_declaration  */
  YYSYMBOL_optional_type_annotation = 89,  /* optional_type_annotation  */
  YYSYMBOL_optional_initializer = 90,      /* optional_initializer  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_block = 92,                     /* block  */
  YYSYMBOL_statements = 93,                /* statements  */
  YYSYMBOL_optional_statement_sequence = 94, /* optional_statement_sequence  */
  YYSYMBOL_semis_statement_list = 95,      /* semis_statement_list  */
  YYSYMBOL_semis = 96,                     /* semis  */
  YYSYMBOL_optional_semis = 97,            /* optional_semis  */
  YYSYMBOL_statement = 98,                 /* statement  */
  YYSYMBOL_loop_statement = 99,            /* loop_statement  */
  YYSYMBOL_for_statement = 100,            /* for_statement  */
  YYSYMBOL_optional_control_structure_body = 101, /* optional_control_structure_body  */
  YYSYMBOL_while_statement = 102,          /* while_statement  */
  YYSYMBOL_do_while_statement = 103,       /* do_while_statement  */
  YYSYMBOL_control_structure_body = 104,   /* control_structure_body  */
  YYSYMBOL_return_statement = 105,         /* return_statement  */
  YYSYMBOL_break_statement = 106,          /* break_statement  */
  YYSYMBOL_continue_statement = 107,       /* continue_statement  */
  YYSYMBOL_if_expression = 108,            /* if_expression  */
  YYSYMBOL_when_expression = 109,          /* when_expression  */
  YYSYMBOL_when_entry_list = 110,          /* when_entry_list  */
  YYSYMBOL_when_entry = 111,               /* when_entry  */
  YYSYMBOL_when_condition_list = 112,      /* when_condition_list  */
  YYSYMBOL_when_condition = 113,           /* when_condition  */
  YYSYMBOL_expression = 114,               /* expression  */
  YYSYMBOL_disjunction = 115,              /* disjunction  */
  YYSYMBOL_conjunction = 116,              /* conjunction  */
  YYSYMBOL_equality_expr = 117,            /* equality_expr  */
  YYSYMBOL_comparison_expr = 118,          /* comparison_expr  */
  YYSYMBOL_infix_operation = 119,          /* infix_operation  */
  YYSYMBOL_elvis_expr = 120,               /* elvis_expr  */
  YYSYMBOL_range_expr = 121,               /* range_expr  */
  YYSYMBOL_additive_expr = 122,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 123,      /* multiplicative_expr  */
  YYSYMBOL_as_expr = 124,                  /* as_expr  */
  YYSYMBOL_prefix_expr = 125,              /* prefix_expr  */
  YYSYMBOL_postfix_expr = 126,             /* postfix_expr  */
  YYSYMBOL_optional_value_arguments = 127, /* optional_value_arguments  */
  YYSYMBOL_value_argument_list = 128,      /* value_argument_list  */
  YYSYMBOL_value_argument = 129,           /* value_argument  */
  YYSYMBOL_primary_expr = 130,             /* primary_expr  */
  YYSYMBOL_literal = 131,                  /* literal  */
  YYSYMBOL_collection_literal = 132,       /* collection_literal  */
  YYSYMBOL_collection_items = 133          /* collection_items  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   550

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   327


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    92,    93,    99,   100,   104,   105,   110,
     111,   115,   123,   124,   142,   146,   147,   151,   152,   156,
     157,   161,   162,   166,   167,   171,   172,   189,   190,   191,
     195,   196,   200,   201,   234,   235,   243,   249,   253,   254,
     258,   259,   263,   264,   268,   269,   304,   305,   306,   307,
     308,   309,   317,   318,   319,   331,   332,   336,   337,   341,
     342,   347,   359,   360,   376,   377,   381,   385,   402,   403,
     404,   426,   427,   431,   432,   436,   437,   441,   442,   448,
     474,   475,   476,   477,   478,   479,   480,   484,   485,   489,
     490,   494,   495,   496,   497,   498,   502,   503,   504,   505,
     506,   511,   512,   516,   517,   521,   522,   523,   527,   528,
     529,   533,   534,   535,   536,   541,   542,   553,   554,   555,
     556,   557,   558,   577,   578,   579,   580,   581,   582,   583,
     584,   588,   589,   593,   594,   600,   601,   609,   610,   611,
     612,   613,   614,   615,   619,   620,   621,   622,   623,   624,
     625,   629,   630,   634,   635
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FUN", "VAL", "VAR",
  "IF", "ELSE", "WHILE", "FOR", "RETURN", "BREAK", "CONTINUE", "WHEN",
  "IN", "DO", "IMPORT", "CONST", "INTEGERLITERAL", "LONGLITERAL",
  "REALLITERAL", "DOUBLELITERAL", "BOOLEANLITERAL", "CHARACTERLITERAL",
  "STRINGLITERAL", "NULLLITERAL", "IDENT", "ASSIGNMENT", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD", "SUB",
  "MUL", "DIV", "MOD", "INCR", "DECR", "EQ", "NEQ", "GTE", "LTE", "REF_EQ",
  "REF_NEQ", "AND", "OR", "NOT", "SAFE_CALL", "ELVIS", "QUEST", "RANGE",
  "RANGE_UNTIL", "AS", "LPAREN", "RPAREN", "LCURL", "RCURL", "LSQUARE",
  "RSQUARE", "LANGLE", "RANGLE", "COMMA", "DOT", "COLON", "SEMI", "ARROW",
  "DOUBLE_COLON", "UMINUS", "UPLUS", "PREINC", "PREDEC", "$accept",
  "program", "import_list", "import_declaration", "import_path",
  "top_level_object_list", "top_level_object", "declaration",
  "function_declaration", "optional_return_type", "optional_function_body",
  "function_value_parameters", "function_value_parameter_list",
  "function_value_parameter", "function_body", "property_declaration",
  "optional_type_annotation", "optional_initializer", "type", "block",
  "statements", "optional_statement_sequence", "semis_statement_list",
  "semis", "optional_semis", "statement", "loop_statement",
  "for_statement", "optional_control_structure_body", "while_statement",
  "do_while_statement", "control_structure_body", "return_statement",
  "break_statement", "continue_statement", "if_expression",
  "when_expression", "when_entry_list", "when_entry",
  "when_condition_list", "when_condition", "expression", "disjunction",
  "conjunction", "equality_expr", "comparison_expr", "infix_operation",
  "elvis_expr", "range_expr", "additive_expr", "multiplicative_expr",
  "as_expr", "prefix_expr", "postfix_expr", "optional_value_arguments",
  "value_argument_list", "value_argument", "primary_expr", "literal",
  "collection_literal", "collection_items", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-230)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -230,    28,    21,  -230,    89,  -230,    66,  -230,   -23,    95,
     106,   119,    78,  -230,    81,  -230,  -230,   125,  -230,    98,
      91,    91,   137,  -230,   118,  -230,  -230,   -21,   107,   161,
     162,   162,    91,  -230,   126,  -230,    56,  -230,   161,   -18,
     143,  -230,   448,  -230,  -230,   162,   161,  -230,   177,  -230,
     448,   319,  -230,  -230,  -230,  -230,   149,    43,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,   448,   448,   448,
     448,   448,   448,   116,  -230,  -230,   150,   170,   173,   157,
     131,   216,   185,   -28,    45,    74,   193,  -230,   -26,  -230,
    -230,  -230,  -230,   221,  -230,   150,   194,   195,   448,  -230,
    -230,   262,  -230,   196,    81,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,   150,   448,   448,  -230,  -230,  -230,  -230,
    -230,  -230,    64,  -230,   150,    14,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   161,  -230,  -230,   226,   491,   448,   227,   229,   448,
     448,   230,   150,  -230,  -230,   249,  -230,  -230,  -230,    81,
      75,    96,   362,  -230,  -230,   448,   150,   150,   150,   150,
     150,   150,   173,   157,   131,   131,   131,   131,   216,   216,
     216,   216,   185,   -28,    45,    45,    74,    74,   193,   193,
     193,  -230,  -230,   232,   150,   204,   198,  -230,   -11,  -230,
    -230,   150,   130,    -7,   208,   203,   262,   207,   209,  -230,
    -230,   -57,  -230,   150,   150,   448,  -230,   491,  -230,    42,
     448,   161,   448,  -230,   271,  -230,   262,   448,   262,   150,
    -230,  -230,  -230,   277,   275,   333,   262,   405,    81,  -230,
      81,   262,   448,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
     376,   262,  -230
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    10,     1,     0,     3,     2,     7,     5,     0,
       0,     0,     0,     9,    45,    12,    13,     0,     6,     0,
      31,    31,     0,    42,    44,    11,     8,     0,    16,     0,
      33,    33,    31,    43,     0,    19,     0,    21,     0,    18,
      34,    30,     0,    27,    28,    33,     0,    20,     0,    15,
       0,    39,    14,    17,    25,    35,     0,     0,   144,   145,
     146,   147,   148,   149,   140,   150,   138,     0,     0,     0,
       0,     0,     0,     0,   142,   143,    32,    80,    87,    89,
      91,    96,   101,   103,   105,   108,   111,   115,   117,   123,
     139,   141,    29,    23,    22,    26,     0,     0,    64,    66,
      67,     0,    46,     0,    45,    41,    47,    52,    53,    54,
      49,    50,    51,    48,     0,     0,    74,   120,   119,   121,
     122,   118,     0,   151,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,     0,   132,     0,     0,     0,     0,
       0,     0,    65,    62,    63,     0,    57,    36,    37,    38,
       0,     0,     0,   137,   152,     0,    81,    82,    83,    84,
      85,    86,    88,    90,    92,    93,    94,    95,   100,    99,
      97,    98,   102,   104,   106,   107,   109,   110,   112,   113,
     114,   116,   127,   138,   136,     0,   131,   133,     0,   126,
     128,    24,     0,     0,     0,     0,     0,     0,     0,    71,
      73,     0,    77,    79,   154,     0,   130,     0,   129,     0,
       0,     0,     0,    40,    68,    74,     0,     0,     0,   135,
     134,    60,    59,     0,     0,     0,     0,     0,    45,    78,
      45,    58,     0,    61,    69,    70,    72,    76,    75,    55,
       0,    58,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,  -230,  -230,  -230,  -230,  -230,   284,  -230,  -230,
    -230,  -230,  -230,   243,  -230,  -230,   -17,    -5,   -35,   253,
    -230,  -230,  -230,   124,  -102,   -50,  -230,  -230,  -229,  -230,
    -230,  -202,  -230,  -230,  -230,    48,  -230,    62,  -230,  -230,
      61,   -42,  -230,   167,   169,    97,   105,   171,   160,    -1,
      53,    90,    99,  -230,  -230,  -230,    84,  -230,  -230,  -230,
    -230
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     8,     6,    13,   102,    15,    39,
      52,    28,    36,    37,    53,    16,    30,    43,    41,   163,
     103,   104,   169,    24,    25,   164,   106,   107,   165,   108,
     109,   166,   110,   111,   112,    74,    75,   172,   220,   221,
     222,   113,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   205,   206,   207,    89,    90,    91,
     125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,   105,   168,    49,    31,    34,   237,   230,    95,    50,
     238,    93,   152,   153,   234,    45,   126,   127,   128,   129,
     130,   131,   259,   154,   144,   145,    44,   242,     3,   155,
     122,   124,   262,   156,   248,    35,   250,     4,   157,    51,
      92,    17,   158,    18,   254,     9,    10,    11,    56,   228,
      96,    97,    98,    99,   100,    57,   162,   101,   231,    12,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     9,
      10,    11,   170,   171,   174,    67,    68,   175,   146,   147,
      69,    70,    22,    12,   176,   177,   178,   179,   180,   181,
      71,   126,   127,   128,   129,   130,   131,    72,   115,    51,
     116,    73,   126,   127,   128,   129,   130,   131,   241,   148,
     149,   150,    47,   204,   208,     7,   201,   211,   212,    48,
     173,    19,    56,   126,   127,   128,   129,   130,   131,    57,
     223,   216,    20,   224,    58,    59,    60,    61,    62,    63,
      64,    65,    66,   194,   195,    21,   257,    23,   258,    67,
      68,    26,   217,    27,    69,    70,    29,   126,   127,   128,
     129,   130,   131,    32,    71,   233,   117,   118,   119,   120,
     121,    72,    38,   138,   139,    73,   123,   126,   127,   128,
     129,   130,   131,   239,    33,   204,   229,    40,   243,    42,
     245,    46,   140,   141,    55,   223,   244,   134,   135,   196,
     197,   136,   137,    34,   114,   223,     9,    10,    11,    56,
     260,    96,    97,    98,    99,   100,    57,   132,   101,   133,
      12,    58,    59,    60,    61,    62,    63,    64,    65,    66,
     142,   184,   185,   186,   187,   143,    67,    68,   198,   199,
     200,    69,    70,   188,   189,   190,   191,   151,   159,   160,
     161,    71,   202,   209,   167,   210,   213,   214,    72,   225,
     226,   227,    73,   232,   235,     9,    10,    11,    56,    33,
      96,    97,    98,    99,   100,    57,   236,   101,   246,    12,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   252,
      14,    94,    54,   215,   255,    67,    68,   247,   249,   182,
      69,    70,   183,   193,   126,   127,   128,   129,   130,   131,
      71,   240,     0,   192,     0,     0,     0,    72,     0,    51,
       0,    73,     9,    10,    11,    56,     0,    96,    97,    98,
      99,   100,    57,   251,   101,     0,    12,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,     0,    69,    70,     0,
     126,   127,   128,   129,   130,   131,     0,    71,    56,   218,
       0,     0,     0,     0,    72,    57,     0,     0,    73,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   253,
       0,     0,     0,     0,     0,    67,    68,     0,     0,     0,
      69,    70,     0,   126,   127,   128,   129,   130,   131,     0,
      71,    56,   218,     0,     0,     0,     0,    72,    57,     0,
     219,    73,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   261,     0,     0,     0,     0,     0,    67,    68,
       0,     0,     0,    69,    70,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    56,     0,     0,     0,     0,     0,
      72,    57,     0,   256,    73,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,     0,
       0,    67,    68,     0,     0,     0,    69,    70,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    56,     0,     0,
       0,     0,     0,    72,    57,     0,     0,    73,     0,    58,
      59,    60,    61,    62,    63,    64,    65,   203,     0,     0,
       0,     0,     0,     0,    67,    68,     0,     0,     0,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
      73
};

static const yytype_int16 yycheck[] =
{
      42,    51,   104,    38,    21,    26,    63,    14,    50,    27,
      67,    46,    38,    39,   216,    32,    27,    28,    29,    30,
      31,    32,   251,    49,    52,    53,    31,   229,     0,    55,
      72,    73,   261,    59,   236,    56,   238,    16,    64,    57,
      45,    64,    68,    66,   246,     3,     4,     5,     6,    60,
       8,     9,    10,    11,    12,    13,    98,    15,    65,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     3,
       4,     5,   114,   115,    60,    33,    34,    63,    33,    34,
      38,    39,     4,    17,   126,   127,   128,   129,   130,   131,
      48,    27,    28,    29,    30,    31,    32,    55,    55,    57,
      57,    59,    27,    28,    29,    30,    31,    32,    66,    35,
      36,    37,    56,   155,   156,    26,   151,   159,   160,    63,
      56,    26,     6,    27,    28,    29,    30,    31,    32,    13,
     172,    56,    26,   175,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   144,   145,    26,   248,    66,   250,    33,
      34,    26,    56,    55,    38,    39,    65,    27,    28,    29,
      30,    31,    32,    26,    48,   215,    67,    68,    69,    70,
      71,    55,    65,    42,    43,    59,    60,    27,    28,    29,
      30,    31,    32,   225,    66,   227,    56,    26,   230,    27,
     232,    65,    61,    62,    51,   237,   231,    40,    41,   146,
     147,    44,    45,    26,    55,   247,     3,     4,     5,     6,
     252,     8,     9,    10,    11,    12,    13,    47,    15,    46,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      14,   134,   135,   136,   137,    50,    33,    34,   148,   149,
     150,    38,    39,   138,   139,   140,   141,    54,    27,    55,
      55,    48,    26,    26,    58,    26,    26,     8,    55,    27,
      56,    63,    59,    55,    57,     3,     4,     5,     6,    66,
       8,     9,    10,    11,    12,    13,    67,    15,     7,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    14,
       6,    48,    39,   169,   246,    33,    34,   235,   237,   132,
      38,    39,   133,   143,    27,    28,    29,    30,    31,    32,
      48,   227,    -1,   142,    -1,    -1,    -1,    55,    -1,    57,
      -1,    59,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    13,    56,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    38,    39,    -1,
      27,    28,    29,    30,    31,    32,    -1,    48,     6,     7,
      -1,    -1,    -1,    -1,    55,    13,    -1,    -1,    59,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    56,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    27,    28,    29,    30,    31,    32,    -1,
      48,     6,     7,    -1,    -1,    -1,    -1,    55,    13,    -1,
      58,    59,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    56,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,     6,    -1,    -1,    -1,    -1,    -1,
      55,    13,    -1,    58,    59,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,     6,    -1,    -1,
      -1,    -1,    -1,    55,    13,    -1,    -1,    59,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    75,     0,    16,    76,    78,    26,    77,     3,
       4,     5,    17,    79,    80,    81,    88,    64,    66,    26,
      26,    26,     4,    66,    96,    97,    26,    55,    84,    65,
      89,    89,    26,    66,    26,    56,    85,    86,    65,    82,
      26,    91,    27,    90,    90,    89,    65,    56,    63,    91,
      27,    57,    83,    87,    92,    51,     6,    13,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    33,    34,    38,
      39,    48,    55,    59,   108,   109,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   130,
     131,   132,    90,    91,    86,   114,     8,     9,    10,    11,
      12,    15,    80,    93,    94,    98,    99,   100,   102,   103,
     105,   106,   107,   114,    55,    55,    57,   125,   125,   125,
     125,   125,   114,    60,   114,   133,    27,    28,    29,    30,
      31,    32,    47,    46,    40,    41,    44,    45,    42,    43,
      61,    62,    14,    50,    52,    53,    33,    34,    35,    36,
      37,    54,    38,    39,    49,    55,    59,    64,    68,    27,
      55,    55,   114,    92,    98,   101,   104,    58,    97,    95,
     114,   114,   110,    56,    60,    63,   114,   114,   114,   114,
     114,   114,   116,   117,   118,   118,   118,   118,   119,   119,
     119,   119,   120,   121,   122,   122,   123,   123,   124,   124,
     124,    91,    26,    26,   114,   127,   128,   129,   114,    26,
      26,   114,   114,    26,     8,    96,    56,    56,     7,    58,
     111,   112,   113,   114,   114,    27,    56,    63,    60,    56,
      14,    65,    55,    98,   104,    57,    67,    63,    67,   114,
     129,    66,   104,   114,    91,   114,     7,   110,   104,   113,
     104,    56,    14,    56,   104,   108,    58,    97,    97,   101,
     114,    56,   101
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    80,    80,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    88,    88,    88,
      89,    89,    90,    90,    91,    91,    92,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    98,    98,    98,    98,
      98,    98,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   104,   104,   105,   105,   106,   107,   108,   108,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   113,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   116,
     116,   117,   117,   117,   117,   117,   118,   118,   118,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   122,   122,
     122,   123,   123,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   130,
     130,   130,   130,   130,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   133,   133
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     3,     1,     3,     2,
       0,     2,     1,     1,     5,     2,     0,     1,     0,     2,
       3,     1,     3,     3,     5,     1,     2,     4,     4,     5,
       2,     0,     2,     0,     1,     2,     3,     2,     2,     0,
       3,     0,     1,     2,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     9,     1,     0,     5,
       5,     6,     1,     1,     1,     2,     1,     1,     5,     7,
       7,     4,     7,     2,     0,     4,     4,     1,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     1,     2,     2,
       2,     2,     2,     1,     2,     2,     3,     3,     3,     4,
       4,     1,     0,     1,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {

#line 1464 "k0gram.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 638 "k0gram.y"


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
