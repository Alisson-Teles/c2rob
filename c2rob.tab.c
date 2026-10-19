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
#include "scope_support.h"
#include "while_support.h"

int yyerror(const char *s);
int yylex(void);
int errorcount = 0;
int current_unamed_arg = 0;
extern bool force_print_tree;

#line 83 "c2rob.tab.c"

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
  YYSYMBOL_multi_decl = 76,                /* multi_decl  */
  YYSYMBOL_multi_declarators = 77,         /* multi_declarators  */
  YYSYMBOL_multi_declarator = 78,          /* multi_declarator  */
  YYSYMBOL_elseblock = 79,                 /* elseblock  */
  YYSYMBOL_scalar_init_decl = 80,          /* scalar_init_decl  */
  YYSYMBOL_scalar_decl = 81,               /* scalar_decl  */
  YYSYMBOL_array_init_decl = 82,           /* array_init_decl  */
  YYSYMBOL_array_decl = 83,                /* array_decl  */
  YYSYMBOL_struct_values_decl = 84,        /* struct_values_decl  */
  YYSYMBOL_array_values_decls = 85,        /* array_values_decls  */
  YYSYMBOL_array_values_decl = 86,         /* array_values_decl  */
  YYSYMBOL_array_values = 87,              /* array_values  */
  YYSYMBOL_expr = 88,                      /* expr  */
  YYSYMBOL_factor = 89,                    /* factor  */
  YYSYMBOL_scalar_or_array = 90,           /* scalar_or_array  */
  YYSYMBOL_function_call = 91,             /* function_call  */
  YYSYMBOL_func_call_args = 92             /* func_call_args  */
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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   773

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  280

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
       0,    72,    72,    83,    89,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   108,   109,   110,   111,   112,   113,
     114,   115,   118,   123,   129,   130,   131,   132,   135,   142,
     147,   152,   157,   162,   166,   171,   177,   181,   185,   189,
     193,   198,   202,   208,   219,   224,   232,   238,   242,   247,
     257,   266,   272,   283,   287,   294,   300,   306,   308,   313,
     319,   320,   321,   322,   323,   324,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   341,   345,   346,   350,
     353,   354,   357,   361,   366,   372,   377,   381,   392,   401,
     405,   409,   413,   418,   438,   444,   450,   454,   458,   462,
     466,   467,   470,   475,   480,   485,   490,   494,   498,   500,
     505,   511,   513,   518,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   543,   544,   546,   550,   554,   558,   562,   566,
     570,   574,   578,   582,   586,   590,   595
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
  "ifstmt", "multi_decl", "multi_declarators", "multi_declarator",
  "elseblock", "scalar_init_decl", "scalar_decl", "array_init_decl",
  "array_decl", "struct_values_decl", "array_values_decls",
  "array_values_decl", "array_values", "expr", "factor", "scalar_or_array",
  "function_call", "func_call_args", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-175)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-139)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     698,   -18,    40,  -175,  -175,    17,  -175,  -175,  -175,    23,
     642,  -175,   147,  -175,  -175,    48,    54,  -175,    58,    61,
      73,    94,    95,  -175,    52,    44,    98,   101,  -175,   148,
     150,  -175,  -175,     8,  -175,   115,   123,  -175,   126,   127,
     136,   137,   140,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
     209,   537,   486,   143,   181,   181,   150,  -175,   386,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,    43,   422,   146,   142,
    -175,    -3,  -175,  -175,  -175,  -175,   537,   537,   537,   537,
     537,   309,   175,  -175,  -175,   537,  -175,   551,   209,     9,
    -175,  -175,   186,   471,    81,  -175,   152,  -175,    55,  -175,
     158,   153,   209,   508,   537,   193,  -175,  -175,  -175,  -175,
     607,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,    53,  -175,    77,   664,   159,   537,   537,
     157,   201,   166,  -175,  -175,  -175,   162,  -175,    70,  -175,
     747,  -175,  -175,   664,   105,   337,  -175,  -175,   678,   703,
     258,   328,   715,   128,    99,     4,     4,  -175,  -175,  -175,
     168,  -175,   537,   169,   346,   664,   191,  -175,  -175,   174,
    -175,    38,   183,   184,   187,   495,   527,   747,  -175,  -175,
     182,  -175,   188,  -175,  -175,   190,   196,   204,   205,   206,
     236,     1,   212,  -175,   537,   207,   486,  -175,   213,   664,
     747,   202,   214,  -175,    10,   537,   499,   537,  -175,   579,
     255,   223,   225,   233,   235,   237,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,   269,   537,   537,  -175,   664,   279,
      78,  -175,   241,   244,  -175,   621,   253,   651,  -175,  -175,
    -175,  -175,  -175,  -175,   664,   664,  -175,  -175,   244,  -175,
    -175,   410,   537,   381,  -175,   747,   285,   593,  -175,   747,
    -175,  -175,   254,   436,  -175,   499,   260,   285,   747,  -175,
     265,  -175,  -175,   281,   462,  -175,   747,  -175,   308,  -175
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    28,    27,     0,    26,    25,    24,     0,
       0,     4,     0,    23,    21,     0,     0,    20,     0,     0,
       0,     0,     0,    57,    96,     0,    93,     0,    32,     0,
      29,     1,     3,     0,    22,     0,     0,    11,     0,     0,
       0,     0,     0,    19,    18,    12,    15,    14,    16,    17,
      44,     0,     0,     0,     0,     0,    30,    31,     0,    10,
       9,    13,     6,     5,     7,     8,    49,     0,     0,    43,
      46,   139,   135,   134,   136,   137,     0,     0,     0,     0,
       0,     0,   131,   133,   132,     0,   103,    97,    44,    96,
      95,    94,     0,     0,     0,    35,     0,    53,    47,    50,
      51,    39,     0,     0,     0,     0,   129,   128,   126,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,   138,     0,   113,     0,     0,     0,
     104,     0,     0,    33,    34,    36,    54,    48,    47,    52,
      81,    45,   143,   146,     0,     0,   141,   130,   117,   116,
     115,   114,   124,   125,   123,   118,   119,   120,   121,   122,
       0,   111,     0,    40,     0,    97,     0,   104,    37,     0,
      55,   139,     0,     0,     0,     0,     0,    80,    59,    74,
       0,    75,     0,    73,    72,     0,     0,     0,     0,     0,
       0,   133,   132,   144,     0,   140,     0,   107,    99,   112,
      81,    98,     0,    56,    96,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,    58,    41,    70,    64,
      67,    66,    68,    69,    86,     0,     0,    71,   145,     0,
       0,   110,     0,     0,    38,     0,     0,     0,    82,    65,
      61,    60,    62,    63,    85,    84,   142,   108,     0,    42,
      99,     0,     0,     0,   109,     0,    89,     0,    79,    81,
      78,    76,     0,     0,    90,     0,     0,    91,     0,   101,
       0,    77,    92,     0,     0,   100,     0,    87,     0,    88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -175,   298,    24,    -8,  -175,  -175,   280,  -175,
    -175,   216,   300,   303,   230,  -175,   227,   229,  -160,  -126,
    -175,  -175,  -170,  -175,  -174,  -175,  -175,     2,  -175,   -45,
      62,     3,    21,     6,     7,  -175,  -175,  -152,  -175,   -51,
     -60,   -36,   -12,  -175
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     9,    10,    11,   176,    13,    14,    15,    30,    35,
      94,    95,    16,    17,    68,    69,    99,    70,   177,   178,
     179,   261,   180,   181,   182,   183,   184,   185,    26,    27,
     264,   186,   187,   188,   189,   197,   230,    86,   125,   126,
      82,    83,    84,   144
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    87,    18,    19,    34,   225,    21,    22,   198,    90,
      91,    24,    18,    19,    38,    39,    21,    22,    41,    42,
      28,    20,    23,    31,    12,   106,   107,   108,   109,   110,
     232,    20,   236,    40,    12,   103,   120,   121,   122,    29,
      25,   204,   104,    24,   231,   105,    97,    53,   226,    58,
    -104,   216,   143,   145,   128,    51,   129,    52,   136,    34,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    25,   170,    67,    98,   103,   164,   165,    96,
     190,   250,    93,   104,    92,    34,   105,   137,    43,   266,
      50,   270,  -104,  -106,    44,   262,   254,    51,    45,    52,
     160,    46,   137,     4,   191,     6,     7,     8,   273,   113,
     114,   199,    67,    47,   132,    96,   278,   190,    93,   161,
     247,   162,   248,   133,   209,   256,    67,   260,   192,   118,
     119,   120,   121,   122,    48,    49,   216,   269,   113,   114,
     190,   191,    54,   228,   193,    55,   190,   216,   277,   194,
      33,    28,   216,    57,   235,    59,   237,   117,   118,   119,
     120,   121,   122,    60,   191,   192,    61,    62,    34,     4,
     191,     6,     7,     8,   244,   245,    63,    64,   211,   212,
      65,    88,   214,   215,    89,   101,   102,   124,   192,   130,
     138,   190,   135,   190,   140,   190,   146,   213,   163,   190,
     166,   257,   190,   190,   167,   190,   168,   169,   190,   196,
     200,   202,    66,   190,   190,   191,   190,   191,   190,   191,
     203,   205,   206,   191,   217,   207,   191,   191,   218,   191,
     219,     4,   191,     6,     7,     8,   220,   191,   191,   192,
     191,   192,   191,   192,   221,   222,   223,   192,   224,   233,
     192,   192,   227,  -105,   234,   229,   192,   171,   204,    72,
      73,   192,   192,   239,   192,   240,   192,    74,   172,   114,
     173,   174,   175,   241,    75,   242,     4,   243,     6,     7,
       8,  -138,   246,   249,   171,    85,    72,    73,   118,   119,
     120,   121,   122,   252,    74,   172,   267,   173,   174,   175,
     263,    75,   271,     4,   274,     6,     7,     8,    32,    56,
     134,   171,    36,    72,    73,    37,   111,   112,   127,   113,
     114,    74,   172,   275,   173,   174,   175,   139,    75,   272,
       4,   141,     6,     7,     8,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   111,   112,     0,   113,   114,     0,
     279,     0,     0,   111,   112,   123,   113,   114,   118,   119,
     120,   121,   122,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,   195,   171,     0,    72,    73,     0,    92,
       0,     0,   201,     0,    74,   172,     0,   173,   174,   175,
       0,    75,     0,     4,     0,     6,     7,     8,     4,     0,
       6,     7,     8,   171,     0,    72,    73,     0,     0,     0,
       0,   258,   259,    74,   172,   100,   173,   174,   175,     0,
      75,     0,     4,     0,     6,     7,     8,     0,     0,   171,
       0,    72,    73,     0,     4,     0,     6,     7,     8,    74,
     172,   255,   173,   174,   175,     0,    75,     0,     4,     0,
       6,     7,     8,     0,     0,   171,     0,    72,    73,     0,
       0,     0,     0,     0,   131,    74,   172,   268,   173,   174,
     175,     0,    75,     0,     4,     0,     6,     7,     8,    71,
       0,    72,    73,     4,     0,     6,     7,     8,    71,    74,
      72,    73,    71,   276,    72,    73,    75,     0,    74,     0,
       0,    71,    74,    72,    73,    75,    76,    77,     0,    75,
       0,    74,    78,    79,    80,    76,    77,    85,    75,     0,
     210,    78,    79,    80,     0,   208,     0,     0,    76,    77,
      71,     0,    72,    73,    78,    79,    80,   142,     0,     4,
      74,     6,     7,     8,     0,     0,     0,    75,   111,   112,
       0,   113,   114,     0,     0,     0,     0,    76,    77,     0,
       0,     0,     0,    78,    79,    80,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   111,   112,     0,   113,
     114,  -102,     0,     0,     0,     0,     0,     0,     0,     0,
     111,   112,     0,   113,   114,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   111,   112,     0,   113,   114,   238,
     115,   116,   117,   118,   119,   120,   121,   122,   111,   112,
       0,   113,   114,   265,   115,   116,   117,   118,   119,   120,
     121,   122,    -2,     1,     0,     2,   147,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,   111,   112,
     251,   113,   114,     3,     4,     5,     6,     7,     8,     0,
       0,   111,   112,     0,   113,   114,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   112,     0,   113,   114,
     253,   115,   116,   117,   118,   119,   120,   121,   122,     1,
       0,     2,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   113,   114,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,   113,   114,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     171,     0,    72,    73,     0,     0,     0,     0,     0,     0,
      74,   172,     0,   173,   174,   175,     0,    75,     0,     4,
       0,     6,     7,     8
};

