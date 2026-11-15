
%{
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <string>
#include <string_view>

char *build_file_name;
bool force_print_tree = false;
class Node;
class Strings;
struct DeclarationSpecifiers;
#include "source_type.h"
#include "preprocess.h"

#include "c2rob.tab.h"

int yyerror(const char *s);
extern int errorcount;
int yycolno = 0;

// The lexer keeps the original bytes of calls; the grammar decides when an
// opening is a call and when it is part of a declaration or a definition.
std::set<std::string> direct_print_names;
static std::string print_text;
static std::string print_closers;

const char *directPrintName(std::string_view opening) {
    return opening.starts_with("printf") ? "printf" : "print";
}

static void appendPrintBytes(const char *source, int length) {
    print_text.append(source, length);
    // YY_USER_ACTION already added yyleng; a multiline match resets the column.
    size_t newline = std::string_view(source, length).rfind('\n');
    if (newline != std::string_view::npos) yycolno = length - newline - 1;
}

#define YY_USER_ACTION  yycolno += yyleng;
%}

%option yylineno

%x COMMENT PRINT_ARGS

SPLICE        \\(\r\n|\n)
BLOCK_COMMENT "/*"([^*]|\*+[^*/])*\*+"/"
LINE_COMMENT  "//"([^\\\r\n]|\\[^\r\n]|{SPLICE})*
PRINT_GAP     ([ \t\r\n\v\f]|{SPLICE}|{BLOCK_COMMENT}|{LINE_COMMENT}\r?\n)*
PRINT_NAME    (printf|print)
IDENTIFIER    [a-zA-Z_][a-zA-Z0-9_]*
PRINT_STRING  \"([^\\\"\n\r]|\\[^\r\n]|{SPLICE})*\"
PRINT_CHAR    \'([^\\'\n\r]|\\[^\r\n]|{SPLICE})*\'
EXP           [eE][+-]?[0-9]+
DEC_FLOAT     (([0-9]+\.[0-9]*|\.[0-9]+){EXP}?|[0-9]+{EXP})
HEX_FLOAT     0[xX]([0-9a-fA-F]+\.?[0-9a-fA-F]*|\.[0-9a-fA-F]+)[pP][+-]?[0-9]+

%%

<PRINT_ARGS>{PRINT_NAME}{PRINT_GAP}"(" {
    direct_print_names.insert(directPrintName(std::string_view(yytext, yyleng)));
    appendPrintBytes(yytext, yyleng);
    print_closers += ')';
}

<PRINT_ARGS>({BLOCK_COMMENT}|{LINE_COMMENT}|{PRINT_STRING}|{PRINT_CHAR}|{SPLICE}) {
    appendPrintBytes(yytext, yyleng);
}

<PRINT_ARGS>(("."|"->"){PRINT_GAP}{IDENTIFIER}|{IDENTIFIER}|[0-9][.a-zA-Z0-9_]*) {
    appendPrintBytes(yytext, yyleng);
}

<PRINT_ARGS>[\(\[\{] {
    appendPrintBytes(yytext, yyleng);
    print_closers += yytext[0] == '(' ? ')' : yytext[0] == '[' ? ']' : '}';
}

<PRINT_ARGS>[\)\]\}] {
    if (print_closers.back() != yytext[0]) {
        BEGIN(INITIAL);
        yyerror("print/printf: mismatched delimiter in argument list");
        return TOK_UNSUPPORTED;
    }
    appendPrintBytes(yytext, yyleng);
    print_closers.pop_back();
    if (print_closers.empty()) {
        BEGIN(INITIAL);
        yylval.str = strdup(print_text.c_str());
        return TOK_PRINT_CALL;
    }
}

<PRINT_ARGS>(\"|\'|"/*"|\x00) {
    BEGIN(INITIAL);
    yyerror("print/printf: invalid or unterminated literal or comment in argument list");
    return TOK_UNSUPPORTED;
}

<PRINT_ARGS>(.|\n) { appendPrintBytes(yytext, yyleng); }

<PRINT_ARGS><<EOF>> {
    BEGIN(INITIAL);
    yyerror("print/printf: unterminated argument list");
    return 0;
}

[ \t\r] { /* ignora */ }
[\n] { yycolno = 0; }

