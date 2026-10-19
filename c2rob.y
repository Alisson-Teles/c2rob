
%{
#include "nodes.h"
#include "scope_support.h"
#include "while_support.h"

int yyerror(const char *s);
int yylex(void);
int errorcount = 0;
int current_unamed_arg = 0;
extern bool force_print_tree;
%}

%define parse.error detailed
%define parse.trace
%define parse.lac full

%union {
    const char *str;
    int64_t itg;
    double flt;
    Node *node;
    Strings *strings;
}

%token TOK_IDENT TOK_ATTRIBUTION
%token TOK_FLOAT TOK_INT
%token TOK_OR TOK_AND TOK_CHAR
%token TOK_CMP_EQNEQ TOK_CMP_RELAT TOK_UNARY_OPERATOR TOK_STRING
%token TOK_IF TOK_ELSE TOK_FOR TOK_WHILE TOK_RETURN TOK_UNSUPPORTED
%token <str> TOK_INTEGER_LITERAL
%token TOK_INCLUDE TOK_STRUCT TOK_TYPEDEF
%token TOK_STATIC TOK_VOLATILE TOK_CONST

%type<str> TOK_STRING TOK_IDENT TOK_CMP_EQNEQ TOK_CMP_RELAT TOK_UNARY_OPERATOR TOK_ATTRIBUTION
%type<str> TOK_INCLUDE
%type<itg> TOK_INT
%type<flt> TOK_FLOAT
%type<node> globals global expr factor array_decl array_init_decl
%type<node> array_values array_values_decls array_values_decl struct_values_decl
%type<node> locals local scalar_decl scalar_init_decl attribution
%type<node> multi_decl multi_declarators multi_declarator
%type<node> scalar_or_array typedef_decl
%type<node> func_arg func_args optional_func_args func_decl func_impl function_call func_call_args
%type<node> ifstmt elseblock forstmt whilestmt whilebody optional_locals returnstmt include
%type<node> struct_decl struct_field struct_fields
%type<node> qualifiers qualifier
%type<itg> pointer_arg
%type<strings> typedef_names

%printer { fprintf(yyo, "%s", $$); } <str>
%printer { fprintf(yyo, "%lld", static_cast<long long>($$)); } <itg>
%printer { fprintf(yyo, "%lf", $$); } <flt>

%left TOK_OR
%left TOK_AND
%left '|'
%left '^'
%left '&'
%left TOK_CMP_EQNEQ
%left TOK_CMP_RELAT
%left '+' '-'
%left '*' '/' '%'
%right UMINUS
%right '!' '~'
%left '(' ')'

%start program

%%

program : globals {
    Node *program = $globals;

    bool scope_valid = errorcount == 0 && resolveScopeProgram(program);
    bool while_valid = scope_valid && validateWhileProgram(program);
    if (while_valid && (errorcount == 0 || force_print_tree))
        cout << program->toStr(-1);
    
    exit(errorcount != 0 ? EXIT_FAILURE : EXIT_SUCCESS);
}

globals : globals[gg] global {
    if ($global)
        $gg->append($global);
    $$ = $gg;
}

globals : global {
    Node *n = new Node();
    if ($global)
        n->append($global);
    $$ = n;
}

global : qualifiers scalar_decl ';'         { $$ = preserveWhileQualifiers($2, $1); }
       | qualifiers scalar_init_decl ';'    { $$ = preserveWhileQualifiers($2, $1); }
       | qualifiers array_init_decl ';'     { $$ = preserveWhileQualifiers($2, $1); }
       | qualifiers array_decl ';'          { $$ = preserveWhileQualifiers($2, $1); }
       | qualifiers func_decl ';'           { $$ = $2; }
       | qualifiers struct_decl ';'         { $$ = $2; }
       | qualifiers func_impl               { $$ = $2; }
       | multi_decl ';'
       | qualifiers multi_decl ';' {
           for (Node *decl : $2->getChildren()) preserveWhileQualifiers(decl, $1);
           $$ = $2;
       }
       | scalar_decl ';'
       | scalar_init_decl ';'
       | array_init_decl ';'
       | array_decl ';'
       | func_decl ';'
       | typedef_decl ';'
       | func_impl
       | include
       ;

