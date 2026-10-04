#pragma once

// A narrow semantic pass for native C while and the statements controlling it.
// Existing for-only programs retain their original emitter.
namespace cwhile {

enum class Kind { Integer, Boolean, Floating, Pointer, Aggregate, Void, Unknown };

struct Symbol {
    Kind kind = Kind::Unknown;
    Kind element = Kind::Unknown;
    string type;
    bool array = false;
    bool sourceVolatile = false;
    bool unsafeLocalStatic = false;
};
using Scope = map<string, Symbol>;
struct FunctionInfo {
    Kind result;
    vector<Kind> parameters;
};
using Functions = map<string, FunctionInfo>;

struct Expression {
    string text;
    Kind kind;
    bool atomic = true;
};

struct ValidationError {
    Node *node;
    string message;
};

Kind kindOfType(const string &source) {
    string type = VariableDecl::convertTypeToRob(source);
    if (type.find('*') != string::npos || type.find('[') != string::npos)
        return Kind::Pointer;
    if (type == "bool" || type == "int1" || type == "uint1") return Kind::Boolean;
    if (type == "float" || type == "double" || type == "long double") return Kind::Floating;
    if (type == "void") return Kind::Void;
    if (type == "char") return Kind::Integer;
    if (type.starts_with("int") || type.starts_with("uint")) {
        size_t offset = type.starts_with("uint") ? 4 : 3;
        if (offset < type.size() && type.find_first_not_of("0123456789", offset) == string::npos)
            return Kind::Integer;
    }
    if (declared_types.contains(type)) return Kind::Aggregate;
    return Kind::Unknown;
}

string grouped(const Expression &expr) {
    return expr.atomic ? expr.text : "(" + expr.text + ")";
}

void requireIntegral(const Expression &expr, Node *node) {
    if (expr.kind == Kind::Integer || expr.kind == Kind::Boolean) return;
    string reason;
    switch (expr.kind) {
        case Kind::Pointer: reason = "condição/expressão com ponteiro não suportada com semântica confiável"; break;
        case Kind::Floating: reason = "condição/expressão com ponto flutuante não suportada neste incremento"; break;
        case Kind::Aggregate: reason = "condição/expressão com agregado não suportada"; break;
        case Kind::Void: reason = "expressão void não pode ser usada como condição/valor"; break;
        default: reason = "tipo desconhecido na expressão"; break;
    }
    throw ValidationError{node, "while: " + reason + ": " + expr.text};
}

Expression asInteger(Expression expr) {
    // C comparison/logical operators yield int. ROB yields a boolean.
    if (expr.kind == Kind::Boolean) {
        expr.text = "int32(" + expr.text + ")";
        expr.kind = Kind::Integer;
        expr.atomic = true;
    }
    return expr;
}

string asCondition(const Expression &expr, Node *node) {
    requireIntegral(expr, node);
    return expr.kind == Kind::Boolean ? expr.text : grouped(expr) + " != 0";
}

Symbol resolveSymbol(const string &name, const Scope &scope) {
    auto dot = name.find('.');
    string base = name.substr(0, dot);
    auto found = scope.find(base);
    if (found == scope.end()) return {};
    Symbol symbol = found->second;
    while (dot != string::npos) {
        if (symbol.kind != Kind::Aggregate || !declared_types.contains(symbol.type)) return {};
        size_t next = name.find('.', dot + 1);
        string field = name.substr(dot + 1, next == string::npos ? string::npos : next - dot - 1);
        Symbol result;
        for (Node *n : declared_types[symbol.type]->getFields()->getChildren()) {
            if (auto *decl = dynamic_cast<VariableDecl*>(n); decl && decl->getName() == field) {
                result = {kindOfType(decl->getTypeName()), Kind::Unknown, decl->getTypeName(), false,
                          symbol.sourceVolatile || decl->isSourceVolatile(), symbol.unsafeLocalStatic};
                break;
            }
        }
        symbol = result;
        dot = next;
    }
    return symbol;
}

void checkVolatile(const Symbol &symbol, Node *node) {
    if (symbol.unsafeLocalStatic)
        throw ValidationError{node, "while: variável local static não suportada; o emissor atual não preserva sua duração entre execuções"};
    if (symbol.sourceVolatile)
        throw ValidationError{node, "while: acesso volatile não suportado; o C2rob atual não preserva esse qualificador na emissão ROB"};
}

Expression expression(Node *node, const Scope &scope, const Functions &functions) {
    if (!node) throw ValidationError{node, "while: expressão ausente"};
    Expression result{"", Kind::Unknown};
    if (auto *literal = dynamic_cast<IntegerToken*>(node)) {
        result = {literal->getText(), Kind::Integer};
    } else if (dynamic_cast<Integer*>(node)) {
        result = {node->toStr(0), Kind::Integer};
    } else if (dynamic_cast<Float*>(node)) {
        result = {node->toStr(0), Kind::Floating};
    } else if (auto *ident = dynamic_cast<Ident*>(node)) {
        Symbol symbol = resolveSymbol(ident->getText(), scope);
        checkVolatile(symbol, node);
        result = {ident->getText(), symbol.kind};
    } else if (auto *paren = dynamic_cast<Parenthesis*>(node)) {
        auto value = expression(paren->getValue(), scope, functions);
        result = {"(" + value.text + ")", value.kind};
    } else if (auto *unary = dynamic_cast<Unary*>(node)) {
        const string &op = unary->getOperation();
        if (op == "++" || op == "--")
            throw ValidationError{node, "while: pós-incremento/decremento em expressão não suportado; o valor anterior não é garantido pelo ROB atual"};
        auto value = expression(unary->getValue(), scope, functions);
        requireIntegral(value, node);
        if (op == "!")
            result = {"!(" + asCondition(value, node) + ")", Kind::Boolean};
        else
            result = {op + grouped(asInteger(value)), Kind::Integer};
    } else if (auto *binary = dynamic_cast<BinaryOp*>(node)) {
        auto left = expression(binary->getLeft(), scope, functions);
        auto right = expression(binary->getRight(), scope, functions);
        requireIntegral(left, binary->getLeft());
        requireIntegral(right, binary->getRight());
        const string &op = binary->getOperation();
        if (op == "and" || op == "or") {
            result = {"(" + asCondition(left, node) + ") " + op + " (" + asCondition(right, node) + ")", Kind::Boolean, false};
        } else {
            bool comparison = op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=";
            result = {grouped(asInteger(left)) + " " + op + " " + grouped(asInteger(right)),
                      comparison ? Kind::Boolean : Kind::Integer, false};
        }
    } else if (auto *array = dynamic_cast<LoadArray*>(node)) {
        Symbol symbol = resolveSymbol(array->getArrayName(), scope);
        checkVolatile(symbol, node);
        if (!symbol.array) {
            requireIntegral({array->getArrayName(), symbol.kind}, node);
            throw ValidationError{node, "while: acesso a vetor de tipo desconhecido: " + array->getArrayName()};
        }
        auto index = expression(array->getIndex(), scope, functions);
        requireIntegral(index, node);
        result = {array->getArrayName() + "[" + asInteger(index).text + "]", symbol.element};
    } else if (auto *field = dynamic_cast<LoadField*>(node)) {
        string name = field->getBaseName() + "." + field->getFieldName();
        Symbol symbol = resolveSymbol(name, scope);
        checkVolatile(symbol, node);
        result = {name, symbol.kind};
    } else if (dynamic_cast<LoadArrayField*>(node)) {
        throw ValidationError{node, "while: acesso a campo de vetor não suportado; a emissão atual antecipa uma leitura para aux"};
    } else if (auto *call = dynamic_cast<FunctionCall*>(node)) {
        auto function = functions.find(call->getName());
        if (function != functions.end()) {
            for (Kind parameter : function->second.parameters)
                requireIntegral({call->getName() + " (tipo do parâmetro)", parameter}, node);
        }
        string args;
        if (call->getArgs()) {
            for (Node *arg : call->getArgs()->getChildren()) {
                auto value = expression(arg, scope, functions);
                requireIntegral(value, arg);
                if (!args.empty()) args += ", ";
                args += asInteger(value).text;
            }
        }
        result = {call->getName() + "(" + args + ")",
                  function == functions.end() ? Kind::Unknown : function->second.result};
    } else {
        throw ValidationError{node, "while: construção de expressão não suportada"};
    }
    node->setCheckedExpression(result.text);
    return result;
}

bool containsNativeWhile(Node *node) {
    if (!node) return false;
    if (auto *loop = dynamic_cast<While*>(node))
        return loop->isNativeCWhile() || containsNativeWhile(loop->getBody());
    if (auto *branch = dynamic_cast<IfStmt*>(node))
        return containsNativeWhile(branch->getIfBody()) || containsNativeWhile(branch->getElseBody());
    for (Node *child : node->getChildren())
        if (containsNativeWhile(child)) return true;
    return false;
}

void addDeclaration(VariableDecl *decl, Scope &scope, bool global = false) {
    Kind kind = kindOfType(decl->getTypeName());
    scope[decl->getName()] = {decl->getIndex() ? Kind::Pointer : kind,
                             decl->getIndex() ? kind : Kind::Unknown,
                             decl->getTypeName(), decl->getIndex() != nullptr, decl->isSourceVolatile(),
                             decl->isSourceStatic() && !global};
}

void checkValue(Node *value, const Scope &scope, const Functions &functions) {
    auto expr = expression(value, scope, functions);
    requireIntegral(expr, value);
    value->setCheckedExpression(asInteger(expr).text);
}

void statements(Node *node, Scope &scope, const Functions &functions, bool strict = false) {
    if (!node) return;
    if (auto *loop = dynamic_cast<While*>(node)) {
        bool native = loop->isNativeCWhile();
        if (native || strict || containsNativeWhile(loop->getBody())) {
            auto condition = expression(loop->getCondition(), scope, functions);
            loop->setCheckedExpression(asCondition(condition, loop->getCondition()));
        }
        Scope body = scope;
        statements(loop->getBody(), body, functions, strict || native);
    } else if (auto *branch = dynamic_cast<IfStmt*>(node)) {
        if (strict || containsNativeWhile(node)) {
            auto condition = expression(branch->getCondition(), scope, functions);
            branch->setCheckedExpression(asCondition(condition, branch->getCondition()));
        }
        Scope ifScope = scope, elseScope = scope;
        statements(branch->getIfBody(), ifScope, functions, strict);
        statements(branch->getElseBody(), elseScope, functions, strict);
    } else if (auto *decl = dynamic_cast<VariableDecl*>(node)) {
        if (strict) checkVolatile({Kind::Unknown, Kind::Unknown, "", false, decl->isSourceVolatile(), decl->isSourceStatic()}, node);
        if (strict && decl->getValue()) {
            if (decl->getIndex()) {
                for (Node *item : decl->getValue()->getChildren()) checkValue(item, scope, functions);
            } else {
                checkValue(decl->getValue(), scope, functions);
            }
        }
        addDeclaration(decl, scope);
    } else if (auto *decl = dynamic_cast<InitializedType*>(node)) {
        if (strict) {
            checkVolatile({Kind::Unknown, Kind::Unknown, "", false, decl->isSourceVolatile(), decl->isSourceStatic()}, node);
            if (!declared_types.contains(decl->getTypeName()))
                throw ValidationError{node, "while: tipo desconhecido na inicialização de agregado: " + decl->getTypeName()};
            if (decl->getValues()->getChildren().size() != declared_types[decl->getTypeName()]->getFields()->getChildren().size())
                throw ValidationError{node, "while: inicialização parcial de estrutura não suportada pelo emissor atual"};
            for (Node *value : decl->getValues()->getChildren()) checkValue(value, scope, functions);
        }
        scope[decl->getName()] = {Kind::Aggregate, Kind::Unknown, decl->getTypeName(), false,
                                decl->isSourceVolatile(), decl->isSourceStatic()};
    } else if (dynamic_cast<StructVariableDecl*>(node)) {
        if (strict)
            throw ValidationError{node, "while: inicialização de vetor de estruturas não suportada com semântica confiável"};
    } else if (auto *store = dynamic_cast<Store*>(node)) {
        if (strict) {
            requireIntegral(expression(store->getLeft(), scope, functions), store->getLeft());
            checkValue(store->getValue(), scope, functions);
        }
    } else if (auto *update = dynamic_cast<UnaryAttribution*>(node)) {
        // Statement n-- is supported; postfix used as a value is deliberately rejected.
        if (strict) requireIntegral(expression(update->getValue(), scope, functions), update->getValue());
    } else if (auto *ret = dynamic_cast<Return*>(node)) {
        if (strict) checkValue(ret->getExpr(), scope, functions);
    } else if (auto *call = dynamic_cast<FunctionCall*>(node)) {
        if (strict) {
            auto value = expression(call, scope, functions);
            if (value.kind != Kind::Void) requireIntegral(value, call);
        }
    } else {
        for (Node *child : node->getChildren()) statements(child, scope, functions, strict);
    }
}

} // namespace cwhile

