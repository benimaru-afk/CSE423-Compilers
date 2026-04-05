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
#include <string.h>
#include "token.h"
#include "tree.h"
#include "symtab.h"
#include "symscan.h"
#include "prodrule.h"

extern int yylex(void);
extern int lineno;
extern char *current_filename;
void yyerror(const char *s);

#line 87 "k0gram.tab.c"

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
  YYSYMBOL_AS = 18,                        /* AS  */
  YYSYMBOL_INTEGERLITERAL = 19,            /* INTEGERLITERAL  */
  YYSYMBOL_LONGLITERAL = 20,               /* LONGLITERAL  */
  YYSYMBOL_REALLITERAL = 21,               /* REALLITERAL  */
  YYSYMBOL_DOUBLELITERAL = 22,             /* DOUBLELITERAL  */
  YYSYMBOL_BOOLEANLITERAL = 23,            /* BOOLEANLITERAL  */
  YYSYMBOL_CHARACTERLITERAL = 24,          /* CHARACTERLITERAL  */
  YYSYMBOL_STRINGLITERAL = 25,             /* STRINGLITERAL  */
  YYSYMBOL_NULLLITERAL = 26,               /* NULLLITERAL  */
  YYSYMBOL_IDENT = 27,                     /* IDENT  */
  YYSYMBOL_ASSIGNMENT = 28,                /* ASSIGNMENT  */
  YYSYMBOL_ADD_ASSIGN = 29,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 30,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 31,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 32,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 33,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD = 34,                       /* ADD  */
  YYSYMBOL_SUB = 35,                       /* SUB  */
  YYSYMBOL_MUL = 36,                       /* MUL  */
  YYSYMBOL_DIV = 37,                       /* DIV  */
  YYSYMBOL_MOD = 38,                       /* MOD  */
  YYSYMBOL_INCR = 39,                      /* INCR  */
  YYSYMBOL_DECR = 40,                      /* DECR  */
  YYSYMBOL_EQ = 41,                        /* EQ  */
  YYSYMBOL_NEQ = 42,                       /* NEQ  */
  YYSYMBOL_GTE = 43,                       /* GTE  */
  YYSYMBOL_LTE = 44,                       /* LTE  */
  YYSYMBOL_LANGLE = 45,                    /* LANGLE  */
  YYSYMBOL_RANGLE = 46,                    /* RANGLE  */
  YYSYMBOL_REF_EQ = 47,                    /* REF_EQ  */
  YYSYMBOL_REF_NEQ = 48,                   /* REF_NEQ  */
  YYSYMBOL_AND = 49,                       /* AND  */
  YYSYMBOL_OR = 50,                        /* OR  */
  YYSYMBOL_NOT = 51,                       /* NOT  */
  YYSYMBOL_SAFE_CALL = 52,                 /* SAFE_CALL  */
  YYSYMBOL_ELVIS = 53,                     /* ELVIS  */
  YYSYMBOL_QUEST = 54,                     /* QUEST  */
  YYSYMBOL_RANGE = 55,                     /* RANGE  */
  YYSYMBOL_RANGE_UNTIL = 56,               /* RANGE_UNTIL  */
  YYSYMBOL_LPAREN = 57,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 58,                    /* RPAREN  */
  YYSYMBOL_LCURL = 59,                     /* LCURL  */
  YYSYMBOL_RCURL = 60,                     /* RCURL  */
  YYSYMBOL_LSQUARE = 61,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 62,                   /* RSQUARE  */
  YYSYMBOL_COMMA = 63,                     /* COMMA  */
  YYSYMBOL_DOT = 64,                       /* DOT  */
  YYSYMBOL_COLON = 65,                     /* COLON  */
  YYSYMBOL_SEMI = 66,                      /* SEMI  */
  YYSYMBOL_ARROW = 67,                     /* ARROW  */
  YYSYMBOL_DOUBLE_COLON = 68,              /* DOUBLE_COLON  */
  YYSYMBOL_NEWLINE = 69,                   /* NEWLINE  */
  YYSYMBOL_UMINUS = 70,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 71,                     /* UPLUS  */
  YYSYMBOL_PREINC = 72,                    /* PREINC  */
  YYSYMBOL_PREDEC = 73,                    /* PREDEC  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_program = 75,                   /* program  */
  YYSYMBOL_import_list = 76,               /* import_list  */
  YYSYMBOL_import_declaration = 77,        /* import_declaration  */
  YYSYMBOL_import_path = 78,               /* import_path  */
  YYSYMBOL_top_level_object_list = 79,     /* top_level_object_list  */
  YYSYMBOL_top_level_object = 80,          /* top_level_object  */
  YYSYMBOL_declaration = 81,               /* declaration  */
  YYSYMBOL_function_declaration = 82,      /* function_declaration  */
  YYSYMBOL_optional_return_type = 83,      /* optional_return_type  */
  YYSYMBOL_optional_function_body = 84,    /* optional_function_body  */
  YYSYMBOL_function_value_parameters = 85, /* function_value_parameters  */
  YYSYMBOL_function_value_parameter_list = 86, /* function_value_parameter_list  */
  YYSYMBOL_function_value_parameter = 87,  /* function_value_parameter  */
  YYSYMBOL_function_body = 88,             /* function_body  */
  YYSYMBOL_property_declaration = 89,      /* property_declaration  */
  YYSYMBOL_optional_type_annotation = 90,  /* optional_type_annotation  */
  YYSYMBOL_optional_initializer = 91,      /* optional_initializer  */
  YYSYMBOL_type = 92,                      /* type  */
  YYSYMBOL_full_type = 93,                 /* full_type  */
  YYSYMBOL_type_args = 94,                 /* type_args  */
  YYSYMBOL_block = 95,                     /* block  */
  YYSYMBOL_statements = 96,                /* statements  */
  YYSYMBOL_statement_list = 97,            /* statement_list  */
  YYSYMBOL_statement = 98,                 /* statement  */
  YYSYMBOL_loop_statement = 99,            /* loop_statement  */
  YYSYMBOL_for_statement = 100,            /* for_statement  */
  YYSYMBOL_optional_control_structure_body = 101, /* optional_control_structure_body  */
  YYSYMBOL_while_statement = 102,          /* while_statement  */
  YYSYMBOL_do_while_statement = 103,       /* do_while_statement  */
  YYSYMBOL_control_structure_body = 104,   /* control_structure_body  */
  YYSYMBOL_simple_statement = 105,         /* simple_statement  */
  YYSYMBOL_return_statement = 106,         /* return_statement  */
  YYSYMBOL_break_statement = 107,          /* break_statement  */
  YYSYMBOL_continue_statement = 108,       /* continue_statement  */
  YYSYMBOL_if_expression = 109,            /* if_expression  */
  YYSYMBOL_when_expression = 110,          /* when_expression  */
  YYSYMBOL_when_entry_list = 111,          /* when_entry_list  */
  YYSYMBOL_when_entry = 112,               /* when_entry  */
  YYSYMBOL_when_condition_list = 113,      /* when_condition_list  */
  YYSYMBOL_when_condition = 114,           /* when_condition  */
  YYSYMBOL_expression = 115,               /* expression  */
  YYSYMBOL_disjunction = 116,              /* disjunction  */
  YYSYMBOL_conjunction = 117,              /* conjunction  */
  YYSYMBOL_equality_expr = 118,            /* equality_expr  */
  YYSYMBOL_comparison_expr = 119,          /* comparison_expr  */
  YYSYMBOL_infix_operation = 120,          /* infix_operation  */
  YYSYMBOL_elvis_expr = 121,               /* elvis_expr  */
  YYSYMBOL_range_expr = 122,               /* range_expr  */
  YYSYMBOL_additive_expr = 123,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 124,      /* multiplicative_expr  */
  YYSYMBOL_as_expr = 125,                  /* as_expr  */
  YYSYMBOL_prefix_expr = 126,              /* prefix_expr  */
  YYSYMBOL_postfix_expr = 127,             /* postfix_expr  */
  YYSYMBOL_optional_value_arguments = 128, /* optional_value_arguments  */
  YYSYMBOL_value_argument_list = 129,      /* value_argument_list  */
  YYSYMBOL_value_argument = 130,           /* value_argument  */
  YYSYMBOL_primary_expr = 131,             /* primary_expr  */
  YYSYMBOL_literal = 132,                  /* literal  */
  YYSYMBOL_collection_literal = 133,       /* collection_literal  */
  YYSYMBOL_collection_items = 134          /* collection_items  */
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
#define YYLAST   450

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    91,    94,    98,   101,   107,   109,   115,
     118,   122,   124,   132,   134,   139,   145,   149,   153,   156,
     160,   163,   169,   171,   177,   180,   186,   188,   194,   197,
     200,   206,   210,   214,   218,   228,   230,   238,   240,   242,
     244,   249,   251,   258,   265,   266,   268,   273,   275,   281,
     283,   285,   287,   289,   291,   293,   295,   302,   304,   306,
     311,   315,   323,   326,   330,   333,   339,   342,   348,   350,
     352,   354,   359,   361,   363,   365,   367,   374,   376,   382,
     387,   394,   397,   404,   407,   414,   417,   425,   428,   434,
     436,   442,   449,   451,   453,   455,   457,   459,   461,   466,
     468,   473,   475,   480,   482,   484,   486,   488,   493,   495,
     497,   499,   501,   506,   508,   513,   515,   520,   522,   524,
     529,   531,   533,   538,   540,   542,   544,   549,   551,   556,
     558,   560,   562,   564,   566,   571,   573,   575,   577,   579,
     581,   583,   585,   590,   593,   597,   599,   605,   612,   615,
     617,   619,   621,   626,   627,   628,   629,   630,   631,   632,
     636,   639,   645,   647
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
  "IN", "DO", "IMPORT", "CONST", "AS", "INTEGERLITERAL", "LONGLITERAL",
  "REALLITERAL", "DOUBLELITERAL", "BOOLEANLITERAL", "CHARACTERLITERAL",
  "STRINGLITERAL", "NULLLITERAL", "IDENT", "ASSIGNMENT", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD", "SUB",
  "MUL", "DIV", "MOD", "INCR", "DECR", "EQ", "NEQ", "GTE", "LTE", "LANGLE",
  "RANGLE", "REF_EQ", "REF_NEQ", "AND", "OR", "NOT", "SAFE_CALL", "ELVIS",
  "QUEST", "RANGE", "RANGE_UNTIL", "LPAREN", "RPAREN", "LCURL", "RCURL",
  "LSQUARE", "RSQUARE", "COMMA", "DOT", "COLON", "SEMI", "ARROW",
  "DOUBLE_COLON", "NEWLINE", "UMINUS", "UPLUS", "PREINC", "PREDEC",
  "$accept", "program", "import_list", "import_declaration", "import_path",
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
  "collection_items", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-210)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
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

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,     8,     6,    13,    98,    15,    36,
      49,    26,    33,    34,    50,    16,    28,    40,   198,    38,
     113,   237,    99,   100,   101,   238,   103,   267,   104,   105,
     268,   240,   241,   242,   243,   244,   245,   212,   230,   231,
     232,   246,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   201,   202,   203,    83,    84,    85,
     122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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
  case 2: /* program: import_list top_level_object_list  */