qualifiers : qualifiers[gg] qualifier {
    $gg->append($qualifier);
    $$ = $gg;
}

qualifiers : qualifier {
    Node *n = new Qualifiers();
    n->append($qualifier);
    $$ = n;
}

qualifier : TOK_CONST       { $$ = new Ident("const"); }
          | TOK_VOLATILE    { $$ = new Ident("volatile"); }
          | TOK_STATIC      { $$ = new Ident("static"); }
          | TOK_STRUCT      { $$ = new Ident("struct"); }
          ;

include : TOK_INCLUDE[name] {
    string name($name);
    size_t start = name.find_first_of("<\"") + 1;
    name = name.substr(start, name.length()-3-start);
    $$ = new Ident("use " + name + ";\n");
}

typedef_decl : TOK_TYPEDEF typedef_names[src] {
    declared_typedefs[$src->getName()] = $src->getType();
    $$ = NULL;
}

typedef_decl : TOK_TYPEDEF TOK_STRUCT typedef_names[src] {
    declared_typedefs[$src->getName()] = $src->getType();
    $$ = NULL;
}

typedef_names : typedef_names[ss] TOK_IDENT[id] {
    $ss->strings.push_back($id);
    $$ = $ss;
}

typedef_names : TOK_IDENT[id] {
    $$ = new Strings();
    $$->strings.push_back($id);
}

struct_decl : TOK_IDENT[name] '{' struct_fields '}' {
    $$ = new Type($name, $struct_fields);
}

struct_fields : struct_fields[gg] struct_field {
    $gg->append($struct_field);
    $$ = $gg;
}

struct_fields : struct_field {
    Node *n = new TypeFields();
    n->append($struct_field);
    $$ = n;
}

struct_field : scalar_decl ';' {
    $$ = $scalar_decl;
}

struct_field : qualifiers scalar_decl ';' {
    $$ = preserveWhileQualifiers($scalar_decl, $qualifiers);
}

struct_field : TOK_IDENT[type] TOK_IDENT[name] ':' TOK_INTEGER_LITERAL[bitfield] ';' {
    $$ = new VariableDecl($type, $name, atoi($bitfield));
}

func_decl : TOK_IDENT[type] TOK_IDENT[name] '(' optional_func_args ')' {
    $$ = new Function($type, $name, $optional_func_args);
}

func_decl : TOK_IDENT[type] '*' TOK_IDENT[name] '(' optional_func_args ')' {
    $$ = new Function($type, $name, $optional_func_args);
    ((Function*)$$)->markPointerResult();
}

func_impl : TOK_IDENT[type] TOK_IDENT[name] '(' optional_func_args ')' '{' optional_locals '}' {
    $$ = new Function($type, $name, $optional_func_args, $optional_locals);
}

func_impl : TOK_IDENT[type] '*' TOK_IDENT[name] '(' optional_func_args ')' '{' optional_locals '}' {
    $$ = new Function($type, $name, $optional_func_args, $optional_locals);
    ((Function*)$$)->markPointerResult();
}

// Reject actual parameters of type void
optional_func_args : func_args {
    for (Node *node : $func_args->getChildren()) {
        auto *arg = static_cast<FuncArg*>(node);

        if (arg->getTypeName() == "void" && !arg->isSourcePointer())
            yyerror("a void parameter cannot have a name or qualifiers");
    }

    $$ = $func_args;
}

optional_func_args : %empty {
    $$ = new NodeArgs();
}

//Reject 'void' when mixed with other parameters in conditional
func_args : func_args[gg] ',' func_arg {
    if($gg->getChildren().empty() || !$func_arg)
        yyerror("void must be the only item in the parameter list");

    $gg->append($func_arg);
    $$ = $gg;
}

func_args : func_arg {
    Node *n = new NodeArgs();
    n->append($func_arg);
    $$ = n;
}

pointer_arg : '*' {
    $$ = 1;
}

pointer_arg : '*' '*' {
    $$ = 1;
}

// unamed parameters
func_arg : TOK_IDENT[type] {
    if(string($type) == "void"){
        $$ = nullptr;
    }else{
        char unamed[10];
        snprintf(unamed, 10, "_un%d", current_unamed_arg++);
        $$ = new FuncArg($type, unamed);
    }
}

