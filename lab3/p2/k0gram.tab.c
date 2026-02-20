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
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_program = 70,                   /* program  */
  YYSYMBOL_import_list = 71,               /* import_list  */
  YYSYMBOL_import_declaration = 72,        /* import_declaration  */
  YYSYMBOL_import_path = 73,               /* import_path  */
  YYSYMBOL_top_level_object_list = 74,     /* top_level_object_list  */
  YYSYMBOL_top_level_object = 75,          /* top_level_object  */
  YYSYMBOL_declaration = 76,               /* declaration  */
  YYSYMBOL_function_declaration = 77,      /* function_declaration  */
  YYSYMBOL_optional_return_type = 78,      /* optional_return_type  */
  YYSYMBOL_optional_function_body = 79,    /* optional_function_body  */
  YYSYMBOL_function_value_parameters = 80, /* function_value_parameters  */
  YYSYMBOL_function_value_parameter_list = 81, /* function_value_parameter_list  */
  YYSYMBOL_function_value_parameter = 82,  /* function_value_parameter  */
  YYSYMBOL_function_body = 83,             /* function_body  */
  YYSYMBOL_property_declaration = 84,      /* property_declaration  */
  YYSYMBOL_optional_type_annotation = 85,  /* optional_type_annotation  */
  YYSYMBOL_optional_initializer = 86,      /* optional_initializer  */
  YYSYMBOL_type = 87,                      /* type  */
  YYSYMBOL_user_type = 88,                 /* user_type  */
  YYSYMBOL_simple_user_type = 89,          /* simple_user_type  */
  YYSYMBOL_type_argument_list = 90,        /* type_argument_list  */
  YYSYMBOL_block = 91,                     /* block  */
  YYSYMBOL_statements = 92,                /* statements  */
  YYSYMBOL_optional_statement_sequence = 93, /* optional_statement_sequence  */
  YYSYMBOL_semis_statement_list = 94,      /* semis_statement_list  */
  YYSYMBOL_semis = 95,                     /* semis  */
  YYSYMBOL_optional_semis = 96,            /* optional_semis  */
  YYSYMBOL_statement = 97,                 /* statement  */
  YYSYMBOL_assignment = 98,                /* assignment  */
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
#define YYLAST   647

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  276

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    74,    75,    83,    84,    89,    90,    95,
      96,   100,   114,   115,   134,   138,   139,   143,   144,   152,
     153,   157,   158,   165,   166,   171,   172,   194,   195,   196,
     200,   201,   205,   206,   228,   229,   233,   234,   238,   239,
     243,   244,   253,   265,   269,   270,   274,   275,   281,   282,
     286,   287,   305,   306,   307,   308,   309,   310,   311,   328,
     329,   330,   331,   332,   333,   341,   342,   343,   353,   354,
     358,   359,   366,   367,   375,   381,   382,   397,   398,   402,
     406,   426,   427,   428,   452,   453,   457,   458,   462,   463,
     467,   468,   474,   475,   507,   511,   512,   516,   517,   521,
     522,   523,   524,   525,   529,   530,   531,   532,   533,   539,
     540,   546,   547,   551,   552,   553,   557,   558,   559,   563,
     564,   565,   566,   573,   574,   578,   579,   580,   581,   582,
     583,   598,   599,   600,   601,   602,   603,   604,   605,   609,
     610,   614,   615,   621,   622,   645,   646,   647,   648,   649,
     650,   651,   658,   659,   660,   661,   662,   663,   664,   670,
     671,   675,   676
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
  "DOUBLE_COLON", "$accept", "program", "import_list",
  "import_declaration", "import_path", "top_level_object_list",
  "top_level_object", "declaration", "function_declaration",
  "optional_return_type", "optional_function_body",
  "function_value_parameters", "function_value_parameter_list",
  "function_value_parameter", "function_body", "property_declaration",
  "optional_type_annotation", "optional_initializer", "type", "user_type",
  "simple_user_type", "type_argument_list", "block", "statements",
  "optional_statement_sequence", "semis_statement_list", "semis",
  "optional_semis", "statement", "assignment", "loop_statement",
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

