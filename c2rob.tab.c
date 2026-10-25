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
#include "qualifier_support.h"
#include "integer_support.h"

int yyerror(const char *s);
int yylex(void);
int errorcount = 0;
int current_unamed_arg = 0;
extern bool force_print_tree;

DeclarationSpecifiers *resolveDeclarationSpecifiers(
    DeclarationSpecifiers *spec
) {
    try {
        spec->resolve();
    } catch (const std::exception &error) {
        yyerror(error.what());
        spec->type = "int32";
    }

    return spec;
}

Node *applyDeclarationSpecifiers(
    Node *node,
    const DeclarationSpecifiers *spec
) {
    if (spec->isConst)
        node->markSourceConst();

    if (spec->isVolatile)
        node->markSourceVolatile();

    if (spec->isStatic)
        node->markSourceStatic();

    return node;
}

FuncArg *makeFunctionArgument(
    DeclarationSpecifiers *spec,
    const string &name,
    bool pointer = false
) {
    string type = spec->type;

    if (pointer && (type == "char" || type == "int32"))
        type += "*";

    auto *arg = new FuncArg(type, name, pointer);

    applyDeclarationSpecifiers(arg, spec);

    if (spec->isStatic)
        yyerror(
            "declaration: static is not allowed on a function parameter"
        );

    return arg;
}