func_arg : TOK_IDENT[type] pointer_arg {
    char unamed[10];
    snprintf(unamed, 10, "_un%d", current_unamed_arg++);
    string atype = $type;
    if ((atype == "char" || atype == "int32" || atype == "int") && $pointer_arg == 1)
        atype.push_back('*');
    $$ = new FuncArg(atype, unamed, true);
}

func_arg : qualifiers TOK_IDENT[type] {
    char unamed[10];
    snprintf(unamed, 10, "_un%d", current_unamed_arg++);
    $$ = new FuncArg($type, unamed);
}

func_arg : qualifiers TOK_IDENT[type] pointer_arg {
    char unamed[10];
    snprintf(unamed, 10, "_un%d", current_unamed_arg++);
    string atype = $type;
    if ((atype == "char" || atype == "int32" || atype == "int") && $pointer_arg == 1)
        atype.push_back('*');
    $$ = new FuncArg(atype, unamed, true);
}

// named parameters

func_arg : TOK_IDENT[type] TOK_IDENT[name] {
    $$ = new FuncArg($type, $name);
}

func_arg : TOK_IDENT[type] '*' TOK_IDENT[name] {
    string atype = $type;
    if (atype == "char" || atype == "int32" || atype == "int")
        atype.push_back('*');
    $$ = new FuncArg(atype, $name, true);
}

func_arg : qualifiers TOK_IDENT[type] '*' TOK_IDENT[name] {
    string atype = $type;
    //atype.push_back('*'); //TODO: check what to do with pointers as rob doesn't have them
    $$ = new FuncArg(atype, $name, true);
}

func_arg : TOK_IDENT[type] '*' TOK_IDENT[name] '[' ']' {
    string atype = $type;
    //atype.push_back('*'); //TODO: check what to do with pointers as rob doesn't have them
    $$ = new FuncArg(atype, $name, true); //TODO: need [] or is just main arg?
}

global : error ';' { $$ = new Node(); }

locals : locals[gg] local {
    $gg->append($local);
    $$ = $gg;
}

locals : local {
    Node *n = new Node();
    n->append($local);
    $$ = n;
}

local : qualifiers scalar_decl ';'      { $$ = preserveWhileQualifiers($2, $1); }
      | qualifiers scalar_init_decl ';' { $$ = preserveWhileQualifiers($2, $1); }
      | qualifiers array_init_decl ';'  { $$ = preserveWhileQualifiers($2, $1); }
      | qualifiers array_decl ';'       { $$ = preserveWhileQualifiers($2, $1); }
      | multi_decl ';'
      | qualifiers multi_decl ';' {
          for (Node *decl : $2->getChildren()) preserveWhileQualifiers(decl, $1);
          $$ = $2;
      }
      | scalar_decl ';'
      | scalar_init_decl ';'
      | array_init_decl ';'
      | array_decl ';'
      | attribution ';'
      | function_call ';'   { ((FunctionCall*)$1)->setInExpr(false); $$ = $1; }
      | ifstmt
      | forstmt
      | whilestmt
      | returnstmt
      ; 

// Always pass a statement list to While, including the two empty-body forms.
whilestmt : TOK_WHILE '(' expr ')' whilebody {
    $$ = new While($expr, $whilebody, true);
}

whilebody : '{' optional_locals '}' { $$ = $optional_locals; }
          | local {
              $$ = new Node();
              $$->append($local);
          }
          | ';' { $$ = new Node(); }
          ;

optional_locals : locals { $$ = $locals; }
                | %empty { $$ = new Node(); }
                ;

returnstmt : TOK_RETURN expr ';' {
    $$ = new Return($expr);
}

returnstmt : TOK_RETURN ';' {
    $$ = new Return();
}

// a = expr;
attribution : scalar_or_array '=' expr {
    $$ = new Store($scalar_or_array, "=", $expr);
}

// a += expr;
// a[x] -= expr;
attribution : scalar_or_array TOK_ATTRIBUTION[at] expr {
    $$ = new Store($scalar_or_array, $at, $expr);
}

// a--;
attribution : factor[f] TOK_UNARY_OPERATOR[op] {
    $$ = new UnaryAttribution($f, $op);
}