#define YYPACT_NINF (-250)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -250,    16,     3,  -250,    11,  -250,    17,  -250,     5,    23,
      51,    74,   103,  -250,    46,  -250,  -250,   118,  -250,    94,
      83,    83,   124,  -250,    85,  -250,  -250,   -20,    87,   127,
     129,   129,    83,  -250,    89,  -250,   -25,  -250,   127,   -18,
      97,  -250,   -38,  -250,   545,  -250,  -250,   129,   127,  -250,
     133,  -250,   545,   330,  -250,  -250,  -250,   127,  -250,   127,
     105,    29,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,   545,   545,   545,   545,   545,   545,   373,  -250,  -250,
    -250,   114,   116,    47,   -32,   149,   115,    63,   106,    59,
     110,  -250,    34,  -250,  -250,  -250,  -250,   139,  -250,  -250,
     113,   117,   545,  -250,  -250,   273,  -250,   111,    46,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,    93,  -250,
      64,  -250,   545,   545,  -250,  -250,  -250,  -250,  -250,  -250,
     119,  -250,  -250,    22,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   127,  -250,  -250,   144,   588,   545,   145,
     147,   545,   545,   148,  -250,  -250,  -250,   168,  -250,  -250,
    -250,    46,   545,   545,   545,   545,   545,   545,  -250,   127,
     121,   122,   416,  -250,  -250,   545,   116,    47,   -32,   -32,
     -32,   -32,   149,   149,   149,   149,   115,    63,   106,   106,
      59,    59,   110,   110,   110,  -250,  -250,   152,  -250,   125,
     120,  -250,   128,  -250,  -250,  -250,   126,    -9,   130,   214,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,   273,   123,   132,
     545,  -250,  -250,     7,  -250,  -250,  -250,   545,  -250,   588,
    -250,    42,   545,   127,   545,  -250,   177,  -250,   273,  -250,
     502,   273,  -250,  -250,  -250,  -250,   131,   175,   134,   273,
     459,    46,  -250,    46,   273,   545,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,   135,   273,  -250
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    10,     1,     0,     3,     2,     7,     5,     0,
       0,     0,     0,     9,    51,    12,    13,     0,     6,     0,
      31,    31,     0,    48,    50,    11,     8,     0,    16,     0,
      33,    33,    31,    49,     0,    19,     0,    21,     0,    18,
      38,    30,    34,    36,     0,    27,    28,    33,     0,    20,
       0,    15,     0,    45,    14,    17,    25,     0,    35,     0,
       0,     0,   152,   153,   154,   155,   156,   157,   148,   158,
     146,     0,     0,     0,     0,     0,     0,     0,   150,   151,
      32,    94,    95,    97,    99,   104,   109,   111,   113,   116,
     119,   123,   125,   131,   147,   149,    29,    23,    22,    26,
       0,     0,    77,    79,    80,     0,    52,     0,    51,    47,
      53,    54,    65,    66,    67,    56,    57,    58,    55,    40,
       0,    37,     0,     0,    87,   128,   127,   129,   130,   126,
       0,   159,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,   140,     0,     0,
       0,     0,     0,     0,    78,    75,    76,     0,    70,    42,
      43,    44,     0,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,   145,   160,     0,    96,    98,   100,   101,
     102,   103,   108,   107,   105,   106,   110,   112,   114,   115,
     117,   118,   120,   121,   122,   124,   135,   146,   143,     0,
     139,   141,     0,   134,   136,    24,     0,     0,     0,     0,
      59,    60,    61,    62,    63,    64,    41,     0,     0,     0,
       0,    84,    86,     0,    90,    92,   162,     0,   138,     0,
     137,     0,     0,     0,     0,    46,    81,    87,     0,    93,
       0,     0,   144,   142,    73,    72,     0,     0,     0,     0,
       0,    51,    91,    51,    71,     0,    74,    82,    83,    85,
      89,    88,    68,     0,    71,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -250,  -250,  -250,  -250,  -250,  -250,  -250,   186,  -250,  -250,
    -250,  -250,  -250,   146,  -250,  -250,   -14,   -19,   -34,  -250,
     138,  -250,   155,  -250,  -250,  -250,    30,  -106,   -52,  -250,
    -250,  -250,  -249,  -250,  -250,  -224,  -250,  -250,  -250,   -57,
    -250,   -43,  -250,  -250,   -47,   -44,  -250,    71,    72,   -33,
      -6,    66,    67,    -4,    -2,   -41,   -31,  -250,  -250,  -250,
     -28,  -250,  -250,  -250,  -250
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     8,     6,    13,   106,    15,    39,
      54,    28,    36,    37,    55,    16,    30,    45,    41,    42,
      43,   120,   165,   107,   108,   171,    24,    25,   166,   110,
     111,   112,   167,   113,   114,   168,   115,   116,   117,    78,
      79,   182,   232,   233,   234,   118,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   209,   210,
     211,    93,    94,    95,   133
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,   109,   170,   246,    51,   242,    34,    31,    99,    52,
     140,   141,    46,    58,    97,   272,     3,   255,    47,     4,
       9,    10,    11,   119,   261,   275,    59,   263,    96,   142,
     143,    49,   130,   132,    12,   267,    35,     7,    50,    53,
     125,   126,   127,   128,   129,     9,    10,    11,    60,    19,
     100,   101,   102,   103,   104,    61,   243,   105,   164,    12,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    17,
     250,    18,   154,   155,   251,    71,    72,    20,   180,   181,
      73,    74,   184,   156,   123,   185,   124,   136,   137,   157,
      75,   138,   139,   158,   150,   151,   152,    76,   159,    53,
      21,    77,   160,   188,   189,   190,   191,    22,   254,   202,
     203,   204,    23,   208,   212,   146,   147,   215,   216,   205,
     172,   173,   174,   175,   176,   177,   178,   179,   220,   221,
     222,   223,   224,   225,   192,   193,   194,   195,   235,   148,
     149,   236,   198,   199,    26,   226,   200,   201,    29,    27,
      32,    33,    38,    40,    48,   270,    44,   271,    57,    34,
     122,   134,   135,   144,   153,   145,   161,   245,   162,   169,
     206,   213,   163,   214,   217,   183,   218,   227,   228,   237,
     247,   238,   241,   239,   259,   244,   249,   264,   240,   265,
     266,   274,    14,   252,    56,   208,    98,   121,   256,   248,
     258,   219,   268,   262,   260,   186,   235,   187,     0,   257,
     196,   253,   197,     0,     0,     0,   235,     9,    10,    11,
      60,   273,   100,   101,   102,   103,   104,    61,     0,   105,
       0,    12,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,     0,     0,     0,     0,    71,    72,     0,
       0,     0,    73,    74,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,    77,     0,     0,     9,    10,    11,    60,
      33,   100,   101,   102,   103,   104,    61,     0,   105,     0,
      12,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,     0,     0,    71,    72,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,    75,     0,     0,     0,     0,     0,     0,    76,     0,
      53,     0,    77,     9,    10,    11,    60,     0,   100,   101,
     102,   103,   104,    61,     0,   105,     0,    12,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,     0,
       0,     0,     0,    71,    72,     0,     0,     0,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    60,
       0,     0,     0,     0,     0,    76,    61,     0,     0,    77,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,     0,     0,    71,    72,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    60,   229,     0,     0,     0,     0,    76,    61,
     230,     0,    77,   131,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,     0,     0,     0,     0,    71,
      72,     0,     0,     0,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    60,   229,     0,     0,     0,
       0,    76,    61,   230,   231,    77,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,     0,     0,
       0,     0,    71,    72,     0,     0,     0,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    60,     0,
       0,     0,     0,     0,    76,    61,   230,   269,    77,     0,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,     0,     0,     0,     0,    71,    72,     0,     0,     0,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    60,     0,     0,     0,     0,     0,    76,    61,     0,
       0,    77,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,     0,     0,     0,     0,    71,    72,
       0,     0,     0,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    60,     0,     0,     0,     0,     0,
      76,    61,     0,     0,    77,     0,    62,    63,    64,    65,
      66,    67,    68,    69,   207,     0,     0,     0,     0,     0,
       0,    71,    72,     0,     0,     0,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,     0,
       0,     0,     0,    76,     0,     0,     0,    77
};