#line 137 "c2rob.tab.c"

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
  YYSYMBOL_TOK_TYPE_SPEC = 27,             /* TOK_TYPE_SPEC  */
  YYSYMBOL_28_ = 28,                       /* '|'  */
  YYSYMBOL_29_ = 29,                       /* '^'  */
  YYSYMBOL_30_ = 30,                       /* '&'  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* '%'  */
  YYSYMBOL_UMINUS = 36,                    /* UMINUS  */
  YYSYMBOL_37_ = 37,                       /* '!'  */
  YYSYMBOL_38_ = 38,                       /* '~'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_globals = 52,                   /* globals  */
  YYSYMBOL_global = 53,                    /* global  */
  YYSYMBOL_builtin_specifiers = 54,        /* builtin_specifiers  */
  YYSYMBOL_specifier_qualifier = 55,       /* specifier_qualifier  */
  YYSYMBOL_specifier_qualifiers = 56,      /* specifier_qualifiers  */
  YYSYMBOL_declaration_specifiers = 57,    /* declaration_specifiers  */
  YYSYMBOL_include = 58,                   /* include  */
  YYSYMBOL_typedef_decl = 59,              /* typedef_decl  */
  YYSYMBOL_struct_decl = 60,               /* struct_decl  */
  YYSYMBOL_struct_fields = 61,             /* struct_fields  */
  YYSYMBOL_struct_field = 62,              /* struct_field  */
  YYSYMBOL_func_decl = 63,                 /* func_decl  */
  YYSYMBOL_func_impl = 64,                 /* func_impl  */
  YYSYMBOL_optional_func_args = 65,        /* optional_func_args  */
  YYSYMBOL_func_args = 66,                 /* func_args  */
  YYSYMBOL_pointer_arg = 67,               /* pointer_arg  */
  YYSYMBOL_func_arg = 68,                  /* func_arg  */
  YYSYMBOL_locals = 69,                    /* locals  */
  YYSYMBOL_local = 70,                     /* local  */
  YYSYMBOL_whilestmt = 71,                 /* whilestmt  */
  YYSYMBOL_whilebody = 72,                 /* whilebody  */
  YYSYMBOL_optional_locals = 73,           /* optional_locals  */
  YYSYMBOL_returnstmt = 74,                /* returnstmt  */
  YYSYMBOL_attribution = 75,               /* attribution  */
  YYSYMBOL_forstmt = 76,                   /* forstmt  */
  YYSYMBOL_ifstmt = 77,                    /* ifstmt  */
  YYSYMBOL_multi_decl = 78,                /* multi_decl  */
  YYSYMBOL_multi_declarators = 79,         /* multi_declarators  */
  YYSYMBOL_multi_declarator = 80,          /* multi_declarator  */
  YYSYMBOL_elseblock = 81,                 /* elseblock  */
  YYSYMBOL_scalar_init_decl = 82,          /* scalar_init_decl  */
  YYSYMBOL_scalar_decl = 83,               /* scalar_decl  */
  YYSYMBOL_array_init_decl = 84,           /* array_init_decl  */
  YYSYMBOL_array_decl = 85,                /* array_decl  */
  YYSYMBOL_struct_values_decl = 86,        /* struct_values_decl  */
  YYSYMBOL_array_values_decls = 87,        /* array_values_decls  */
  YYSYMBOL_array_values_decl = 88,         /* array_values_decl  */
  YYSYMBOL_array_values = 89,              /* array_values  */
  YYSYMBOL_expr = 90,                      /* expr  */
  YYSYMBOL_factor = 91,                    /* factor  */
  YYSYMBOL_scalar_or_array = 92,           /* scalar_or_array  */
  YYSYMBOL_function_call = 93,             /* function_call  */
  YYSYMBOL_func_call_args = 94             /* func_call_args  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   747

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
       2,     2,     2,    37,     2,     2,     2,    35,    30,     2,
      39,    40,    33,    31,    45,    32,    49,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    41,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,    29,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,    28,    43,    38,     2,     2,     2,
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
      25,    26,    27,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   129,   129,   167,   173,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   193,   196,   199,   205,   208,
     211,   217,   220,   226,   229,   234,   239,   244,   249,   254,
     261,   270,   284,   288,   293,   299,   305,   322,   334,   349,
     363,   380,   391,   396,   404,   410,   414,   420,   438,   448,
     457,   469,   481,   483,   488,   494,   495,   496,   497,   498,
     499,   500,   504,   505,   506,   507,   511,   515,   516,   520,
     523,   524,   527,   531,   536,   542,   547,   551,   562,   571,
     575,   579,   583,   588,   610,   616,   622,   626,   630,   634,
     638,   639,   643,   659,   675,   688,   709,   725,   741,   743,
     748,   754,   756,   761,   767,   768,   769,   770,   771,   772,
     773,   774,   775,   776,   777,   778,   779,   780,   781,   782,
     783,   784,   786,   787,   789,   793,   797,   801,   805,   809,
     813,   817,   821,   825,   829,   833,   838
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
  "TOK_STATIC", "TOK_VOLATILE", "TOK_CONST", "TOK_TYPE_SPEC", "'|'", "'^'",
  "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "'!'", "'~'", "'('",
  "')'", "';'", "'{'", "'}'", "':'", "','", "'['", "']'", "'='", "'.'",
  "$accept", "program", "globals", "global", "builtin_specifiers",
  "specifier_qualifier", "specifier_qualifiers", "declaration_specifiers",
  "include", "typedef_decl", "struct_decl", "struct_fields",
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

#define YYPACT_NINF (-206)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     665,   -37,   135,  -206,    32,   383,  -206,  -206,  -206,  -206,
      38,   608,  -206,   165,  -206,     7,     6,  -206,    31,    47,
      55,  -206,    56,    84,    94,    97,   128,  -206,   135,     5,
      45,   104,  -206,  -206,  -206,  -206,   135,   165,  -206,   100,
     114,   127,   129,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,   383,  -206,  -206,   135,   383,   500,   450,   141,   178,
     178,   181,     3,  -206,   145,     8,   147,   155,  -206,    43,
    -206,  -206,  -206,  -206,   500,   500,   500,   500,   500,   267,
     189,  -206,  -206,   500,  -206,   514,   383,    65,  -206,  -206,
     158,  -206,  -206,  -206,  -206,   171,   202,   166,   383,   496,
     500,   206,  -206,  -206,  -206,  -206,   572,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   106,
    -206,   110,   630,   170,   500,   500,   191,  -206,   168,   720,
    -206,  -206,   630,    74,   296,  -206,  -206,   645,   671,   214,
     286,   683,   697,   338,   143,   143,  -206,  -206,  -206,   177,
    -206,   500,   179,   305,   630,   188,   184,   119,   194,   199,
     200,   459,   237,   720,  -206,  -206,   207,  -206,   201,  -206,
    -206,   216,   218,   220,   225,   226,   256,     1,   229,  -206,
     500,   224,   450,  -206,   235,   630,   720,   239,  -206,  -206,
     500,    80,   500,  -206,   543,    82,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,   273,   500,   500,  -206,   630,   291,
     121,  -206,   246,   263,   586,   269,   617,  -206,   630,   630,
    -206,  -206,   263,  -206,  -206,   371,   500,   341,  -206,   720,
     293,   557,  -206,   720,  -206,  -206,   210,   398,  -206,    80,
     268,   293,   720,  -206,   282,  -206,  -206,   238,   425,  -206,
     720,  -206,   266,  -206
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    25,    30,     0,     0,    20,    19,    18,    15,
       0,     0,     4,    23,    21,     0,     0,    14,     0,     0,
       0,    13,     0,     0,     0,     0,     0,    52,    26,    29,
       0,     0,     1,     3,    16,    17,    27,    24,    22,    86,
       0,    83,     0,    11,    12,    10,     9,     6,     5,     7,
       8,     0,    29,    31,    28,    42,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    47,     0,    41,    44,   129,
     125,   124,   126,   127,     0,     0,     0,     0,     0,     0,
     121,   123,   122,     0,    93,    87,    42,    86,    85,    84,
      94,    32,    33,    35,    49,    45,    48,    37,     0,     0,
       0,     0,   119,   118,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
     128,     0,   103,     0,     0,     0,     0,    46,    50,    71,
      43,   133,   136,     0,     0,   131,   120,   107,   106,   105,
     104,   114,   115,   113,   108,   109,   110,   111,   112,     0,
     101,     0,    38,     0,    87,     0,     0,   129,     0,     0,
       0,     0,     0,    70,    54,    64,     0,    65,     0,    63,
      62,     0,     0,     0,     0,     0,     0,   123,   122,   134,
       0,   130,     0,    97,    89,   102,    71,    88,    36,    51,
       0,     0,     0,    73,     0,    86,    53,    39,    60,    55,
      57,    56,    58,    59,    76,     0,     0,    61,   135,     0,
       0,   100,     0,     0,     0,     0,     0,    72,    75,    74,
     132,    98,     0,    40,    89,     0,     0,     0,    99,     0,
      79,     0,    69,    71,    68,    66,     0,     0,    80,     0,
       0,    81,     0,    91,     0,    67,    82,     0,     0,    90,
       0,    77,     0,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,  -206,   312,   317,    66,     0,    12,  -206,  -206,
    -206,  -206,   279,  -206,  -206,   259,  -206,  -206,   244,  -205,
     -85,  -206,  -206,  -183,  -206,  -175,  -206,  -206,    73,  -206,
     -46,   109,    76,    15,    90,    91,  -206,  -206,  -142,  -206,
     -56,  -121,   -54,   -30,  -206
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,   162,    17,    18,
      19,    62,    63,    20,    21,    66,    67,    96,    68,   163,
     164,   165,   235,   166,   167,   168,   169,   170,   171,    41,
      42,   238,   172,   173,   174,   175,   183,   210,    84,   121,
     122,    80,    81,    82,   133
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    85,    28,   212,    27,   205,     2,   184,   176,    39,
      36,    94,    16,    88,    89,    24,   215,    31,   102,   103,
     104,   105,   106,    16,   236,    30,    24,     6,     7,     8,
       9,     6,     7,     8,     9,    29,    54,   247,    32,    40,
     211,    95,   176,   132,   134,   252,    91,    51,    52,   206,
     240,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    61,   244,   176,    64,    65,   153,   154,
     176,   224,    43,    22,    61,   177,    23,    64,   196,    35,
     228,    38,    99,    69,    22,    70,    71,    23,    44,   100,
      25,    26,   101,    72,    38,   185,    45,    46,    65,   178,
      73,    25,    26,    35,   176,   194,   176,    53,   176,   177,
      65,   124,   176,   125,   179,   176,   176,    58,   176,   180,
      38,   176,   -25,   -94,   208,    47,   176,   176,    56,   176,
      57,   176,   177,   178,   214,    48,   216,   177,    49,    55,
     230,   -94,   234,     6,     7,     8,    56,   -96,    57,   218,
     219,   196,   243,   150,   149,   151,   178,    28,    99,     6,
       7,     8,   196,   251,   221,   100,   222,   196,   101,    50,
     231,   177,    59,   177,    60,   177,   116,   117,   118,   177,
      86,    87,   177,   177,    90,   177,    93,    97,   177,     6,
       7,     8,    34,   177,   177,   178,   177,   178,   177,   178,
      98,   120,   126,   178,   127,   128,   178,   178,   129,   135,
     152,   155,   178,   157,   156,    70,    71,   178,   178,   182,
     178,   186,   178,    72,   158,   110,   159,   160,   161,   188,
      73,   189,    30,   190,     6,     7,     8,     9,   191,   192,
     195,   157,   198,    70,    71,   114,   115,   116,   117,   118,
     197,    72,   158,   241,   159,   160,   161,   199,    73,   200,
      30,   201,     6,     7,     8,     9,   202,   203,   204,   157,
     207,    70,    71,   209,   107,   108,   -95,   109,   110,    72,
     158,   249,   159,   160,   161,  -128,    73,   213,    30,   223,
       6,     7,     8,     9,   220,   111,   112,   113,   114,   115,
     116,   117,   118,   107,   108,    83,   109,   110,   237,   253,
     226,   245,   107,   108,   119,   109,   110,   114,   115,   116,
     117,   118,   248,    33,   111,   112,   113,   114,   115,   116,
     117,   118,    37,   111,   112,   113,   114,   115,   116,   117,
     118,    92,   130,   181,   157,   123,    70,    71,   109,   110,
     246,     0,   187,     0,    72,   158,     0,   159,   160,   161,
       0,    73,     0,    30,     0,     6,     7,     8,     9,   114,
     115,   116,   117,   118,   157,     0,    70,    71,     0,     0,
       0,     0,   232,   233,    72,   158,     2,   159,   160,   161,
       0,    73,     0,    30,     0,     6,     7,     8,     9,     0,
       0,   157,     0,    70,    71,    30,     0,     6,     7,     8,
       9,    72,   158,   229,   159,   160,   161,     0,    73,     0,
      30,     0,     6,     7,     8,     9,     0,     0,   157,     0,
      70,    71,     0,     0,     0,     0,     0,     0,    72,   158,
     242,   159,   160,   161,     0,    73,     0,    30,     0,     6,
       7,     8,     9,    69,     0,    70,    71,     0,     0,     0,
       0,     0,    69,    72,    70,    71,     0,   250,     0,     0,
      73,     0,    72,     0,     0,     0,     0,     0,     0,    73,
       0,    74,    75,     0,     0,     0,     0,    76,    77,    78,
      74,    75,    83,     0,     0,     0,    76,    77,    78,    69,
     193,    70,    71,    69,     0,    70,    71,     0,     0,    72,
       0,     0,     0,    72,     0,     0,    73,     0,     0,     0,
      73,   107,   108,     0,   109,   110,     0,    74,    75,     0,
       0,    74,    75,    76,    77,    78,   131,    76,    77,    78,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     107,   108,     0,   109,   110,   -92,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,   109,   110,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   107,
     108,     0,   109,   110,   217,   111,   112,   113,   114,   115,
     116,   117,   118,   107,   108,     0,   109,   110,   239,     0,
     111,   112,   113,   114,   115,   116,   117,   118,    -2,     1,
       0,     2,   136,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,     0,   107,   108,   225,   109,   110,     3,
       4,     5,     6,     7,     8,     9,     0,   107,   108,     0,
     109,   110,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   108,     0,   109,   110,   227,   111,   112,
     113,   114,   115,   116,   117,   118,     1,     0,     2,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   109,   110,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   109,   110,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,     0,
       0,     0,     0,   157,     0,    70,    71,   113,   114,   115,
     116,   117,   118,    72,   158,     0,   159,   160,   161,     0,
      73,     0,    30,     0,     6,     7,     8,     9
};

static const yytype_int16 yycheck[] =
{
      56,    57,     2,   186,    41,     4,     3,   149,   129,     3,
       3,     3,     0,    59,    60,     0,   191,     5,    74,    75,
      76,    77,    78,    11,   229,    22,    11,    24,    25,    26,
      27,    24,    25,    26,    27,     3,    36,   242,     0,    33,
     182,    33,   163,    99,   100,   250,    43,    42,     3,    48,
     233,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    51,   239,   186,    51,    55,   124,   125,
     191,   213,    41,     0,    62,   129,     0,    62,   163,    13,
     222,    15,    39,     3,    11,     5,     6,    11,    41,    46,
       0,     0,    49,    13,    28,   151,    41,    41,    86,   129,
      20,    11,    11,    37,   225,   161,   227,     3,   229,   163,
      98,    46,   233,    48,    40,   236,   237,     3,   239,    45,
      54,   242,     3,    41,   180,    41,   247,   248,    46,   250,
      48,   252,   186,   163,   190,    41,   192,   191,    41,    39,
     225,    41,   227,    24,    25,    26,    46,    41,    48,   205,
     206,   236,   237,    43,    48,    45,   186,   157,    39,    24,
      25,    26,   247,   248,    43,    46,    45,   252,    49,    41,
     226,   225,    45,   227,    45,   229,    33,    34,    35,   233,
      39,     3,   236,   237,     3,   239,    41,    40,   242,    24,
      25,    26,    27,   247,   248,   225,   250,   227,   252,   229,
      45,    12,    44,   233,    33,     3,   236,   237,    42,     3,
      40,    20,   242,     3,    46,     5,     6,   247,   248,    42,
     250,    42,   252,    13,    14,    11,    16,    17,    18,    41,
      20,    47,    22,    39,    24,    25,    26,    27,    39,    39,
       3,     3,    41,     5,     6,    31,    32,    33,    34,    35,
      43,    13,    14,    43,    16,    17,    18,    41,    20,    41,
      22,    41,    24,    25,    26,    27,    41,    41,    12,     3,
      41,     5,     6,    49,     7,     8,    41,    10,    11,    13,
      14,    43,    16,    17,    18,    12,    20,    48,    22,    43,
      24,    25,    26,    27,     3,    28,    29,    30,    31,    32,
      33,    34,    35,     7,     8,    42,    10,    11,    15,    43,
      41,    43,     7,     8,    47,    10,    11,    31,    32,    33,
      34,    35,    40,    11,    28,    29,    30,    31,    32,    33,
      34,    35,    15,    28,    29,    30,    31,    32,    33,    34,
      35,    62,    98,    47,     3,    86,     5,     6,    10,    11,
     241,    -1,    47,    -1,    13,    14,    -1,    16,    17,    18,
      -1,    20,    -1,    22,    -1,    24,    25,    26,    27,    31,
      32,    33,    34,    35,     3,    -1,     5,     6,    -1,    -1,
      -1,    -1,    41,    42,    13,    14,     3,    16,    17,    18,
      -1,    20,    -1,    22,    -1,    24,    25,    26,    27,    -1,
      -1,     3,    -1,     5,     6,    22,    -1,    24,    25,    26,
      27,    13,    14,    42,    16,    17,    18,    -1,    20,    -1,
      22,    -1,    24,    25,    26,    27,    -1,    -1,     3,    -1,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      42,    16,    17,    18,    -1,    20,    -1,    22,    -1,    24,
      25,    26,    27,     3,    -1,     5,     6,    -1,    -1,    -1,
      -1,    -1,     3,    13,     5,     6,    -1,    42,    -1,    -1,
      20,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      31,    32,    42,    -1,    -1,    -1,    37,    38,    39,     3,
      41,     5,     6,     3,    -1,     5,     6,    -1,    -1,    13,
      -1,    -1,    -1,    13,    -1,    -1,    20,    -1,    -1,    -1,
      20,     7,     8,    -1,    10,    11,    -1,    31,    32,    -1,
      -1,    31,    32,    37,    38,    39,    40,    37,    38,    39,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
       7,     8,    -1,    10,    11,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,    -1,    10,    11,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,     7,
       8,    -1,    10,    11,    41,    28,    29,    30,    31,    32,
      33,    34,    35,     7,     8,    -1,    10,    11,    41,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     1,
      -1,     3,    40,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,     7,     8,    40,    10,    11,    21,
      22,    23,    24,    25,    26,    27,    -1,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,     8,    -1,    10,    11,    40,    28,    29,
      30,    31,    32,    33,    34,    35,     1,    -1,     3,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    10,    11,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    10,    11,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    10,    11,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,    30,    31,    32,
      33,    34,    35,    13,    14,    -1,    16,    17,    18,    -1,
      20,    -1,    22,    -1,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    21,    22,    23,    24,    25,    26,    27,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      63,    64,    78,    82,    83,    84,    85,    41,    56,     3,
      22,    57,     0,    53,    27,    55,     3,    54,    55,     3,
      33,    79,    80,    41,    41,    41,    41,    41,    41,    41,
      41,    42,     3,     3,    56,    39,    46,    48,     3,    45,
      45,    57,    61,    62,    83,    57,    65,    66,    68,     3,
       5,     6,    13,    20,    31,    32,    37,    38,    39,    90,
      91,    92,    93,    42,    88,    90,    39,     3,    80,    80,
       3,    43,    62,    41,     3,    33,    67,    40,    45,    39,
      46,    49,    90,    90,    90,    90,    90,     7,     8,    10,
      11,    28,    29,    30,    31,    32,    33,    34,    35,    47,
      12,    89,    90,    65,    46,    48,    44,    33,     3,    42,
      68,    40,    90,    94,    90,     3,    40,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    48,
      43,    45,    40,    90,    90,    20,    46,     3,    14,    16,
      17,    18,    57,    69,    70,    71,    73,    74,    75,    76,
      77,    78,    82,    83,    84,    85,    91,    92,    93,    40,
      45,    47,    42,    86,    88,    90,    42,    47,    41,    47,
      39,    39,    39,    41,    90,     3,    70,    43,    41,    41,
      41,    41,    41,    41,    12,     4,    48,    41,    90,    49,
      87,    88,    73,    48,    90,    75,    90,    41,    90,    90,
       3,    43,    45,    43,    88,    40,    41,    40,    88,    42,
      70,    90,    41,    42,    70,    72,    69,    15,    81,    41,
      73,    43,    42,    70,    75,    43,    81,    69,    40,    43,
      42,    70,    69,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    55,    55,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    57,
      58,    59,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    53,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    76,    76,    77,
      77,    77,    77,    78,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    82,    83,    84,    85,    84,    86,    87,
      87,    88,    89,    89,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    92,    92,    93,    93,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     2,     3,     2,
       1,     3,     5,     2,     1,     2,     5,     5,     6,     8,
       9,     1,     0,     3,     1,     1,     2,     1,     2,     2,
       3,     5,     2,     2,     1,     2,     2,     2,     2,     2,
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
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1089 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_ATTRIBUTION: /* TOK_ATTRIBUTION  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1095 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_FLOAT: /* TOK_FLOAT  */
#line 108 "c2rob.y"
         { fprintf(yyo, "%lf", ((*yyvaluep).flt)); }
