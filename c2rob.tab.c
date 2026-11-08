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

DeclarationSpecifiers *resolveDeclarationSpecifiers(DeclarationSpecifiers *spec) {
    try { spec->resolve(); }
    catch (const std::exception &error) { yyerror(error.what()); spec->type = "int32"; }
    return spec;
}

Node *applyDeclarationSpecifiers(Node *node, const DeclarationSpecifiers *spec) {
    if (spec->isConst) node->markSourceConst();
    if (spec->isVolatile) node->markSourceVolatile();
    if (spec->isStatic) node->markSourceStatic();
    return node;
}

FuncArg *makeFunctionArgument(DeclarationSpecifiers *spec, const string &name, bool pointer = false) {
    string type = spec->type;
    if (pointer && (type == "char" || type == "int32")) type += "*";
    auto *arg = new FuncArg(type, name, pointer);
    applyDeclarationSpecifiers(arg, spec);
    if (spec->isStatic) yyerror("declaration: static is not allowed on a function parameter");
    return arg;
}

Function *makeFunctionHeader(const DeclarationSpecifiers *spec, const char *name, Node *args) {
    auto *function = new Function(spec->type, name, args);
    if (spec->isStatic) function->markSourceStatic();
    return function;
}

// A declaration can attach noinline to the function before its definition.
void propagateNoInline(Node *program) {
    set<string> names;
    for (Node *node : program->getChildren())
        if (auto *function = dynamic_cast<Function*>(node); function && function->hasNoInline())
            names.insert(function->getName());
    for (Node *node : program->getChildren()) {
        auto *function = dynamic_cast<Function*>(node);
        if (!function || !names.contains(function->getName())) continue;
        // The emitter cannot represent C's internal linkage for functions.
        if (function->isSourceStatic()) {
            fprintf(stderr, "%s:%d: function attribute: static linkage with noinline is outside this pilot: %s\n",
                    build_file_name, function->getLineNo(), function->getName().c_str());
            ++errorcount;
        }
        function->markNoInline();
    }
}