forstmt : TOK_FOR '(' attribution[a1] ';' expr ';' attribution[a2] ')' local {
    Node *nfor = new Container();
    nfor->append($a1);
    Node *body = new Node();
    body->append($local);
    auto *loop = new While($expr, body);
    loop->setUpdate($a2);
    nfor->append(loop);
    $$ = nfor;
}

forstmt : TOK_FOR '(' attribution[a1] ';' expr ';' attribution[a2] ')' '{' locals '}' {
    Node *nfor = new Container();
    nfor->append($a1);
    auto *loop = new While($expr, $locals);
    loop->setUpdate($a2);
    nfor->append(loop);
    $$ = nfor;
}

ifstmt : TOK_IF '(' expr ')' local {
    $$ = new IfStmt($expr, $local);
}

ifstmt : TOK_IF '(' expr ')' local elseblock {
    $$ = new IfStmt($expr, $local, $elseblock);
}

ifstmt : TOK_IF '(' expr ')' '{' locals '}' {
    $$ = new IfStmt($expr, $locals);
}

ifstmt : TOK_IF '(' expr ')' '{' locals '}' elseblock {
    $$ = new IfStmt($expr, $locals, $elseblock);
}

// Require at least two declarators; single declarations keep their existing rules.
multi_decl : TOK_IDENT[type] multi_declarators {
    string type = VariableDecl::convertTypeToRob($type);
    if (declared_types.contains(type))
        yyerror("multiple declaration: aggregate type not supported");
    if (type == "void")
        yyerror("multiple declaration: type 'void' cannot be used to declare variables");
    for (Node *node : $multi_declarators->getChildren()) {
        auto *decl = static_cast<VariableDecl*>(node);
        decl->setDeclarationType($type);
        if (decl->getIndex()) {
            string size = decl->getIndex()->toStr(0);
            if (!regex_match(size, regex("[1-9][0-9]*")))
                yyerror("multiple declaration: vector dimension must be a positive integer literal");
            else if (decl->getValue() && to_string(decl->getValue()->getChildren().size()) != size)
                yyerror("multiple declaration: array initialization must populate all elements");
        }
    }
    $$ = $multi_declarators;
}

multi_declarators : multi_declarator[a] ',' multi_declarator[b] {
    $$ = new Container();
    $$->append($a);
    $$->append($b);
}

multi_declarators : multi_declarators[list] ',' multi_declarator {
    $list->append($multi_declarator);
    $$ = $list;
}

// The shared source type is applied by multi_decl before emitting ROB.
multi_declarator : TOK_IDENT[name] {
    $$ = new VariableDecl("", $name);
}

multi_declarator : TOK_IDENT[name] '=' expr {
    $$ = new VariableDecl("", $name, $expr);
}

multi_declarator : TOK_IDENT[name] '[' expr ']' {
    $$ = new VariableDecl("", $name, $expr, nullptr);
}

multi_declarator : TOK_IDENT[name] '[' expr[idx] ']' '=' array_values_decl[value] {
    $$ = new VariableDecl("", $name, $idx, $value);
}

elseblock : TOK_ELSE '{' locals '}' { $$ = $locals; }
elseblock : TOK_ELSE local          { $$ = $local; }

/* scalars */
scalar_init_decl : TOK_IDENT[type] TOK_IDENT[name] '=' expr {
    $$ = new VariableDecl($type, $name, $expr);
}

/* initialized structs */
scalar_init_decl : TOK_IDENT[type] TOK_IDENT[name] '=' array_values_decl[value] {
    $$ = new InitializedType($type, $name, $value);
}

/* not initialized scalars */
scalar_decl : TOK_IDENT[type] TOK_IDENT[name] {
    $$ = new VariableDecl($type, $name);
}

/* arrays */
array_init_decl : TOK_IDENT[type] TOK_IDENT[name] '[' expr[idx] ']' '=' array_values_decl[value] {
    ((NodeArgs*)$value)->setArrayInitType($type);
    $$ = new VariableDecl($type, $name, $idx, $value);
}

array_decl : TOK_IDENT[type] TOK_IDENT[name] '[' expr[idx] ']' {
    $$ = new VariableDecl($type, $name, $idx, nullptr);
}

