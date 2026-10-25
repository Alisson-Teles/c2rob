#pragma once

// Apply C integer promotions and conversions after name resolution.
namespace cinteger {

struct Value {
    string text, type;
    bool boolean = false;
    bool changed = false;
};

inline unsigned bits(const string &type) {
    if (type == "char")
        return 8;

    if (!regex_match(type, regex("u?int(8|16|32|64)")))
        return 0;

    return stoi(
        type.substr(type.starts_with("uint") ? 4 : 3)
    );
}

inline bool integral(const Value &value) {
    return value.boolean || bits(value.type);
}

inline bool unsignedType(const string &type) {
    return type == "char" || type.starts_with("uint");
}

inline string promoted(const string &type) {
    return bits(type) < 32 ? "int32" : type;
}

inline string commonType(
    const string &left,
    const string &right
) {
    unsigned lb = bits(left);
    unsigned rb = bits(right);

    if (unsignedType(left) == unsignedType(right))
        return lb >= rb ? left : right;

    string u = unsignedType(left) ? left : right;
    string s = unsignedType(left) ? right : left;

    return bits(u) >= bits(s) ? u : s;
}

inline Value asInteger(Value value) {
    if (value.boolean) {
        value.text = "int32(uint32(" + value.text + "))";
        value.type = "int32";
        value.boolean = false;
        value.changed = true;
    }

    return value;
}

inline string castTo(const string &target, Value value) {
    value = asInteger(value);

    string text = value.text;

    // Extend using the source's signedness before changing signedness.
    if (
        bits(target) > bits(value.type)
        && unsignedType(target) != unsignedType(value.type)
    ) {
        string middle =
            (unsignedType(value.type) ? "uint" : "int")
            + to_string(bits(target));

        text = middle + "(" + text + ")";
    }

    return target + "(" + text + ")";
}

struct Symbol {
    string type;
    bool array = false;
};

using Scope = map<string, Symbol>;

struct FunctionInfo {
    string result;
    vector<string> parameters;
};

class Validator {
    Scope globals;
    map<string, FunctionInfo> functions;

    Symbol symbol(const string &name, const Scope &scope) {
        size_t dot = name.find('.');
        auto found = scope.find(name.substr(0, dot));

        if (found == scope.end())
            return {};

        Symbol result = found->second;

        while (dot != string::npos) {
            if (!declared_types.contains(result.type))
                return {};

            size_t next = name.find('.', dot + 1);

            string field = name.substr(
                dot + 1,
                next == string::npos
                    ? string::npos
                    : next - dot - 1
            );

            bool matched = false;

            for (
                Node *node :
                declared_types[result.type]->getFields()->getChildren()
            ) {
                auto *decl = dynamic_cast<VariableDecl*>(node);

                if (decl && decl->getName() == field) {
                    result = {
                        decl->getTypeName(),
                        decl->getIndex() != nullptr
                    };

                    matched = true;
                    break;
                }
            }

            if (!matched)
                return {};

            dot = next;
        }

        return result;
    }

    Symbol lvalue(Node *node, const Scope &scope) {
        if (auto *ident = dynamic_cast<Ident*>(node))
            return symbol(ident->getText(), scope);

        if (auto *array = dynamic_cast<LoadArray*>(node)) {
            Symbol result = symbol(array->getArrayName(), scope);
            result.array = false;
            return result;
        }

        if (auto *field = dynamic_cast<LoadField*>(node))
            return symbol(
                field->getBaseName() + "." + field->getFieldName(),
                scope
            );

        return {};
    }

