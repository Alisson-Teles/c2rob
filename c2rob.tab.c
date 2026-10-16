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
#line 2 "c2rob.y"

#include "nodes.h"
#include "while_support.h"

int yyerror(const char *s);
int yylex(void);
int errorcount = 0;
int current_unamed_arg = 0;
extern bool force_print_tree;

#line 82 "c2rob.tab.c"

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

#include "c2rob.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_IDENT = 3,                  /* TOK_IDENT  */
  YYSYMBOL_TOK_ATTRIBUTION = 4,            /* TOK_ATTRIBUTION  */
  YYSYMBOL_TOK_FLOAT = 5,                  /* TOK_FLOAT  */
  YYSYMBOL_TOK_INT = 6,                    /* TOK_INT  */
  YYSYMBOL_TOK_OR = 7,                     /* TOK_OR  */
  YYSYMBOL_TOK_AND = 8,                    /* TOK_AND  */
  YYSYMBOL_TOK_CHAR = 9,                   /* TOK_CHAR  */
  YYSYMBOL_TOK_CMP_EQNEQ = 10,             /* TOK_CMP_EQNEQ  */
  YYSYMBOL_TOK_CMP_RELAT = 11,             /* TOK_CMP_RELAT  */
  YYSYMBOL_TOK_UNARY_OPERATOR = 12,        /* TOK_UNARY_OPERATOR  */
  YYSYMBOL_TOK_STRING = 13,                /* TOK_STRING  */
  YYSYMBOL_TOK_IF = 14,                    /* TOK_IF  */
  YYSYMBOL_TOK_ELSE = 15,                  /* TOK_ELSE  */
  YYSYMBOL_TOK_FOR = 16,                   /* TOK_FOR  */
  YYSYMBOL_TOK_WHILE = 17,                 /* TOK_WHILE  */
  YYSYMBOL_TOK_RETURN = 18,                /* TOK_RETURN  */
  YYSYMBOL_TOK_UNSUPPORTED = 19,           /* TOK_UNSUPPORTED  */
  YYSYMBOL_TOK_INTEGER_LITERAL = 20,       /* TOK_INTEGER_LITERAL  */
  YYSYMBOL_TOK_INCLUDE = 21,               /* TOK_INCLUDE  */
  YYSYMBOL_TOK_STRUCT = 22,                /* TOK_STRUCT  */
  YYSYMBOL_TOK_TYPEDEF = 23,               /* TOK_TYPEDEF  */
  YYSYMBOL_TOK_STATIC = 24,                /* TOK_STATIC  */
  YYSYMBOL_TOK_VOLATILE = 25,              /* TOK_VOLATILE  */
  YYSYMBOL_TOK_CONST = 26,                 /* TOK_CONST  */
  YYSYMBOL_27_ = 27,                       /* '|'  */
  YYSYMBOL_28_ = 28,                       /* '^'  */
  YYSYMBOL_29_ = 29,                       /* '&'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_UMINUS = 35,                    /* UMINUS  */
  YYSYMBOL_36_ = 36,                       /* '!'  */
  YYSYMBOL_37_ = 37,                       /* '~'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_48_ = 48,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_globals = 51,                   /* globals  */
  YYSYMBOL_global = 52,                    /* global  */
  YYSYMBOL_qualifiers = 53,                /* qualifiers  */
  YYSYMBOL_qualifier = 54,                 /* qualifier  */
  YYSYMBOL_include = 55,                   /* include  */
  YYSYMBOL_typedef_decl = 56,              /* typedef_decl  */
  YYSYMBOL_typedef_names = 57,             /* typedef_names  */
  YYSYMBOL_struct_decl = 58,               /* struct_decl  */
  YYSYMBOL_struct_fields = 59,             /* struct_fields  */
  YYSYMBOL_struct_field = 60,              /* struct_field  */
  YYSYMBOL_func_decl = 61,                 /* func_decl  */
  YYSYMBOL_func_impl = 62,                 /* func_impl  */
  YYSYMBOL_optional_func_args = 63,        /* optional_func_args  */
  YYSYMBOL_func_args = 64,                 /* func_args  */
  YYSYMBOL_pointer_arg = 65,               /* pointer_arg  */
  YYSYMBOL_func_arg = 66,                  /* func_arg  */
  YYSYMBOL_locals = 67,                    /* locals  */
  YYSYMBOL_local = 68,                     /* local  */
  YYSYMBOL_whilestmt = 69,                 /* whilestmt  */
  YYSYMBOL_whilebody = 70,                 /* whilebody  */
  YYSYMBOL_optional_locals = 71,           /* optional_locals  */
  YYSYMBOL_returnstmt = 72,                /* returnstmt  */
  YYSYMBOL_attribution = 73,               /* attribution  */
  YYSYMBOL_forstmt = 74,                   /* forstmt  */
  YYSYMBOL_ifstmt = 75,                    /* ifstmt  */
  YYSYMBOL_elseblock = 76,                 /* elseblock  */
  YYSYMBOL_scalar_init_decl = 77,          /* scalar_init_decl  */
  YYSYMBOL_scalar_decl = 78,               /* scalar_decl  */
  YYSYMBOL_array_init_decl = 79,           /* array_init_decl  */
  YYSYMBOL_array_decl = 80,                /* array_decl  */
  YYSYMBOL_struct_values_decl = 81,        /* struct_values_decl  */
  YYSYMBOL_array_values_decls = 82,        /* array_values_decls  */
  YYSYMBOL_array_values_decl = 83,         /* array_values_decl  */
  YYSYMBOL_array_values = 84,              /* array_values  */
  YYSYMBOL_expr = 85,                      /* expr  */
  YYSYMBOL_factor = 86,                    /* factor  */
  YYSYMBOL_scalar_or_array = 87,           /* scalar_or_array  */
  YYSYMBOL_function_call = 88,             /* function_call  */
  YYSYMBOL_func_call_args = 89             /* func_call_args  */
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

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif /* 1 */

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   679

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,    36,     2,     2,     2,    34,    29,     2,
      38,    39,    32,    30,    44,    31,    48,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    40,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    27,    42,    37,     2,     2,     2,
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
      25,    26,    35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    80,    86,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     110,   115,   121,   122,   123,   124,   127,   134,   139,   144,
     149,   154,   158,   163,   169,   173,   177,   181,   185,   190,
     194,   200,   211,   216,   224,   230,   234,   239,   249,   258,
     264,   275,   279,   286,   292,   298,   300,   305,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   328,   332,   333,   337,   340,   341,   344,   349,
     355,   360,   364,   374,   382,   386,   390,   394,   398,   399,
     402,   407,   412,   417,   422,   426,   430,   432,   437,   443,
     445,   450,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     475,   476,   478,   482,   486,   490,   494,   498,   502,   506,
     510,   514,   518,   522,   527
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "TOK_IDENT", "TOK_ATTRIBUTION",
  "TOK_FLOAT", "TOK_INT", "TOK_OR", "TOK_AND", "TOK_CHAR", "TOK_CMP_EQNEQ",
  "TOK_CMP_RELAT", "TOK_UNARY_OPERATOR", "TOK_STRING", "TOK_IF",
  "TOK_ELSE", "TOK_FOR", "TOK_WHILE", "TOK_RETURN", "TOK_UNSUPPORTED",
  "TOK_INTEGER_LITERAL", "TOK_INCLUDE", "TOK_STRUCT", "TOK_TYPEDEF",
  "TOK_STATIC", "TOK_VOLATILE", "TOK_CONST", "'|'", "'^'", "'&'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "UMINUS", "'!'", "'~'", "'('", "')'", "';'",
  "'{'", "'}'", "':'", "','", "'['", "']'", "'='", "'.'", "$accept",
  "program", "globals", "global", "qualifiers", "qualifier", "include",
  "typedef_decl", "typedef_names", "struct_decl", "struct_fields",
  "struct_field", "func_decl", "func_impl", "optional_func_args",
  "func_args", "pointer_arg", "func_arg", "locals", "local", "whilestmt",
  "whilebody", "optional_locals", "returnstmt", "attribution", "forstmt",
  "ifstmt", "elseblock", "scalar_init_decl", "scalar_decl",
  "array_init_decl", "array_decl", "struct_values_decl",
  "array_values_decls", "array_values_decl", "array_values", "expr",
  "factor", "scalar_or_array", "function_call", "func_call_args", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-127)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     601,    39,    18,  -163,  -163,    17,  -163,  -163,  -163,    43,
     545,  -163,   121,  -163,  -163,    60,    61,  -163,    62,    70,
      72,    76,  -163,    82,    89,  -163,   114,   118,  -163,  -163,
       8,  -163,    95,   109,  -163,   116,   122,   126,   129,  -163,
    -163,  -163,  -163,  -163,  -163,   151,   450,   437,   117,   118,
    -163,   177,  -163,  -163,  -163,  -163,  -163,  -163,    34,   373,
     140,   141,  -163,   -10,  -163,  -163,  -163,  -163,   450,   450,
     450,   450,   450,   270,   174,  -163,  -163,   450,  -163,   567,
     151,   185,   422,   115,  -163,   149,  -163,    45,  -163,   158,
     150,   151,   446,   450,   191,  -163,  -163,  -163,  -163,   510,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   162,  -163,     0,   567,   166,   167,   208,   175,
    -163,  -163,  -163,   181,  -163,    67,  -163,   653,  -163,  -163,
     567,    52,   298,  -163,  -163,   581,   606,    75,   329,   618,
     631,   309,    -2,    -2,  -163,  -163,  -163,   179,  -163,   450,
     189,   202,  -163,  -163,   186,  -163,    30,   196,   200,   201,
     450,   476,   653,  -163,  -163,   198,  -163,   203,  -163,  -163,
     206,   209,   210,   214,   230,     5,   217,  -163,   450,   213,
     437,  -163,  -163,   567,   653,   223,  -163,   -11,   450,   145,
     450,   482,   248,   225,   229,   231,   233,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,   258,   450,   450,  -163,   567,   273,
      46,  -163,   237,  -163,   524,   250,   554,  -163,  -163,  -163,
    -163,  -163,   567,   567,  -163,  -163,   247,  -163,   361,   450,
     332,  -163,   653,   277,   496,  -163,   653,  -163,  -163,   211,
     387,  -163,   145,   254,   277,   653,  -163,   268,  -163,  -163,
     242,   413,  -163,   653,  -163,   269,  -163
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    26,    25,     0,    24,    23,    22,     0,
       0,     4,     0,    21,    19,     0,     0,    18,     0,     0,
       0,     0,    55,    92,     0,    30,     0,    27,     1,     3,
       0,    20,     0,     0,    11,     0,     0,     0,     0,    17,
      16,    13,    12,    14,    15,    42,     0,     0,     0,    28,
      29,     0,    10,     9,     6,     5,     7,     8,    47,     0,
       0,    41,    44,   127,   123,   122,   124,   125,     0,     0,
       0,     0,     0,     0,   119,   121,   120,     0,    91,    90,
      42,     0,     0,     0,    33,     0,    51,    45,    48,    49,
      37,     0,     0,     0,     0,   117,   116,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,   126,     0,   101,     0,    92,     0,     0,
      31,    32,    34,    52,    46,    45,    50,    77,    43,   131,
     134,     0,     0,   129,   118,   105,   104,   103,   102,   112,
     113,   111,   106,   107,   108,   109,   110,     0,    99,     0,
      38,     0,    92,    35,     0,    53,   127,     0,     0,     0,
       0,     0,    76,    57,    70,     0,    71,     0,    69,    68,
       0,     0,     0,     0,     0,   121,   120,   132,     0,   128,
       0,    95,    93,   100,    77,     0,    54,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    39,    66,
      63,    62,    64,    65,    81,     0,     0,    67,   133,     0,
       0,    98,     0,    36,     0,     0,     0,    78,    59,    58,
      60,    61,    80,    79,   130,    96,     0,    40,     0,     0,
       0,    97,     0,    84,     0,    75,    77,    74,    72,     0,
       0,    85,     0,     0,    86,     0,    89,     0,    73,    87,
       0,     0,    88,     0,    82,     0,    83
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,   300,   161,    -8,  -163,  -163,   286,  -163,
    -163,   232,   301,   302,   238,  -163,   228,   243,  -156,  -157,
    -163,  -163,  -155,  -163,  -162,  -163,  -163,    77,     3,     2,
       6,     7,  -163,  -163,  -139,  -163,   -46,  -117,   -58,   -32,
    -163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    11,   161,    13,    14,    15,    27,    32,
      83,    84,    16,    17,    60,    61,    88,    62,   162,   163,
     164,   238,   165,   166,   167,   168,   169,   241,   170,   171,
     172,   173,   181,   210,    78,   114,   115,    74,    75,    76,
     131
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    79,    19,    18,    31,   197,    20,    21,   182,   205,
     174,    23,    19,    18,    36,    35,    20,    21,    37,    38,
      25,    23,    95,    96,    97,    98,    99,   215,    92,   212,
     109,   110,   111,   187,    46,    93,    47,    86,    94,    26,
      24,   211,   148,    28,   149,   174,   130,   132,   123,    51,
      24,    31,   206,    85,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    87,   174,    92,   175,
     155,   233,   174,   237,    31,    93,   239,   124,    94,    22,
     247,   243,   197,   246,   119,    85,   103,   231,   225,   250,
     226,   177,    48,   197,   254,   176,   178,   255,   197,   124,
      39,    40,    41,   183,   175,   107,   108,   109,   110,   111,
      42,   174,    43,   174,   191,   174,    44,    25,    81,   174,
      45,    50,   174,   174,    30,   174,   175,    46,   174,    47,
     176,   175,   208,   174,   174,    52,   174,     4,   174,     6,
       7,     8,   214,     4,   216,     6,     7,     8,    63,    53,
      64,    65,   176,    31,    58,    80,    54,   120,    66,   222,
     223,    12,    55,   194,   193,    67,    56,   195,   196,    57,
     175,    12,   175,     4,   175,     6,     7,     8,   175,    90,
      81,   175,   175,   234,   175,    91,   113,   175,   117,   122,
     125,   127,   175,   175,   133,   175,   176,   175,   176,     4,
     176,     6,     7,     8,   176,   150,    59,   176,   176,   147,
     151,   152,    82,   176,   156,   153,    64,    65,   176,   176,
     180,   176,   185,   176,    66,   157,   154,   158,   159,   160,
     184,    67,   186,     4,   188,     6,     7,     8,   189,   190,
     198,    59,   204,   199,    82,   156,   200,    64,    65,   201,
     202,   187,    59,   244,   203,    66,   157,   207,   158,   159,
     160,   209,    67,   213,     4,   218,     6,     7,     8,   219,
    -126,   220,   156,   221,    64,    65,   224,   100,   101,   227,
     102,   103,    66,   157,   252,   158,   159,   160,    77,    67,
     229,     4,   240,     6,     7,     8,   248,   104,   105,   106,
     107,   108,   109,   110,   111,   100,   101,   251,   102,   103,
      29,   256,    49,    33,    34,   121,   112,   126,   116,   102,
     103,   249,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,     0,   128,   156,     0,    64,    65,   107,
     108,   109,   110,   111,   179,    66,   157,     0,   158,   159,
     160,     0,    67,     0,     4,     0,     6,     7,     8,   107,
     108,   109,   110,   111,   156,     0,    64,    65,     0,     0,
       0,     0,   235,   236,    66,   157,    89,   158,   159,   160,
       0,    67,     0,     4,     0,     6,     7,     8,     0,     0,
     156,     0,    64,    65,     0,     4,     0,     6,     7,     8,
      66,   157,   232,   158,   159,   160,     0,    67,     0,     4,
       0,     6,     7,     8,     0,     0,   156,     0,    64,    65,
       0,     0,     0,     0,     0,   118,    66,   157,   245,   158,
     159,   160,     0,    67,     0,     4,     0,     6,     7,     8,
      63,     0,    64,    65,     4,     0,     6,     7,     8,    63,
      66,    64,    65,    63,   253,    64,    65,    67,     0,    66,
       0,     0,     0,    66,     0,     0,    67,    68,    69,     0,
      67,     0,     0,    70,    71,    72,    68,    69,    77,   192,
      68,    69,    70,    71,    72,   129,    70,    71,    72,   100,
     101,     0,   102,   103,     0,     0,     0,     0,     4,     0,
       6,     7,     8,   100,   101,     0,   102,   103,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   100,   101,     0,
     102,   103,   217,   104,   105,   106,   107,   108,   109,   110,
     111,   100,   101,     0,   102,   103,   242,   104,   105,   106,
     107,   108,   109,   110,   111,    -2,     1,     0,     2,   134,
       0,   104,   105,   106,   107,   108,   109,   110,   111,     0,
       0,   100,   101,   228,   102,   103,     3,     4,     5,     6,
       7,     8,     0,     0,   100,   101,     0,   102,   103,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   101,
       0,   102,   103,   230,   104,   105,   106,   107,   108,   109,
     110,   111,     1,     0,     2,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   102,   103,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,   102,   103,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   102,   103,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   111,     0,     0,     0,   156,     0,    64,    65,
     106,   107,   108,   109,   110,   111,    66,   157,     0,   158,
     159,   160,     0,    67,     0,     4,     0,     6,     7,     8
};

