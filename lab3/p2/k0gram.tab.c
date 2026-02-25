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

extern int yylex(void);
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
  YYSYMBOL_block = 93,                     /* block  */
  YYSYMBOL_statements = 94,                /* statements  */
  YYSYMBOL_statement_list = 95,            /* statement_list  */
  YYSYMBOL_statement = 96,                 /* statement  */
  YYSYMBOL_loop_statement = 97,            /* loop_statement  */
  YYSYMBOL_for_statement = 98,             /* for_statement  */
  YYSYMBOL_optional_control_structure_body = 99, /* optional_control_structure_body  */
  YYSYMBOL_while_statement = 100,          /* while_statement  */
  YYSYMBOL_do_while_statement = 101,       /* do_while_statement  */
  YYSYMBOL_control_structure_body = 102,   /* control_structure_body  */
  YYSYMBOL_simple_statement = 103,         /* simple_statement  */
  YYSYMBOL_return_statement = 104,         /* return_statement  */
  YYSYMBOL_break_statement = 105,          /* break_statement  */
  YYSYMBOL_continue_statement = 106,       /* continue_statement  */
  YYSYMBOL_if_expression = 107,            /* if_expression  */
  YYSYMBOL_when_expression = 108,          /* when_expression  */
  YYSYMBOL_when_entry_list = 109,          /* when_entry_list  */
  YYSYMBOL_when_entry = 110,               /* when_entry  */
  YYSYMBOL_when_condition_list = 111,      /* when_condition_list  */
  YYSYMBOL_when_condition = 112,           /* when_condition  */
  YYSYMBOL_expression = 113,               /* expression  */
  YYSYMBOL_disjunction = 114,              /* disjunction  */
  YYSYMBOL_conjunction = 115,              /* conjunction  */
  YYSYMBOL_equality_expr = 116,            /* equality_expr  */
  YYSYMBOL_comparison_expr = 117,          /* comparison_expr  */
  YYSYMBOL_infix_operation = 118,          /* infix_operation  */
  YYSYMBOL_elvis_expr = 119,               /* elvis_expr  */
  YYSYMBOL_range_expr = 120,               /* range_expr  */
  YYSYMBOL_additive_expr = 121,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 122,      /* multiplicative_expr  */
  YYSYMBOL_as_expr = 123,                  /* as_expr  */
  YYSYMBOL_prefix_expr = 124,              /* prefix_expr  */
  YYSYMBOL_postfix_expr = 125,             /* postfix_expr  */
  YYSYMBOL_optional_value_arguments = 126, /* optional_value_arguments  */
  YYSYMBOL_value_argument_list = 127,      /* value_argument_list  */
  YYSYMBOL_value_argument = 128,           /* value_argument  */
  YYSYMBOL_primary_expr = 129,             /* primary_expr  */
  YYSYMBOL_literal = 130,                  /* literal  */
  YYSYMBOL_collection_literal = 131,       /* collection_literal  */
  YYSYMBOL_collection_items = 132          /* collection_items  */
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
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

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
       0,    53,    53,    57,    58,    62,    63,    67,    68,    72,
      73,    77,    78,    84,    85,    90,    94,    95,    99,   100,
     104,   105,   109,   110,   114,   115,   119,   120,   125,   126,
     127,   131,   132,   136,   137,   143,   144,   150,   161,   163,
     164,   168,   169,   174,   175,   176,   177,   178,   179,   185,
     186,   187,   191,   192,   196,   197,   201,   202,   206,   211,
     212,   216,   217,   218,   219,   220,   226,   227,   230,   231,
     236,   237,   238,   242,   243,   247,   248,   252,   253,   254,
     255,   259,   260,   264,   270,   271,   272,   273,   274,   275,
     276,   280,   281,   285,   286,   290,   291,   292,   293,   294,
     298,   299,   300,   301,   302,   306,   307,   311,   312,   316,
     317,   318,   322,   323,   324,   328,   329,   330,   331,   335,
     336,   340,   341,   342,   343,   344,   345,   349,   350,   351,
     352,   353,   354,   355,   356,   360,   361,   365,   366,   370,
     371,   377,   378,   379,   380,   381,   382,   383,   387,   388,
     389,   390,   391,   392,   393,   397,   398,   402,   403
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
  "optional_type_annotation", "optional_initializer", "type", "block",
  "statements", "statement_list", "statement", "loop_statement",
  "for_statement", "optional_control_structure_body", "while_statement",
  "do_while_statement", "control_structure_body", "simple_statement",
  "return_statement", "break_statement", "continue_statement",
  "if_expression", "when_expression", "when_entry_list", "when_entry",
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

