/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_C2ROB_TAB_H_INCLUDED
# define YY_YY_C2ROB_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_IDENT = 258,               /* TOK_IDENT  */
    TOK_ATTRIBUTION = 259,         /* TOK_ATTRIBUTION  */
    TOK_FLOAT = 260,               /* TOK_FLOAT  */
    TOK_INT = 261,                 /* TOK_INT  */
    TOK_OR = 262,                  /* TOK_OR  */
    TOK_AND = 263,                 /* TOK_AND  */
    TOK_CHAR = 264,                /* TOK_CHAR  */
    TOK_CMP_EQNEQ = 265,           /* TOK_CMP_EQNEQ  */
    TOK_CMP_RELAT = 266,           /* TOK_CMP_RELAT  */
    TOK_UNARY_OPERATOR = 267,      /* TOK_UNARY_OPERATOR  */
    TOK_STRING = 268,              /* TOK_STRING  */
    TOK_IF = 269,                  /* TOK_IF  */
    TOK_ELSE = 270,                /* TOK_ELSE  */
    TOK_FOR = 271,                 /* TOK_FOR  */
    TOK_WHILE = 272,               /* TOK_WHILE  */
    TOK_RETURN = 273,              /* TOK_RETURN  */
    TOK_UNSUPPORTED = 274,         /* TOK_UNSUPPORTED  */
    TOK_INTEGER_LITERAL = 275,     /* TOK_INTEGER_LITERAL  */
    TOK_INCLUDE = 276,             /* TOK_INCLUDE  */
    TOK_STRUCT = 277,              /* TOK_STRUCT  */
    TOK_TYPEDEF = 278,             /* TOK_TYPEDEF  */
    TOK_STATIC = 279,              /* TOK_STATIC  */
    TOK_VOLATILE = 280,            /* TOK_VOLATILE  */
    TOK_CONST = 281,               /* TOK_CONST  */
    UMINUS = 282                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "c2rob.y"

    const char *str;
    int64_t itg;
    double flt;
    Node *node;
    Strings *strings;

#line 99 "c2rob.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_C2ROB_TAB_H_INCLUDED  */