#line 1101 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INT: /* TOK_INT  */
#line 107 "c2rob.y"
         { fprintf(yyo, "%lld", static_cast<long long>(((*yyvaluep).itg))); }
#line 1107 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_CMP_EQNEQ: /* TOK_CMP_EQNEQ  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1113 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_CMP_RELAT: /* TOK_CMP_RELAT  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1119 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_UNARY_OPERATOR: /* TOK_UNARY_OPERATOR  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1125 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_STRING: /* TOK_STRING  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1131 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INTEGER_LITERAL: /* TOK_INTEGER_LITERAL  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1137 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INCLUDE: /* TOK_INCLUDE  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1143 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_TYPE_SPEC: /* TOK_TYPE_SPEC  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1149 "c2rob.tab.c"
        break;

    case YYSYMBOL_specifier_qualifier: /* specifier_qualifier  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1155 "c2rob.tab.c"
        break;

    case YYSYMBOL_pointer_arg: /* pointer_arg  */
#line 107 "c2rob.y"
         { fprintf(yyo, "%lld", static_cast<long long>(((*yyvaluep).itg))); }
#line 1161 "c2rob.tab.c"
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
#line 129 "c2rob.y"
                  {
    Node *program = (yyvsp[0].node);

    try {
        bool scope_valid =
            errorcount == 0
            && resolveScopeProgram(program);

        bool while_valid =
            scope_valid
            && validateWhileProgram(program);

        bool qualifier_valid =
            while_valid
            && validateQualifierProgram(program);

        bool integer_valid =
            qualifier_valid
            && validateIntegerProgram(program);

        if (
            integer_valid
            && (errorcount == 0 || force_print_tree)
        ) {
            cout << program->toStr(-1);
        }

    } catch (const std::exception &error) {
        yyerror(error.what());
    }

    exit(
        errorcount != 0
            ? EXIT_FAILURE
            : EXIT_SUCCESS
    );
}
#line 2067 "c2rob.tab.c"
    break;

  case 3: /* globals: globals global  */