#define YYPACT_NINF (-228)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -228,    28,    17,  -228,    54,  -228,    73,  -228,     4,    75,
      78,    94,   108,  -228,    62,  -228,  -228,   106,  -228,    96,
      81,    81,   128,  -228,  -228,   -20,    92,   145,   149,   149,
      81,   121,  -228,   -31,  -228,   145,    -5,   134,  -228,   382,
    -228,  -228,   149,   145,  -228,   164,  -228,   382,   139,  -228,
    -228,  -228,  -228,   136,    39,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,   382,   382,   382,   382,   382,   382,
     196,  -228,  -228,   395,   147,   146,    88,    95,   187,   154,
     -19,    85,    56,   210,  -228,    43,  -228,  -228,  -228,  -228,
     186,  -228,   395,   172,   175,   382,  -228,  -228,   253,  -228,
     183,   178,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
     395,   382,   382,  -228,  -228,  -228,  -228,  -228,  -228,   -11,
    -228,   395,   113,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   145,  -228,
    -228,   218,   425,   382,   219,   221,   382,   382,   222,   395,
    -228,  -228,   242,  -228,  -228,  -228,  -228,  -228,   395,  -228,
     139,    11,   152,   296,  -228,  -228,   382,   395,   395,   395,
     395,   395,   395,   146,    88,    95,    95,    95,    95,   187,
     187,   187,   187,   154,   -19,    85,    85,    56,    56,   210,
     210,   210,  -228,  -228,   223,   395,   194,   191,  -228,   -17,
    -228,  -228,   395,   209,    -8,   198,  -228,   253,   197,   193,
    -228,  -228,   -38,  -228,   395,   395,   382,  -228,   425,  -228,
      40,   382,   145,   382,   262,  -228,   253,   382,   253,   395,
    -228,  -228,  -228,   266,   256,   309,   253,   339,   205,  -228,
     215,   253,   382,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
     352,   253,  -228
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    10,     1,     0,     3,     2,     7,     5,     0,
       0,     0,     0,     9,    11,    13,    14,     0,     6,     0,
      32,    32,     0,    12,     8,     0,    17,     0,    34,    34,
      32,     0,    20,     0,    22,     0,    19,    35,    31,     0,
      28,    29,    34,     0,    21,     0,    16,     0,    38,    15,
      18,    26,    36,     0,     0,   148,   149,   150,   151,   152,
     153,   144,   154,   142,     0,     0,     0,     0,     0,     0,
       0,   146,   147,    33,    84,    91,    93,    95,   100,   105,
     107,   109,   112,   115,   119,   121,   127,   143,   145,    30,
      24,    23,    27,     0,     0,    66,    68,    69,     0,    43,
       0,    39,    41,    44,    49,    50,    51,    46,    47,    48,
      45,     0,     0,    76,   124,   123,   125,   126,   122,     0,
     155,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
     129,     0,   136,     0,     0,     0,     0,     0,     0,    67,
      59,    61,     0,    54,    60,    63,    64,    65,    62,    37,
      40,     0,     0,     0,   141,   156,     0,    85,    86,    87,
      88,    89,    90,    92,    94,    96,    97,    98,    99,   104,
     103,   101,   102,   106,   108,   110,   111,   113,   114,   116,
     117,   118,   120,   131,   142,   140,     0,   135,   137,     0,
     130,   132,    25,     0,     0,     0,    42,     0,     0,     0,
      73,    75,     0,    81,    83,   158,     0,   134,     0,   133,
       0,     0,     0,     0,    70,    76,     0,     0,     0,   139,
     138,    57,    56,     0,     0,     0,     0,     0,    79,    82,
      77,    55,     0,    58,    71,    72,    74,    80,    78,    52,
       0,    55,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -228,  -228,  -228,  -228,  -228,  -228,  -228,   276,  -228,  -228,
    -228,  -228,  -228,   238,  -228,  -228,     5,    29,   -33,   248,
    -228,  -228,   115,   -47,  -228,  -227,  -228,  -228,  -114,  -228,
     -45,   -44,   -43,    44,  -228,    51,  -228,  -228,    52,   -39,
    -228,   162,   170,    72,    89,   166,   161,    70,    90,   -37,
     103,  -228,  -228,  -228,    79,  -228,  -228,  -228,  -228
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     8,     6,    13,    99,    15,    36,
      49,    26,    33,    34,    50,    16,    28,    40,    38,   160,
     100,   101,   102,   161,   104,   162,   105,   106,   163,   164,
     165,   166,   167,    71,    72,   173,   221,   222,   223,   168,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   206,   207,   208,    86,    87,    88,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   103,    46,   107,   108,   109,   231,    31,    92,   110,
      90,   123,   124,   125,   126,   127,   128,   123,   124,   125,
     126,   127,   128,    47,   259,   237,    29,    44,     3,   238,
     119,   121,    45,     4,   262,    42,   141,   142,    32,   123,
     124,   125,   126,   127,   128,   229,    53,   174,    93,    94,
      95,    96,    97,    54,    48,    98,   159,   232,    41,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    17,   217,
      18,    89,   171,   172,    64,    65,     9,    10,    11,    66,
      67,     7,   149,   150,   177,   178,   179,   180,   181,   182,
      12,    68,   145,   146,   147,   151,   112,    69,   113,    48,
     152,    70,    19,   234,   153,    20,   241,   154,   199,   200,
     201,   155,    22,   205,   209,   202,   242,   212,   213,   143,
     144,    21,   248,   103,   250,   107,   108,   109,    23,   131,
     132,   110,   254,    24,   224,   133,   134,   225,   135,   136,
     137,   138,     9,    10,    11,    53,    27,    93,    94,    95,
      96,    97,    54,    25,    98,    30,    12,    35,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   114,   115,   116,
     117,   118,    37,    64,    65,   175,   176,    39,    66,    67,
     123,   124,   125,   126,   127,   128,    43,   239,    52,   205,
      68,    31,   243,   111,   245,   130,    69,   129,   224,   244,
      70,   139,    53,   185,   186,   187,   188,   140,   224,    54,
     218,   195,   196,   260,   156,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   189,   190,   191,   192,   148,   157,
      64,    65,   158,   197,   198,    66,    67,   123,   124,   125,
     126,   127,   128,   169,   170,   203,   210,    68,   211,   214,
     215,   226,   227,    69,   228,   233,   235,    70,   120,    53,
     236,    93,    94,    95,    96,    97,    54,   230,    98,   246,
     252,   257,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   258,    14,    91,    51,   216,   247,    64,    65,   249,
     255,   183,    66,    67,   123,   124,   125,   126,   127,   128,
     184,   194,    53,   219,    68,   193,     0,   240,     0,    54,
      69,     0,    48,     0,    70,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   251,     0,     0,     0,     0,     0,
      64,    65,     0,     0,     0,    66,    67,   123,   124,   125,
     126,   127,   128,     0,     0,    53,   219,    68,     0,     0,
       0,     0,    54,    69,     0,     0,   220,    70,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   253,     0,     0,
       0,     0,     0,    64,    65,     0,     0,     0,    66,    67,
     123,   124,   125,   126,   127,   128,     0,     0,    53,     0,
      68,     0,     0,     0,     0,    54,    69,     0,     0,   256,
      70,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     261,     0,     0,     0,     0,     0,    64,    65,     0,     0,
       0,    66,    67,   123,   124,   125,   126,   127,   128,     0,
       0,    53,     0,    68,     0,     0,     0,     0,    54,    69,
       0,     0,     0,    70,    55,    56,    57,    58,    59,    60,
      61,    62,   204,     0,     0,     0,     0,     0,     0,    64,
      65,     0,     0,     0,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,    69,     0,     0,     0,    70
};