#line 132 "c2rob.tab.c"

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
  YYSYMBOL_TOK_GNU_ATTRIBUTE = 24,         /* TOK_GNU_ATTRIBUTE  */
  YYSYMBOL_TOK_STATIC = 25,                /* TOK_STATIC  */
  YYSYMBOL_TOK_VOLATILE = 26,              /* TOK_VOLATILE  */
  YYSYMBOL_TOK_CONST = 27,                 /* TOK_CONST  */
  YYSYMBOL_TOK_TYPE_SPEC = 28,             /* TOK_TYPE_SPEC  */
  YYSYMBOL_29_ = 29,                       /* '|'  */
  YYSYMBOL_30_ = 30,                       /* '^'  */
  YYSYMBOL_31_ = 31,                       /* '&'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '%'  */
  YYSYMBOL_UMINUS = 37,                    /* UMINUS  */
  YYSYMBOL_38_ = 38,                       /* '!'  */
  YYSYMBOL_39_ = 39,                       /* '~'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '['  */
  YYSYMBOL_48_ = 48,                       /* ']'  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_globals = 53,                   /* globals  */
  YYSYMBOL_global = 54,                    /* global  */
  YYSYMBOL_builtin_specifiers = 55,        /* builtin_specifiers  */
  YYSYMBOL_specifier_qualifier = 56,       /* specifier_qualifier  */
  YYSYMBOL_specifier_qualifiers = 57,      /* specifier_qualifiers  */
  YYSYMBOL_declaration_specifiers = 58,    /* declaration_specifiers  */
  YYSYMBOL_include = 59,                   /* include  */
  YYSYMBOL_typedef_decl = 60,              /* typedef_decl  */
  YYSYMBOL_struct_decl = 61,               /* struct_decl  */
  YYSYMBOL_struct_fields = 62,             /* struct_fields  */
  YYSYMBOL_struct_field = 63,              /* struct_field  */
  YYSYMBOL_function_attribute = 64,        /* function_attribute  */
  YYSYMBOL_function_header = 65,           /* function_header  */
  YYSYMBOL_func_decl = 66,                 /* func_decl  */
  YYSYMBOL_func_impl = 67,                 /* func_impl  */
  YYSYMBOL_optional_func_args = 68,        /* optional_func_args  */
  YYSYMBOL_func_args = 69,                 /* func_args  */
  YYSYMBOL_pointer_arg = 70,               /* pointer_arg  */
  YYSYMBOL_func_arg = 71,                  /* func_arg  */
  YYSYMBOL_locals = 72,                    /* locals  */
  YYSYMBOL_local = 73,                     /* local  */
  YYSYMBOL_whilestmt = 74,                 /* whilestmt  */
  YYSYMBOL_whilebody = 75,                 /* whilebody  */
  YYSYMBOL_optional_locals = 76,           /* optional_locals  */
  YYSYMBOL_returnstmt = 77,                /* returnstmt  */
  YYSYMBOL_attribution = 78,               /* attribution  */
  YYSYMBOL_forstmt = 79,                   /* forstmt  */
  YYSYMBOL_ifstmt = 80,                    /* ifstmt  */
  YYSYMBOL_elseblock = 81,                 /* elseblock  */
  YYSYMBOL_multi_decl = 82,                /* multi_decl  */
  YYSYMBOL_multi_declarators = 83,         /* multi_declarators  */
  YYSYMBOL_multi_declarator = 84,          /* multi_declarator  */
  YYSYMBOL_scalar_init_decl = 85,          /* scalar_init_decl  */
  YYSYMBOL_scalar_decl = 86,               /* scalar_decl  */
  YYSYMBOL_array_init_decl = 87,           /* array_init_decl  */
  YYSYMBOL_array_decl = 88,                /* array_decl  */
  YYSYMBOL_struct_values_decl = 89,        /* struct_values_decl  */
  YYSYMBOL_array_values_decls = 90,        /* array_values_decls  */
  YYSYMBOL_array_values_decl = 91,         /* array_values_decl  */
  YYSYMBOL_array_values = 92,              /* array_values  */
  YYSYMBOL_expr = 93,                      /* expr  */
  YYSYMBOL_factor = 94,                    /* factor  */
  YYSYMBOL_scalar_or_array = 95,           /* scalar_or_array  */
  YYSYMBOL_function_call = 96,             /* function_call  */
  YYSYMBOL_func_call_args = 97             /* func_call_args  */
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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   739

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  270

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,    38,     2,     2,     2,    36,    31,     2,
      40,    41,    34,    32,    46,    33,    50,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    42,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    29,    44,    39,     2,     2,     2,
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
      25,    26,    27,    28,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   141,   147,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   167,   168,   169,   172,   173,
     174,   177,   178,   182,   183,   184,   185,   186,   187,   188,
     191,   198,   205,   209,   214,   220,   224,   229,   236,   240,
     245,   251,   257,   258,   263,   269,   278,   282,   290,   296,
     300,   305,   313,   317,   321,   325,   329,   331,   336,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     356,   360,   361,   365,   368,   369,   372,   376,   381,   387,
     392,   396,   407,   416,   420,   424,   428,   432,   433,   436,
     457,   463,   469,   473,   477,   481,   486,   491,   496,   501,
     506,   510,   515,   517,   522,   528,   530,   535,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   560,   561,   563,   567,
     571,   575,   579,   583,   587,   591,   595,   599,   603,   607,
     612
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
  "TOK_GNU_ATTRIBUTE", "TOK_STATIC", "TOK_VOLATILE", "TOK_CONST",
  "TOK_TYPE_SPEC", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UMINUS", "'!'", "'~'", "'('", "')'", "';'", "'{'", "'}'", "':'", "','",
  "'['", "']'", "'='", "'.'", "$accept", "program", "globals", "global",
  "builtin_specifiers", "specifier_qualifier", "specifier_qualifiers",
  "declaration_specifiers", "include", "typedef_decl", "struct_decl",
  "struct_fields", "struct_field", "function_attribute", "function_header",
  "func_decl", "func_impl", "optional_func_args", "func_args",
  "pointer_arg", "func_arg", "locals", "local", "whilestmt", "whilebody",
  "optional_locals", "returnstmt", "attribution", "forstmt", "ifstmt",
  "elseblock", "multi_decl", "multi_declarators", "multi_declarator",
  "scalar_init_decl", "scalar_decl", "array_init_decl", "array_decl",
  "struct_values_decl", "array_values_decls", "array_values_decl",
  "array_values", "expr", "factor", "scalar_or_array", "function_call",
  "func_call_args", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-210)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-133)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     658,   -18,   154,  -210,    27,   121,     0,  -210,  -210,  -210,
    -210,    41,   600,  -210,   176,  -210,    61,     9,  -210,    38,
      57,   121,   -17,    89,  -210,    93,    94,    99,   109,   115,
    -210,   154,    26,    56,    74,   118,  -210,  -210,  -210,  -210,
     154,   176,  -210,   122,   158,   170,   130,   140,  -210,  -210,
     196,   711,  -210,  -210,  -210,  -210,  -210,  -210,  -210,   121,
    -210,  -210,   204,   154,   121,   489,   458,   168,   171,   207,
     207,   180,    35,  -210,  -210,  -210,   185,   189,   191,   238,
    -210,   225,   711,  -210,  -210,   193,  -210,   190,  -210,  -210,
     200,   203,   205,   214,   220,   223,     5,   224,   243,    69,
    -210,   226,   208,    19,   242,   240,  -210,    31,   489,   489,
     489,   489,   489,   277,   283,  -210,  -210,   489,  -210,   503,
     121,   121,    43,  -210,  -210,   121,   467,   489,   294,   489,
     172,   489,  -210,   533,   103,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,   287,   489,   489,  -210,   255,  -210,  -210,
    -210,   264,  -210,   282,   318,  -210,   121,  -210,  -210,  -210,
    -210,   563,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,    14,  -210,   145,   622,   278,   281,
     489,   489,   292,  -210,   622,    75,   307,  -210,   577,   293,
     609,  -210,   622,   622,   314,  -210,  -210,   297,  -210,  -210,
     638,   665,   388,   296,   677,   515,   350,   188,   188,  -210,
    -210,  -210,   310,  -210,   489,  -210,  -210,   316,   622,  -210,
    -210,   489,   304,   384,   489,   353,   315,   317,   458,  -210,
     320,   622,   319,   622,   360,   711,   357,   547,  -210,   711,
    -210,  -210,  -210,  -210,   150,  -210,   331,  -210,   112,   412,
    -210,   172,   332,  -210,   331,  -210,   357,   711,  -210,   336,
    -210,  -210,  -210,   247,   440,  -210,   711,  -210,   276,  -210
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    25,    30,     0,     0,     0,    20,    19,    18,
      15,     0,     0,     4,    23,    21,     0,     0,    14,     0,
       0,     0,    42,     0,    13,     0,     0,     0,     0,     0,
      56,    26,    29,     0,     0,     0,     1,     3,    16,    17,
      27,    24,    22,    92,     0,     0,    89,     0,    11,    12,
       0,    75,    43,    10,     9,     6,     5,     7,     8,     0,
      29,    31,     0,    28,    46,     0,     0,     0,     0,     0,
       0,     0,   133,   129,   128,   130,     0,     0,     0,     0,
     131,     0,    74,    58,    68,     0,    69,     0,    67,    66,
       0,     0,     0,     0,     0,     0,   127,   126,     0,     0,
      34,     0,     0,    51,     0,    45,    48,   133,     0,     0,
       0,     0,     0,     0,   125,   127,   126,     0,    97,    93,
      46,    46,    92,    91,    90,    46,     0,     0,     0,     0,
       0,     0,    77,     0,    92,    57,    44,    64,    59,    61,
      60,    62,    63,    80,     0,     0,    65,    98,    32,    33,
      35,     0,    53,    49,    52,    38,     0,   123,   122,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,   132,     0,   107,     0,     0,
       0,     0,     0,   137,   140,     0,     0,   135,     0,     0,
       0,    76,    79,    78,     0,    37,    50,    54,    47,   124,
     111,   110,   109,   108,   118,   119,   117,   112,   113,   114,
     115,   116,     0,   105,     0,    39,    41,     0,    93,    40,
     138,     0,   134,     0,     0,     0,     0,     0,     0,   101,
      95,   106,    94,   139,     0,     0,    83,     0,    73,    75,
      72,    70,    36,    55,     0,   104,     0,   136,     0,     0,
      84,     0,     0,   102,     0,    95,    85,     0,    88,     0,
      71,   103,    86,     0,     0,    87,     0,    81,     0,    82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,  -210,  -210,   376,   375,    -6,     4,    34,  -210,  -210,
    -210,  -210,   295,   105,  -210,  -210,  -210,    45,  -210,  -210,
     236,  -199,   -81,  -210,  -210,   164,  -210,  -128,  -210,  -210,
     137,    11,  -210,   -56,    16,    15,    17,    20,  -210,  -210,
    -209,  -210,   -61,   -51,   -30,    -9,  -210
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    81,    18,    19,
      20,    99,   100,    21,    22,    23,    24,   104,   105,   154,
     106,    82,    83,    84,   241,    85,    86,    87,    88,    89,
     250,    90,    46,    47,    91,    92,    93,    94,   229,   244,
     118,   176,   177,   114,   115,   116,   185
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,   135,   189,   230,   113,   119,    31,     6,    39,   144,
      42,    25,    43,   123,   124,    27,    26,    28,   133,   245,
      29,    96,   152,    25,    30,    42,    51,    27,    26,    28,
      32,    95,    29,     6,    17,    39,   248,   255,   -25,    34,
      35,    36,    97,    44,    63,   261,    17,   157,   158,   159,
     160,   161,    96,   153,   145,    50,  -100,    42,   263,    60,
       7,     8,     9,   212,    40,   184,   186,   268,   188,    59,
     190,   126,     2,    97,   101,   126,    31,    61,   127,    95,
      48,   128,   127,   192,   193,   128,     7,     8,     9,    10,
     180,    33,   181,    98,     7,     8,     9,    10,   103,    49,
      96,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   148,   101,    72,   220,    73,    74,   217,
     218,   221,    45,   259,     2,    75,    76,    52,    77,    78,
      79,    53,    80,    98,    33,    54,    55,     7,     8,     9,
      10,    56,   236,    33,   240,   -98,     7,     8,     9,    10,
      65,    57,    66,   231,   103,   103,   256,    58,    62,   103,
     233,    67,    64,   237,   -98,   178,   179,   135,   258,    65,
     182,    66,    95,    68,    95,   107,    69,    73,    74,     7,
       8,     9,   135,   267,    95,    75,    70,   135,    95,   213,
     103,   214,    80,    96,   253,    96,   254,    95,    95,    71,
      95,     7,     8,     9,    38,    96,    95,   102,   120,    96,
     122,   121,    95,    95,    97,    95,    97,    95,    96,    96,
     125,    96,   171,   172,   173,   129,    97,    96,   134,   130,
      97,   131,   137,    96,    96,   143,    96,   136,    96,    97,
      97,   107,   138,    73,    74,   139,   147,   140,    97,   151,
      72,    75,    73,    74,    97,    97,   141,    97,    80,    97,
      75,    76,   142,    77,    78,    79,   146,    80,   150,    33,
     108,   109,     7,     8,     9,    10,   110,   111,   112,    72,
     132,    73,    74,   155,   162,   163,   156,   164,   165,    75,
      76,   265,    77,    78,    79,   175,    80,   187,    33,  -132,
     194,     7,     8,     9,    10,   195,   166,   167,   168,   169,
     170,   171,   172,   173,   162,   163,   196,   164,   165,   215,
     269,   197,   216,   162,   163,   174,   164,   165,   169,   170,
     171,   172,   173,   219,   226,   224,   166,   167,   168,   169,
     170,   171,   172,   173,   227,   166,   167,   168,   169,   170,
     171,   172,   173,   228,   234,   222,    72,   242,    73,    74,
     164,   165,   -99,   247,   232,   243,    75,    76,   246,    77,
      78,    79,   249,    80,   117,    33,   260,   264,     7,     8,
       9,    10,   169,   170,   171,   172,   173,    72,    37,    73,
      74,    41,   198,   262,   149,   238,   239,    75,    76,   165,
      77,    78,    79,   252,    80,     0,    33,     0,     0,     7,
       8,     9,    10,     0,     0,    72,     0,    73,    74,     0,
     169,   170,   171,   172,   173,    75,    76,   235,    77,    78,
      79,     0,    80,     0,    33,     0,     0,     7,     8,     9,
      10,     0,     0,    72,     0,    73,    74,     0,     0,     0,
       0,     0,     0,    75,    76,   257,    77,    78,    79,     0,
      80,   107,    33,    73,    74,     7,     8,     9,    10,     0,
     107,    75,    73,    74,     0,     0,     0,     0,    80,     0,
      75,     0,     0,   266,     0,     0,     0,    80,     0,     0,
     108,   109,   107,     0,    73,    74,   110,   111,   112,   108,
     109,   117,    75,     0,     0,   110,   111,   112,   183,    80,
     162,   163,     0,   164,   165,     0,     0,     0,     0,     0,
       0,   108,   109,     0,     0,   164,   165,   110,   111,   112,
       0,     0,   166,   167,   168,   169,   170,   171,   172,   173,
     162,   163,     0,   164,   165,   -96,   168,   169,   170,   171,
     172,   173,     0,     0,   162,   163,     0,   164,   165,     0,
       0,     0,   166,   167,   168,   169,   170,   171,   172,   173,
     162,   163,     0,   164,   165,   191,   166,   167,   168,   169,
     170,   171,   172,   173,   162,   163,     0,   164,   165,   251,
       0,     0,   166,   167,   168,   169,   170,   171,   172,   173,
      -2,     1,     0,     2,   199,     0,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,   162,   163,   223,   164,
     165,     3,     4,     5,     6,     7,     8,     9,    10,   162,
     163,     0,   164,   165,     0,     0,     0,     0,   166,   167,
     168,   169,   170,   171,   172,   173,   163,     0,   164,   165,
     225,   166,   167,   168,   169,   170,   171,   172,   173,     1,
       0,     2,     0,     0,     0,     0,     0,   166,   167,   168,
     169,   170,   171,   172,   173,   164,   165,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,   164,   165,     0,
       0,     0,     0,     0,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,    72,     0,    73,    74,     0,     0,
       0,     0,     0,     0,    75,    76,     0,    77,    78,    79,
       0,    80,     0,    33,     0,     0,     7,     8,     9,    10
};

