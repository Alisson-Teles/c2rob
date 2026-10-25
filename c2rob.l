
%{
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "source_type.h"

char *build_file_name;
bool force_print_tree = false;
class Node;
class Strings;

#include "c2rob.tab.h"

int yyerror(const char *s);
extern int errorcount;
int yycolno = 0;

#define YY_USER_ACTION  yycolno += yyleng;
%}

%option yylineno

%x COMMENT

%%

[ \t\r] { /* ignora */ }
[\n] { yycolno = 0; }

"/*"					{ yymore(); BEGIN COMMENT; }
<COMMENT>[^*]			{ yymore(); }
<COMMENT>"*"/[^/]		{ yymore(); }
<COMMENT>"*/"			{ BEGIN(INITIAL); }

"//".*\n { /* ignora */ }
#define.*\n { /* ignora */ }
__attribute__\(\(used\)\) { /* TODO: make generic or map supported robcmp attributes */ }

#include[\t ]*[<"].*[>"] {
    yylval.str = strndup(yytext, yyleng); 
    return TOK_INCLUDE;
}

"if"     { return TOK_IF; }
"else"   { return TOK_ELSE; }
"for"    { return TOK_FOR; }
"while"  { return TOK_WHILE; }
"do"|"switch"|"goto"|"break"|"continue"|"case"|"default" {
    std::string message = std::string("unsupported C statement: ") + yytext;
    yyerror(message.c_str());
    return TOK_UNSUPPORTED;
}
"return" { return TOK_RETURN; }
"struct" { return TOK_STRUCT; }
"typedef" { return TOK_TYPEDEF; }

"static"    { return TOK_STATIC; }
"volatile"  { return TOK_VOLATILE; }
"inline"    { /* ignora */ }
"const"     { return TOK_CONST; }
"NULL"      { 
    yylval.str = "0";
    return TOK_INTEGER_LITERAL;
}

">"  { yylval.str = ">";  return TOK_CMP_RELAT; }
"<"  { yylval.str = "<";  return TOK_CMP_RELAT; }
">=" { yylval.str = ">="; return TOK_CMP_RELAT; }
"<=" { yylval.str = "<="; return TOK_CMP_RELAT; }
"==" { yylval.str = "=="; return TOK_CMP_EQNEQ; }
"!=" { yylval.str = "!="; return TOK_CMP_EQNEQ; }

"++" { yylval.str = "++"; return TOK_UNARY_OPERATOR; }
"--" { yylval.str = "--"; return TOK_UNARY_OPERATOR; }

"&&" { return TOK_AND; }
"||" { return TOK_OR; }

"-" { return '-'; } // has two meanings: binary and unary operator
"/" { return '/'; }
"+" { return '+'; }
"%" { return '%'; }
"|" { return '|'; }
"&" { return '&'; }
"^" { return '^'; }
"!" { return '!'; }
"~" { return '~'; }

  /* attributions */
"="  { return '='; } // has two meanings: initialized decl and set variable values
"+=" { yylval.str = "+="; return TOK_ATTRIBUTION; }
"-=" { yylval.str = "-="; return TOK_ATTRIBUTION; }
"*=" { yylval.str = "*="; return TOK_ATTRIBUTION; }
"/=" { yylval.str = "/="; return TOK_ATTRIBUTION; }
"^=" { yylval.str = "^="; return TOK_ATTRIBUTION; }
"|=" { yylval.str = "|="; return TOK_ATTRIBUTION; }
"&=" { yylval.str = "&="; return TOK_ATTRIBUTION; }
"->" { return '.'; }

"*" { return '*'; } // multiple meanings

";" { return ';'; }
"(" { return '('; }
")" { return ')'; }
"[" { return '['; }
"]" { return ']'; }
"{" { return '{'; }
"}" { return '}'; }
"," { return ','; }
":" { return ':'; }
"\." { return '.'; }

"void"|"char"|"short"|"int"|"long"|"signed"|"unsigned"|"float"|"double"|"_Bool" {
    yylval.str = strndup(yytext, yyleng);
    return TOK_TYPE_SPEC;
}

[a-zA-Z_][a-zA-Z0-9_\.]* {
    yylval.str = strndup(yytext, yyleng);
    return TOK_IDENT;
}

[0-9]+\.[0-9]* {
    yylval.flt = atof(yytext);
    return TOK_FLOAT;
}

(0[xX][0-9a-fA-F]+|[0-9]+)([uU](ll|LL|[lL])?|(ll|LL|[lL])[uU]?)? {
    yylval.str = strndup(yytext, yyleng);
    return TOK_INTEGER_LITERAL;
}

\"([^\\\"]|\\.)*\"		{ yylval.str = strndup(yytext, yyleng);
						  return TOK_STRING; }

'\\?.'					{ yylval.itg = yytext[0];
						  return TOK_CHAR; }

. { 
    fprintf(stderr, "%s:%d:%d: Unrecognized symbol %c\n", build_file_name, yylineno, yycolno, yytext[0]);
    errorcount++;
    return yytext[0];
  }


%%

int yywrap() {
    return 1;
}

extern int errorcount;
extern int yydebug;

int yyerror(const char *s) {
    fprintf(stderr, "%s:%d:%d: %s\n", 
        build_file_name, yylineno, yycolno, s);
    errorcount++;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(
            stderr,
            "Usage: %s [-f] [-d] [--abi=ilp32|lp64] program_name\n",
            argv[0]
        );
        return 1;
    }

    int build_file_id = 0;

    for (int argid = 1; argid < argc; ++argid) {
        std::string option(argv[argid]);

        if (option == "-f") {
            force_print_tree = true;
        } else if (option == "-d") {
            yydebug = 1;
        } else if (option == "--abi=ilp32") {
            sourceAbi = SourceAbi::ILP32;
        } else if (option == "--abi=lp64") {
            sourceAbi = SourceAbi::LP64;
        } else if (option.starts_with("-")) {
            fprintf(
                stderr,
                "Unknown option: %s. Supported ABIs: ilp32, lp64.\n",
                argv[argid]
            );
            return 1;
        } else if (build_file_id) {
            fprintf(
                stderr,
                "Exactly one C input file is required.\n"
            );
            return 1;
        } else {
            build_file_id = argid;
        }
    }

    if (!build_file_id) {
        fprintf(stderr, "A C input file is required.\n");
        return 1;
    }

    build_file_name = argv[build_file_id];
    yyin = fopen(build_file_name, "r");

    if (yyin == NULL) {
        fprintf(
            stderr,
            "Could not open file %s.\n",
            build_file_name
        );
        return 1;
    }

    int parse_status = 1;

    try {
        parse_status = yyparse();
    } catch (const std::exception &error) {
        yyerror(error.what());
    }

    if (yyin) {
        fclose(yyin);
    }

    return (parse_status != 0 || errorcount != 0) ?
        EXIT_FAILURE : EXIT_SUCCESS;
}