"/*"					{ yymore(); BEGIN COMMENT; }
<COMMENT>[^*]			{ yymore(); }
<COMMENT>"*"/[^/]		{ yymore(); }
<COMMENT>"*/"			{ BEGIN(INITIAL); }

"//".*\n { /* ignora */ }
#define.*\n { /* ignora */ }
__attribute__\(\(used\)\) { /* TODO: make generic or map supported robcmp attributes */ }
"__attribute__" { return TOK_GNU_ATTRIBUTE; }

#[\t ]*include[\t ]*(<[^>\n]+>|\"[^"\n]+\") {
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
"extern"    { return TOK_EXTERN; }
"restrict"|"__restrict"|"__restrict__" { return TOK_RESTRICT; }
"inline"    { /* ignora */ }
"const"     { return TOK_CONST; }

"void"|"char"|"short"|"int"|"long"|"signed"|"unsigned"|"float"|"double"|"_Bool" {
    yylval.str = strndup(yytext, yyleng);
    return TOK_TYPE_SPEC;
}
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
"..." { return TOK_ELLIPSIS; }

{PRINT_NAME}{PRINT_GAP}"(" {
    size_t newline = std::string_view(yytext, yyleng).rfind('\n');
    if (newline != std::string_view::npos) yycolno = yyleng - newline - 1;
    yylval.str = strndup(yytext, yyleng);
    return TOK_PRINT_OPEN;
}

[a-zA-Z_][a-zA-Z0-9_\.]* {
    yylval.str = strndup(yytext, yyleng);
    return TOK_IDENT;
}

({DEC_FLOAT}|{HEX_FLOAT})[fFlL]? {
    yylval.str = strndup(yytext, yyleng);
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

void beginDirectPrint(const char *opening) {
    print_text = opening;
    print_closers = ")";
    direct_print_names.insert(directPrintName(opening));
    BEGIN(PRINT_ARGS);
}

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
        fprintf(stderr, "Usage: %s [-f] [-d] [--abi=ilp32|lp64] [--preprocess] [--printf] program_name\n",
            argv[0]);
        return 1;
    }

    int build_file_id = 0;
    bool preprocess = false;
    for (int argid = 1; argid < argc; ++argid) {
        std::string option(argv[argid]);
        if (option == "-f") force_print_tree = true;
        else if (option == "-d") yydebug = 1;
        else if (option == "--abi=ilp32") sourceAbi = SourceAbi::ILP32;
        else if (option == "--abi=lp64") sourceAbi = SourceAbi::LP64;
        else if (option == "--preprocess") preprocess = true;
        else if (option == "--printf") continue; // Historical flag; direct printing is now the default.
        else if (option.starts_with("-")) {
            fprintf(stderr, "Unknown option: %s. Supported ABIs: ilp32, lp64.\n", argv[argid]);
            return 1;
        } else if (build_file_id) {
            fprintf(stderr, "Exactly one C input file is required.\n");
            return 1;
        } else build_file_id = argid;
    }
    if (!build_file_id) {
        fprintf(stderr, "A C input file is required.\n");
        return 1;
    }
    const char *input = argv[build_file_id];
    std::string diagnostic_name(input);
    if (preprocess) {
        try { yyin = cpreprocess::open(input); }
        catch (const std::exception &error) {
            fprintf(stderr, "%s: preprocess: %s\n", input, error.what());
            return 1;
        }
        diagnostic_name += " (preprocessed)";
    } else {
        yyin = fopen(input, "r");
        if (yyin == NULL) {
            fprintf(stderr, "Could not open file %s.\n", input);
            return 1;
        }
    }
    build_file_name = diagnostic_name.data();

    int parse_status = 1;
    try { parse_status = yyparse(); }
    catch (const std::exception &error) { yyerror(error.what()); }

    if (yyin)
        fclose(yyin);
    
    return (parse_status != 0 || errorcount != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