static const yytype_int16 yycheck[] =
{
      51,    82,   130,   212,    65,    66,     2,    24,    14,     4,
      16,     0,     3,    69,    70,     0,     0,     0,    79,   228,
       0,    51,     3,    12,    42,    31,    43,    12,    12,    12,
       3,    82,    12,    24,     0,    41,   235,   246,     3,     5,
      40,     0,    51,    34,    40,   254,    12,   108,   109,   110,
     111,   112,    82,    34,    49,    21,    42,    63,   257,     3,
      25,    26,    27,    49,     3,   126,   127,   266,   129,    43,
     131,    40,     3,    82,    59,    40,    72,     3,    47,   130,
      42,    50,    47,   144,   145,    50,    25,    26,    27,    28,
      47,    22,    49,    59,    25,    26,    27,    28,    64,    42,
     130,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,    44,    99,     3,    41,     5,     6,   180,
     181,    46,    17,   251,     3,    13,    14,    22,    16,    17,
      18,    42,    20,    99,    22,    42,    42,    25,    26,    27,
      28,    42,   223,    22,   225,    42,    25,    26,    27,    28,
      47,    42,    49,   214,   120,   121,    44,    42,    40,   125,
     221,     3,    40,   224,    42,   120,   121,   248,   249,    47,
     125,    49,   223,     3,   225,     3,    46,     5,     6,    25,
      26,    27,   263,   264,   235,    13,    46,   268,   239,    44,
     156,    46,    20,   223,    44,   225,    46,   248,   249,     3,
     251,    25,    26,    27,    28,   235,   257,     3,    40,   239,
       3,    40,   263,   264,   223,   266,   225,   268,   248,   249,
      40,   251,    34,    35,    36,    40,   235,   257,     3,    40,
     239,    40,    42,   263,   264,    12,   266,    44,   268,   248,
     249,     3,    42,     5,     6,    42,     3,    42,   257,    41,
       3,    13,     5,     6,   263,   264,    42,   266,    20,   268,
      13,    14,    42,    16,    17,    18,    42,    20,    42,    22,
      32,    33,    25,    26,    27,    28,    38,    39,    40,     3,
      42,     5,     6,    41,     7,     8,    46,    10,    11,    13,
      14,    44,    16,    17,    18,    12,    20,     3,    22,    12,
      45,    25,    26,    27,    28,    41,    29,    30,    31,    32,
      33,    34,    35,    36,     7,     8,    34,    10,    11,    41,
      44,     3,    41,     7,     8,    48,    10,    11,    32,    33,
      34,    35,    36,    41,    20,    42,    29,    30,    31,    32,
      33,    34,    35,    36,    47,    29,    30,    31,    32,    33,
      34,    35,    36,    43,    50,    48,     3,    42,     5,     6,
      10,    11,    42,     3,    48,    48,    13,    14,    49,    16,
      17,    18,    15,    20,    43,    22,    44,    41,    25,    26,
      27,    28,    32,    33,    34,    35,    36,     3,    12,     5,
       6,    16,   156,   256,    99,    42,    43,    13,    14,    11,
      16,    17,    18,   239,    20,    -1,    22,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,     3,    -1,     5,     6,    -1,
      32,    33,    34,    35,    36,    13,    14,    43,    16,    17,
      18,    -1,    20,    -1,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,     3,    -1,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    43,    16,    17,    18,    -1,
      20,     3,    22,     5,     6,    25,    26,    27,    28,    -1,
       3,    13,     5,     6,    -1,    -1,    -1,    -1,    20,    -1,
      13,    -1,    -1,    43,    -1,    -1,    -1,    20,    -1,    -1,
      32,    33,     3,    -1,     5,     6,    38,    39,    40,    32,
      33,    43,    13,    -1,    -1,    38,    39,    40,    41,    20,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    10,    11,    38,    39,    40,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
       7,     8,    -1,    10,    11,    42,    31,    32,    33,    34,
      35,    36,    -1,    -1,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
       7,     8,    -1,    10,    11,    42,    29,    30,    31,    32,
      33,    34,    35,    36,     7,     8,    -1,    10,    11,    42,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     1,    -1,     3,    41,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,     7,     8,    41,    10,
      11,    21,    22,    23,    24,    25,    26,    27,    28,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,     8,    -1,    10,    11,
      41,    29,    30,    31,    32,    33,    34,    35,    36,     1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    10,    11,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    10,    11,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,     3,    -1,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    16,    17,    18,
      -1,    20,    -1,    22,    -1,    -1,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    21,    22,    23,    24,    25,    26,    27,
      28,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    64,    65,    66,    67,    82,    85,    86,    87,    88,
      42,    57,     3,    22,    58,    40,     0,    54,    28,    56,
       3,    55,    56,     3,    34,    64,    83,    84,    42,    42,
      58,    43,    64,    42,    42,    42,    42,    42,    42,    43,
       3,     3,    40,    57,    40,    47,    49,     3,     3,    46,
      46,     3,     3,     5,     6,    13,    14,    16,    17,    18,
      20,    58,    72,    73,    74,    76,    77,    78,    79,    80,
      82,    85,    86,    87,    88,    94,    95,    96,    58,    62,
      63,    86,     3,    58,    68,    69,    71,     3,    32,    33,
      38,    39,    40,    93,    94,    95,    96,    43,    91,    93,
      40,    40,     3,    84,    84,    40,    40,    47,    50,    40,
      40,    40,    42,    93,     3,    73,    44,    42,    42,    42,
      42,    42,    42,    12,     4,    49,    42,     3,    44,    63,
      42,    41,     3,    34,    70,    41,    46,    93,    93,    93,
      93,    93,     7,     8,    10,    11,    29,    30,    31,    32,
      33,    34,    35,    36,    48,    12,    92,    93,    68,    68,
      47,    49,    68,    41,    93,    97,    93,     3,    93,    78,
      93,    42,    93,    93,    45,    41,    34,     3,    71,    41,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    49,    44,    46,    41,    41,    93,    93,    41,
      41,    46,    48,    41,    42,    41,    20,    47,    43,    89,
      91,    93,    48,    93,    50,    43,    73,    93,    42,    43,
      73,    75,    42,    48,    90,    91,    49,     3,    72,    15,
      81,    42,    76,    44,    46,    91,    44,    43,    73,    78,
      44,    91,    81,    72,    41,    44,    43,    73,    72,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    56,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    61,    62,    62,    63,    63,    64,    65,    65,
      65,    65,    66,    66,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    54,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    80,    80,    80,    80,    81,    81,    82,
      83,    83,    84,    84,    84,    84,    85,    85,    86,    87,
      88,    87,    89,    90,    90,    91,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    96,    96,    97,
      97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     2,     3,     2,
       1,     3,     5,     2,     1,     2,     5,     6,     5,     6,
       6,     6,     1,     2,     4,     1,     0,     3,     1,     1,
       2,     1,     2,     2,     3,     5,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       5,     3,     1,     1,     1,     0,     3,     2,     3,     3,
       2,     9,    11,     5,     6,     7,     8,     4,     2,     2,
       3,     3,     1,     3,     4,     6,     4,     4,     2,     7,
       5,     7,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     4,     3,     6,     3,     4,     3,
       1
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
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1092 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_ATTRIBUTION: /* TOK_ATTRIBUTION  */
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1098 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_FLOAT: /* TOK_FLOAT  */
#line 106 "c2rob.y"
         { fprintf(yyo, "%lf", ((*yyvaluep).flt)); }
#line 1104 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INT: /* TOK_INT  */
#line 105 "c2rob.y"
         { fprintf(yyo, "%lld", static_cast<long long>(((*yyvaluep).itg))); }
#line 1110 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_CMP_EQNEQ: /* TOK_CMP_EQNEQ  */
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1116 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_CMP_RELAT: /* TOK_CMP_RELAT  */
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1122 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_UNARY_OPERATOR: /* TOK_UNARY_OPERATOR  */
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1128 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_STRING: /* TOK_STRING  */
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1134 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INTEGER_LITERAL: /* TOK_INTEGER_LITERAL  */
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1140 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_INCLUDE: /* TOK_INCLUDE  */
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1146 "c2rob.tab.c"
        break;

    case YYSYMBOL_TOK_TYPE_SPEC: /* TOK_TYPE_SPEC  */
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1152 "c2rob.tab.c"
        break;

    case YYSYMBOL_specifier_qualifier: /* specifier_qualifier  */
#line 104 "c2rob.y"
         { fprintf(yyo, "%s", ((*yyvaluep).str)); }
#line 1158 "c2rob.tab.c"
        break;

    case YYSYMBOL_function_attribute: /* function_attribute  */
#line 105 "c2rob.y"
         { fprintf(yyo, "%lld", static_cast<long long>(((*yyvaluep).itg))); }
#line 1164 "c2rob.tab.c"
        break;

    case YYSYMBOL_pointer_arg: /* pointer_arg  */
#line 105 "c2rob.y"
         { fprintf(yyo, "%lld", static_cast<long long>(((*yyvaluep).itg))); }
#line 1170 "c2rob.tab.c"
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
#line 125 "c2rob.y"
                  {
    Node *program = (yyvsp[0].node);

    try {
    if (errorcount == 0) propagateNoInline(program);
    bool scope_valid = errorcount == 0 && resolveScopeProgram(program);
    bool while_valid = scope_valid && validateWhileProgram(program);
    bool qualifier_valid = while_valid && validateQualifierProgram(program);
    bool integer_valid = qualifier_valid && validateIntegerProgram(program);
    if (integer_valid && (errorcount == 0 || force_print_tree))
        cout << program->toStr(-1);
    } catch (const std::exception &error) { yyerror(error.what()); }

    exit(errorcount != 0 ? EXIT_FAILURE : EXIT_SUCCESS);
}
#line 2054 "c2rob.tab.c"
    break;

  case 3: /* globals: globals global  */
#line 141 "c2rob.y"
                             {
    if ((yyvsp[0].node))
        (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2064 "c2rob.tab.c"
    break;

  case 4: /* globals: global  */
#line 147 "c2rob.y"
                 {
    Node *n = new Node();
    if ((yyvsp[0].node))
        n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2075 "c2rob.tab.c"
    break;

  case 15: /* builtin_specifiers: TOK_TYPE_SPEC  */
#line 167 "c2rob.y"
                                   { (yyval.spec) = new DeclarationSpecifiers((yyvsp[0].str)); }
#line 2081 "c2rob.tab.c"
    break;

  case 16: /* builtin_specifiers: builtin_specifiers TOK_TYPE_SPEC  */
#line 168 "c2rob.y"
                                                      { (yyval.spec) = (yyvsp[-1].spec)->append((yyvsp[0].str)); }
#line 2087 "c2rob.tab.c"
    break;

  case 17: /* builtin_specifiers: builtin_specifiers specifier_qualifier  */
#line 169 "c2rob.y"
                                                            { (yyval.spec) = (yyvsp[-1].spec)->append((yyvsp[0].str)); }
#line 2093 "c2rob.tab.c"
    break;

  case 18: /* specifier_qualifier: TOK_CONST  */
#line 172 "c2rob.y"
                                { (yyval.str) = "const"; }
#line 2099 "c2rob.tab.c"
    break;

  case 19: /* specifier_qualifier: TOK_VOLATILE  */
#line 173 "c2rob.y"
                         { (yyval.str) = "volatile"; }
#line 2105 "c2rob.tab.c"
    break;

  case 20: /* specifier_qualifier: TOK_STATIC  */
#line 174 "c2rob.y"
                       { (yyval.str) = "static"; }
#line 2111 "c2rob.tab.c"
    break;

  case 21: /* specifier_qualifiers: specifier_qualifier  */
#line 177 "c2rob.y"
                                           { (yyval.spec) = new DeclarationSpecifiers((yyvsp[0].str)); }
#line 2117 "c2rob.tab.c"
    break;

  case 22: /* specifier_qualifiers: specifier_qualifiers specifier_qualifier  */
#line 178 "c2rob.y"
                                                      { (yyval.spec) = (yyvsp[-1].spec)->append((yyvsp[0].str)); }
#line 2123 "c2rob.tab.c"
    break;

  case 23: /* declaration_specifiers: builtin_specifiers  */
#line 182 "c2rob.y"
                         { (yyval.spec) = resolveDeclarationSpecifiers((yyvsp[0].spec)); }
#line 2129 "c2rob.tab.c"
    break;

  case 24: /* declaration_specifiers: specifier_qualifiers builtin_specifiers  */
#line 183 "c2rob.y"
                                              { (yyval.spec) = resolveDeclarationSpecifiers((yyvsp[-1].spec)->append((yyvsp[0].spec))); }
#line 2135 "c2rob.tab.c"
    break;

  case 25: /* declaration_specifiers: TOK_IDENT  */
#line 184 "c2rob.y"
                { (yyval.spec) = resolveDeclarationSpecifiers(new DeclarationSpecifiers((yyvsp[0].str))); }
#line 2141 "c2rob.tab.c"
    break;

  case 26: /* declaration_specifiers: TOK_IDENT specifier_qualifiers  */
#line 185 "c2rob.y"
                                     { (yyval.spec) = resolveDeclarationSpecifiers((yyvsp[0].spec)->append((yyvsp[-1].str))); }
#line 2147 "c2rob.tab.c"
    break;

  case 27: /* declaration_specifiers: specifier_qualifiers TOK_IDENT  */
#line 186 "c2rob.y"
                                     { (yyval.spec) = resolveDeclarationSpecifiers((yyvsp[-1].spec)->append((yyvsp[0].str))); }
#line 2153 "c2rob.tab.c"
    break;

  case 28: /* declaration_specifiers: specifier_qualifiers TOK_IDENT specifier_qualifiers  */
#line 187 "c2rob.y"
                                                          { (yyval.spec) = resolveDeclarationSpecifiers((yyvsp[-2].spec)->append((yyvsp[-1].str))->append((yyvsp[0].spec))); }
#line 2159 "c2rob.tab.c"
    break;

  case 29: /* declaration_specifiers: TOK_STRUCT TOK_IDENT  */
#line 188 "c2rob.y"
                           { (yyval.spec) = new DeclarationSpecifiers((yyvsp[0].str)); (yyval.spec)->type = (yyvsp[0].str); }
#line 2165 "c2rob.tab.c"
    break;

  case 30: /* include: TOK_INCLUDE  */
#line 191 "c2rob.y"
                            {
    string name((yyvsp[0].str));
    size_t start = name.find_first_of("<\"") + 1;
    name = name.substr(start, name.length()-3-start);
    (yyval.node) = new Ident("use " + name + ";\n");
}
#line 2176 "c2rob.tab.c"
    break;

  case 31: /* typedef_decl: TOK_TYPEDEF declaration_specifiers TOK_IDENT  */
#line 198 "c2rob.y"
                                                                       {
    if ((yyvsp[-1].spec)->isStatic) yyerror("declaration: static is not allowed in a typedef");
    declared_typedefs[(yyvsp[0].str)] = (yyvsp[-1].spec)->type;
    sourceTypedefs.insert_or_assign((yyvsp[0].str), *(yyvsp[-1].spec));
    (yyval.node) = nullptr;
}
#line 2187 "c2rob.tab.c"
    break;

  case 32: /* struct_decl: TOK_STRUCT TOK_IDENT '{' struct_fields '}'  */
#line 205 "c2rob.y"
                                                               {
    (yyval.node) = new Type((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2195 "c2rob.tab.c"
    break;

  case 33: /* struct_fields: struct_fields struct_field  */
#line 209 "c2rob.y"
                                               {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2204 "c2rob.tab.c"
    break;

  case 34: /* struct_fields: struct_field  */
#line 214 "c2rob.y"
                             {
    Node *n = new TypeFields();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2214 "c2rob.tab.c"
    break;

  case 35: /* struct_field: scalar_decl ';'  */
#line 220 "c2rob.y"
                               {
    (yyval.node) = (yyvsp[-1].node);
}
#line 2222 "c2rob.tab.c"
    break;

  case 36: /* struct_field: declaration_specifiers TOK_IDENT ':' TOK_INTEGER_LITERAL ';'  */
#line 224 "c2rob.y"
                                                                                                  {
    (yyval.node) = applyDeclarationSpecifiers(new VariableDecl((yyvsp[-4].spec)->type, (yyvsp[-3].str), atoi((yyvsp[-1].str))), (yyvsp[-4].spec));
}
#line 2230 "c2rob.tab.c"
    break;

  case 37: /* function_attribute: TOK_GNU_ATTRIBUTE '(' '(' TOK_IDENT ')' ')'  */
#line 229 "c2rob.y"
                                                                       {
    string name((yyvsp[-2].str));
    (yyval.itg) = name == "noinline" || name == "__noinline__";
    if (!(yyval.itg))
        yyerror(("unsupported GNU function attribute: " + name).c_str());
}
#line 2241 "c2rob.tab.c"
    break;

  case 38: /* function_header: declaration_specifiers TOK_IDENT '(' optional_func_args ')'  */
#line 236 "c2rob.y"
                                                                                          {
    (yyval.node) = makeFunctionHeader((yyvsp[-4].spec), (yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2249 "c2rob.tab.c"
    break;

  case 39: /* function_header: declaration_specifiers '*' TOK_IDENT '(' optional_func_args ')'  */
#line 240 "c2rob.y"
                                                                                              {
    (yyval.node) = makeFunctionHeader((yyvsp[-5].spec), (yyvsp[-3].str), (yyvsp[-1].node));
    ((Function*)(yyval.node))->markPointerResult();
}
#line 2258 "c2rob.tab.c"
    break;

  case 40: /* function_header: function_attribute declaration_specifiers TOK_IDENT '(' optional_func_args ')'  */
#line 245 "c2rob.y"
                                                                                                                   {
    auto *function = makeFunctionHeader((yyvsp[-4].spec), (yyvsp[-3].str), (yyvsp[-1].node));
    if ((yyvsp[-5].itg)) function->markNoInline();
    (yyval.node) = function;
}
#line 2268 "c2rob.tab.c"
    break;

  case 41: /* function_header: declaration_specifiers function_attribute TOK_IDENT '(' optional_func_args ')'  */
#line 251 "c2rob.y"
                                                                                                                   {
    auto *function = makeFunctionHeader((yyvsp[-5].spec), (yyvsp[-3].str), (yyvsp[-1].node));
    if ((yyvsp[-4].itg)) function->markNoInline();
    (yyval.node) = function;
}
#line 2278 "c2rob.tab.c"
    break;

  case 43: /* func_decl: function_header function_attribute  */
#line 258 "c2rob.y"
                                                     {
    (yyval.node) = (yyvsp[-1].node);
    if ((yyvsp[0].itg)) static_cast<Function*>((yyval.node))->markNoInline();
}
#line 2287 "c2rob.tab.c"
    break;

  case 44: /* func_impl: function_header '{' optional_locals '}'  */
#line 263 "c2rob.y"
                                                    {
    (yyval.node) = (yyvsp[-3].node);
    static_cast<Function*>((yyval.node))->setBody((yyvsp[-1].node));
}
#line 2296 "c2rob.tab.c"
    break;

  case 45: /* optional_func_args: func_args  */
#line 269 "c2rob.y"
                               {
    for (Node *node : (yyvsp[0].node)->getChildren()) {
        auto *arg = static_cast<FuncArg*>(node);
        if (arg->getTypeName() == "void" && !arg->isSourcePointer())
            yyerror("a void parameter cannot have a name or qualifiers");
    }
    (yyval.node) = (yyvsp[0].node);
}
#line 2309 "c2rob.tab.c"
    break;

  case 46: /* optional_func_args: %empty  */
#line 278 "c2rob.y"
                            {
    (yyval.node) = new NodeArgs();
}
#line 2317 "c2rob.tab.c"
    break;

  case 47: /* func_args: func_args ',' func_arg  */
#line 282 "c2rob.y"
                                       {
    // A bare void is represented by an empty list and must stand alone.
    if ((yyvsp[-2].node)->getChildren().empty() || !(yyvsp[0].node))
        yyerror("void must be the only item in the parameter list");
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2329 "c2rob.tab.c"
    break;

  case 48: /* func_args: func_arg  */
#line 290 "c2rob.y"
                     {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2339 "c2rob.tab.c"
    break;

  case 49: /* pointer_arg: '*'  */
#line 296 "c2rob.y"
                  {
    (yyval.itg) = 1;
}
#line 2347 "c2rob.tab.c"
    break;

  case 50: /* pointer_arg: '*' '*'  */
#line 300 "c2rob.y"
                      {
    (yyval.itg) = 1;
}
#line 2355 "c2rob.tab.c"
    break;

  case 51: /* func_arg: declaration_specifiers  */
#line 305 "c2rob.y"
                                        {
    if ((yyvsp[0].spec)->type == "void" && !(yyvsp[0].spec)->isConst && !(yyvsp[0].spec)->isVolatile && !(yyvsp[0].spec)->isStatic) {
        (yyval.node) = nullptr;
    } else {
        (yyval.node) = makeFunctionArgument((yyvsp[0].spec), "_un" + to_string(current_unamed_arg++));
    }
}
#line 2367 "c2rob.tab.c"
    break;

  case 52: /* func_arg: declaration_specifiers pointer_arg  */
#line 313 "c2rob.y"
                                                    {
    (yyval.node) = makeFunctionArgument((yyvsp[-1].spec), "_un" + to_string(current_unamed_arg++), true);
}
#line 2375 "c2rob.tab.c"
    break;

  case 53: /* func_arg: declaration_specifiers TOK_IDENT  */
#line 317 "c2rob.y"
                                                        {
    (yyval.node) = makeFunctionArgument((yyvsp[-1].spec), (yyvsp[0].str));
}
#line 2383 "c2rob.tab.c"
    break;

  case 54: /* func_arg: declaration_specifiers pointer_arg TOK_IDENT  */
#line 321 "c2rob.y"
                                                                    {
    (yyval.node) = makeFunctionArgument((yyvsp[-2].spec), (yyvsp[0].str), true);
}
#line 2391 "c2rob.tab.c"
    break;

  case 55: /* func_arg: declaration_specifiers pointer_arg TOK_IDENT '[' ']'  */
#line 325 "c2rob.y"
                                                                            {
    (yyval.node) = makeFunctionArgument((yyvsp[-4].spec), (yyvsp[-2].str), true);
}
#line 2399 "c2rob.tab.c"
    break;

  case 56: /* global: error ';'  */
#line 329 "c2rob.y"
                   { (yyval.node) = new Node(); }
#line 2405 "c2rob.tab.c"
    break;

  case 57: /* locals: locals local  */
#line 331 "c2rob.y"
                          {
    (yyvsp[-1].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-1].node);
}
#line 2414 "c2rob.tab.c"
    break;

  case 58: /* locals: local  */
#line 336 "c2rob.y"
               {
    Node *n = new Node();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2424 "c2rob.tab.c"
    break;

  case 65: /* local: function_call ';'  */
#line 348 "c2rob.y"
                            { ((FunctionCall*)(yyvsp[-1].node))->setInExpr(false); (yyval.node) = (yyvsp[-1].node); }
#line 2430 "c2rob.tab.c"
    break;

  case 70: /* whilestmt: TOK_WHILE '(' expr ')' whilebody  */
#line 356 "c2rob.y"
                                             {
    (yyval.node) = new While((yyvsp[-2].node), (yyvsp[0].node), true);
}
#line 2438 "c2rob.tab.c"
    break;

  case 71: /* whilebody: '{' optional_locals '}'  */
#line 360 "c2rob.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2444 "c2rob.tab.c"
    break;

  case 72: /* whilebody: local  */
#line 361 "c2rob.y"
                  {
              (yyval.node) = new Node();
              (yyval.node)->append((yyvsp[0].node));
          }
#line 2453 "c2rob.tab.c"
    break;

  case 73: /* whilebody: ';'  */
#line 365 "c2rob.y"
                { (yyval.node) = new Node(); }
#line 2459 "c2rob.tab.c"
    break;

  case 74: /* optional_locals: locals  */
#line 368 "c2rob.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2465 "c2rob.tab.c"
    break;

  case 75: /* optional_locals: %empty  */
#line 369 "c2rob.y"
                         { (yyval.node) = new Node(); }
#line 2471 "c2rob.tab.c"
    break;

  case 76: /* returnstmt: TOK_RETURN expr ';'  */
#line 372 "c2rob.y"
                                 {
    (yyval.node) = new Return((yyvsp[-1].node));
}
#line 2479 "c2rob.tab.c"
    break;

  case 77: /* returnstmt: TOK_RETURN ';'  */
#line 376 "c2rob.y"
                            {
    (yyval.node) = new Return();
}
#line 2487 "c2rob.tab.c"
    break;

  case 78: /* attribution: scalar_or_array '=' expr  */
#line 381 "c2rob.y"
                                       {
    (yyval.node) = new Store((yyvsp[-2].node), "=", (yyvsp[0].node));
}
#line 2495 "c2rob.tab.c"
    break;

  case 79: /* attribution: scalar_or_array TOK_ATTRIBUTION expr  */
#line 387 "c2rob.y"
                                                       {
    (yyval.node) = new Store((yyvsp[-2].node), (yyvsp[-1].str), (yyvsp[0].node));
}
#line 2503 "c2rob.tab.c"
    break;

  case 80: /* attribution: factor TOK_UNARY_OPERATOR  */
#line 392 "c2rob.y"
                                               {
    (yyval.node) = new UnaryAttribution((yyvsp[-1].node), (yyvsp[0].str));
}
#line 2511 "c2rob.tab.c"
    break;

  case 81: /* forstmt: TOK_FOR '(' attribution ';' expr ';' attribution ')' local  */
#line 396 "c2rob.y"
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
#line 2526 "c2rob.tab.c"
    break;

  case 82: /* forstmt: TOK_FOR '(' attribution ';' expr ';' attribution ')' '{' locals '}'  */
#line 407 "c2rob.y"
                                                                                      {
    Node *nfor = new Container();
    nfor->append((yyvsp[-8].node));
    auto *loop = new While((yyvsp[-6].node), (yyvsp[-1].node));
    loop->setUpdate((yyvsp[-4].node));
    nfor->append(loop);
    (yyval.node) = nfor;
}
#line 2539 "c2rob.tab.c"
    break;

  case 83: /* ifstmt: TOK_IF '(' expr ')' local  */
#line 416 "c2rob.y"
                                   {
    (yyval.node) = new IfStmt((yyvsp[-2].node), (yyvsp[0].node));
}
#line 2547 "c2rob.tab.c"
    break;

  case 84: /* ifstmt: TOK_IF '(' expr ')' local elseblock  */
#line 420 "c2rob.y"
                                             {
    (yyval.node) = new IfStmt((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
}
#line 2555 "c2rob.tab.c"
    break;

  case 85: /* ifstmt: TOK_IF '(' expr ')' '{' locals '}'  */
#line 424 "c2rob.y"
                                            {
    (yyval.node) = new IfStmt((yyvsp[-4].node), (yyvsp[-1].node));
}
#line 2563 "c2rob.tab.c"
    break;

  case 86: /* ifstmt: TOK_IF '(' expr ')' '{' locals '}' elseblock  */
#line 428 "c2rob.y"
                                                      {
    (yyval.node) = new IfStmt((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
}
#line 2571 "c2rob.tab.c"
    break;

  case 87: /* elseblock: TOK_ELSE '{' locals '}'  */
#line 432 "c2rob.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2577 "c2rob.tab.c"
    break;

  case 88: /* elseblock: TOK_ELSE local  */
#line 433 "c2rob.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2583 "c2rob.tab.c"
    break;

  case 89: /* multi_decl: declaration_specifiers multi_declarators  */
#line 436 "c2rob.y"
                                                            {
    string type = VariableDecl::convertTypeToRob((yyvsp[-1].spec)->type);
    if (declared_types.contains(type))
        yyerror("multiple declaration: aggregate type is not supported");
    if (type == "void")
        yyerror("multiple declaration: void cannot be used as a variable type");
    for (Node *node : (yyvsp[0].node)->getChildren()) {
        auto *decl = static_cast<VariableDecl*>(node);
        decl->setDeclarationType((yyvsp[-1].spec)->type);
        applyDeclarationSpecifiers(decl, (yyvsp[-1].spec));
        if (decl->getIndex()) {
            string size = decl->getIndex()->toStr(0);
            if (!regex_match(size, regex("[1-9][0-9]*")))
                yyerror("multiple declaration: array size must be a positive integer literal");
            else if (decl->getValue() && to_string(decl->getValue()->getChildren().size()) != size)
                yyerror("multiple declaration: array initialization must provide all elements");
        }
    }
    (yyval.node) = (yyvsp[0].node);
}
#line 2608 "c2rob.tab.c"
    break;

  case 90: /* multi_declarators: multi_declarator ',' multi_declarator  */
#line 457 "c2rob.y"
                                                                {
    (yyval.node) = new Container();
    (yyval.node)->append((yyvsp[-2].node));
    (yyval.node)->append((yyvsp[0].node));
}
#line 2618 "c2rob.tab.c"
    break;

  case 91: /* multi_declarators: multi_declarators ',' multi_declarator  */
#line 463 "c2rob.y"
                                                                 {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2627 "c2rob.tab.c"
    break;

  case 92: /* multi_declarator: TOK_IDENT  */
#line 469 "c2rob.y"
                                   {
    (yyval.node) = new VariableDecl("", (yyvsp[0].str));
}
#line 2635 "c2rob.tab.c"
    break;

  case 93: /* multi_declarator: TOK_IDENT '=' expr  */
#line 473 "c2rob.y"
                                            {
    (yyval.node) = new VariableDecl("", (yyvsp[-2].str), (yyvsp[0].node));
}
#line 2643 "c2rob.tab.c"
    break;

  case 94: /* multi_declarator: TOK_IDENT '[' expr ']'  */
#line 477 "c2rob.y"
                                                {
    (yyval.node) = new VariableDecl("", (yyvsp[-3].str), (yyvsp[-1].node), nullptr);
}
#line 2651 "c2rob.tab.c"
    break;

  case 95: /* multi_declarator: TOK_IDENT '[' expr ']' '=' array_values_decl  */
#line 481 "c2rob.y"
                                                                                  {
    (yyval.node) = new VariableDecl("", (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node));
}
#line 2659 "c2rob.tab.c"
    break;

  case 96: /* scalar_init_decl: declaration_specifiers TOK_IDENT '=' expr  */
#line 486 "c2rob.y"
                                                                         {
    (yyval.node) = applyDeclarationSpecifiers(new VariableDecl((yyvsp[-3].spec)->type, (yyvsp[-2].str), (yyvsp[0].node)), (yyvsp[-3].spec));
}
#line 2667 "c2rob.tab.c"
    break;

  case 97: /* scalar_init_decl: declaration_specifiers TOK_IDENT '=' array_values_decl  */
#line 491 "c2rob.y"
                                                                                             {
    (yyval.node) = applyDeclarationSpecifiers(new InitializedType((yyvsp[-3].spec)->type, (yyvsp[-2].str), (yyvsp[0].node)), (yyvsp[-3].spec));
}
#line 2675 "c2rob.tab.c"
    break;

  case 98: /* scalar_decl: declaration_specifiers TOK_IDENT  */
#line 496 "c2rob.y"
                                                           {
    (yyval.node) = applyDeclarationSpecifiers(new VariableDecl((yyvsp[-1].spec)->type, (yyvsp[0].str)), (yyvsp[-1].spec));
}
#line 2683 "c2rob.tab.c"
    break;

  case 99: /* array_init_decl: declaration_specifiers TOK_IDENT '[' expr ']' '=' array_values_decl  */
#line 501 "c2rob.y"
                                                                                                              {
    ((NodeArgs*)(yyvsp[0].node))->setArrayInitType((yyvsp[-6].spec)->type);
    (yyval.node) = applyDeclarationSpecifiers(new VariableDecl((yyvsp[-6].spec)->type, (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node)), (yyvsp[-6].spec));
}
#line 2692 "c2rob.tab.c"
    break;

  case 100: /* array_decl: declaration_specifiers TOK_IDENT '[' expr ']'  */
#line 506 "c2rob.y"
                                                                            {
    (yyval.node) = applyDeclarationSpecifiers(new VariableDecl((yyvsp[-4].spec)->type, (yyvsp[-3].str), (yyvsp[-1].node), nullptr), (yyvsp[-4].spec));
}
#line 2700 "c2rob.tab.c"
    break;

  case 101: /* array_init_decl: declaration_specifiers TOK_IDENT '[' expr ']' '=' struct_values_decl  */
#line 510 "c2rob.y"
                                                                                                               {
    (yyval.node) = applyDeclarationSpecifiers(new StructVariableDecl((yyvsp[-6].spec)->type, (yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].node)), (yyvsp[-6].spec));
}
#line 2708 "c2rob.tab.c"
    break;

  case 102: /* struct_values_decl: '{' array_values_decls '}'  */
#line 515 "c2rob.y"
                                                      { (yyval.node) = (yyvsp[-1].node); }
#line 2714 "c2rob.tab.c"
    break;

  case 103: /* array_values_decls: array_values_decls ',' array_values_decl  */
#line 517 "c2rob.y"
                                                                  {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2723 "c2rob.tab.c"
    break;

  case 104: /* array_values_decls: array_values_decl  */
#line 522 "c2rob.y"
                                       {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2733 "c2rob.tab.c"
    break;

  case 105: /* array_values_decl: '{' array_values '}'  */
#line 528 "c2rob.y"
                                         { (yyval.node) = (yyvsp[-1].node); }
#line 2739 "c2rob.tab.c"
    break;

  case 106: /* array_values: array_values ',' expr  */
#line 530 "c2rob.y"
                                         {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2748 "c2rob.tab.c"
    break;

  case 107: /* array_values: expr  */
#line 535 "c2rob.y"
                    {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2758 "c2rob.tab.c"
    break;

  case 108: /* expr: expr TOK_CMP_RELAT expr  */
#line 541 "c2rob.y"
                                          { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].str)); }
#line 2764 "c2rob.tab.c"
    break;

  case 109: /* expr: expr TOK_CMP_EQNEQ expr  */
#line 542 "c2rob.y"
                                          { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].str)); }
#line 2770 "c2rob.tab.c"
    break;

  case 110: /* expr: expr TOK_AND expr  */
#line 543 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "and"); }
#line 2776 "c2rob.tab.c"
    break;

  case 111: /* expr: expr TOK_OR expr  */
#line 544 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "or"); }
#line 2782 "c2rob.tab.c"
    break;

  case 112: /* expr: expr '+' expr  */
#line 545 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "+"); }
#line 2788 "c2rob.tab.c"
    break;

  case 113: /* expr: expr '-' expr  */
#line 546 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "-"); }
#line 2794 "c2rob.tab.c"
    break;

  case 114: /* expr: expr '*' expr  */
#line 547 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "*"); }
#line 2800 "c2rob.tab.c"
    break;

  case 115: /* expr: expr '/' expr  */
#line 548 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "/"); }
#line 2806 "c2rob.tab.c"
    break;

  case 116: /* expr: expr '%' expr  */
#line 549 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "%"); }
#line 2812 "c2rob.tab.c"
    break;

  case 117: /* expr: expr '&' expr  */
#line 550 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "&"); }
#line 2818 "c2rob.tab.c"
    break;

  case 118: /* expr: expr '|' expr  */
#line 551 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "|"); }
#line 2824 "c2rob.tab.c"
    break;

  case 119: /* expr: expr '^' expr  */
#line 552 "c2rob.y"
                                { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[0].node), "^"); }
#line 2830 "c2rob.tab.c"
    break;

  case 120: /* expr: '!' expr  */
#line 553 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "!"); }
#line 2836 "c2rob.tab.c"
    break;

  case 121: /* expr: '~' expr  */
#line 554 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "~"); }
#line 2842 "c2rob.tab.c"
    break;

  case 122: /* expr: '-' expr  */
#line 555 "c2rob.y"
                                { (yyval.node) = new Unary((yyvsp[0].node), "-"); }
#line 2848 "c2rob.tab.c"
    break;

  case 123: /* expr: '+' expr  */
#line 556 "c2rob.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2854 "c2rob.tab.c"
    break;

  case 124: /* expr: '(' expr ')'  */
#line 557 "c2rob.y"
                                { (yyval.node) = new Parenthesis((yyvsp[-1].node)); }
#line 2860 "c2rob.tab.c"
    break;

  case 128: /* factor: TOK_INT  */
#line 563 "c2rob.y"
                      {
    (yyval.node) = new Integer((yyvsp[0].itg));
}
#line 2868 "c2rob.tab.c"
    break;

  case 129: /* factor: TOK_FLOAT  */
#line 567 "c2rob.y"
                        {
    (yyval.node) = new Float((yyvsp[0].flt));
}
#line 2876 "c2rob.tab.c"
    break;

  case 130: /* factor: TOK_STRING  */
#line 571 "c2rob.y"
                         {
    (yyval.node) = new Ident((yyvsp[0].str));
}
#line 2884 "c2rob.tab.c"
    break;

  case 131: /* factor: TOK_INTEGER_LITERAL  */
#line 575 "c2rob.y"
                                  {
    (yyval.node) = new IntegerToken((yyvsp[0].str));
}
#line 2892 "c2rob.tab.c"
    break;

  case 132: /* factor: factor TOK_UNARY_OPERATOR  */
#line 579 "c2rob.y"
                                          {
    (yyval.node) = new Unary((yyvsp[-1].node), (yyvsp[0].str));
}
#line 2900 "c2rob.tab.c"
    break;

  case 133: /* scalar_or_array: TOK_IDENT  */
#line 583 "c2rob.y"
                                {
    (yyval.node) = new Ident((yyvsp[0].str));
}
#line 2908 "c2rob.tab.c"
    break;

  case 134: /* scalar_or_array: TOK_IDENT '[' expr ']'  */
#line 587 "c2rob.y"
                                             {
    (yyval.node) = new LoadArray((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2916 "c2rob.tab.c"
    break;

  case 135: /* scalar_or_array: TOK_IDENT '.' TOK_IDENT  */
#line 591 "c2rob.y"
                                                   {
    (yyval.node) = new LoadField((yyvsp[-2].str), (yyvsp[0].str));
}
#line 2924 "c2rob.tab.c"
    break;

  case 136: /* scalar_or_array: TOK_IDENT '[' expr ']' '.' TOK_IDENT  */
#line 595 "c2rob.y"
                                                                {
    (yyval.node) = new LoadArrayField((yyvsp[-5].str), (yyvsp[-3].node), (yyvsp[0].str));
}
#line 2932 "c2rob.tab.c"
    break;

  case 137: /* function_call: TOK_IDENT '(' ')'  */
#line 599 "c2rob.y"
                                      {
    (yyval.node) = new FunctionCall((yyvsp[-2].str));
}
#line 2940 "c2rob.tab.c"
    break;

  case 138: /* function_call: TOK_IDENT '(' func_call_args ')'  */
#line 603 "c2rob.y"
                                                           {
    (yyval.node) = new FunctionCall((yyvsp[-3].str), (yyvsp[-1].node));
}
#line 2948 "c2rob.tab.c"
    break;

  case 139: /* func_call_args: func_call_args ',' expr  */
#line 607 "c2rob.y"
                                             {
    (yyvsp[-2].node)->append((yyvsp[0].node));
    (yyval.node) = (yyvsp[-2].node);
}
#line 2957 "c2rob.tab.c"
    break;

  case 140: /* func_call_args: expr  */
#line 612 "c2rob.y"
                      {
    Node *n = new NodeArgs();
    n->append((yyvsp[0].node));
    (yyval.node) = n;
}
#line 2967 "c2rob.tab.c"
    break;


#line 2971 "c2rob.tab.c"

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

#line 618 "c2rob.y"