    Value expression(Node *node, const Scope &scope) {
        if (!node)
            return {};

        Value result{node->toStr(0), ""};

        if (auto *literal = dynamic_cast<IntegerToken*>(node)) {
            auto info = sourceIntegerLiteral(literal->getText());

            result = {
                info.type == "int32"
                    ? info.digits
                    : info.type + "(" + info.digits + ")",
                info.type,
                false,
                info.type != "int32"
            };

        } else if (auto *ident = dynamic_cast<Ident*>(node)) {
            Symbol sym = symbol(ident->getText(), scope);

            if (!sym.array)
                result.type = sym.type;

        } else if (auto *paren = dynamic_cast<Parenthesis*>(node)) {
            result = expression(paren->getValue(), scope);
            result.text = "(" + result.text + ")";

        } else if (auto *unary = dynamic_cast<Unary*>(node)) {
            Value value = expression(unary->getValue(), scope);
            string op = unary->getOperation();

            if (integral(value) && op != "++" && op != "--") {
                if (op == "!") {
                    string condition = value.boolean
                        ? value.text
                        : "(" + value.text + ") != 0";

                    result = {
                        "!(" + condition + ")",
                        "int32",
                        true,
                        true
                    };

                } else {
                    value = asInteger(value);
                    string type = promoted(value.type);

                    bool changed =
                        value.changed
                        || type != "int32"
                        || value.type != type;

                    string text =
                        op + "(" + castTo(type, value) + ")";

                    if (op == "~") {
                        // Avoid Robcmp's FlipOp path.
                        text =
                            "(" + castTo(type, value)
                            + " ^ "
                            + castTo(type, {"-1", "int32"})
                            + ")";

                        changed = true;

                    } else if (op == "-" && changed) {
                        text =
                            "(" + type + "(0) - "
                            + castTo(type, value)
                            + ")";
                    }

                    result = {
                        text,
                        type,
                        false,
                        changed
                    };
                }
            }

        } else if (auto *binary = dynamic_cast<BinaryOp*>(node)) {
            Value left = expression(binary->getLeft(), scope);
            Value right = expression(binary->getRight(), scope);
            string op = binary->getOperation();

            if (integral(left) && integral(right)) {
                if (op == "and" || op == "or") {
                    string l = left.boolean
                        ? left.text
                        : "(" + left.text + ") != 0";

                    string r = right.boolean
                        ? right.text
                        : "(" + right.text + ") != 0";

                    result = {
                        "(" + l + ") " + op + " (" + r + ")",
                        "int32",
                        true,
                        true
                    };

                } else {
                    left = asInteger(left);
                    right = asInteger(right);

                    string type = commonType(
                        promoted(left.type),
                        promoted(right.type)
                    );

                    bool comparison =
                        op == "<"
                        || op == ">"
                        || op == "<="
                        || op == ">="
                        || op == "=="
                        || op == "!=";

                    bool changed =
                        left.changed
                        || right.changed
                        || left.type != "int32"
                        || right.type != "int32";

                    result = {
                        "("
                            + castTo(type, left)
                            + " " + op + " "
                            + castTo(type, right)
                            + ")",
                        comparison ? "int32" : type,
                        comparison,
                        changed
                    };
                }
            }

        } else if (auto *array = dynamic_cast<LoadArray*>(node)) {
            Value index = asInteger(
                expression(array->getIndex(), scope)
            );

            if (index.changed)
                array->getIndex()->setCheckedExpression(index.text);

            Symbol sym = symbol(array->getArrayName(), scope);

            result = {
                array->getArrayName()
                    + "[" + array->getIndex()->toStr(0) + "]",
                sym.array ? sym.type : ""
            };

        } else if (auto *field = dynamic_cast<LoadField*>(node)) {
            result.type = symbol(
                field->getBaseName() + "." + field->getFieldName(),
                scope
            ).type;

        } else if (auto *call = dynamic_cast<FunctionCall*>(node)) {
            auto found = functions.find(call->getName());

            string args;
            bool changed = false;
            size_t index = 0;

            if (call->getArgs()) {
                for (Node *arg : call->getArgs()->getChildren()) {
                    Value value = asInteger(
                        expression(arg, scope)
                    );

                    if (
                        found != functions.end()
                        && index < found->second.parameters.size()
                    ) {
                        string target =
                            found->second.parameters[index];

                        if (
                            integral(value)
                            && bits(target)
                            && (
                                value.type != target
                                || value.changed
                            )
                        ) {
                            value.text = castTo(target, value);
                            value.changed = true;
                        }
                    }

                    if (!args.empty())
                        args += ", ";

                    args += value.changed
                        ? value.text
                        : arg->toStr(0);

                    changed |= value.changed;
                    ++index;
                }
            }

            result = {
                call->getName() + "(" + args + ")",
                found == functions.end()
                    ? ""
                    : found->second.result,
                false,
                changed
            };
        }

        if (result.changed)
            node->setCheckedExpression(result.text);
        else
            result.text = node->toStr(0);

        return result;
    }

    void initializer(VariableDecl *decl, const Scope &scope) {
        if (!decl->getValue())
            return;

        vector<Node*> values = decl->getIndex()
            ? decl->getValue()->getChildren()
            : vector<Node*>{decl->getValue()};

        for (Node *node : values) {
            Value value = asInteger(expression(node, scope));

            if (
                !integral(value)
                || !bits(decl->getTypeName())
            ) {
                continue;
            }

            if (
                value.changed
                || value.type != decl->getTypeName()
            ) {
                string text = value.text;

                if (value.type != decl->getTypeName())
                    text = castTo(decl->getTypeName(), value);

                auto *literal = dynamic_cast<IntegerToken*>(node);

                if (
                    !value.changed
                    && literal
                    && bits(decl->getTypeName()) >= 32
                ) {
                    continue;
                }

                node->setCheckedExpression(text);
            }
        }
    }