Node *preserveWhileQualifiers(Node *node, Node *qualifiers) {
    for (Node *qualifier : qualifiers->getChildren()) {
        auto *ident = dynamic_cast<Ident*>(qualifier);
        if (ident && ident->getText() == "volatile") node->markSourceVolatile();
        if (ident && ident->getText() == "static") node->markSourceStatic();
    }
    return node;
}

bool validateWhileProgram(Node *program) {
    using namespace cwhile;
    if (!containsNativeWhile(program)) return true;
    Scope globals;
    Functions functions;
    for (Node *node : program->getChildren()) {
        if (auto *function = dynamic_cast<Function*>(node)) {
            FunctionInfo info{function->hasPointerResult() ? Kind::Pointer : kindOfType(function->getTypeName()), {}};
            if (function->getArgs()) {
                for (Node *argNode : function->getArgs()->getChildren())
                    if (auto *arg = dynamic_cast<FuncArg*>(argNode))
                        info.parameters.push_back(arg->isSourcePointer() ? Kind::Pointer : kindOfType(arg->getTypeName()));
            }
            functions[function->getName()] = info;
        } else if (auto *decl = dynamic_cast<VariableDecl*>(node))
            addDeclaration(decl, globals, true);
        else if (auto *decl = dynamic_cast<InitializedType*>(node))
            globals[decl->getName()] = {Kind::Aggregate, Kind::Unknown, decl->getTypeName(), false, decl->isSourceVolatile()};
    }
    try {
        for (Node *node : program->getChildren()) {
            auto *function = dynamic_cast<Function*>(node);
            if (!function || !function->getBody()) continue;
            Scope scope = globals;
            if (function->getArgs()) {
                for (Node *argNode : function->getArgs()->getChildren()) {
                    auto *arg = dynamic_cast<FuncArg*>(argNode);
                    if (arg)
                        scope[arg->getName()] = {arg->isSourcePointer() ? Kind::Pointer : kindOfType(arg->getTypeName()),
                                                Kind::Unknown, VariableDecl::convertTypeToRob(arg->getTypeName()), false};
                }
            }
            statements(function->getBody(), scope, functions);
        }
    } catch (const ValidationError &error) {
        fprintf(stderr, "%s:%d: %s\n", build_file_name, error.node ? error.node->getLineNo() : yylineno,
                error.message.c_str());
        errorcount++;
        return false;
    }
    return true;
}