static const yytype_int16 yycheck[] =
{
      46,    47,     0,     0,    12,   162,     0,     0,   147,     4,
     127,     3,    10,    10,    12,    12,    10,    10,    12,    12,
       3,     3,    68,    69,    70,    71,    72,   189,    38,   184,
      32,    33,    34,     3,    45,    45,    47,     3,    48,    22,
      32,   180,    42,     0,    44,   162,    92,    93,     3,    41,
      32,    59,    47,    51,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    32,   184,    38,   127,
       3,   228,   189,   230,    82,    45,   232,    32,    48,    40,
     242,   236,   239,   240,    82,    83,    11,   226,    42,   245,
      44,    39,     3,   250,   251,   127,    44,   253,   255,    32,
      40,    40,    40,   149,   162,    30,    31,    32,    33,    34,
      40,   228,    40,   230,   160,   232,    40,     3,     3,   236,
      38,     3,   239,   240,     3,   242,   184,    45,   245,    47,
     162,   189,   178,   250,   251,    40,   253,    22,   255,    24,
      25,    26,   188,    22,   190,    24,    25,    26,     3,    40,
       5,     6,   184,   161,     3,    38,    40,    42,    13,   205,
     206,     0,    40,   161,   161,    20,    40,   161,   161,    40,
     228,    10,   230,    22,   232,    24,    25,    26,   236,    39,
       3,   239,   240,   229,   242,    44,    12,   245,     3,    40,
      32,    41,   250,   251,     3,   253,   228,   255,   230,    22,
     232,    24,    25,    26,   236,    39,    45,   239,   240,    47,
      43,     3,    51,   245,     3,    40,     5,     6,   250,   251,
      41,   253,    20,   255,    13,    14,    45,    16,    17,    18,
      41,    20,    46,    22,    38,    24,    25,    26,    38,    38,
      42,    80,    12,    40,    83,     3,    40,     5,     6,    40,
      40,     3,    91,    42,    40,    13,    14,    40,    16,    17,
      18,    48,    20,    40,    22,    40,    24,    25,    26,    40,
      12,    40,     3,    40,     5,     6,     3,     7,     8,    42,
      10,    11,    13,    14,    42,    16,    17,    18,    41,    20,
      40,    22,    15,    24,    25,    26,    42,    27,    28,    29,
      30,    31,    32,    33,    34,     7,     8,    39,    10,    11,
      10,    42,    26,    12,    12,    83,    46,    89,    80,    10,
      11,   244,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    91,     3,    -1,     5,     6,    30,
      31,    32,    33,    34,    46,    13,    14,    -1,    16,    17,
      18,    -1,    20,    -1,    22,    -1,    24,    25,    26,    30,
      31,    32,    33,    34,     3,    -1,     5,     6,    -1,    -1,
      -1,    -1,    40,    41,    13,    14,     3,    16,    17,    18,
      -1,    20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,
       3,    -1,     5,     6,    -1,    22,    -1,    24,    25,    26,
      13,    14,    41,    16,    17,    18,    -1,    20,    -1,    22,
      -1,    24,    25,    26,    -1,    -1,     3,    -1,     5,     6,
      -1,    -1,    -1,    -1,    -1,     3,    13,    14,    41,    16,
      17,    18,    -1,    20,    -1,    22,    -1,    24,    25,    26,
       3,    -1,     5,     6,    22,    -1,    24,    25,    26,     3,
      13,     5,     6,     3,    41,     5,     6,    20,    -1,    13,
      -1,    -1,    -1,    13,    -1,    -1,    20,    30,    31,    -1,
      20,    -1,    -1,    36,    37,    38,    30,    31,    41,     3,
      30,    31,    36,    37,    38,    39,    36,    37,    38,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    22,    -1,
      24,    25,    26,     7,     8,    -1,    10,    11,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,     7,     8,    -1,
      10,    11,    40,    27,    28,    29,    30,    31,    32,    33,
      34,     7,     8,    -1,    10,    11,    40,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     1,    -1,     3,    39,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,     7,     8,    39,    10,    11,    21,    22,    23,    24,
      25,    26,    -1,    -1,     7,     8,    -1,    10,    11,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,     8,
      -1,    10,    11,    39,    27,    28,    29,    30,    31,    32,
      33,    34,     1,    -1,     3,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    10,    11,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    10,    11,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    10,    11,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,     3,    -1,     5,     6,
      29,    30,    31,    32,    33,    34,    13,    14,    -1,    16,
      17,    18,    -1,    20,    -1,    22,    -1,    24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    21,    22,    23,    24,    25,    26,    50,
      51,    52,    53,    54,    55,    56,    61,    62,    77,    78,
      79,    80,    40,     3,    32,     3,    22,    57,     0,    52,
       3,    54,    58,    61,    62,    77,    78,    79,    80,    40,
      40,    40,    40,    40,    40,    38,    45,    47,     3,    57,
       3,    41,    40,    40,    40,    40,    40,    40,     3,    53,
      63,    64,    66,     3,     5,     6,    13,    20,    30,    31,
      36,    37,    38,    85,    86,    87,    88,    41,    83,    85,
      38,     3,    53,    59,    60,    78,     3,    32,    65,     3,
      39,    44,    38,    45,    48,    85,    85,    85,    85,    85,
       7,     8,    10,    11,    27,    28,    29,    30,    31,    32,
      33,    34,    46,    12,    84,    85,    63,     3,     3,    78,
      42,    60,    40,     3,    32,    32,    65,    41,    66,    39,
      85,    89,    85,     3,    39,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    47,    42,    44,
      39,    43,     3,    40,    45,     3,     3,    14,    16,    17,
      18,    53,    67,    68,    69,    71,    72,    73,    74,    75,
      77,    78,    79,    80,    86,    87,    88,    39,    44,    46,
      41,    81,    83,    85,    41,    20,    46,     3,    38,    38,
      38,    85,     3,    77,    78,    79,    80,    68,    42,    40,
      40,    40,    40,    40,    12,     4,    47,    40,    85,    48,
      82,    83,    71,    40,    85,    73,    85,    40,    40,    40,
      40,    40,    85,    85,     3,    42,    44,    42,    39,    40,
      39,    83,    41,    68,    85,    40,    41,    68,    70,    67,
      15,    76,    40,    71,    42,    41,    68,    73,    42,    76,
      67,    39,    42,    41,    68,    67,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    55,    56,    56,    57,
      57,    58,    59,    59,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    52,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    70,    70,    70,    71,    71,    72,    73,
      73,    73,    74,    74,    75,    75,    75,    75,    76,    76,
      77,    77,    78,    79,    80,    79,    81,    82,    82,    83,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    87,
      87,    88,    88,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       1,     4,     2,     1,     2,     3,     5,     5,     6,     8,
       9,     1,     0,     3,     1,     1,     2,     1,     2,     2,
       3,     2,     3,     4,     5,     2,     2,     1,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     5,     3,     1,     1,     1,     0,     3,     3,
       3,     2,     9,    11,     5,     6,     7,     8,     4,     2,
       4,     4,     2,     7,     5,     7,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     4,     3,
       6,     3,     4,     3,     1
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
        YY_LAC_DISCARD ("YYBACKUP");                              \
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
  switch (yykind)
    {
    case YYSYMBOL_TOK_IDENT: /* TOK_IDENT  */
#line 49 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1013 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_ATTRIBUTION: /* TOK_ATTRIBUTION  */
#line 49 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1019 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_FLOAT: /* TOK_FLOAT  */
#line 51 "c2rob.y"
         { fprintf(yyo, "%lf", ((*yyvaluep).flt)); }
#line 1025 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INT: /* TOK_INT  */
#line 50 "c2rob.y"
         { fprintf(yyo, "%lld", static_cast<long long>(((*yyvaluep).itg))); }
#line 1031 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_CMP_EQNEQ: /* TOK_CMP_EQNEQ  */
#line 49 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1037 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_CMP_RELAT: /* TOK_CMP_RELAT  */
#line 49 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1043 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_UNARY_OPERATOR: /* TOK_UNARY_OPERATOR  */
#line 49 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1049 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_STRING: /* TOK_STRING  */
#line 49 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1055 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INTEGER_LITERAL: /* TOK_INTEGER_LITERAL  */
#line 49 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1061 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INCLUDE: /* TOK_INCLUDE  */
#line 49 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1067 "c2rob.tab.c"
        break;

    case YYSYMBOL_pointer_arg: /* pointer_arg  */
#line 50 "c2rob.y"
         { fprintf(yyo, "%lld", static_cast<long long>(((*yyvaluep).itg))); }
#line 1073 "c2rob.tab.c"
        break;

      default:
        break;
    }
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* program: globals  */
#line 70 "c2rob.y"
                  {
    Node *program = (yyvsp[0].node);

    bool while_valid = errorcount == 0 ? validateWhileProgram(program) : false;
    if (while_valid && (errorcount == 0 || force_print_tree))
        cout << program->toStr(-1);
    
    exit(errorcount != 0 ? EXIT_FAILURE : EXIT_SUCCESS);
}
#line 1951 "c2rob.tab.c"
    break;

  case 3: /* globals: globals global  */
#line 80 "c2rob.y"
                             {
    if ((yyvsp[0].node))
        (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 1961 "c2rob.tab.c"
    break;

  case 4: /* globals: global  */
#line 86 "c2rob.y"
                 {
    Node *n = new Node();
    if ((yyvsp[0].node))
        n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 1972 "c2rob.tab.c"
    break;

  case 5: /* global: qualifiers scalar_decl ';'  */
#line 93 "c2rob.y"
                                            { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 1978 "c2rob.tab.c"
    break;

  case 6: /* global: qualifiers scalar_init_decl ';'  */
#line 94 "c2rob.y"
                                            { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 1984 "c2rob.tab.c"
    break;

  case 7: /* global: qualifiers array_init_decl ';'  */
#line 95 "c2rob.y"
                                            { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 1990 "c2rob.tab.c"
    break;

  case 8: /* global: qualifiers array_decl ';'  */
#line 96 "c2rob.y"
                                            { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 1996 "c2rob.tab.c"
    break;

  case 9: /* global: qualifiers func_decl ';'  */
#line 97 "c2rob.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2002 "c2rob.tab.c"
    break;

  case 10: /* global: qualifiers struct_decl ';'  */
#line 98 "c2rob.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2008 "c2rob.tab.c"
    break;

  case 11: /* global: qualifiers func_impl  */
#line 99 "c2rob.y"
                                            { (yyval.node) = (yyvsp[0].node); }
#line 2014 "c2rob.tab.c"
    break;

  case 20: /* qualifiers: qualifiers qualifier  */
#line 110 "c2rob.y"
                                      {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2023 "c2rob.tab.c"
    break;

  case 21: /* qualifiers: qualifier  */
#line 115 "c2rob.y"
                       {
    Node *n = new Qualifiers();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2033 "c2rob.tab.c"
    break;

  case 22: /* qualifier: TOK_CONST  */
#line 121 "c2rob.y"
                            { (yyval.node) = new Ident("const"); }
#line 2039 "c2rob.tab.c"
    break;

  case 23: /* qualifier: TOK_VOLATILE  */
#line 122 "c2rob.y"
                            { (yyval.node) = new Ident("volatile"); }
#line 2045 "c2rob.tab.c"
    break;

  case 24: /* qualifier: TOK_STATIC  */
#line 123 "c2rob.y"
                            { (yyval.node) = new Ident("static"); }
#line 2051 "c2rob.tab.c"
    break;

  case 25: /* qualifier: TOK_STRUCT  */
#line 124 "c2rob.y"
                            { (yyval.node) = new Ident("struct"); }
#line 2057 "c2rob.tab.c"
    break;

  case 26: /* include: TOK_INCLUDE  */
#line 127 "c2rob.y"
                            {
    string name((yyvsp[0].str));
    size_t start = name.find_first_of("<\"") + 1;
    name = name.substr(start, name.length()-3-start);
    (yyval.node) = new Ident("use " + name + ";\n");
}
#line 2068 "c2rob.tab.c"
    break;

  case 27: /* typedef_decl: TOK_TYPEDEF typedef_names  */
#line 134 "c2rob.y"
                                              {
    declared_typedefs[(yyvsp[0].strings)->getName()] = (yyvsp[0].strings)->getType();
    (yyval.node) = NULL;
}
#line 2077 "c2rob.tab.c"
    break;

  case 28: /* typedef_decl: TOK_TYPEDEF TOK_STRUCT typedef_names  */
#line 139 "c2rob.y"
                                                         {
    declared_typedefs[(yyvsp[0].strings)->getName()] = (yyvsp[0].strings)->getType();
    (yyval.node) = NULL;
}
#line 2086 "c2rob.tab.c"
    break;

  case 29: /* typedef_names: typedef_names TOK_IDENT  */
#line 144 "c2rob.y"
                                                {
    (yyvsp[-1].strings)->strings.push_back((yyvsp[0].str));
    (yyval.strings) = (yyvsp[-1].strings);
}
#line 2095 "c2rob.tab.c"
    break;

  case 30: /* typedef_names: TOK_IDENT  */
#line 149 "c2rob.y"
                              {
    (yyval.strings) = new Strings();
    (yyval.strings)->strings.push_back((yyvsp[0].str));
}
#line 2104 "c2rob.tab.c"
    break;

  case 31: /* struct_decl: TOK_IDENT '{' struct_fields '}'  */
#line 154 "c2rob.y"
                                                    {
    (yyval.node) = new Type((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2112 "c2rob.tab.c"
    break;

  case 32: /* struct_fields: struct_fields struct_field  */
#line 158 "c2rob.y"
                                               {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2121 "c2rob.tab.c"
    break;

  case 33: /* struct_fields: struct_field  */
#line 163 "c2rob.y"
                             {
    Node *n = new TypeFields();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2131 "c2rob.tab.c"
    break;

  case 34: /* struct_field: scalar_decl ';'  */
#line 169 "c2rob.y"
                               {
    (yyval.node) = (yyvsp[-1].node);
}
#line 2139 "c2rob.tab.c"
    break;

  case 35: /* struct_field: qualifiers scalar_decl ';'  */
#line 173 "c2rob.y"
                                          {
    (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node));
}
#line 2147 "c2rob.tab.c"
    break;

  case 36: /* struct_field: TOK_IDENT TOK_IDENT ':' TOK_INTEGER_LITERAL ';'  */
#line 177 "c2rob.y"
                                                                                     {
    (yyval.node) = new VariableDecl((yyvsp[-4].str), (yyvsp[-3].str), atoi((yyvsp[-1].str)));
}
#line 2155 "c2rob.tab.c"
    break;

  case 37: /* func_decl: TOK_IDENT TOK_IDENT '(' optional_func_args ')'  */
#line 181 "c2rob.y"
                                                                       {
    (yyval.node) = new Function((yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2163 "c2rob.tab.c"
    break;

  case 38: /* func_decl: TOK_IDENT '*' TOK_IDENT '(' optional_func_args ')'  */
#line 185 "c2rob.y"
                                                                           {
    (yyval.node) = new Function((yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].node));
    ((Function*)(yyval.node))->markPointerResult();
}
#line 2172 "c2rob.tab.c"
    break;

  case 39: /* func_impl: TOK_IDENT TOK_IDENT '(' optional_func_args ')' '{' optional_locals '}'  */
#line 190 "c2rob.y"
                                                                                               {
    (yyval.node) = new Function((yyvsp[-7].str), (yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
}
#line 2180 "c2rob.tab.c"
    break;

  case 40: /* func_impl: TOK_IDENT '*' TOK_IDENT '(' optional_func_args ')' '{' optional_locals '}'  */
#line 194 "c2rob.y"
                                                                                                   {
    (yyval.node) = new Function((yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    ((Function*)(yyval.node))->markPointerResult();
}
#line 2189 "c2rob.tab.c"
    break;

  case 41: /* optional_func_args: func_args  */
#line 200 "c2rob.y"
                               {
    for (Node *node : (yyvsp[0].node)->getChildren()) {
        auto *arg = static_cast<FuncArg*>(node);

        if (arg->getTypeName() == "void" && !arg->isSourcePointer())
            yyerror("a void parameter cannot have a name or qualifiers");
    }

    (yyval.node) = (yyvsp[0].node);
}
#line 2204 "c2rob.tab.c"
    break;

  case 42: /* optional_func_args: %empty  */
#line 211 "c2rob.y"
                            {
    (yyval.node) = new NodeArgs();
}
#line 2212 "c2rob.tab.c"
    break;

  case 43: /* func_args: func_args ',' func_arg  */
#line 216 "c2rob.y"
                                       {
    if((yyvsp[-2].node)->getChildren().empty() || !(yyvsp[0].node))
        yyerror("void must be the only item in the parameter list");

    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2224 "c2rob.tab.c"
    break;

  case 44: /* func_args: func_arg  */
#line 224 "c2rob.y"
                     {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2234 "c2rob.tab.c"
    break;

  case 45: /* pointer_arg: '*'  */
#line 230 "c2rob.y"
                  {
    (yyval.itg) = 1;
}
#line 2242 "c2rob.tab.c"
    break;

  case 46: /* pointer_arg: '*' '*'  */
#line 234 "c2rob.y"
                      {
    (yyval.itg) = 1;
}
#line 2250 "c2rob.tab.c"
    break;

  case 47: /* func_arg: TOK_IDENT  */
#line 239 "c2rob.y"
                           {
    if(string((yyvsp[0].str)) == "void"){
        (yyval.node) = nullptr;
    }else{
        char unamed[10];
        snprintf(unamed, 10, "_un%d", current_unamed_arg++);
        (yyval.node) = new FuncArg((yyvsp[0].str), unamed);
    }
}
#line 2264 "c2rob.tab.c"
    break;

  case 48: /* func_arg: TOK_IDENT pointer_arg  */
#line 249 "c2rob.y"
                                       {
    char unamed[10];
    snprintf(unamed, 10, "_un%d", current_unamed_arg++);
    string atype = (yyvsp[-1].str);
    if ((atype == "char" || atype == "int32" || atype == "int") && (yyvsp[0].itg) == 1)
        atype.push_back('*');
    (yyval.node) = new FuncArg(atype, unamed, true);
}
#line 2277 "c2rob.tab.c"
    break;

  case 49: /* func_arg: qualifiers TOK_IDENT  */
#line 258 "c2rob.y"
                                      {
    char unamed[10];
    snprintf(unamed, 10, "_un%d", current_unamed_arg++);
    (yyval.node) = new FuncArg((yyvsp[0].str), unamed);
}
#line 2287 "c2rob.tab.c"
    break;

  case 50: /* func_arg: qualifiers TOK_IDENT pointer_arg  */
#line 264 "c2rob.y"
                                                  {
    char unamed[10];
    snprintf(unamed, 10, "_un%d", current_unamed_arg++);
    string atype = (yyvsp[-1].str);
    if ((atype == "char" || atype == "int32" || atype == "int") && (yyvsp[0].itg) == 1)
        atype.push_back('*');
    (yyval.node) = new FuncArg(atype, unamed, true);
}
#line 2300 "c2rob.tab.c"
    break;

  case 51: /* func_arg: TOK_IDENT TOK_IDENT  */
#line 275 "c2rob.y"
                                           {
    (yyval.node) = new FuncArg((yyvsp[-1].str), (yyvsp[0].str));
}
#line 2308 "c2rob.tab.c"
    break;

  case 52: /* func_arg: TOK_IDENT '*' TOK_IDENT  */
#line 279 "c2rob.y"
                                               {
    string atype = (yyvsp[-2].str);
    if (atype == "char" || atype == "int32" || atype == "int")
        atype.push_back('*');
    (yyval.node) = new FuncArg(atype, (yyvsp[0].str), true);
}
#line 2319 "c2rob.tab.c"
    break;

  case 53: /* func_arg: qualifiers TOK_IDENT '*' TOK_IDENT  */
#line 286 "c2rob.y"
                                                          {
    string atype = (yyvsp[-2].str);
    //atype.push_back('*'); //TODO: check what to do with pointers as rob doesn't have them
    (yyval.node) = new FuncArg(atype, (yyvsp[0].str), true);
}
#line 2329 "c2rob.tab.c"
    break;

  case 54: /* func_arg: TOK_IDENT '*' TOK_IDENT '[' ']'  */
#line 292 "c2rob.y"
                                                       {
    string atype = (yyvsp[-4].str);
    //atype.push_back('*'); //TODO: check what to do with pointers as rob doesn't have them
    (yyval.node) = new FuncArg(atype, (yyvsp[-2].str), true); //TODO: need [] or is just main arg?
}
#line 2339 "c2rob.tab.c"
    break;

  case 55: /* global: error ';'  */
#line 298 "c2rob.y"
                   { (yyval.node) = new Node(); }
#line 2345 "c2rob.tab.c"
    break;

  case 56: /* locals: locals local  */
#line 300 "c2rob.y"
                          {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2354 "c2rob.tab.c"
    break;

  case 57: /* locals: local  */
#line 305 "c2rob.y"
               {
    Node *n = new Node();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2364 "c2rob.tab.c"
    break;

  case 58: /* local: qualifiers scalar_decl ';'  */
#line 311 "c2rob.y"
                                        { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2370 "c2rob.tab.c"
    break;

  case 59: /* local: qualifiers scalar_init_decl ';'  */
#line 312 "c2rob.y"
                                        { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2376 "c2rob.tab.c"
    break;

  case 60: /* local: qualifiers array_init_decl ';'  */
#line 313 "c2rob.y"
                                        { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2382 "c2rob.tab.c"
    break;

  case 61: /* local: qualifiers array_decl ';'  */
#line 314 "c2rob.y"
                                        { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2388 "c2rob.tab.c"
    break;

  case 67: /* local: function_call ';'  */
#line 320 "c2rob.y"
                            { ((FunctionCall*)(yyvsp[-1].node))->setInExpr(false); (yyval.node) = (yyvsp[-1].node); }
#line 2394 "c2rob.tab.c"
    break;

  case 72: /* whilestmt: TOK_WHILE '(' expr ')' whilebody  */
#line 328 "c2rob.y"
                                             {
    (yyval.node) = new While((yyvsp[-2].node), (yyvsp[0].node), true);
}
#line 2402 "c2rob.tab.c"
    break;

  case 73: /* whilebody: '{' optional_locals '}'  */
#line 332 "c2rob.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2408 "c2rob.tab.c"
    break;

  case 74: /* whilebody: local  */
#line 333 "c2rob.y"
                  {
              (yyval.node) = new Node();
              (yyval.node)->append((yyvsp[0].node));
          }
#line 2417 "c2rob.tab.c"
    break;

  case 75: /* whilebody: ';'  */
#line 337 "c2rob.y"
                { (yyval.node) = new Node(); }
#line 2423 "c2rob.tab.c"
    break;

  case 76: /* optional_locals: locals  */
#line 340 "c2rob.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2429 "c2rob.tab.c"
    break;

  case 77: /* optional_locals: %empty  */
#line 341 "c2rob.y"
                         { (yyval.node) = new Node(); }
#line 2435 "c2rob.tab.c"
    break;

  case 78: /* returnstmt: TOK_RETURN expr ';'  */
#line 344 "c2rob.y"
                                 {
    (yyval.node) = new Return((yyvsp[-1].node));
}
#line 2443 "c2rob.tab.c"
    break;

  case 79: /* attribution: scalar_or_array '=' expr  */
#line 349 "c2rob.y"
                                       {
    (yyval.node) = new Store((yyvsp[-2].node), "=", (yyvsp[0].node));
}
#line 2451 "c2rob.tab.c"
    break;

  case 80: /* attribution: scalar_or_array TOK_ATTRIBUTION expr  */
#line 355 "c2rob.y"
                                                       {
    (yyval.node) = new Store((yyvsp[-2].node), (yyvsp[-1].str), (yyvsp[0].node));
}
#line 2459 "c2rob.tab.c"
    break;

  case 81: /* attribution: factor TOK_UNARY_OPERATOR  */
#line 360 "c2rob.y"
                                               {
    (yyval.node) = new UnaryAttribution((yyvsp[-1].node), (yyvsp[0].str));
}
#line 2467 "c2rob.tab.c"
    break;

  case 82: /* forstmt: TOK_FOR '(' attribution ';' expr ';' attribution ')' local  */
#line 364 "c2rob.y"
                                                                             {
    Node *nfor = new Container();
    nfor->append((yyvsp[-6].node));
    Node *body = new Node();
    body->append((yyvsp[0].node));
    body->append((yyvsp[-2].node));
    nfor->append(new While((yyvsp[-4].node), body));
    (yyval.node) = nfor;
}
#line 2481 "c2rob.tab.c"
    break;

  case 83: /* forstmt: TOK_FOR '(' attribution ';' expr ';' attribution ')' '{' locals '}'  */
#line 374 "c2rob.y"
                                                                                      {
    Node *nfor = new Container();
    nfor->append((yyvsp[-8].node));
    (yyvsp[-1].node)->append((yyvsp[-4].node));
    nfor->append(new While((yyvsp[-6].node), (yyvsp[-1].node)));
    (yyval.node) = nfor;
}
#line 2493 "c2rob.tab.c"
    break;

  case 84: /* ifstmt: TOK_IF '(' expr ')' local  */
#line 382 "c2rob.y"
                                   {
    (yyval.node) = new IfStmt((yyvsp[-2].node), (yyvsp[0].node));
}
#line 2501 "c2rob.tab.c"
    break;

  case 85: /* ifstmt: TOK_IF '(' expr ')' local elseblock  */
#line 386 "c2rob.y"
                                             {
    (yyval.node) = new IfStmt((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2509 "c2rob.tab.c"
    break;

  case 86: /* ifstmt: TOK_IF '(' expr ')' '{' locals '}'  */
#line 390 "c2rob.y"
                                            {
    (yyval.node) = new IfStmt((yyvsp[-4].node), (yyvsp[-1].node));
}
#line 2517 "c2rob.tab.c"
    break;

  case 87: /* ifstmt: TOK_IF '(' expr ')' '{' locals '}' elseblock  */
#line 394 "c2rob.y"
                                                      {
    (yyval.node) = new IfStmt((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
}
#line 2525 "c2rob.tab.c"
    break;

  case 88: /* elseblock: TOK_ELSE '{' locals '}'  */
#line 398 "c2rob.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2531 "c2rob.tab.c"
    break;

  case 89: /* elseblock: TOK_ELSE local  */
#line 399 "c2rob.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2537 "c2rob.tab.c"
    break;

  case 90: /* scalar_init_decl: TOK_IDENT TOK_IDENT '=' expr  */
#line 402 "c2rob.y"
                                                            {
    (yyval.node) = new VariableDecl((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[0].node));
}
#line 2545 "c2rob.tab.c"
    break;

  case 91: /* scalar_init_decl: TOK_IDENT TOK_IDENT '=' array_values_decl  */
#line 407 "c2rob.y"
                                                                                {
    (yyval.node) = new InitializedType((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[0].node));
}
#line 2553 "c2rob.tab.c"
    break;

  case 92: /* scalar_decl: TOK_IDENT TOK_IDENT  */
#line 412 "c2rob.y"
                                              {
    (yyval.node) = new VariableDecl((yyvsp[-1].str), (yyvsp[0].str));
}
#line 2561 "c2rob.tab.c"
    break;

  case 93: /* array_init_decl: TOK_IDENT TOK_IDENT '[' expr ']' '=' array_values_decl  */
#line 417 "c2rob.y"
                                                                                                 {
    ((NodeArgs*)(yyvsp[0].node))->setArrayInitType((yyvsp[-6].str));
    (yyval.node) = new VariableDecl((yyvsp[-6].str), (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node));
}
#line 2570 "c2rob.tab.c"
    break;

  case 94: /* array_decl: TOK_IDENT TOK_IDENT '[' expr ']'  */
#line 422 "c2rob.y"
                                                               {
    (yyval.node) = new VariableDecl((yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-1].node), nullptr);
}
#line 2578 "c2rob.tab.c"
    break;

  case 95: /* array_init_decl: TOK_IDENT TOK_IDENT '[' expr ']' '=' struct_values_decl  */
#line 426 "c2rob.y"
                                                                                                  {
    (yyval.node) = new StructVariableDecl((yyvsp[-6].str), (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node));
}
#line 2586 "c2rob.tab.c"
    break;

  case 96: /* struct_values_decl: '{' array_values_decls '}'  */
#line 430 "c2rob.y"
                                                      { (yyval.node) = (yyvsp[-1].node); }
#line 2592 "c2rob.tab.c"
    break;

  case 97: /* array_values_decls: array_values_decls ',' array_values_decl  */
#line 432 "c2rob.y"
                                                                  {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2601 "c2rob.tab.c"
    break;

  case 98: /* array_values_decls: array_values_decl  */
#line 437 "c2rob.y"
                                       {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2611 "c2rob.tab.c"
    break;

  case 99: /* array_values_decl: '{' array_values '}'  */
#line 443 "c2rob.y"
                                         { (yyval.node) = (yyvsp[-1].node); }
#line 2617 "c2rob.tab.c"
    break;

  case 100: /* array_values: array_values ',' expr  */
#line 445 "c2rob.y"
                                         {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2626 "c2rob.tab.c"
    break;

  case 101: /* array_values: expr  */
#line 450 "c2rob.y"
                    {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2636 "c2rob.tab.c"
    break;

  case 102: /* expr: expr TOK_CMP_RELAT expr  */
#line 456 "c2rob.y"
                                          { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].str)); }
#line 2642 "c2rob.tab.c"
    break;

  case 103: /* expr: expr TOK_CMP_EQNEQ expr  */
#line 457 "c2rob.y"
                                          { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].str)); }
#line 2648 "c2rob.tab.c"
    break;

  case 104: /* expr: expr TOK_AND expr  */
#line 458 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "and"); }
#line 2654 "c2rob.tab.c"
    break;

  case 105: /* expr: expr TOK_OR expr  */
#line 459 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "or"); }
#line 2660 "c2rob.tab.c"
    break;

  case 106: /* expr: expr '+' expr  */
#line 460 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "+"); }
#line 2666 "c2rob.tab.c"
    break;

  case 107: /* expr: expr '-' expr  */
#line 461 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "-"); }
#line 2672 "c2rob.tab.c"
    break;

  case 108: /* expr: expr '*' expr  */
#line 462 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "*"); }
#line 2678 "c2rob.tab.c"
    break;

  case 109: /* expr: expr '/' expr  */
#line 463 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "/"); }
#line 2684 "c2rob.tab.c"
    break;

  case 110: /* expr: expr '%' expr  */
#line 464 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "%"); }
#line 2690 "c2rob.tab.c"
    break;

  case 111: /* expr: expr '&' expr  */
#line 465 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "&"); }
#line 2696 "c2rob.tab.c"
    break;

  case 112: /* expr: expr '|' expr  */
#line 466 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "|"); }
#line 2702 "c2rob.tab.c"
    break;

  case 113: /* expr: expr '^' expr  */
#line 467 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "^"); }
#line 2708 "c2rob.tab.c"
    break;

  case 114: /* expr: '!' expr  */
#line 468 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "!"); }
#line 2714 "c2rob.tab.c"
    break;

  case 115: /* expr: '~' expr  */
#line 469 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "~"); }
#line 2720 "c2rob.tab.c"
    break;

  case 116: /* expr: '-' expr  */
#line 470 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "-"); }
#line 2726 "c2rob.tab.c"
    break;

  case 117: /* expr: '+' expr  */
#line 471 "c2rob.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2732 "c2rob.tab.c"
    break;

  case 118: /* expr: '(' expr ')'  */
#line 472 "c2rob.y"
                                { (yyval.node) = new Parenthesis((yyvsp[-1].node)); }
#line 2738 "c2rob.tab.c"
    break;

  case 122: /* factor: TOK_INT  */
#line 478 "c2rob.y"
                      {
    (yyval.node) = new Integer((yyvsp[0].itg));
}
#line 2746 "c2rob.tab.c"
    break;

  case 123: /* factor: TOK_FLOAT  */
#line 482 "c2rob.y"
                        {
    (yyval.node) = new Float((yyvsp[0].flt));
}
#line 2754 "c2rob.tab.c"
    break;

  case 124: /* factor: TOK_STRING  */
#line 486 "c2rob.y"
                         {
    (yyval.node) = new Ident((yyvsp[0].str));
}
#line 2762 "c2rob.tab.c"
    break;

  case 125: /* factor: TOK_INTEGER_LITERAL  */
#line 490 "c2rob.y"
                                  {
    (yyval.node) = new IntegerToken((yyvsp[0].str));
}
#line 2770 "c2rob.tab.c"
    break;

  case 126: /* factor: factor TOK_UNARY_OPERATOR  */
#line 494 "c2rob.y"
                                          {
    (yyval.node) = new Unary((yyvsp[-1].node), (yyvsp[0].str));
}
#line 2778 "c2rob.tab.c"
    break;

  case 127: /* scalar_or_array: TOK_IDENT  */
#line 498 "c2rob.y"
                                {
    (yyval.node) = new Ident((yyvsp[0].str));
}
#line 2786 "c2rob.tab.c"
    break;

  case 128: /* scalar_or_array: TOK_IDENT '[' expr ']'  */
#line 502 "c2rob.y"
                                             {
    (yyval.node) = new LoadArray((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2794 "c2rob.tab.c"
    break;

  case 129: /* scalar_or_array: TOK_IDENT '.' TOK_IDENT  */
#line 506 "c2rob.y"
                                                   {
    (yyval.node) = new LoadField((yyvsp[-2].str), (yyvsp[0].str));
}
#line 2802 "c2rob.tab.c"
    break;

  case 130: /* scalar_or_array: TOK_IDENT '[' expr ']' '.' TOK_IDENT  */
#line 510 "c2rob.y"
                                                                {
    (yyval.node) = new LoadArrayField((yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].str));
}
#line 2810 "c2rob.tab.c"
    break;

  case 131: /* function_call: TOK_IDENT '(' ')'  */
#line 514 "c2rob.y"
                                      {
    (yyval.node) = new FunctionCall((yyvsp[-2].str));
}
#line 2818 "c2rob.tab.c"
    break;

  case 132: /* function_call: TOK_IDENT '(' func_call_args ')'  */
#line 518 "c2rob.y"
                                                           {
    (yyval.node) = new FunctionCall((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2826 "c2rob.tab.c"
    break;

  case 133: /* func_call_args: func_call_args ',' expr  */
#line 522 "c2rob.y"
                                             {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2835 "c2rob.tab.c"
    break;

  case 134: /* func_call_args: expr  */
#line 527 "c2rob.y"
                      {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2845 "c2rob.tab.c"
    break;


#line 2849 "c2rob.tab.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 533 "c2rob.y"