    void statements(
        Node *node,
        Scope &scope,
        const string &returnType
    ) {
        if (!node)
            return;

        if (auto *decl = dynamic_cast<VariableDecl*>(node)) {
            if (decl->getTypeName() == "void")
                throw cwhile::ValidationError{
                    node,
                    "declaration: void cannot be used as a variable type"
                };

            scope[decl->getName()] = {
                decl->getTypeName(),
                decl->getIndex() != nullptr
            };

            initializer(decl, scope);

        } else if (auto *branch = dynamic_cast<IfStmt*>(node)) {
            Value condition = expression(
                branch->getCondition(),
                scope
            );

            if (condition.changed && integral(condition))
                branch->setCheckedExpression(
                    condition.boolean
                        ? condition.text
                        : "(" + condition.text + ") != 0"
                );

            Scope a = scope;
            Scope b = scope;

            statements(branch->getIfBody(), a, returnType);
            statements(branch->getElseBody(), b, returnType);

        } else if (auto *loop = dynamic_cast<While*>(node)) {
            Value condition = expression(
                loop->getCondition(),
                scope
            );

            if (condition.changed && integral(condition))
                loop->setCheckedExpression(
                    condition.boolean
                        ? condition.text
                        : "(" + condition.text + ") != 0"
                );

            Scope body = scope;

            statements(loop->getBody(), body, returnType);
            statements(loop->getUpdate(), scope, returnType);

        } else if (auto *store = dynamic_cast<Store*>(node)) {
            Symbol target = lvalue(store->getLeft(), scope);

            if (
                dynamic_cast<LoadArray*>(store->getLeft())
                && store->getOperation() != "="
            ) {
                throw cwhile::ValidationError{
                    node,
                    "declaration: compound assignment to an array element "
                    "is not supported in this increment"
                };
            }

            Value value = asInteger(
                expression(store->getValue(), scope)
            );

            if (integral(value) && bits(target.type)) {
                if (store->getOperation() == "=") {
                    if (
                        value.changed
                        || value.type != target.type
                    ) {
                        store->getValue()->setCheckedExpression(
                            castTo(target.type, value)
                        );
                    }

                } else if (
                    dynamic_cast<Ident*>(store->getLeft())
                    && (
                        value.changed
                        || value.type != "int32"
                        || target.type != "int32"
                    )
                ) {
                    string left = store->getLeft()->toStr(0);

                    string common = commonType(
                        promoted(target.type),
                        promoted(value.type)
                    );

                    string op =
                        store->getOperation().substr(0, 1);

                    Value computed{
                        "("
                            + castTo(common, {left, target.type})
                            + " " + op + " "
                            + castTo(common, value)
                            + ")",
                        common
                    };

                    store->setCheckedExpression(
                        left + " = " + castTo(target.type, computed)
                    );
                }
            }

        } else if (auto *ret = dynamic_cast<Return*>(node)) {
            if (ret->getExpr()) {
                Value value = asInteger(
                    expression(ret->getExpr(), scope)
                );

                if (
                    integral(value)
                    && bits(returnType)
                    && (
                        value.changed
                        || value.type != returnType
                    )
                ) {
                    ret->getExpr()->setCheckedExpression(
                        castTo(returnType, value)
                    );
                }
            }

        } else if (auto *call = dynamic_cast<FunctionCall*>(node)) {
            expression(call, scope);

        } else if (auto *decl = dynamic_cast<InitializedType*>(node)) {
            scope[decl->getName()] = {
                decl->getTypeName()
            };

        } else {
            for (Node *child : node->getChildren())
                statements(child, scope, returnType);
        }
    }

public:
    void run(Node *program) {
        for (Node *node : program->getChildren()) {
            if (auto *fn = dynamic_cast<Function*>(node)) {
                if (fn->hasPointerResult())
                    throw cwhile::ValidationError{
                        node,
                        "declaration: pointer return types "
                        "are not supported in this increment"
                    };

                FunctionInfo info{
                    fn->getTypeName(),
                    {}
                };

                for (Node *node : fn->getArgs()->getChildren()) {
                    auto *arg = static_cast<FuncArg*>(node);

                    if (
                        arg->isSourcePointer()
                        && arg->getTypeName() != "char*"
                    ) {
                        throw cwhile::ValidationError{
                            node,
                            "declaration: pointer parameters "
                            "are not supported in this increment"
                        };
                    }

                    info.parameters.push_back(
                        arg->isSourcePointer()
                            ? ""
                            : VariableDecl::convertTypeToRob(
                                arg->getTypeName()
                            )
                    );
                }

                functions[fn->getName()] = info;

            } else {
                statements(node, globals, "");
            }
        }

        for (Node *node : program->getChildren()) {
            auto *fn = dynamic_cast<Function*>(node);

            if (!fn || !fn->getBody())
                continue;

            Scope scope = globals;

            for (Node *node : fn->getArgs()->getChildren()) {
                auto *arg = static_cast<FuncArg*>(node);

                scope[arg->getName()] = {
                    arg->isSourcePointer()
                        ? ""
                        : VariableDecl::convertTypeToRob(
                            arg->getTypeName()
                        ),
                    false
                };
            }

            statements(
                fn->getBody(),
                scope,
                fn->hasPointerResult() ? "" : fn->getTypeName()
            );
        }
    }
};

} // namespace cinteger

inline bool validateIntegerProgram(Node *program) {
    try {
        cinteger::Validator validator;
        validator.run(program);
        return true;

    } catch (const cwhile::ValidationError &error) {
        fprintf(
            stderr,
            "%s:%d: %s\n",
            build_file_name,
            error.node ? error.node->getLineNo() : yylineno,
            error.message.c_str()
        );

        errorcount++;
        return false;
    }
}