#line 86 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PROGRAM, "program", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));
          parseroot = (yyval.treeptr); }
#line 1460 "k0gram.tab.c"
    break;

  case 3: /* import_list: import_list import_declaration  */
#line 92 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_IMPORT_LIST, "import_list", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1466 "k0gram.tab.c"
    break;

  case 4: /* import_list: %empty  */
#line 94 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 1472 "k0gram.tab.c"
    break;

  case 5: /* import_declaration: IMPORT import_path  */
#line 99 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_IMPORT_DECLARATION, "import_declaration", 2,
                         (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1479 "k0gram.tab.c"
    break;

  case 6: /* import_declaration: IMPORT import_path SEMI  */
#line 102 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_IMPORT_DECLARATION, "import_declaration", 3,
                         (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1486 "k0gram.tab.c"
    break;

  case 7: /* import_path: IDENT  */
#line 108 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1492 "k0gram.tab.c"
    break;

  case 8: /* import_path: import_path DOT IDENT  */
#line 110 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_IMPORT_PATH, "import_path", 3,
                         (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1499 "k0gram.tab.c"
    break;

  case 9: /* top_level_object_list: top_level_object_list top_level_object  */
#line 116 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_TOP_LEVEL_OBJECT_LIST, "top_level_object_list", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1505 "k0gram.tab.c"
    break;

  case 10: /* top_level_object_list: %empty  */
#line 118 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 1511 "k0gram.tab.c"
    break;

  case 11: /* top_level_object: declaration  */
#line 123 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1517 "k0gram.tab.c"
    break;

  case 12: /* top_level_object: declaration SEMI  */
#line 125 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_TOP_LEVEL_OBJECT, "top_level_object", 2,
                         (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 1524 "k0gram.tab.c"
    break;

  case 13: /* declaration: function_declaration  */
#line 133 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1530 "k0gram.tab.c"
    break;

  case 14: /* declaration: property_declaration  */
#line 135 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1536 "k0gram.tab.c"
    break;

  case 15: /* function_declaration: FUN IDENT function_value_parameters optional_return_type optional_function_body  */
#line 140 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_FUNCTION_DECLARATION, "function_declaration", 5,
                         (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1543 "k0gram.tab.c"
    break;

  case 16: /* optional_return_type: COLON full_type  */
#line 146 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_OPTIONAL_RETURN_TYPE, "optional_return_type", 2,
                         (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1550 "k0gram.tab.c"
    break;

  case 17: /* optional_return_type: %empty  */
#line 149 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 1556 "k0gram.tab.c"
    break;

  case 18: /* optional_function_body: function_body  */
#line 154 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1562 "k0gram.tab.c"
    break;

  case 19: /* optional_function_body: %empty  */
#line 156 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 1568 "k0gram.tab.c"
    break;

  case 20: /* function_value_parameters: LPAREN RPAREN  */
#line 161 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAMETERS, "function_value_parameters", 2,
                         (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1575 "k0gram.tab.c"
    break;

  case 21: /* function_value_parameters: LPAREN function_value_parameter_list RPAREN  */
#line 164 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAMETERS, "function_value_parameters", 3,
                         (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1582 "k0gram.tab.c"
    break;

  case 22: /* function_value_parameter_list: function_value_parameter  */
#line 170 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1588 "k0gram.tab.c"
    break;

  case 23: /* function_value_parameter_list: function_value_parameter_list COMMA function_value_parameter  */
#line 172 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAM_LIST, "function_value_parameter_list", 3,
                         (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1595 "k0gram.tab.c"
    break;

  case 24: /* function_value_parameter: IDENT COLON full_type  */
#line 178 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAMETER, "function_value_parameter", 3,
                         (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1602 "k0gram.tab.c"
    break;

  case 25: /* function_value_parameter: IDENT COLON full_type ASSIGNMENT expression  */
#line 181 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_FUNCTION_VALUE_PARAMETER, "function_value_parameter", 5,
                         (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1609 "k0gram.tab.c"
    break;

  case 26: /* function_body: block  */
#line 187 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1615 "k0gram.tab.c"
    break;

  case 27: /* function_body: ASSIGNMENT expression  */
#line 189 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_FUNCTION_BODY, "function_body", 2,
                         (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1622 "k0gram.tab.c"
    break;

  case 28: /* property_declaration: VAL IDENT optional_type_annotation optional_initializer  */
#line 195 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PROPERTY_DECLARATION, "property_declaration", 4,
                         (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1629 "k0gram.tab.c"
    break;

  case 29: /* property_declaration: VAR IDENT optional_type_annotation optional_initializer  */
#line 198 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PROPERTY_DECLARATION, "property_declaration", 4,
                         (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1636 "k0gram.tab.c"
    break;

  case 30: /* property_declaration: CONST VAL IDENT optional_type_annotation optional_initializer  */
#line 201 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PROPERTY_DECLARATION, "property_declaration", 5,
                         (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1643 "k0gram.tab.c"
    break;

  case 31: /* optional_type_annotation: COLON full_type  */
#line 207 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_OPTIONAL_TYPE_ANNOTATION, "optional_type_annotation", 2,
                         (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1650 "k0gram.tab.c"
    break;

  case 32: /* optional_type_annotation: %empty  */
#line 210 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 1656 "k0gram.tab.c"
    break;

  case 33: /* optional_initializer: ASSIGNMENT expression  */
#line 215 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_OPTIONAL_INITIALIZER, "optional_initializer", 2,
                         (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1663 "k0gram.tab.c"
    break;

  case 34: /* optional_initializer: %empty  */
#line 218 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 1669 "k0gram.tab.c"
    break;

  case 35: /* type: IDENT  */
#line 229 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1675 "k0gram.tab.c"
    break;

  case 36: /* type: IDENT QUEST  */
#line 231 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_TYPE, "type", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1681 "k0gram.tab.c"
    break;

  case 37: /* full_type: IDENT  */
#line 239 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1687 "k0gram.tab.c"
    break;

  case 38: /* full_type: IDENT QUEST  */
#line 241 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_TYPE, "type", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1693 "k0gram.tab.c"
    break;

  case 39: /* full_type: IDENT LANGLE type_args RANGLE  */
#line 243 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_TYPE, "type", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1699 "k0gram.tab.c"
    break;

  case 40: /* full_type: IDENT LANGLE type_args RANGLE QUEST  */
#line 245 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_TYPE, "type", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1705 "k0gram.tab.c"
    break;

  case 41: /* type_args: full_type  */
#line 250 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1711 "k0gram.tab.c"
    break;

  case 42: /* type_args: type_args COMMA full_type  */
#line 252 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_TYPE, "type_args", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1717 "k0gram.tab.c"
    break;

  case 43: /* block: LCURL statements RCURL  */
#line 259 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_BLOCK, "block", 3,
                         (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1724 "k0gram.tab.c"
    break;

  case 44: /* statements: %empty  */
#line 265 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 1730 "k0gram.tab.c"
    break;

  case 45: /* statements: statement_list  */
#line 267 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1736 "k0gram.tab.c"
    break;

  case 46: /* statements: statement_list SEMI  */
#line 269 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_STATEMENTS, "statements", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1742 "k0gram.tab.c"
    break;

  case 47: /* statement_list: statement  */
#line 274 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1748 "k0gram.tab.c"
    break;

  case 48: /* statement_list: statement_list SEMI statement  */
#line 276 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_STATEMENT_LIST, "statement_list", 3,
                         (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1755 "k0gram.tab.c"
    break;

  case 49: /* statement: declaration  */
#line 282 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1761 "k0gram.tab.c"
    break;

  case 50: /* statement: loop_statement  */
#line 284 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1767 "k0gram.tab.c"
    break;

  case 51: /* statement: if_expression  */
#line 286 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1773 "k0gram.tab.c"
    break;

  case 52: /* statement: when_expression  */
#line 288 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1779 "k0gram.tab.c"
    break;

  case 53: /* statement: expression  */
#line 290 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1785 "k0gram.tab.c"
    break;

  case 54: /* statement: return_statement  */
#line 292 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1791 "k0gram.tab.c"
    break;

  case 55: /* statement: break_statement  */
#line 294 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1797 "k0gram.tab.c"
    break;

  case 56: /* statement: continue_statement  */
#line 296 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1803 "k0gram.tab.c"
    break;

  case 57: /* loop_statement: for_statement  */
#line 303 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1809 "k0gram.tab.c"
    break;

  case 58: /* loop_statement: while_statement  */
#line 305 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1815 "k0gram.tab.c"
    break;

  case 59: /* loop_statement: do_while_statement  */
#line 307 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1821 "k0gram.tab.c"
    break;

  case 60: /* for_statement: FOR LPAREN IDENT IN expression RPAREN optional_control_structure_body  */
#line 312 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_FOR_STATEMENT, "for_statement", 7,
                         (yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr),
                         (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1829 "k0gram.tab.c"
    break;

  case 61: /* for_statement: FOR LPAREN IDENT COLON full_type IN expression RPAREN optional_control_structure_body  */
#line 316 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_FOR_STATEMENT, "for_statement", 9,
                         (yyvsp[-8].treeptr), (yyvsp[-7].treeptr), (yyvsp[-6].treeptr),
                         (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),
                         (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1838 "k0gram.tab.c"
    break;

  case 62: /* optional_control_structure_body: control_structure_body  */
#line 324 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1844 "k0gram.tab.c"
    break;

  case 63: /* optional_control_structure_body: %empty  */
#line 326 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 1850 "k0gram.tab.c"
    break;

  case 64: /* while_statement: WHILE LPAREN expression RPAREN control_structure_body  */
#line 331 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_WHILE_STATEMENT, "while_statement", 5,
                         (yyvsp[-4].treeptr),  (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1857 "k0gram.tab.c"
    break;

  case 65: /* while_statement: WHILE LPAREN expression RPAREN SEMI  */
#line 334 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_WHILE_STATEMENT, "while_statement", 5,
                         (yyvsp[-4].treeptr),  (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 1864 "k0gram.tab.c"
    break;

  case 66: /* do_while_statement: DO block WHILE LPAREN expression RPAREN  */
#line 340 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_DO_WHILE_STATEMENT, "do_while_statement", 6,
                          (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1871 "k0gram.tab.c"
    break;

  case 67: /* do_while_statement: DO SEMI WHILE LPAREN expression RPAREN  */
#line 343 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_DO_WHILE_STATEMENT, "do_while_statement", 6,
                          (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1878 "k0gram.tab.c"
    break;

  case 68: /* control_structure_body: block  */
#line 349 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1884 "k0gram.tab.c"
    break;

  case 69: /* control_structure_body: if_expression  */
#line 351 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1890 "k0gram.tab.c"
    break;

  case 70: /* control_structure_body: when_expression  */
#line 353 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1896 "k0gram.tab.c"
    break;

  case 71: /* control_structure_body: simple_statement  */
#line 355 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1902 "k0gram.tab.c"
    break;

  case 72: /* simple_statement: loop_statement  */
#line 360 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1908 "k0gram.tab.c"
    break;

  case 73: /* simple_statement: expression  */
#line 362 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1914 "k0gram.tab.c"
    break;

  case 74: /* simple_statement: return_statement  */
#line 364 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1920 "k0gram.tab.c"
    break;

  case 75: /* simple_statement: break_statement  */
#line 366 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1926 "k0gram.tab.c"
    break;

  case 76: /* simple_statement: continue_statement  */
#line 368 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1932 "k0gram.tab.c"
    break;

  case 77: /* return_statement: RETURN  */
#line 375 "k0gram.y"
        { (yyval.treeptr) =  (yyvsp[0].treeptr); }
#line 1938 "k0gram.tab.c"
    break;

  case 78: /* return_statement: RETURN expression  */
#line 377 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_RETURN_STATEMENT, "return_statement", 2,
                         (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1945 "k0gram.tab.c"
    break;

  case 79: /* break_statement: BREAK  */
#line 383 "k0gram.y"
        { (yyval.treeptr) =  (yyvsp[0].treeptr); }
#line 1951 "k0gram.tab.c"
    break;

  case 80: /* continue_statement: CONTINUE  */
#line 388 "k0gram.y"
        { (yyval.treeptr) =  (yyvsp[0].treeptr); }
#line 1957 "k0gram.tab.c"
    break;

  case 81: /* if_expression: IF LPAREN expression RPAREN control_structure_body  */
#line 395 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_IF_EXPRESSION, "if_expression", 5,
                          (yyvsp[-4].treeptr),  (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1964 "k0gram.tab.c"
    break;

  case 82: /* if_expression: IF LPAREN expression RPAREN control_structure_body ELSE control_structure_body  */
#line 398 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_IF_EXPRESSION, "if_expression", 7,
                          (yyvsp[-6].treeptr),  (yyvsp[-5].treeptr), (yyvsp[-4].treeptr),  (yyvsp[-3].treeptr),
                         (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1972 "k0gram.tab.c"
    break;

  case 83: /* when_expression: WHEN LCURL when_entry_list RCURL  */
#line 405 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_WHEN_EXPRESSION, "when_expression", 4,
                          (yyvsp[-3].treeptr),  (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 1979 "k0gram.tab.c"
    break;

  case 84: /* when_expression: WHEN LPAREN expression RPAREN LCURL when_entry_list RCURL  */
#line 408 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_WHEN_EXPRESSION, "when_expression", 7,
                          (yyvsp[-6].treeptr),  (yyvsp[-5].treeptr), (yyvsp[-4].treeptr),  (yyvsp[-3].treeptr),
                          (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 1987 "k0gram.tab.c"
    break;

  case 85: /* when_entry_list: when_entry_list when_entry  */
#line 415 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_WHEN_ENTRY_LIST, "when_entry_list", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 1993 "k0gram.tab.c"
    break;

  case 86: /* when_entry_list: %empty  */
#line 417 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 1999 "k0gram.tab.c"
    break;

  case 87: /* when_entry: when_condition_list ARROW control_structure_body SEMI  */
#line 426 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_WHEN_ENTRY, "when_entry", 4,
                         (yyvsp[-3].treeptr),  (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2006 "k0gram.tab.c"
    break;

  case 88: /* when_entry: ELSE ARROW control_structure_body SEMI  */
#line 429 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_WHEN_ENTRY, "when_entry", 4,
                          (yyvsp[-3].treeptr),  (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2013 "k0gram.tab.c"
    break;

  case 89: /* when_condition_list: when_condition  */
#line 435 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2019 "k0gram.tab.c"
    break;

  case 90: /* when_condition_list: when_condition_list COMMA when_condition  */
#line 437 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_WHEN_CONDITION_LIST, "when_condition_list", 3,
                         (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2026 "k0gram.tab.c"
    break;

  case 91: /* when_condition: expression  */
#line 443 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2032 "k0gram.tab.c"
    break;

  case 92: /* expression: disjunction  */
#line 450 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2038 "k0gram.tab.c"
    break;

  case 93: /* expression: disjunction ASSIGNMENT expression  */
#line 452 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2044 "k0gram.tab.c"
    break;

  case 94: /* expression: disjunction ADD_ASSIGN expression  */
#line 454 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2050 "k0gram.tab.c"
    break;

  case 95: /* expression: disjunction SUB_ASSIGN expression  */
#line 456 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2056 "k0gram.tab.c"
    break;

  case 96: /* expression: disjunction MUL_ASSIGN expression  */
#line 458 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2062 "k0gram.tab.c"
    break;

  case 97: /* expression: disjunction DIV_ASSIGN expression  */
#line 460 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2068 "k0gram.tab.c"
    break;

  case 98: /* expression: disjunction MOD_ASSIGN expression  */
#line 462 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EXPRESSION, "expression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2074 "k0gram.tab.c"
    break;

  case 99: /* disjunction: conjunction  */
#line 467 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2080 "k0gram.tab.c"
    break;

  case 100: /* disjunction: disjunction OR conjunction  */
#line 469 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_DISJUNCTION, "disjunction", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2086 "k0gram.tab.c"
    break;

  case 101: /* conjunction: equality_expr  */
#line 474 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2092 "k0gram.tab.c"
    break;

  case 102: /* conjunction: conjunction AND equality_expr  */
#line 476 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_CONJUNCTION, "conjunction", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2098 "k0gram.tab.c"
    break;

  case 103: /* equality_expr: comparison_expr  */
#line 481 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2104 "k0gram.tab.c"
    break;

  case 104: /* equality_expr: equality_expr EQ comparison_expr  */
#line 483 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2110 "k0gram.tab.c"
    break;

  case 105: /* equality_expr: equality_expr NEQ comparison_expr  */
#line 485 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2116 "k0gram.tab.c"
    break;

  case 106: /* equality_expr: equality_expr REF_EQ comparison_expr  */
#line 487 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2122 "k0gram.tab.c"
    break;

  case 107: /* equality_expr: equality_expr REF_NEQ comparison_expr  */
#line 489 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_EQUALITY_EXPR, "equality_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2128 "k0gram.tab.c"
    break;

  case 108: /* comparison_expr: infix_operation  */
#line 494 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2134 "k0gram.tab.c"
    break;

  case 109: /* comparison_expr: comparison_expr LANGLE infix_operation  */
#line 496 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2140 "k0gram.tab.c"
    break;

  case 110: /* comparison_expr: comparison_expr RANGLE infix_operation  */
#line 498 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2146 "k0gram.tab.c"
    break;

  case 111: /* comparison_expr: comparison_expr LTE infix_operation  */
#line 500 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2152 "k0gram.tab.c"
    break;

  case 112: /* comparison_expr: comparison_expr GTE infix_operation  */
#line 502 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_COMPARISON_EXPR, "comparison_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2158 "k0gram.tab.c"
    break;

  case 113: /* infix_operation: elvis_expr  */
#line 507 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2164 "k0gram.tab.c"
    break;

  case 114: /* infix_operation: infix_operation IN elvis_expr  */
#line 509 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_INFIX_OPERATION, "infix_operation", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2170 "k0gram.tab.c"
    break;

  case 115: /* elvis_expr: range_expr  */
#line 514 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2176 "k0gram.tab.c"
    break;

  case 116: /* elvis_expr: elvis_expr ELVIS range_expr  */
#line 516 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_ELVIS_EXPR, "elvis_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2182 "k0gram.tab.c"
    break;

  case 117: /* range_expr: additive_expr  */
#line 521 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2188 "k0gram.tab.c"
    break;

  case 118: /* range_expr: range_expr RANGE additive_expr  */
#line 523 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_RANGE_EXPR, "range_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2194 "k0gram.tab.c"
    break;

  case 119: /* range_expr: range_expr RANGE_UNTIL additive_expr  */
#line 525 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_RANGE_EXPR, "range_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2200 "k0gram.tab.c"
    break;

  case 120: /* additive_expr: multiplicative_expr  */
#line 530 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2206 "k0gram.tab.c"
    break;

  case 121: /* additive_expr: additive_expr ADD multiplicative_expr  */
#line 532 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_ADDITIVE_EXPR, "additive_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2212 "k0gram.tab.c"
    break;

  case 122: /* additive_expr: additive_expr SUB multiplicative_expr  */
#line 534 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_ADDITIVE_EXPR, "additive_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2218 "k0gram.tab.c"
    break;

  case 123: /* multiplicative_expr: as_expr  */
#line 539 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2224 "k0gram.tab.c"
    break;

  case 124: /* multiplicative_expr: multiplicative_expr MUL as_expr  */
#line 541 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_MULTIPLICATIVE_EXPR, "multiplicative_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2230 "k0gram.tab.c"
    break;

  case 125: /* multiplicative_expr: multiplicative_expr DIV as_expr  */
#line 543 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_MULTIPLICATIVE_EXPR, "multiplicative_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2236 "k0gram.tab.c"
    break;

  case 126: /* multiplicative_expr: multiplicative_expr MOD as_expr  */
#line 545 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_MULTIPLICATIVE_EXPR, "multiplicative_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2242 "k0gram.tab.c"
    break;

  case 127: /* as_expr: prefix_expr  */
#line 550 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2248 "k0gram.tab.c"
    break;

  case 128: /* as_expr: as_expr AS type  */
#line 552 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_AS_EXPR, "as_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2254 "k0gram.tab.c"
    break;

  case 129: /* prefix_expr: postfix_expr  */
#line 557 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2260 "k0gram.tab.c"
    break;

  case 130: /* prefix_expr: NOT prefix_expr  */
#line 559 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2266 "k0gram.tab.c"
    break;

  case 131: /* prefix_expr: SUB prefix_expr  */
#line 561 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2272 "k0gram.tab.c"
    break;

  case 132: /* prefix_expr: ADD prefix_expr  */
#line 563 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2278 "k0gram.tab.c"
    break;

  case 133: /* prefix_expr: INCR prefix_expr  */
#line 565 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2284 "k0gram.tab.c"
    break;

  case 134: /* prefix_expr: DECR prefix_expr  */
#line 567 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PREFIX_EXPR, "prefix_expr", 2,  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2290 "k0gram.tab.c"
    break;

  case 135: /* postfix_expr: primary_expr  */
#line 572 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2296 "k0gram.tab.c"
    break;

  case 136: /* postfix_expr: postfix_expr INCR  */
#line 574 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 2, (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2302 "k0gram.tab.c"
    break;

  case 137: /* postfix_expr: postfix_expr DECR  */
#line 576 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 2, (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2308 "k0gram.tab.c"
    break;

  case 138: /* postfix_expr: postfix_expr DOT IDENT  */
#line 578 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2314 "k0gram.tab.c"
    break;

  case 139: /* postfix_expr: postfix_expr SAFE_CALL IDENT  */
#line 580 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2320 "k0gram.tab.c"
    break;

  case 140: /* postfix_expr: postfix_expr DOUBLE_COLON IDENT  */
#line 582 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 3, (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2326 "k0gram.tab.c"
    break;

  case 141: /* postfix_expr: postfix_expr LSQUARE expression RSQUARE  */
#line 584 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 4, (yyvsp[-3].treeptr),  (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2332 "k0gram.tab.c"
    break;

  case 142: /* postfix_expr: postfix_expr LPAREN optional_value_arguments RPAREN  */
#line 586 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_POSTFIX_EXPR, "postfix_expr", 4, (yyvsp[-3].treeptr),  (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2338 "k0gram.tab.c"
    break;

  case 143: /* optional_value_arguments: value_argument_list  */
#line 591 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2344 "k0gram.tab.c"
    break;

  case 144: /* optional_value_arguments: %empty  */
#line 593 "k0gram.y"
        { (yyval.treeptr) = NULL; }
#line 2350 "k0gram.tab.c"
    break;

  case 145: /* value_argument_list: value_argument  */
#line 598 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2356 "k0gram.tab.c"
    break;

  case 146: /* value_argument_list: value_argument_list COMMA value_argument  */
#line 600 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_VALUE_ARGUMENT_LIST, "value_argument_list", 3,
                         (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2363 "k0gram.tab.c"
    break;

  case 147: /* value_argument: expression  */
#line 606 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2369 "k0gram.tab.c"
    break;

  case 148: /* primary_expr: LPAREN expression RPAREN  */
#line 613 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_PRIMARY_EXPR, "primary_expr", 3,
                          (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2376 "k0gram.tab.c"
    break;

  case 149: /* primary_expr: IDENT  */
#line 616 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2382 "k0gram.tab.c"
    break;

  case 150: /* primary_expr: literal  */
#line 618 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2388 "k0gram.tab.c"
    break;

  case 151: /* primary_expr: STRINGLITERAL  */
#line 620 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2394 "k0gram.tab.c"
    break;

  case 152: /* primary_expr: collection_literal  */
#line 622 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2400 "k0gram.tab.c"
    break;

  case 153: /* literal: INTEGERLITERAL  */
#line 626 "k0gram.y"
                       { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2406 "k0gram.tab.c"
    break;

  case 154: /* literal: LONGLITERAL  */
#line 627 "k0gram.y"
                       { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2412 "k0gram.tab.c"
    break;

  case 155: /* literal: REALLITERAL  */
#line 628 "k0gram.y"
                       { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2418 "k0gram.tab.c"
    break;

  case 156: /* literal: DOUBLELITERAL  */
#line 629 "k0gram.y"
                       { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2424 "k0gram.tab.c"
    break;

  case 157: /* literal: BOOLEANLITERAL  */
#line 630 "k0gram.y"
                       { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2430 "k0gram.tab.c"
    break;

  case 158: /* literal: CHARACTERLITERAL  */
#line 631 "k0gram.y"
                       { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2436 "k0gram.tab.c"
    break;

  case 159: /* literal: NULLLITERAL  */
#line 632 "k0gram.y"
                       { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2442 "k0gram.tab.c"
    break;

  case 160: /* collection_literal: LSQUARE RSQUARE  */
#line 637 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_COLLECTION_LITERAL, "collection_literal", 2,
                          (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2449 "k0gram.tab.c"
    break;

  case 161: /* collection_literal: LSQUARE collection_items RSQUARE  */
#line 640 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_COLLECTION_LITERAL, "collection_literal", 3,
                          (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),  (yyvsp[0].treeptr)); }
#line 2456 "k0gram.tab.c"
    break;

  case 162: /* collection_items: expression  */
#line 646 "k0gram.y"
        { (yyval.treeptr) = (yyvsp[0].treeptr); }
#line 2462 "k0gram.tab.c"
    break;

  case 163: /* collection_items: collection_items COMMA expression  */
#line 648 "k0gram.y"
        { (yyval.treeptr) = alloktree(R_COLLECTION_ITEMS, "collection_items", 3,
                         (yyvsp[-2].treeptr),  (yyvsp[-1].treeptr), (yyvsp[0].treeptr)); }
#line 2469 "k0gram.tab.c"
    break;


#line 2473 "k0gram.tab.c"

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

#line 652 "k0gram.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s:%d: syntax error: %s\n",
            current_filename ? current_filename : "stdin", lineno, s);
}

int main(int argc, char *argv[]) {
    extern FILE *yyin;

    /* ── Parse command-line flags ──────────────────────────────────── */
    int do_tree   = 0;
    int do_symtab = 0;
    int first_file = -1;   /* index of first non-flag argument */

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-tree")   == 0) { do_tree   = 1; continue; }
        if (strcmp(argv[i], "-symtab") == 0) { do_symtab = 1; continue; }
        if (first_file < 0) first_file = i;
    }

    if (first_file < 0) {
        fprintf(stderr, "usage: k0 [-tree] [-symtab] <file.kt>\n");
        return 1;
    }

    /* ── Process each source file ──────────────────────────────────── */
    int exit_status = 0;

    for (int i = first_file; i < argc; i++) {
        if (argv[i][0] == '-') continue;   /* skip flags */

        /* Print filename as required by the spec */
        printf("%s\n", argv[i]);

        yyin = fopen(argv[i], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file: %s\n", argv[i]);
            exit_status = 1;
            continue;
        }
        current_filename = argv[i];

        /* Reset parser state for this file */
        parseroot = NULL;

        int result = yyparse();

        if (result != 0) {
            /* Syntax error -- yyerror already printed the message */
            fclose(yyin);
            exit_status = 2;
            continue;
        }

        if (!parseroot) { fclose(yyin); continue; }

        /* ── Optional tree print ─────────────────────────────────── */
        if (do_tree)
            treeprint(parseroot, 0);

        /* ── Build symbol tables (always -- needed for error checking) */
        SymbolTable global = buildsyms(parseroot);

        /* ── Undeclared variable checking ────────────────────────── */
        checksyms(parseroot, global);

        /* ── Output ──────────────────────────────────────────────── */
        if (semantic_errors > 0) {
            /* Errors already printed to stderr by insertsym/checksyms */
            if (exit_status < 3) exit_status = 3;
        } else if (do_symtab) {
            printsyms_all(global);
        } else {
            printf("No errors\n");
        }

        treefree(parseroot);
        fclose(yyin);
    }

    return exit_status;
}