static const yytype_int16 yycheck[] =
{
      51,    52,     0,     0,    12,     4,     0,     0,   160,    54,
      55,     3,    10,    10,    12,    12,    10,    10,    12,    12,
       3,     0,    40,     0,     0,    76,    77,    78,    79,    80,
     200,    10,   206,    12,    10,    38,    32,    33,    34,    22,
      32,     3,    45,     3,   196,    48,     3,     3,    47,    41,
      40,   177,   103,   104,    45,    45,    47,    47,     3,    67,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    32,     3,    50,    32,    38,   128,   129,    58,
     140,   233,    58,    45,     3,    93,    48,    32,    40,   259,
      38,   265,    40,    40,    40,   255,   248,    45,    40,    47,
      47,    40,    32,    22,   140,    24,    25,    26,   268,    10,
      11,   162,    88,    40,    93,    94,   276,   177,    94,    42,
      42,    44,    44,    42,   175,   251,   102,   253,   140,    30,
      31,    32,    33,    34,    40,    40,   262,   263,    10,    11,
     200,   177,    44,   194,    39,    44,   206,   273,   274,    44,
       3,     3,   278,     3,   205,    40,   207,    29,    30,    31,
      32,    33,    34,    40,   200,   177,    40,    40,   176,    22,
     206,    24,    25,    26,   225,   226,    40,    40,   176,   176,
      40,    38,   176,   176,     3,    39,    44,    12,   200,     3,
      32,   251,    40,   253,    41,   255,     3,   176,    39,   259,
      43,   252,   262,   263,     3,   265,    40,    45,   268,    41,
      41,    20,     3,   273,   274,   251,   276,   253,   278,   255,
      46,    38,    38,   259,    42,    38,   262,   263,    40,   265,
      40,    22,   268,    24,    25,    26,    40,   273,   274,   251,
     276,   253,   278,   255,    40,    40,    40,   259,    12,    47,
     262,   263,    40,    40,    40,    48,   268,     3,     3,     5,
       6,   273,   274,    40,   276,    40,   278,    13,    14,    11,
      16,    17,    18,    40,    20,    40,    22,    40,    24,    25,
      26,    12,     3,    42,     3,    41,     5,     6,    30,    31,
      32,    33,    34,    40,    13,    14,    42,    16,    17,    18,
      15,    20,    42,    22,    39,    24,    25,    26,    10,    29,
      94,     3,    12,     5,     6,    12,     7,     8,    88,    10,
      11,    13,    14,    42,    16,    17,    18,   100,    20,   267,
      22,   102,    24,    25,    26,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,     7,     8,    -1,    10,    11,    -1,
      42,    -1,    -1,     7,     8,    46,    10,    11,    30,    31,
      32,    33,    34,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    46,     3,    -1,     5,     6,    -1,     3,
      -1,    -1,    46,    -1,    13,    14,    -1,    16,    17,    18,
      -1,    20,    -1,    22,    -1,    24,    25,    26,    22,    -1,
      24,    25,    26,     3,    -1,     5,     6,    -1,    -1,    -1,
      -1,    40,    41,    13,    14,     3,    16,    17,    18,    -1,
      20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,     3,
      -1,     5,     6,    -1,    22,    -1,    24,    25,    26,    13,
      14,    41,    16,    17,    18,    -1,    20,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,     3,    -1,     5,     6,    -1,
      -1,    -1,    -1,    -1,     3,    13,    14,    41,    16,    17,
      18,    -1,    20,    -1,    22,    -1,    24,    25,    26,     3,
      -1,     5,     6,    22,    -1,    24,    25,    26,     3,    13,
       5,     6,     3,    41,     5,     6,    20,    -1,    13,    -1,
      -1,     3,    13,     5,     6,    20,    30,    31,    -1,    20,
      -1,    13,    36,    37,    38,    30,    31,    41,    20,    -1,
       3,    36,    37,    38,    -1,    40,    -1,    -1,    30,    31,
       3,    -1,     5,     6,    36,    37,    38,    39,    -1,    22,
      13,    24,    25,    26,    -1,    -1,    -1,    20,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,     7,     8,    -1,    10,
      11,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,    -1,    10,    11,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,     7,     8,    -1,    10,    11,    40,
      27,    28,    29,    30,    31,    32,    33,    34,     7,     8,
      -1,    10,    11,    40,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     1,    -1,     3,    39,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,     7,     8,
      39,    10,    11,    21,    22,    23,    24,    25,    26,    -1,
      -1,     7,     8,    -1,    10,    11,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,     8,    -1,    10,    11,
      39,    27,    28,    29,    30,    31,    32,    33,    34,     1,
      -1,     3,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    10,    11,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    10,    11,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
       3,    -1,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    16,    17,    18,    -1,    20,    -1,    22,
      -1,    24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    21,    22,    23,    24,    25,    26,    50,
      51,    52,    53,    54,    55,    56,    61,    62,    76,    80,
      81,    82,    83,    40,     3,    32,    77,    78,     3,    22,
      57,     0,    52,     3,    54,    58,    61,    62,    76,    80,
      81,    82,    83,    40,    40,    40,    40,    40,    40,    40,
      38,    45,    47,     3,    44,    44,    57,     3,    41,    40,
      40,    40,    40,    40,    40,    40,     3,    53,    63,    64,
      66,     3,     5,     6,    13,    20,    30,    31,    36,    37,
      38,    88,    89,    90,    91,    41,    86,    88,    38,     3,
      78,    78,     3,    53,    59,    60,    81,     3,    32,    65,
       3,    39,    44,    38,    45,    48,    88,    88,    88,    88,
      88,     7,     8,    10,    11,    27,    28,    29,    30,    31,
      32,    33,    34,    46,    12,    87,    88,    63,    45,    47,
       3,     3,    81,    42,    60,    40,     3,    32,    32,    65,
      41,    66,    39,    88,    92,    88,     3,    39,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      47,    42,    44,    39,    88,    88,    43,     3,    40,    45,
       3,     3,    14,    16,    17,    18,    53,    67,    68,    69,
      71,    72,    73,    74,    75,    76,    80,    81,    82,    83,
      89,    90,    91,    39,    44,    46,    41,    84,    86,    88,
      41,    46,    20,    46,     3,    38,    38,    38,    40,    88,
       3,    76,    80,    81,    82,    83,    68,    42,    40,    40,
      40,    40,    40,    40,    12,     4,    47,    40,    88,    48,
      85,    86,    71,    47,    40,    88,    73,    88,    40,    40,
      40,    40,    40,    40,    88,    88,     3,    42,    44,    42,
      86,    39,    40,    39,    86,    41,    68,    88,    40,    41,
      68,    70,    67,    15,    79,    40,    71,    42,    41,    68,
      73,    42,    79,    67,    39,    42,    41,    68,    67,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    54,    54,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    52,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    76,    77,    77,    78,    78,    78,    78,
      79,    79,    80,    80,    81,    82,    83,    82,    84,    85,
      85,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    91,    91,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     2,     2,     2,     2,     2,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     2,     1,     4,     2,     1,     2,     3,     5,     5,
       6,     8,     9,     1,     0,     3,     1,     1,     2,     1,
       2,     2,     3,     2,     3,     4,     5,     2,     2,     1,
       3,     3,     3,     3,     2,     3,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     5,     3,     1,     1,
       1,     0,     3,     2,     3,     3,     2,     9,    11,     5,
       6,     7,     8,     2,     3,     3,     1,     3,     4,     6,
       4,     2,     4,     4,     2,     7,     5,     7,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     3,     6,     3,     4,     3,     1
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
#line 51 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1047 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_ATTRIBUTION: /* TOK_ATTRIBUTION  */
#line 51 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1053 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_FLOAT: /* TOK_FLOAT  */
#line 53 "c2rob.y"
         { fprintf(yyo, "%lf", ((*yyvaluep).flt)); }
#line 1059 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INT: /* TOK_INT  */
#line 52 "c2rob.y"
         { fprintf(yyo, "%lld", static_cast<long long>(((*yyvaluep).itg))); }
#line 1065 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_CMP_EQNEQ: /* TOK_CMP_EQNEQ  */
#line 51 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1071 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_CMP_RELAT: /* TOK_CMP_RELAT  */
#line 51 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1077 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_UNARY_OPERATOR: /* TOK_UNARY_OPERATOR  */
#line 51 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1083 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_STRING: /* TOK_STRING  */
#line 51 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1089 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INTEGER_LITERAL: /* TOK_INTEGER_LITERAL  */
#line 51 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1095 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INCLUDE: /* TOK_INCLUDE  */
#line 51 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1101 "c2rob.tab.c"
        break;

    case YYSYMBOL_pointer_arg: /* pointer_arg  */
#line 52 "c2rob.y"
         { fprintf(yyo, "%lld", static_cast<long long>(((*yyvaluep).itg))); }
#line 1107 "c2rob.tab.c"
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
#line 72 "c2rob.y"
                  {
    Node *program = (yyvsp[0].node);

    bool scope_valid = errorcount == 0 && resolveScopeProgram(program);
    bool while_valid = scope_valid && validateWhileProgram(program);
    if (while_valid && (errorcount == 0 || force_print_tree))
        cout << program->toStr(-1);
    
    exit(errorcount != 0 ? EXIT_FAILURE : EXIT_SUCCESS);
}
#line 1986 "c2rob.tab.c"
    break;

  case 3: /* globals: globals global  */
#line 83 "c2rob.y"
                             {
    if ((yyvsp[0].node))
        (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 1996 "c2rob.tab.c"
    break;

  case 4: /* globals: global  */
#line 89 "c2rob.y"
                 {
    Node *n = new Node();
    if ((yyvsp[0].node))
        n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2007 "c2rob.tab.c"
    break;

  case 5: /* global: qualifiers scalar_decl ';'  */
#line 96 "c2rob.y"
                                            { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2013 "c2rob.tab.c"
    break;

  case 6: /* global: qualifiers scalar_init_decl ';'  */
#line 97 "c2rob.y"
                                            { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2019 "c2rob.tab.c"
    break;

  case 7: /* global: qualifiers array_init_decl ';'  */
#line 98 "c2rob.y"
                                            { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2025 "c2rob.tab.c"
    break;

  case 8: /* global: qualifiers array_decl ';'  */
#line 99 "c2rob.y"
                                            { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2031 "c2rob.tab.c"
    break;

  case 9: /* global: qualifiers func_decl ';'  */
#line 100 "c2rob.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2037 "c2rob.tab.c"
    break;

  case 10: /* global: qualifiers struct_decl ';'  */
#line 101 "c2rob.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 2043 "c2rob.tab.c"
    break;

  case 11: /* global: qualifiers func_impl  */
#line 102 "c2rob.y"
                                            { (yyval.node) = (yyvsp[0].node); }
#line 2049 "c2rob.tab.c"
    break;

  case 13: /* global: qualifiers multi_decl ';'  */
#line 104 "c2rob.y"
                                   {
           for (Node *decl : (yyvsp[-1].node)->getChildren()) preserveWhileQualifiers(decl, (yyvsp[-2].node));
           (yyval.node) = (yyvsp[-1].node);
       }
#line 2058 "c2rob.tab.c"
    break;

  case 22: /* qualifiers: qualifiers qualifier  */
#line 118 "c2rob.y"
                                      {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2067 "c2rob.tab.c"
    break;

  case 23: /* qualifiers: qualifier  */
#line 123 "c2rob.y"
                       {
    Node *n = new Qualifiers();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2077 "c2rob.tab.c"
    break;

  case 24: /* qualifier: TOK_CONST  */
#line 129 "c2rob.y"
                            { (yyval.node) = new Ident("const"); }
#line 2083 "c2rob.tab.c"
    break;

  case 25: /* qualifier: TOK_VOLATILE  */
#line 130 "c2rob.y"
                            { (yyval.node) = new Ident("volatile"); }
#line 2089 "c2rob.tab.c"
    break;

  case 26: /* qualifier: TOK_STATIC  */
#line 131 "c2rob.y"
                            { (yyval.node) = new Ident("static"); }
#line 2095 "c2rob.tab.c"
    break;

  case 27: /* qualifier: TOK_STRUCT  */
#line 132 "c2rob.y"
                            { (yyval.node) = new Ident("struct"); }
#line 2101 "c2rob.tab.c"
    break;

  case 28: /* include: TOK_INCLUDE  */
#line 135 "c2rob.y"
                            {
    string name((yyvsp[0].str));
    size_t start = name.find_first_of("<\"") + 1;
    name = name.substr(start, name.length()-3-start);
    (yyval.node) = new Ident("use " + name + ";\n");
}
#line 2112 "c2rob.tab.c"
    break;

  case 29: /* typedef_decl: TOK_TYPEDEF typedef_names  */
#line 142 "c2rob.y"
                                              {
    declared_typedefs[(yyvsp[0].strings)->getName()] = (yyvsp[0].strings)->getType();
    (yyval.node) = NULL;
}
#line 2121 "c2rob.tab.c"
    break;

  case 30: /* typedef_decl: TOK_TYPEDEF TOK_STRUCT typedef_names  */
#line 147 "c2rob.y"
                                                         {
    declared_typedefs[(yyvsp[0].strings)->getName()] = (yyvsp[0].strings)->getType();
    (yyval.node) = NULL;
}
#line 2130 "c2rob.tab.c"
    break;

  case 31: /* typedef_names: typedef_names TOK_IDENT  */
#line 152 "c2rob.y"
                                                {
    (yyvsp[-1].strings)->strings.push_back((yyvsp[0].str));
    (yyval.strings) = (yyvsp[-1].strings);
}
#line 2139 "c2rob.tab.c"
    break;

  case 32: /* typedef_names: TOK_IDENT  */
#line 157 "c2rob.y"
                              {
    (yyval.strings) = new Strings();
    (yyval.strings)->strings.push_back((yyvsp[0].str));
}
#line 2148 "c2rob.tab.c"
    break;

  case 33: /* struct_decl: TOK_IDENT '{' struct_fields '}'  */
#line 162 "c2rob.y"
                                                    {
    (yyval.node) = new Type((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2156 "c2rob.tab.c"
    break;

  case 34: /* struct_fields: struct_fields struct_field  */
#line 166 "c2rob.y"
                                               {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2165 "c2rob.tab.c"
    break;

  case 35: /* struct_fields: struct_field  */
#line 171 "c2rob.y"
                             {
    Node *n = new TypeFields();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2175 "c2rob.tab.c"
    break;

  case 36: /* struct_field: scalar_decl ';'  */
#line 177 "c2rob.y"
                               {
    (yyval.node) = (yyvsp[-1].node);
}
#line 2183 "c2rob.tab.c"
    break;

  case 37: /* struct_field: qualifiers scalar_decl ';'  */
#line 181 "c2rob.y"
                                          {
    (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node));
}
#line 2191 "c2rob.tab.c"
    break;

  case 38: /* struct_field: TOK_IDENT TOK_IDENT ':' TOK_INTEGER_LITERAL ';'  */
#line 185 "c2rob.y"
                                                                                     {
    (yyval.node) = new VariableDecl((yyvsp[-4].str), (yyvsp[-3].str), atoi((yyvsp[-1].str)));
}
#line 2199 "c2rob.tab.c"
    break;

  case 39: /* func_decl: TOK_IDENT TOK_IDENT '(' optional_func_args ')'  */
#line 189 "c2rob.y"
                                                                       {
    (yyval.node) = new Function((yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2207 "c2rob.tab.c"
    break;

  case 40: /* func_decl: TOK_IDENT '*' TOK_IDENT '(' optional_func_args ')'  */
#line 193 "c2rob.y"
                                                                           {
    (yyval.node) = new Function((yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].node));
    ((Function*)(yyval.node))->markPointerResult();
}
#line 2216 "c2rob.tab.c"
    break;

  case 41: /* func_impl: TOK_IDENT TOK_IDENT '(' optional_func_args ')' '{' optional_locals '}'  */
#line 198 "c2rob.y"
                                                                                               {
    (yyval.node) = new Function((yyvsp[-7].str), (yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
}
#line 2224 "c2rob.tab.c"
    break;

  case 42: /* func_impl: TOK_IDENT '*' TOK_IDENT '(' optional_func_args ')' '{' optional_locals '}'  */
#line 202 "c2rob.y"
                                                                                                   {
    (yyval.node) = new Function((yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    ((Function*)(yyval.node))->markPointerResult();
}
#line 2233 "c2rob.tab.c"
    break;

  case 43: /* optional_func_args: func_args  */
#line 208 "c2rob.y"
                               {
    for (Node *node : (yyvsp[0].node)->getChildren()) {
        auto *arg = static_cast<FuncArg*>(node);

        if (arg->getTypeName() == "void" && !arg->isSourcePointer())
            yyerror("a void parameter cannot have a name or qualifiers");
    }

    (yyval.node) = (yyvsp[0].node);
}
#line 2248 "c2rob.tab.c"
    break;

  case 44: /* optional_func_args: %empty  */
#line 219 "c2rob.y"
                            {
    (yyval.node) = new NodeArgs();
}
#line 2256 "c2rob.tab.c"
    break;

  case 45: /* func_args: func_args ',' func_arg  */
#line 224 "c2rob.y"
                                       {
    if((yyvsp[-2].node)->getChildren().empty() || !(yyvsp[0].node))
        yyerror("void must be the only item in the parameter list");

    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2268 "c2rob.tab.c"
    break;

  case 46: /* func_args: func_arg  */
#line 232 "c2rob.y"
                     {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2278 "c2rob.tab.c"
    break;

  case 47: /* pointer_arg: '*'  */
#line 238 "c2rob.y"
                  {
    (yyval.itg) = 1;
}
#line 2286 "c2rob.tab.c"
    break;

  case 48: /* pointer_arg: '*' '*'  */
#line 242 "c2rob.y"
                      {
    (yyval.itg) = 1;
}
#line 2294 "c2rob.tab.c"
    break;

  case 49: /* func_arg: TOK_IDENT  */
#line 247 "c2rob.y"
                           {
    if(string((yyvsp[0].str)) == "void"){
        (yyval.node) = nullptr;
    }else{
        char unamed[10];
        snprintf(unamed, 10, "_un%d", current_unamed_arg++);
        (yyval.node) = new FuncArg((yyvsp[0].str), unamed);
    }
}
#line 2308 "c2rob.tab.c"
    break;

  case 50: /* func_arg: TOK_IDENT pointer_arg  */
#line 257 "c2rob.y"
                                       {
    char unamed[10];
    snprintf(unamed, 10, "_un%d", current_unamed_arg++);
    string atype = (yyvsp[-1].str);
    if ((atype == "char" || atype == "int32" || atype == "int") && (yyvsp[0].itg) == 1)
        atype.push_back('*');
    (yyval.node) = new FuncArg(atype, unamed, true);
}
#line 2321 "c2rob.tab.c"
    break;

  case 51: /* func_arg: qualifiers TOK_IDENT  */
#line 266 "c2rob.y"
                                      {
    char unamed[10];
    snprintf(unamed, 10, "_un%d", current_unamed_arg++);
    (yyval.node) = new FuncArg((yyvsp[0].str), unamed);
}
#line 2331 "c2rob.tab.c"
    break;

  case 52: /* func_arg: qualifiers TOK_IDENT pointer_arg  */
#line 272 "c2rob.y"
                                                  {
    char unamed[10];
    snprintf(unamed, 10, "_un%d", current_unamed_arg++);
    string atype = (yyvsp[-1].str);
    if ((atype == "char" || atype == "int32" || atype == "int") && (yyvsp[0].itg) == 1)
        atype.push_back('*');
    (yyval.node) = new FuncArg(atype, unamed, true);
}
#line 2344 "c2rob.tab.c"
    break;

  case 53: /* func_arg: TOK_IDENT TOK_IDENT  */
#line 283 "c2rob.y"
                                           {
    (yyval.node) = new FuncArg((yyvsp[-1].str), (yyvsp[0].str));
}
#line 2352 "c2rob.tab.c"
    break;

  case 54: /* func_arg: TOK_IDENT '*' TOK_IDENT  */
#line 287 "c2rob.y"
                                               {
    string atype = (yyvsp[-2].str);
    if (atype == "char" || atype == "int32" || atype == "int")
        atype.push_back('*');
    (yyval.node) = new FuncArg(atype, (yyvsp[0].str), true);
}
#line 2363 "c2rob.tab.c"
    break;

  case 55: /* func_arg: qualifiers TOK_IDENT '*' TOK_IDENT  */
#line 294 "c2rob.y"
                                                          {
    string atype = (yyvsp[-2].str);
    //atype.push_back('*'); //TODO: check what to do with pointers as rob doesn't have them
    (yyval.node) = new FuncArg(atype, (yyvsp[0].str), true);
}
#line 2373 "c2rob.tab.c"
    break;

  case 56: /* func_arg: TOK_IDENT '*' TOK_IDENT '[' ']'  */
#line 300 "c2rob.y"
                                                       {
    string atype = (yyvsp[-4].str);
    //atype.push_back('*'); //TODO: check what to do with pointers as rob doesn't have them
    (yyval.node) = new FuncArg(atype, (yyvsp[-2].str), true); //TODO: need [] or is just main arg?
}
#line 2383 "c2rob.tab.c"
    break;

  case 57: /* global: error ';'  */
#line 306 "c2rob.y"
                   { (yyval.node) = new Node(); }
#line 2389 "c2rob.tab.c"
    break;

  case 58: /* locals: locals local  */
#line 308 "c2rob.y"
                          {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2398 "c2rob.tab.c"
    break;

  case 59: /* locals: local  */
#line 313 "c2rob.y"
               {
    Node *n = new Node();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2408 "c2rob.tab.c"
    break;

  case 60: /* local: qualifiers scalar_decl ';'  */
#line 319 "c2rob.y"
                                        { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2414 "c2rob.tab.c"
    break;

  case 61: /* local: qualifiers scalar_init_decl ';'  */
#line 320 "c2rob.y"
                                        { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2420 "c2rob.tab.c"
    break;

  case 62: /* local: qualifiers array_init_decl ';'  */
#line 321 "c2rob.y"
                                        { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2426 "c2rob.tab.c"
    break;

  case 63: /* local: qualifiers array_decl ';'  */
#line 322 "c2rob.y"
                                        { (yyval.node) = preserveWhileQualifiers((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 2432 "c2rob.tab.c"
    break;

  case 65: /* local: qualifiers multi_decl ';'  */
#line 324 "c2rob.y"
                                  {
          for (Node *decl : (yyvsp[-1].node)->getChildren()) preserveWhileQualifiers(decl, (yyvsp[-2].node));
          (yyval.node) = (yyvsp[-1].node);
      }
#line 2441 "c2rob.tab.c"
    break;

  case 71: /* local: function_call ';'  */
#line 333 "c2rob.y"
                            { ((FunctionCall*)(yyvsp[-1].node))->setInExpr(false); (yyval.node) = (yyvsp[-1].node); }
#line 2447 "c2rob.tab.c"
    break;

  case 76: /* whilestmt: TOK_WHILE '(' expr ')' whilebody  */
#line 341 "c2rob.y"
                                             {
    (yyval.node) = new While((yyvsp[-2].node), (yyvsp[0].node), true);
}
#line 2455 "c2rob.tab.c"
    break;

  case 77: /* whilebody: '{' optional_locals '}'  */
#line 345 "c2rob.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2461 "c2rob.tab.c"
    break;

  case 78: /* whilebody: local  */
#line 346 "c2rob.y"
                  {
              (yyval.node) = new Node();
              (yyval.node)->append((yyvsp[0].node));
          }
#line 2470 "c2rob.tab.c"
    break;

  case 79: /* whilebody: ';'  */
#line 350 "c2rob.y"
                { (yyval.node) = new Node(); }
#line 2476 "c2rob.tab.c"
    break;

  case 80: /* optional_locals: locals  */
#line 353 "c2rob.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2482 "c2rob.tab.c"
    break;

  case 81: /* optional_locals: %empty  */
#line 354 "c2rob.y"
                         { (yyval.node) = new Node(); }
#line 2488 "c2rob.tab.c"
    break;

  case 82: /* returnstmt: TOK_RETURN expr ';'  */
#line 357 "c2rob.y"
                                 {
    (yyval.node) = new Return((yyvsp[-1].node));
}
#line 2496 "c2rob.tab.c"
    break;

  case 83: /* returnstmt: TOK_RETURN ';'  */
#line 361 "c2rob.y"
                            {
    (yyval.node) = new Return();
}
#line 2504 "c2rob.tab.c"
    break;

  case 84: /* attribution: scalar_or_array '=' expr  */
#line 366 "c2rob.y"
                                       {
    (yyval.node) = new Store((yyvsp[-2].node), "=", (yyvsp[0].node));
}
#line 2512 "c2rob.tab.c"
    break;

  case 85: /* attribution: scalar_or_array TOK_ATTRIBUTION expr  */
#line 372 "c2rob.y"
                                                       {
    (yyval.node) = new Store((yyvsp[-2].node), (yyvsp[-1].str), (yyvsp[0].node));
}
#line 2520 "c2rob.tab.c"
    break;

  case 86: /* attribution: factor TOK_UNARY_OPERATOR  */
#line 377 "c2rob.y"
                                               {
    (yyval.node) = new UnaryAttribution((yyvsp[-1].node), (yyvsp[0].str));
}
#line 2528 "c2rob.tab.c"
    break;

  case 87: /* forstmt: TOK_FOR '(' attribution ';' expr ';' attribution ')' local  */
#line 381 "c2rob.y"
                                                                             {
    Node *nfor = new Container();
    nfor->append((yyvsp[-6].node));
    Node *body = new Node();
    body->append((yyvsp[0].node));
    auto *loop = new While((yyvsp[-4].node), body);
    loop->setUpdate((yyvsp[-2].node));
    nfor->append(loop);
    (yyval.node) = nfor;
}
#line 2543 "c2rob.tab.c"
    break;

  case 88: /* forstmt: TOK_FOR '(' attribution ';' expr ';' attribution ')' '{' locals '}'  */
#line 392 "c2rob.y"
                                                                                      {
    Node *nfor = new Container();
    nfor->append((yyvsp[-8].node));
    auto *loop = new While((yyvsp[-6].node), (yyvsp[-1].node));
    loop->setUpdate((yyvsp[-4].node));
    nfor->append(loop);
    (yyval.node) = nfor;
}
#line 2556 "c2rob.tab.c"
    break;

  case 89: /* ifstmt: TOK_IF '(' expr ')' local  */
#line 401 "c2rob.y"
                                   {
    (yyval.node) = new IfStmt((yyvsp[-2].node), (yyvsp[0].node));
}
#line 2564 "c2rob.tab.c"
    break;

  case 90: /* ifstmt: TOK_IF '(' expr ')' local elseblock  */
#line 405 "c2rob.y"
                                             {
    (yyval.node) = new IfStmt((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2572 "c2rob.tab.c"
    break;

  case 91: /* ifstmt: TOK_IF '(' expr ')' '{' locals '}'  */
#line 409 "c2rob.y"
                                            {
    (yyval.node) = new IfStmt((yyvsp[-4].node), (yyvsp[-1].node));
}
#line 2580 "c2rob.tab.c"
    break;

  case 92: /* ifstmt: TOK_IF '(' expr ')' '{' locals '}' elseblock  */
#line 413 "c2rob.y"
                                                      {
    (yyval.node) = new IfStmt((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
}
#line 2588 "c2rob.tab.c"
    break;

  case 93: /* multi_decl: TOK_IDENT multi_declarators  */
#line 418 "c2rob.y"
                                               {
    string type = VariableDecl::convertTypeToRob((yyvsp[-1].str));
    if (declared_types.contains(type))
        yyerror("multiple declaration: aggregate type not supported");
    if (type == "void")
        yyerror("multiple declaration: type 'void' cannot be used to declare variables");
    for (Node *node : (yyvsp[0].node)->getChildren()) {
        auto *decl = static_cast<VariableDecl*>(node);
        decl->setDeclarationType((yyvsp[-1].str));
        if (decl->getIndex()) {
            string size = decl->getIndex()->toStr(0);
            if (!regex_match(size, regex("[1-9][0-9]*")))
                yyerror("multiple declaration: vector dimension must be a positive integer literal");
            else if (decl->getValue() && to_string(decl->getValue()->getChildren().size()) != size)
                yyerror("multiple declaration: array initialization must populate all elements");
        }
    }
    (yyval.node) = (yyvsp[0].node);
}
#line 2612 "c2rob.tab.c"
    break;

  case 94: /* multi_declarators: multi_declarator ',' multi_declarator  */
#line 438 "c2rob.y"
                                                                {
    (yyval.node) = new Container();
    (yyval.node)->append((yyvsp[-2].node));
    (yyval.node)->append((yyvsp[0].node));
}
#line 2622 "c2rob.tab.c"
    break;

  case 95: /* multi_declarators: multi_declarators ',' multi_declarator  */
#line 444 "c2rob.y"
                                                                 {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2631 "c2rob.tab.c"
    break;

  case 96: /* multi_declarator: TOK_IDENT  */
#line 450 "c2rob.y"
                                   {
    (yyval.node) = new VariableDecl("", (yyvsp[0].str));
}
#line 2639 "c2rob.tab.c"
    break;

  case 97: /* multi_declarator: TOK_IDENT '=' expr  */
#line 454 "c2rob.y"
                                            {
    (yyval.node) = new VariableDecl("", (yyvsp[-2].str), (yyvsp[0].node));
}
#line 2647 "c2rob.tab.c"
    break;

  case 98: /* multi_declarator: TOK_IDENT '[' expr ']'  */
#line 458 "c2rob.y"
                                                {
    (yyval.node) = new VariableDecl("", (yyvsp[-3].str), (yyvsp[-1].node), nullptr);
}
#line 2655 "c2rob.tab.c"
    break;

  case 99: /* multi_declarator: TOK_IDENT '[' expr ']' '=' array_values_decl  */
#line 462 "c2rob.y"
                                                                                  {
    (yyval.node) = new VariableDecl("", (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node));
}
#line 2663 "c2rob.tab.c"
    break;

  case 100: /* elseblock: TOK_ELSE '{' locals '}'  */
#line 466 "c2rob.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2669 "c2rob.tab.c"
    break;

  case 101: /* elseblock: TOK_ELSE local  */
#line 467 "c2rob.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2675 "c2rob.tab.c"
    break;

  case 102: /* scalar_init_decl: TOK_IDENT TOK_IDENT '=' expr  */
#line 470 "c2rob.y"
                                                            {
    (yyval.node) = new VariableDecl((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[0].node));
}
#line 2683 "c2rob.tab.c"
    break;

  case 103: /* scalar_init_decl: TOK_IDENT TOK_IDENT '=' array_values_decl  */
#line 475 "c2rob.y"
                                                                                {
    (yyval.node) = new InitializedType((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[0].node));
}
#line 2691 "c2rob.tab.c"
    break;

  case 104: /* scalar_decl: TOK_IDENT TOK_IDENT  */
#line 480 "c2rob.y"
                                              {
    (yyval.node) = new VariableDecl((yyvsp[-1].str), (yyvsp[0].str));
}
#line 2699 "c2rob.tab.c"
    break;

  case 105: /* array_init_decl: TOK_IDENT TOK_IDENT '[' expr ']' '=' array_values_decl  */
#line 485 "c2rob.y"
                                                                                                 {
    ((NodeArgs*)(yyvsp[0].node))->setArrayInitType((yyvsp[-6].str));
    (yyval.node) = new VariableDecl((yyvsp[-6].str), (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node));
}
#line 2708 "c2rob.tab.c"
    break;

  case 106: /* array_decl: TOK_IDENT TOK_IDENT '[' expr ']'  */
#line 490 "c2rob.y"
                                                               {
    (yyval.node) = new VariableDecl((yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-1].node), nullptr);
}
#line 2716 "c2rob.tab.c"
    break;

  case 107: /* array_init_decl: TOK_IDENT TOK_IDENT '[' expr ']' '=' struct_values_decl  */
#line 494 "c2rob.y"
                                                                                                  {
    (yyval.node) = new StructVariableDecl((yyvsp[-6].str), (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node));
}
#line 2724 "c2rob.tab.c"
    break;

  case 108: /* struct_values_decl: '{' array_values_decls '}'  */
#line 498 "c2rob.y"
                                                      { (yyval.node) = (yyvsp[-1].node); }
#line 2730 "c2rob.tab.c"
    break;

  case 109: /* array_values_decls: array_values_decls ',' array_values_decl  */
#line 500 "c2rob.y"
                                                                  {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2739 "c2rob.tab.c"
    break;

  case 110: /* array_values_decls: array_values_decl  */
#line 505 "c2rob.y"
                                       {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2749 "c2rob.tab.c"
    break;

  case 111: /* array_values_decl: '{' array_values '}'  */
#line 511 "c2rob.y"
                                         { (yyval.node) = (yyvsp[-1].node); }
#line 2755 "c2rob.tab.c"
    break;

  case 112: /* array_values: array_values ',' expr  */
#line 513 "c2rob.y"
                                         {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2764 "c2rob.tab.c"
    break;

  case 113: /* array_values: expr  */
#line 518 "c2rob.y"
                    {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2774 "c2rob.tab.c"
    break;

  case 114: /* expr: expr TOK_CMP_RELAT expr  */
#line 524 "c2rob.y"
                                          { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].str)); }
#line 2780 "c2rob.tab.c"
    break;

  case 115: /* expr: expr TOK_CMP_EQNEQ expr  */
#line 525 "c2rob.y"
                                          { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].str)); }
#line 2786 "c2rob.tab.c"
    break;

  case 116: /* expr: expr TOK_AND expr  */
#line 526 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "and"); }
#line 2792 "c2rob.tab.c"
    break;

  case 117: /* expr: expr TOK_OR expr  */
#line 527 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "or"); }
#line 2798 "c2rob.tab.c"
    break;

  case 118: /* expr: expr '+' expr  */
#line 528 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "+"); }
#line 2804 "c2rob.tab.c"
    break;

  case 119: /* expr: expr '-' expr  */
#line 529 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "-"); }
#line 2810 "c2rob.tab.c"
    break;

  case 120: /* expr: expr '*' expr  */
#line 530 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "*"); }
#line 2816 "c2rob.tab.c"
    break;

  case 121: /* expr: expr '/' expr  */
#line 531 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "/"); }
#line 2822 "c2rob.tab.c"
    break;

  case 122: /* expr: expr '%' expr  */
#line 532 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "%"); }
#line 2828 "c2rob.tab.c"
    break;

  case 123: /* expr: expr '&' expr  */
#line 533 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "&"); }
#line 2834 "c2rob.tab.c"
    break;

  case 124: /* expr: expr '|' expr  */
#line 534 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "|"); }
#line 2840 "c2rob.tab.c"
    break;

  case 125: /* expr: expr '^' expr  */
#line 535 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "^"); }
#line 2846 "c2rob.tab.c"
    break;

  case 126: /* expr: '!' expr  */
#line 536 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "!"); }
#line 2852 "c2rob.tab.c"
    break;

  case 127: /* expr: '~' expr  */
#line 537 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "~"); }
#line 2858 "c2rob.tab.c"
    break;

  case 128: /* expr: '-' expr  */
#line 538 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "-"); }
#line 2864 "c2rob.tab.c"
    break;

  case 129: /* expr: '+' expr  */
#line 539 "c2rob.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2870 "c2rob.tab.c"
    break;

  case 130: /* expr: '(' expr ')'  */
#line 540 "c2rob.y"
                                { (yyval.node) = new Parenthesis((yyvsp[-1].node)); }
#line 2876 "c2rob.tab.c"
    break;

  case 134: /* factor: TOK_INT  */
#line 546 "c2rob.y"
                      {
    (yyval.node) = new Integer((yyvsp[0].itg));
}
#line 2884 "c2rob.tab.c"
    break;

  case 135: /* factor: TOK_FLOAT  */
#line 550 "c2rob.y"
                        {
    (yyval.node) = new Float((yyvsp[0].flt));
}
#line 2892 "c2rob.tab.c"
    break;

  case 136: /* factor: TOK_STRING  */
#line 554 "c2rob.y"
                         {
    (yyval.node) = new Ident((yyvsp[0].str));
}
#line 2900 "c2rob.tab.c"
    break;

  case 137: /* factor: TOK_INTEGER_LITERAL  */
#line 558 "c2rob.y"
                                  {
    (yyval.node) = new IntegerToken((yyvsp[0].str));
}
#line 2908 "c2rob.tab.c"
    break;

  case 138: /* factor: factor TOK_UNARY_OPERATOR  */
#line 562 "c2rob.y"
                                          {
    (yyval.node) = new Unary((yyvsp[-1].node), (yyvsp[0].str));
}
#line 2916 "c2rob.tab.c"
    break;

  case 139: /* scalar_or_array: TOK_IDENT  */
#line 566 "c2rob.y"
                                {
    (yyval.node) = new Ident((yyvsp[0].str));
}
#line 2924 "c2rob.tab.c"
    break;

  case 140: /* scalar_or_array: TOK_IDENT '[' expr ']'  */
#line 570 "c2rob.y"
                                             {
    (yyval.node) = new LoadArray((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2932 "c2rob.tab.c"
    break;

  case 141: /* scalar_or_array: TOK_IDENT '.' TOK_IDENT  */
#line 574 "c2rob.y"
                                                   {
    (yyval.node) = new LoadField((yyvsp[-2].str), (yyvsp[0].str));
}
#line 2940 "c2rob.tab.c"
    break;

  case 142: /* scalar_or_array: TOK_IDENT '[' expr ']' '.' TOK_IDENT  */
#line 578 "c2rob.y"
                                                                {
    (yyval.node) = new LoadArrayField((yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].str));
}
#line 2948 "c2rob.tab.c"
    break;

  case 143: /* function_call: TOK_IDENT '(' ')'  */
#line 582 "c2rob.y"
                                      {
    (yyval.node) = new FunctionCall((yyvsp[-2].str));
}
#line 2956 "c2rob.tab.c"
    break;

  case 144: /* function_call: TOK_IDENT '(' func_call_args ')'  */
#line 586 "c2rob.y"
                                                           {
    (yyval.node) = new FunctionCall((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2964 "c2rob.tab.c"
    break;

  case 145: /* func_call_args: func_call_args ',' expr  */
#line 590 "c2rob.y"
                                             {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2973 "c2rob.tab.c"
    break;

  case 146: /* func_call_args: expr  */
#line 595 "c2rob.y"
                      {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2983 "c2rob.tab.c"
    break;


#line 2987 "c2rob.tab.c"

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

#line 601 "c2rob.y"