static const yytype_int16 yycheck[] =
{
      44,    53,   108,   227,    38,    14,    26,    21,    52,    27,
      42,    43,    31,    51,    48,   264,     0,   241,    32,    16,
       3,     4,     5,    57,   248,   274,    64,   251,    47,    61,
      62,    56,    76,    77,    17,   259,    56,    26,    63,    57,
      71,    72,    73,    74,    75,     3,     4,     5,     6,    26,
       8,     9,    10,    11,    12,    13,    65,    15,   102,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    64,
      63,    66,    38,    39,    67,    33,    34,    26,   122,   123,
      38,    39,    60,    49,    55,    63,    57,    40,    41,    55,
      48,    44,    45,    59,    35,    36,    37,    55,    64,    57,
      26,    59,    68,   136,   137,   138,   139,     4,    66,   150,
     151,   152,    66,   157,   158,    52,    53,   161,   162,   153,
      27,    28,    29,    30,    31,    32,    62,    63,   172,   173,
     174,   175,   176,   177,   140,   141,   142,   143,   182,    33,
      34,   185,   146,   147,    26,   179,   148,   149,    65,    55,
      26,    66,    65,    26,    65,   261,    27,   263,    61,    26,
      55,    47,    46,    14,    54,    50,    27,   219,    55,    58,
      26,    26,    55,    26,    26,    56,     8,    56,    56,    27,
      57,    56,    56,    63,     7,    55,   230,    56,    60,    14,
      56,    56,     6,   237,    39,   239,    50,    59,   242,    67,
     244,   171,   259,   250,   247,   134,   250,   135,    -1,   243,
     144,   239,   145,    -1,    -1,    -1,   260,     3,     4,     5,
       6,   265,     8,     9,    10,    11,    12,    13,    -1,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    -1,    -1,     3,     4,     5,     6,
      66,     8,     9,    10,    11,    12,    13,    -1,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      57,    -1,    59,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    12,    13,    -1,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,     6,
      -1,    -1,    -1,    -1,    -1,    55,    13,    -1,    -1,    59,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,     6,     7,    -1,    -1,    -1,    -1,    55,    13,
      14,    -1,    59,    60,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,     6,     7,    -1,    -1,    -1,
      -1,    55,    13,    14,    58,    59,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,     6,    -1,
      -1,    -1,    -1,    -1,    55,    13,    14,    58,    59,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,     6,    -1,    -1,    -1,    -1,    -1,    55,    13,    -1,
      -1,    59,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,     6,    -1,    -1,    -1,    -1,    -1,
      55,    13,    -1,    -1,    59,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    71,     0,    16,    72,    74,    26,    73,     3,
       4,     5,    17,    75,    76,    77,    84,    64,    66,    26,
      26,    26,     4,    66,    95,    96,    26,    55,    80,    65,
      85,    85,    26,    66,    26,    56,    81,    82,    65,    78,
      26,    87,    88,    89,    27,    86,    86,    85,    65,    56,
      63,    87,    27,    57,    79,    83,    91,    61,    51,    64,
       6,    13,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    33,    34,    38,    39,    48,    55,    59,   108,   109,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   130,   131,   132,    86,    87,    82,   114,
       8,     9,    10,    11,    12,    15,    76,    92,    93,    97,
      98,    99,   100,   102,   103,   105,   106,   107,   114,    87,
      90,    89,    55,    55,    57,   125,   125,   125,   125,   125,
     114,    60,   114,   133,    47,    46,    40,    41,    44,    45,
      42,    43,    61,    62,    14,    50,    52,    53,    33,    34,
      35,    36,    37,    54,    38,    39,    49,    55,    59,    64,
      68,    27,    55,    55,   114,    91,    97,   101,   104,    58,
      96,    94,    27,    28,    29,    30,    31,    32,    62,    63,
     114,   114,   110,    56,    60,    63,   116,   117,   118,   118,
     118,   118,   119,   119,   119,   119,   120,   121,   122,   122,
     123,   123,   124,   124,   124,    87,    26,    26,   114,   127,
     128,   129,   114,    26,    26,   114,   114,    26,     8,    95,
     114,   114,   114,   114,   114,   114,    87,    56,    56,     7,
      14,    58,   111,   112,   113,   114,   114,    27,    56,    63,
      60,    56,    14,    65,    55,    97,   104,    57,    67,   114,
      63,    67,   114,   129,    66,   104,   114,    87,   114,     7,
     110,   104,   113,   104,    56,    14,    56,   104,   108,    58,
      96,    96,   101,   114,    56,   101
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    76,    76,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    98,    98,    98,    98,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   104,   104,   105,   105,   106,
     107,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   115,   115,   116,   116,   117,
     117,   117,   117,   117,   118,   118,   118,   118,   118,   119,
     119,   120,   120,   121,   121,   121,   122,   122,   122,   123,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   125,
     125,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   131,   131,   131,   131,   131,   131,   131,   132,
     132,   133,   133
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     3,     1,     3,     2,
       0,     2,     1,     1,     5,     2,     0,     1,     0,     2,
       3,     1,     3,     3,     5,     1,     2,     4,     4,     5,
       2,     0,     2,     0,     1,     2,     1,     3,     1,     4,
       1,     3,     3,     2,     2,     0,     3,     0,     1,     2,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     7,     9,
       1,     0,     5,     5,     6,     1,     1,     1,     2,     1,
       1,     5,     7,     7,     4,     7,     2,     0,     4,     4,
       1,     3,     1,     2,     1,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     1,     2,     2,     2,     2,
       2,     1,     2,     2,     3,     3,     3,     4,     4,     1,
       0,     1,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     3
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

#line 1489 "k0gram.tab.c"

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

#line 679 "k0gram.y"


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