#line 167 "c2rob.y"
                             {
    if ((yyvsp[0].node))
        (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2077 "c2rob.tab.c"
    break;

  case 4: /* globals: global  */
#line 173 "c2rob.y"
                 {
    Node *n = new Node();
    if ((yyvsp[0].node))
        n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2088 "c2rob.tab.c"
    break;

  case 15: /* builtin_specifiers: TOK_TYPE_SPEC  */
#line 193 "c2rob.y"
                    {
        (yyval.spec) = new DeclarationSpecifiers((yyvsp[0].str));
    }
#line 2096 "c2rob.tab.c"
    break;

  case 16: /* builtin_specifiers: builtin_specifiers TOK_TYPE_SPEC  */
#line 196 "c2rob.y"
                                       {
        (yyval.spec) = (yyvsp[-1].spec)->append((yyvsp[0].str));
    }
#line 2104 "c2rob.tab.c"
    break;

  case 17: /* builtin_specifiers: builtin_specifiers specifier_qualifier  */
#line 199 "c2rob.y"
                                             {
        (yyval.spec) = (yyvsp[-1].spec)->append((yyvsp[0].str));
    }
#line 2112 "c2rob.tab.c"
    break;

  case 18: /* specifier_qualifier: TOK_CONST  */
#line 205 "c2rob.y"
                {
        (yyval.str) = "const";
    }
#line 2120 "c2rob.tab.c"
    break;

  case 19: /* specifier_qualifier: TOK_VOLATILE  */
#line 208 "c2rob.y"
                   {
        (yyval.str) = "volatile";
    }
#line 2128 "c2rob.tab.c"
    break;

  case 20: /* specifier_qualifier: TOK_STATIC  */
#line 211 "c2rob.y"
                 {
        (yyval.str) = "static";
    }
#line 2136 "c2rob.tab.c"
    break;

  case 21: /* specifier_qualifiers: specifier_qualifier  */
#line 217 "c2rob.y"
                          {
        (yyval.spec) = new DeclarationSpecifiers((yyvsp[0].str));
    }
#line 2144 "c2rob.tab.c"
    break;

  case 22: /* specifier_qualifiers: specifier_qualifiers specifier_qualifier  */
#line 220 "c2rob.y"
                                               {
        (yyval.spec) = (yyvsp[-1].spec)->append((yyvsp[0].str));
    }
#line 2152 "c2rob.tab.c"
    break;

  case 23: /* declaration_specifiers: builtin_specifiers  */
#line 226 "c2rob.y"
                         {
        (yyval.spec) = resolveDeclarationSpecifiers((yyvsp[0].spec));
    }
#line 2160 "c2rob.tab.c"
    break;

  case 24: /* declaration_specifiers: specifier_qualifiers builtin_specifiers  */
#line 229 "c2rob.y"
                                              {
        (yyval.spec) = resolveDeclarationSpecifiers(
            (yyvsp[-1].spec)->append((yyvsp[0].spec))
        );
    }
#line 2170 "c2rob.tab.c"
    break;

  case 25: /* declaration_specifiers: TOK_IDENT  */
#line 234 "c2rob.y"
                {
        (yyval.spec) = resolveDeclarationSpecifiers(
            new DeclarationSpecifiers((yyvsp[0].str))
        );
    }
#line 2180 "c2rob.tab.c"
    break;

  case 26: /* declaration_specifiers: TOK_IDENT specifier_qualifiers  */
#line 239 "c2rob.y"
                                     {
        (yyval.spec) = resolveDeclarationSpecifiers(
            (yyvsp[0].spec)->append((yyvsp[-1].str))
        );
    }
#line 2190 "c2rob.tab.c"
    break;

  case 27: /* declaration_specifiers: specifier_qualifiers TOK_IDENT  */
#line 244 "c2rob.y"
                                     {
        (yyval.spec) = resolveDeclarationSpecifiers(
            (yyvsp[-1].spec)->append((yyvsp[0].str))
        );
    }
#line 2200 "c2rob.tab.c"
    break;

  case 28: /* declaration_specifiers: specifier_qualifiers TOK_IDENT specifier_qualifiers  */
#line 249 "c2rob.y"
                                                          {
        (yyval.spec) = resolveDeclarationSpecifiers(
            (yyvsp[-2].spec)->append((yyvsp[-1].str))->append((yyvsp[0].spec))
        );
    }
#line 2210 "c2rob.tab.c"
    break;

  case 29: /* declaration_specifiers: TOK_STRUCT TOK_IDENT  */
#line 254 "c2rob.y"
                           {
        // Struct tags use their own C namespace.
        (yyval.spec) = new DeclarationSpecifiers((yyvsp[0].str));
        (yyval.spec)->type = (yyvsp[0].str);
    }
#line 2220 "c2rob.tab.c"
    break;

  case 30: /* include: TOK_INCLUDE  */
#line 261 "c2rob.y"
                            {
    string name((yyvsp[0].str));
    size_t start = name.find_first_of("<\"") + 1;
    name = name.substr(start, name.length()-3-start);
    (yyval.node) = new Ident("use " + name + ";\n");
}
#line 2231 "c2rob.tab.c"
    break;

  case 31: /* typedef_decl: TOK_TYPEDEF declaration_specifiers TOK_IDENT  */
#line 270 "c2rob.y"
                                                              {
        if ((yyvsp[-1].spec)->isStatic)
            yyerror(
                "declaration: static is not allowed in a typedef"
            );

        declared_typedefs[(yyvsp[0].str)] = (yyvsp[-1].spec)->type;
        sourceTypedefs.insert_or_assign((yyvsp[0].str), *(yyvsp[-1].spec));

        (yyval.node) = nullptr;
    }
#line 2247 "c2rob.tab.c"
    break;

  case 32: /* struct_decl: TOK_STRUCT TOK_IDENT '{' struct_fields '}'  */
#line 284 "c2rob.y"
                                                       {
        (yyval.node) = new Type((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 2255 "c2rob.tab.c"
    break;

  case 33: /* struct_fields: struct_fields struct_field  */
#line 288 "c2rob.y"
                                               {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2264 "c2rob.tab.c"
    break;

  case 34: /* struct_fields: struct_field  */
#line 293 "c2rob.y"
                             {
    Node *n = new TypeFields();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2274 "c2rob.tab.c"
    break;

  case 35: /* struct_field: scalar_decl ';'  */
#line 299 "c2rob.y"
                               {
    (yyval.node) = (yyvsp[-1].node);
}
#line 2282 "c2rob.tab.c"
    break;

  case 36: /* struct_field: declaration_specifiers TOK_IDENT ':' TOK_INTEGER_LITERAL ';'  */
#line 309 "c2rob.y"
          {
        (yyval.node) = applyDeclarationSpecifiers(
            new VariableDecl(
                (yyvsp[-4].spec)->type,
                (yyvsp[-3].str),
                atoi((yyvsp[-1].str))
            ),
            (yyvsp[-4].spec)
        );
    }
#line 2297 "c2rob.tab.c"
    break;

  case 37: /* func_decl: declaration_specifiers TOK_IDENT '(' optional_func_args ')'  */
#line 324 "c2rob.y"
                                 {
        (yyval.node) = new Function(
            (yyvsp[-4].spec)->type,
            (yyvsp[-3].str),
            (yyvsp[-1].node)
        );
    }
#line 2309 "c2rob.tab.c"
    break;

  case 38: /* func_decl: declaration_specifiers '*' TOK_IDENT '(' optional_func_args ')'  */
#line 337 "c2rob.y"
                                 {
        (yyval.node) = new Function(
            (yyvsp[-5].spec)->type,
            (yyvsp[-3].str),
            (yyvsp[-1].node)
        );

        ((Function*)(yyval.node))->markPointerResult();
    }
#line 2323 "c2rob.tab.c"
    break;

  case 39: /* func_impl: declaration_specifiers TOK_IDENT '(' optional_func_args ')' '{' optional_locals '}'  */
#line 352 "c2rob.y"
                              {
        (yyval.node) = new Function(
            (yyvsp[-7].spec)->type,
            (yyvsp[-6].str),
            (yyvsp[-4].node),
            (yyvsp[-1].node)
        );
    }
#line 2336 "c2rob.tab.c"
    break;

  case 40: /* func_impl: declaration_specifiers '*' TOK_IDENT '(' optional_func_args ')' '{' optional_locals '}'  */
#line 367 "c2rob.y"
                              {
        (yyval.node) = new Function(
            (yyvsp[-8].spec)->type,
            (yyvsp[-6].str),
            (yyvsp[-4].node),
            (yyvsp[-1].node)
        );

        ((Function*)(yyval.node))->markPointerResult();
    }
#line 2351 "c2rob.tab.c"
    break;

  case 41: /* optional_func_args: func_args  */
#line 380 "c2rob.y"
                               {
    for (Node *node : (yyvsp[0].node)->getChildren()) {
        auto *arg = static_cast<FuncArg*>(node);

        if (arg->getTypeName() == "void" && !arg->isSourcePointer())
            yyerror("a void parameter cannot have a name or qualifiers");
    }

    (yyval.node) = (yyvsp[0].node);
}
#line 2366 "c2rob.tab.c"
    break;

  case 42: /* optional_func_args: %empty  */
#line 391 "c2rob.y"
                            {
    (yyval.node) = new NodeArgs();
}
#line 2374 "c2rob.tab.c"
    break;

  case 43: /* func_args: func_args ',' func_arg  */
#line 396 "c2rob.y"
                                       {
    if((yyvsp[-2].node)->getChildren().empty() || !(yyvsp[0].node))
        yyerror("void must be the only item in the parameter list");

    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2386 "c2rob.tab.c"
    break;

  case 44: /* func_args: func_arg  */
#line 404 "c2rob.y"
                     {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2396 "c2rob.tab.c"
    break;

  case 45: /* pointer_arg: '*'  */
#line 410 "c2rob.y"
                  {
    (yyval.itg) = 1;
}
#line 2404 "c2rob.tab.c"
    break;

  case 46: /* pointer_arg: '*' '*'  */
#line 414 "c2rob.y"
                      {
    (yyval.itg) = 1;
}
#line 2412 "c2rob.tab.c"
    break;

  case 47: /* func_arg: declaration_specifiers  */
#line 420 "c2rob.y"
                                   {
        if (
            (yyvsp[0].spec)->type == "void"
            && !(yyvsp[0].spec)->isConst
            && !(yyvsp[0].spec)->isVolatile
            && !(yyvsp[0].spec)->isStatic
        ) {
            (yyval.node) = nullptr;
        } else {
            (yyval.node) = makeFunctionArgument(
                (yyvsp[0].spec),
                "_un" + to_string(current_unamed_arg++)
            );
        }
    }
#line 2432 "c2rob.tab.c"
    break;

  case 48: /* func_arg: declaration_specifiers pointer_arg  */
#line 438 "c2rob.y"
                                               {
        (yyval.node) = makeFunctionArgument(
            (yyvsp[-1].spec),
            "_un" + to_string(current_unamed_arg++),
            true
        );
    }
#line 2444 "c2rob.tab.c"
    break;

  case 49: /* func_arg: declaration_specifiers TOK_IDENT  */
#line 448 "c2rob.y"
                                                   {
        (yyval.node) = makeFunctionArgument(
            (yyvsp[-1].spec),
            (yyvsp[0].str)
        );
    }
#line 2455 "c2rob.tab.c"
    break;

  case 50: /* func_arg: declaration_specifiers pointer_arg TOK_IDENT  */
#line 459 "c2rob.y"
                      {
        (yyval.node) = makeFunctionArgument(
            (yyvsp[-2].spec),
            (yyvsp[0].str),
            true
        );
    }
#line 2467 "c2rob.tab.c"
    break;

  case 51: /* func_arg: declaration_specifiers pointer_arg TOK_IDENT '[' ']'  */
#line 472 "c2rob.y"
              {
        (yyval.node) = makeFunctionArgument(
            (yyvsp[-4].spec),
            (yyvsp[-2].str),
            true
        );
    }
#line 2479 "c2rob.tab.c"
    break;

  case 52: /* global: error ';'  */
#line 481 "c2rob.y"
                   { (yyval.node) = new Node(); }
#line 2485 "c2rob.tab.c"
    break;

  case 53: /* locals: locals local  */
#line 483 "c2rob.y"
                          {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2494 "c2rob.tab.c"
    break;

  case 54: /* locals: local  */
#line 488 "c2rob.y"
               {
    Node *n = new Node();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2504 "c2rob.tab.c"
    break;

  case 61: /* local: function_call ';'  */
#line 500 "c2rob.y"
                        {
        ((FunctionCall*)(yyvsp[-1].node))->setInExpr(false);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2513 "c2rob.tab.c"
    break;

  case 66: /* whilestmt: TOK_WHILE '(' expr ')' whilebody  */
#line 511 "c2rob.y"
                                             {
    (yyval.node) = new While((yyvsp[-2].node), (yyvsp[0].node), true);
}
#line 2521 "c2rob.tab.c"
    break;

  case 67: /* whilebody: '{' optional_locals '}'  */
#line 515 "c2rob.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2527 "c2rob.tab.c"
    break;

  case 68: /* whilebody: local  */
#line 516 "c2rob.y"
                  {
              (yyval.node) = new Node();
              (yyval.node)->append((yyvsp[0].node));
          }
#line 2536 "c2rob.tab.c"
    break;

  case 69: /* whilebody: ';'  */
#line 520 "c2rob.y"
                { (yyval.node) = new Node(); }
#line 2542 "c2rob.tab.c"
    break;

  case 70: /* optional_locals: locals  */
#line 523 "c2rob.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2548 "c2rob.tab.c"
    break;

  case 71: /* optional_locals: %empty  */
#line 524 "c2rob.y"
                         { (yyval.node) = new Node(); }
#line 2554 "c2rob.tab.c"
    break;

  case 72: /* returnstmt: TOK_RETURN expr ';'  */
#line 527 "c2rob.y"
                                 {
    (yyval.node) = new Return((yyvsp[-1].node));
}
#line 2562 "c2rob.tab.c"
    break;

  case 73: /* returnstmt: TOK_RETURN ';'  */
#line 531 "c2rob.y"
                            {
    (yyval.node) = new Return();
}
#line 2570 "c2rob.tab.c"
    break;

  case 74: /* attribution: scalar_or_array '=' expr  */
#line 536 "c2rob.y"
                                       {
    (yyval.node) = new Store((yyvsp[-2].node), "=", (yyvsp[0].node));
}
#line 2578 "c2rob.tab.c"
    break;

  case 75: /* attribution: scalar_or_array TOK_ATTRIBUTION expr  */
#line 542 "c2rob.y"
                                                       {
    (yyval.node) = new Store((yyvsp[-2].node), (yyvsp[-1].str), (yyvsp[0].node));
}
#line 2586 "c2rob.tab.c"
    break;

  case 76: /* attribution: factor TOK_UNARY_OPERATOR  */
#line 547 "c2rob.y"
                                               {
    (yyval.node) = new UnaryAttribution((yyvsp[-1].node), (yyvsp[0].str));
}
#line 2594 "c2rob.tab.c"
    break;

  case 77: /* forstmt: TOK_FOR '(' attribution ';' expr ';' attribution ')' local  */
#line 551 "c2rob.y"
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
#line 2609 "c2rob.tab.c"
    break;

  case 78: /* forstmt: TOK_FOR '(' attribution ';' expr ';' attribution ')' '{' locals '}'  */
#line 562 "c2rob.y"
                                                                                      {
    Node *nfor = new Container();
    nfor->append((yyvsp[-8].node));
    auto *loop = new While((yyvsp[-6].node), (yyvsp[-1].node));
    loop->setUpdate((yyvsp[-4].node));
    nfor->append(loop);
    (yyval.node) = nfor;
}
#line 2622 "c2rob.tab.c"
    break;

  case 79: /* ifstmt: TOK_IF '(' expr ')' local  */
#line 571 "c2rob.y"
                                   {
    (yyval.node) = new IfStmt((yyvsp[-2].node), (yyvsp[0].node));
}
#line 2630 "c2rob.tab.c"
    break;

  case 80: /* ifstmt: TOK_IF '(' expr ')' local elseblock  */
#line 575 "c2rob.y"
                                             {
    (yyval.node) = new IfStmt((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2638 "c2rob.tab.c"
    break;

  case 81: /* ifstmt: TOK_IF '(' expr ')' '{' locals '}'  */
#line 579 "c2rob.y"
                                            {
    (yyval.node) = new IfStmt((yyvsp[-4].node), (yyvsp[-1].node));
}
#line 2646 "c2rob.tab.c"
    break;

  case 82: /* ifstmt: TOK_IF '(' expr ')' '{' locals '}' elseblock  */
#line 583 "c2rob.y"
                                                      {
    (yyval.node) = new IfStmt((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
}
#line 2654 "c2rob.tab.c"
    break;

  case 83: /* multi_decl: declaration_specifiers multi_declarators  */
#line 588 "c2rob.y"
                                                            {
    string type = VariableDecl::convertTypeToRob(
    (yyvsp[-1].spec)->type
    );
    if (declared_types.contains(type))
        yyerror("multiple declaration: aggregate type not supported");
    if (type == "void")
        yyerror("multiple declaration: type 'void' cannot be used to declare variables");
    for (Node *node : (yyvsp[0].node)->getChildren()) {
        auto *decl = static_cast<VariableDecl*>(node);
        decl->setDeclarationType((yyvsp[-1].spec)->type);
        applyDeclarationSpecifiers(decl, (yyvsp[-1].spec));        if (decl->getIndex()) {
            string size = decl->getIndex()->toStr(0);
            if (!regex_match(size, regex("[1-9][0-9]*")))
                yyerror("multiple declaration: vector dimension must be a positive integer literal");
            else if (decl->getValue() && to_string(decl->getValue()->getChildren().size()) != size)
                yyerror("multiple declaration: array initialization must populate all elements");
        }
    }
    (yyval.node) = (yyvsp[0].node);
}
#line 2680 "c2rob.tab.c"
    break;

  case 84: /* multi_declarators: multi_declarator ',' multi_declarator  */
#line 610 "c2rob.y"
                                                                {
    (yyval.node) = new Container();
    (yyval.node)->append((yyvsp[-2].node));
    (yyval.node)->append((yyvsp[0].node));
}
#line 2690 "c2rob.tab.c"
    break;

  case 85: /* multi_declarators: multi_declarators ',' multi_declarator  */
#line 616 "c2rob.y"
                                                                 {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2699 "c2rob.tab.c"
    break;

  case 86: /* multi_declarator: TOK_IDENT  */
#line 622 "c2rob.y"
                                   {
    (yyval.node) = new VariableDecl("", (yyvsp[0].str));
}
#line 2707 "c2rob.tab.c"
    break;

  case 87: /* multi_declarator: TOK_IDENT '=' expr  */
#line 626 "c2rob.y"
                                            {
    (yyval.node) = new VariableDecl("", (yyvsp[-2].str), (yyvsp[0].node));
}
#line 2715 "c2rob.tab.c"
    break;

  case 88: /* multi_declarator: TOK_IDENT '[' expr ']'  */
#line 630 "c2rob.y"
                                                {
    (yyval.node) = new VariableDecl("", (yyvsp[-3].str), (yyvsp[-1].node), nullptr);
}
#line 2723 "c2rob.tab.c"
    break;

  case 89: /* multi_declarator: TOK_IDENT '[' expr ']' '=' array_values_decl  */
#line 634 "c2rob.y"
                                                                                  {
    (yyval.node) = new VariableDecl("", (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node));
}
#line 2731 "c2rob.tab.c"
    break;

  case 90: /* elseblock: TOK_ELSE '{' locals '}'  */
#line 638 "c2rob.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2737 "c2rob.tab.c"
    break;

  case 91: /* elseblock: TOK_ELSE local  */
#line 639 "c2rob.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2743 "c2rob.tab.c"
    break;

  case 92: /* scalar_init_decl: declaration_specifiers TOK_IDENT '=' expr  */
#line 645 "c2rob.y"
               {
        (yyval.node) = applyDeclarationSpecifiers(
            new VariableDecl(
                (yyvsp[-3].spec)->type,
                (yyvsp[-2].str),
                (yyvsp[0].node)
            ),
            (yyvsp[-3].spec)
        );
    }
#line 2758 "c2rob.tab.c"
    break;

  case 93: /* scalar_init_decl: declaration_specifiers TOK_IDENT '=' array_values_decl  */
#line 661 "c2rob.y"
                                   {
        (yyval.node) = applyDeclarationSpecifiers(
            new InitializedType(
                (yyvsp[-3].spec)->type,
                (yyvsp[-2].str),
                (yyvsp[0].node)
            ),
            (yyvsp[-3].spec)
        );
    }
#line 2773 "c2rob.tab.c"
    break;

  case 94: /* scalar_decl: declaration_specifiers TOK_IDENT  */
#line 675 "c2rob.y"
                                                   {
        (yyval.node) = applyDeclarationSpecifiers(
            new VariableDecl(
                (yyvsp[-1].spec)->type,
                (yyvsp[0].str)
            ),
            (yyvsp[-1].spec)
        );
    }
#line 2787 "c2rob.tab.c"
    break;

  case 95: /* array_init_decl: declaration_specifiers TOK_IDENT '[' expr ']' '=' array_values_decl  */
#line 691 "c2rob.y"
                                   {
        ((NodeArgs*)(yyvsp[0].node))->setArrayInitType(
            (yyvsp[-6].spec)->type
        );

        (yyval.node) = applyDeclarationSpecifiers(
            new VariableDecl(
                (yyvsp[-6].spec)->type,
                (yyvsp[-5].str),
                (yyvsp[-3].node),
                (yyvsp[0].node)
            ),
            (yyvsp[-6].spec)
        );
    }
#line 2807 "c2rob.tab.c"
    break;

  case 96: /* array_decl: declaration_specifiers TOK_IDENT '[' expr ']'  */
#line 711 "c2rob.y"
                        {
        (yyval.node) = applyDeclarationSpecifiers(
            new VariableDecl(
                (yyvsp[-4].spec)->type,
                (yyvsp[-3].str),
                (yyvsp[-1].node),
                nullptr
            ),
            (yyvsp[-4].spec)
        );
    }
#line 2823 "c2rob.tab.c"
    break;

  case 97: /* array_init_decl: declaration_specifiers TOK_IDENT '[' expr ']' '=' struct_values_decl  */
#line 728 "c2rob.y"
                                    {
        (yyval.node) = applyDeclarationSpecifiers(
            new StructVariableDecl(
                (yyvsp[-6].spec)->type,
                (yyvsp[-5].str),
                (yyvsp[-3].node),
                (yyvsp[0].node)
            ),
            (yyvsp[-6].spec)
        );
    }
#line 2839 "c2rob.tab.c"
    break;

  case 98: /* struct_values_decl: '{' array_values_decls '}'  */
#line 741 "c2rob.y"
                                                      { (yyval.node) = (yyvsp[-1].node); }
#line 2845 "c2rob.tab.c"
    break;

  case 99: /* array_values_decls: array_values_decls ',' array_values_decl  */
#line 743 "c2rob.y"
                                                                  {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2854 "c2rob.tab.c"
    break;

  case 100: /* array_values_decls: array_values_decl  */
#line 748 "c2rob.y"
                                       {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2864 "c2rob.tab.c"
    break;

  case 101: /* array_values_decl: '{' array_values '}'  */
#line 754 "c2rob.y"
                                         { (yyval.node) = (yyvsp[-1].node); }
#line 2870 "c2rob.tab.c"
    break;

  case 102: /* array_values: array_values ',' expr  */
#line 756 "c2rob.y"
                                         {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2879 "c2rob.tab.c"
    break;

  case 103: /* array_values: expr  */
#line 761 "c2rob.y"
                    {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2889 "c2rob.tab.c"
    break;

  case 104: /* expr: expr TOK_CMP_RELAT expr  */
#line 767 "c2rob.y"
                                          { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].str)); }
#line 2895 "c2rob.tab.c"
    break;

  case 105: /* expr: expr TOK_CMP_EQNEQ expr  */
#line 768 "c2rob.y"
                                          { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].str)); }
#line 2901 "c2rob.tab.c"
    break;

  case 106: /* expr: expr TOK_AND expr  */
#line 769 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "and"); }
#line 2907 "c2rob.tab.c"
    break;

  case 107: /* expr: expr TOK_OR expr  */
#line 770 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "or"); }
#line 2913 "c2rob.tab.c"
    break;

  case 108: /* expr: expr '+' expr  */
#line 771 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "+"); }
#line 2919 "c2rob.tab.c"
    break;

  case 109: /* expr: expr '-' expr  */
#line 772 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "-"); }
#line 2925 "c2rob.tab.c"
    break;

  case 110: /* expr: expr '*' expr  */
#line 773 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "*"); }
#line 2931 "c2rob.tab.c"
    break;

  case 111: /* expr: expr '/' expr  */
#line 774 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "/"); }
#line 2937 "c2rob.tab.c"
    break;

  case 112: /* expr: expr '%' expr  */
#line 775 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "%"); }
#line 2943 "c2rob.tab.c"
    break;

  case 113: /* expr: expr '&' expr  */
#line 776 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "&"); }
#line 2949 "c2rob.tab.c"
    break;

  case 114: /* expr: expr '|' expr  */
#line 777 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "|"); }
#line 2955 "c2rob.tab.c"
    break;

  case 115: /* expr: expr '^' expr  */
#line 778 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "^"); }
#line 2961 "c2rob.tab.c"
    break;

  case 116: /* expr: '!' expr  */
#line 779 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "!"); }
#line 2967 "c2rob.tab.c"
    break;

  case 117: /* expr: '~' expr  */
#line 780 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "~"); }
#line 2973 "c2rob.tab.c"
    break;

  case 118: /* expr: '-' expr  */
#line 781 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "-"); }
#line 2979 "c2rob.tab.c"
    break;

  case 119: /* expr: '+' expr  */
#line 782 "c2rob.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2985 "c2rob.tab.c"
    break;

  case 120: /* expr: '(' expr ')'  */
#line 783 "c2rob.y"
                                { (yyval.node) = new Parenthesis((yyvsp[-1].node)); }
#line 2991 "c2rob.tab.c"
    break;

  case 124: /* factor: TOK_INT  */
#line 789 "c2rob.y"
                      {
    (yyval.node) = new Integer((yyvsp[0].itg));
}
#line 2999 "c2rob.tab.c"
    break;

  case 125: /* factor: TOK_FLOAT  */
#line 793 "c2rob.y"
                        {
    (yyval.node) = new Float((yyvsp[0].flt));
}
#line 3007 "c2rob.tab.c"
    break;

  case 126: /* factor: TOK_STRING  */
#line 797 "c2rob.y"
                         {
    (yyval.node) = new Ident((yyvsp[0].str));
}
#line 3015 "c2rob.tab.c"
    break;

  case 127: /* factor: TOK_INTEGER_LITERAL  */
#line 801 "c2rob.y"
                                  {
    (yyval.node) = new IntegerToken((yyvsp[0].str));
}
#line 3023 "c2rob.tab.c"
    break;

  case 128: /* factor: factor TOK_UNARY_OPERATOR  */
#line 805 "c2rob.y"
                                          {
    (yyval.node) = new Unary((yyvsp[-1].node), (yyvsp[0].str));
}
#line 3031 "c2rob.tab.c"
    break;

  case 129: /* scalar_or_array: TOK_IDENT  */
#line 809 "c2rob.y"
                                {
    (yyval.node) = new Ident((yyvsp[0].str));
}
#line 3039 "c2rob.tab.c"
    break;

  case 130: /* scalar_or_array: TOK_IDENT '[' expr ']'  */
#line 813 "c2rob.y"
                                             {
    (yyval.node) = new LoadArray((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 3047 "c2rob.tab.c"
    break;

  case 131: /* scalar_or_array: TOK_IDENT '.' TOK_IDENT  */
#line 817 "c2rob.y"
                                                   {
    (yyval.node) = new LoadField((yyvsp[-2].str), (yyvsp[0].str));
}
#line 3055 "c2rob.tab.c"
    break;

  case 132: /* scalar_or_array: TOK_IDENT '[' expr ']' '.' TOK_IDENT  */
#line 821 "c2rob.y"
                                                                {
    (yyval.node) = new LoadArrayField((yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].str));
}
#line 3063 "c2rob.tab.c"
    break;

  case 133: /* function_call: TOK_IDENT '(' ')'  */
#line 825 "c2rob.y"
                                      {
    (yyval.node) = new FunctionCall((yyvsp[-2].str));
}
#line 3071 "c2rob.tab.c"
    break;

  case 134: /* function_call: TOK_IDENT '(' func_call_args ')'  */
#line 829 "c2rob.y"
                                                           {
    (yyval.node) = new FunctionCall((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 3079 "c2rob.tab.c"
    break;

  case 135: /* func_call_args: func_call_args ',' expr  */
#line 833 "c2rob.y"
                                             {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 3088 "c2rob.tab.c"
    break;

  case 136: /* func_call_args: expr  */
#line 838 "c2rob.y"
                      {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 3098 "c2rob.tab.c"
    break;


#line 3102 "c2rob.tab.c"

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

#line 844 "c2rob.y"