static const yytype_int16 yycheck[] =
{
      39,    48,    35,    48,    48,    48,    14,    27,    47,    48,
      43,    28,    29,    30,    31,    32,    33,    28,    29,    30,
      31,    32,    33,    28,   251,    63,    21,    58,     0,    67,
      69,    70,    63,    16,   261,    30,    55,    56,    58,    28,
      29,    30,    31,    32,    33,    62,     6,    58,     8,     9,
      10,    11,    12,    13,    59,    15,    95,    65,    29,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    64,    58,
      66,    42,   111,   112,    34,    35,     3,     4,     5,    39,
      40,    27,    39,    40,   123,   124,   125,   126,   127,   128,
      17,    51,    36,    37,    38,    52,    57,    57,    59,    59,
      57,    61,    27,   217,    61,    27,    66,    64,   145,   146,
     147,    68,     4,   152,   153,   148,   230,   156,   157,    34,
      35,    27,   236,   170,   238,   170,   170,   170,    66,    41,
      42,   170,   246,    27,   173,    47,    48,   176,    43,    44,
      45,    46,     3,     4,     5,     6,    65,     8,     9,    10,
      11,    12,    13,    57,    15,    27,    17,    65,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    64,    65,    66,
      67,    68,    27,    34,    35,    62,    63,    28,    39,    40,
      28,    29,    30,    31,    32,    33,    65,   226,    54,   228,
      51,    27,   231,    57,   233,    49,    57,    50,   237,   232,
      61,    14,     6,   131,   132,   133,   134,    53,   247,    13,
      58,   141,   142,   252,    28,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   135,   136,   137,   138,    18,    57,
      34,    35,    57,   143,   144,    39,    40,    28,    29,    30,
      31,    32,    33,    60,    66,    27,    27,    51,    27,    27,
       8,    28,    58,    57,    63,    57,    59,    61,    62,     6,
      67,     8,     9,    10,    11,    12,    13,    58,    15,     7,
      14,    66,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    66,     6,    45,    36,   170,   235,    34,    35,   237,
     246,   129,    39,    40,    28,    29,    30,    31,    32,    33,
     130,   140,     6,     7,    51,   139,    -1,   228,    -1,    13,
      57,    -1,    59,    -1,    61,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    58,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    -1,    39,    40,    28,    29,    30,
      31,    32,    33,    -1,    -1,     6,     7,    51,    -1,    -1,
      -1,    -1,    13,    57,    -1,    -1,    60,    61,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    58,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    39,    40,
      28,    29,    30,    31,    32,    33,    -1,    -1,     6,    -1,
      51,    -1,    -1,    -1,    -1,    13,    57,    -1,    -1,    60,
      61,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      58,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    39,    40,    28,    29,    30,    31,    32,    33,    -1,
      -1,     6,    -1,    51,    -1,    -1,    -1,    -1,    13,    57,
      -1,    -1,    -1,    61,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,    76,     0,    16,    77,    79,    27,    78,     3,
       4,     5,    17,    80,    81,    82,    89,    64,    66,    27,
      27,    27,     4,    66,    27,    57,    85,    65,    90,    90,
      27,    27,    58,    86,    87,    65,    83,    27,    92,    28,
      91,    91,    90,    65,    58,    63,    92,    28,    59,    84,
      88,    93,    54,     6,    13,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    34,    35,    39,    40,    51,    57,
      61,   107,   108,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   129,   130,   131,    91,
      92,    87,   113,     8,     9,    10,    11,    12,    15,    81,
      94,    95,    96,    97,    98,   100,   101,   104,   105,   106,
     113,    57,    57,    59,   124,   124,   124,   124,   124,   113,
      62,   113,   132,    28,    29,    30,    31,    32,    33,    50,
      49,    41,    42,    47,    48,    43,    44,    45,    46,    14,
      53,    55,    56,    34,    35,    36,    37,    38,    18,    39,
      40,    52,    57,    61,    64,    68,    28,    57,    57,   113,
      93,    97,    99,   102,   103,   104,   105,   106,   113,    60,
      66,   113,   113,   109,    58,    62,    63,   113,   113,   113,
     113,   113,   113,   115,   116,   117,   117,   117,   117,   118,
     118,   118,   118,   119,   120,   121,   121,   122,   122,   123,
     123,   123,    92,    27,    27,   113,   126,   127,   128,   113,
      27,    27,   113,   113,    27,     8,    96,    58,    58,     7,
      60,   110,   111,   112,   113,   113,    28,    58,    63,    62,
      58,    14,    65,    57,   102,    59,    67,    63,    67,   113,
     128,    66,   102,   113,    92,   113,     7,   109,   102,   112,
     102,    58,    14,    58,   102,   107,    60,    66,    66,    99,
     113,    58,    99
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    94,    94,
      94,    95,    95,    96,    96,    96,    96,    96,    96,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   102,
     102,   103,   103,   103,   103,   103,   104,   104,   105,   106,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     110,   111,   111,   112,   113,   113,   113,   113,   113,   113,
     113,   114,   114,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   120,   121,   121,   121,   122,   122,   122,   122,   123,
     123,   124,   124,   124,   124,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   129,   129,   129,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   131,   131,   132,   132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     3,     1,     3,     2,
       0,     1,     2,     1,     1,     5,     2,     0,     1,     0,
       2,     3,     1,     3,     3,     5,     1,     2,     4,     4,
       5,     2,     0,     2,     0,     1,     2,     3,     0,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     7,     9,     1,     0,     5,     5,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       5,     7,     7,     4,     7,     2,     0,     3,     4,     3,
       4,     1,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     1,     2,     2,     2,     2,     2,     1,     2,     2,
       3,     3,     3,     4,     4,     1,     0,     1,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     3
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

#line 1446 "k0gram.tab.c"

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

#line 406 "k0gram.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", lineno, s);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        extern FILE *yyin;
        extern char *current_filename;
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file: %s\n", argv[1]);
            return 1;
        }
        current_filename = argv[1];
    }
    return yyparse();
}