array_init_decl : TOK_IDENT[type] TOK_IDENT[name] '[' expr[idx] ']' '=' struct_values_decl[value] {
    $$ = new StructVariableDecl($type, $name, $idx, $value);
}

struct_values_decl : '{' array_values_decls[decl] '}' { $$ = $decl; }

array_values_decls : array_values_decls[gg] ',' array_values_decl {
    $gg->append($array_values_decl);
    $$ = $gg;
}

array_values_decls : array_values_decl {
    Node *n = new NodeArgs();
    n->append($array_values_decl);
    $$ = n;
}

array_values_decl : '{' array_values '}' { $$ = $array_values; } ;

array_values : array_values[gg] ',' expr {
    $gg->append($expr);
    $$ = $gg;
}

array_values : expr {
    Node *n = new NodeArgs();
    n->append($expr);
    $$ = n;
}

expr: expr[e1] TOK_CMP_RELAT[op] expr[e2] { $$ = new BinaryOp($e1, $e2, $op); }
expr: expr[e1] TOK_CMP_EQNEQ[op] expr[e2] { $$ = new BinaryOp($e1, $e2, $op); }
expr: expr[e1] TOK_AND expr[e2] { $$ = new BinaryOp($e1, $e2, "and"); }
expr: expr[e1] TOK_OR expr[e2]  { $$ = new BinaryOp($e1, $e2, "or"); }
expr: expr[e1] '+' expr[e2]     { $$ = new BinaryOp($e1, $e2, "+"); }
expr: expr[e1] '-' expr[e2]     { $$ = new BinaryOp($e1, $e2, "-"); }
expr: expr[e1] '*' expr[e2]     { $$ = new BinaryOp($e1, $e2, "*"); }
expr: expr[e1] '/' expr[e2]     { $$ = new BinaryOp($e1, $e2, "/"); }
expr: expr[e1] '%' expr[e2]     { $$ = new BinaryOp($e1, $e2, "%"); }
expr: expr[e1] '&' expr[e2]     { $$ = new BinaryOp($e1, $e2, "&"); }
expr: expr[e1] '|' expr[e2]     { $$ = new BinaryOp($e1, $e2, "|"); }
expr: expr[e1] '^' expr[e2]     { $$ = new BinaryOp($e1, $e2, "^"); }
expr: '!' expr[e1]              { $$ = new Unary($e1, "!"); }
expr: '~' expr[e1]              { $$ = new Unary($e1, "~"); }
expr: '-' expr[e1] %prec UMINUS { $$ = new Unary($e1, "-"); }
expr: '+' expr[e1] %prec UMINUS { $$ = $e1; }
expr: '(' expr[e1] ')'          { $$ = new Parenthesis($e1); }
expr: factor

factor : function_call
factor : scalar_or_array 

factor : TOK_INT[itg] {
    $$ = new Integer($itg);
}

factor : TOK_FLOAT[flt] {
    $$ = new Float($flt);
}

factor : TOK_STRING[str] {
    $$ = new Ident($str);
}

factor : TOK_INTEGER_LITERAL[str] {
    $$ = new IntegerToken($str);
}

factor : factor[f] TOK_UNARY_OPERATOR[op] {
    $$ = new Unary($f, $op);
}

scalar_or_array : TOK_IDENT[id] {
    $$ = new Ident($id);
}

scalar_or_array : TOK_IDENT[id] '[' expr ']' {
    $$ = new LoadArray($id, $expr);
}

scalar_or_array : TOK_IDENT[id] '.' TOK_IDENT[id2] {
    $$ = new LoadField($id, $id2);
}

scalar_or_array : TOK_IDENT[id] '[' expr ']' '.' TOK_IDENT[id2] {
    $$ = new LoadArrayField($id, $expr, $id2);
}

function_call : TOK_IDENT[id] '(' ')' {
    $$ = new FunctionCall($id);
}

function_call : TOK_IDENT[id] '(' func_call_args[args] ')' {
    $$ = new FunctionCall($id, $args);
}

func_call_args : func_call_args[gg] ',' expr {
    $gg->append($expr);
    $$ = $gg;
}

func_call_args : expr {
    Node *n = new NodeArgs();
    n->append($expr);
    $$ = n;
}

%%
