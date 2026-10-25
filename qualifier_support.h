#pragma once

// Validate source qualifiers after name resolution and before ROB emission.
namespace cqualifier {

struct Symbol {
    string type;
    bool readOnly = false;
};

using Scope = map<string, Symbol>;

class Validator {
    Scope globals;

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
                        result.readOnly || decl->isSourceConst()
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

    Symbol target(Node *node, const Scope &scope) {
        if (auto *ident = dynamic_cast<Ident*>(node))
            return symbol(ident->getText(), scope);

        if (auto *array = dynamic_cast<LoadArray*>(node))
            return symbol(array->getArrayName(), scope);

        if (auto *field = dynamic_cast<LoadField*>(node))
            return symbol(
                field->getBaseName() + "." + field->getFieldName(),
                scope
            );

        if (auto *paren = dynamic_cast<Parenthesis*>(node))
            return target(paren->getValue(), scope);

        return {};
    }

    void checkQualifiers(Node *node, bool global = false) {
        if (node->isSourceVolatile())
            throw cwhile::ValidationError{
                node,
                "while: volatile access is not supported; "
                "the current C2ROB emitter does not preserve this qualifier in ROB"
            };

        if (node->isSourceStatic() && !global)
            throw cwhile::ValidationError{
                node,
                "while: local static variable is not supported; "
                "the current emitter does not preserve its lifetime across calls"
            };
    }

    void requireWritable(Node *node, const Scope &scope) {
        if (target(node, scope).readOnly)
            throw cwhile::ValidationError{
                node,
                "declaration: cannot modify a const-qualified object"
            };
    }

    void expression(Node *node, const Scope &scope) {
        if (!node)
            return;

        if (auto *unary = dynamic_cast<Unary*>(node)) {
            if (
                unary->getOperation() == "++"
                || unary->getOperation() == "--"
            ) {
                requireWritable(unary->getValue(), scope);
            }

            expression(unary->getValue(), scope);

        } else if (auto *array = dynamic_cast<LoadArray*>(node)) {
            expression(array->getIndex(), scope);

        } else if (auto *field = dynamic_cast<LoadArrayField*>(node)) {
            expression(field->getIndex(), scope);

        } else if (auto *paren = dynamic_cast<Parenthesis*>(node)) {
            expression(paren->getValue(), scope);

        } else if (auto *call = dynamic_cast<FunctionCall*>(node)) {
            expression(call->getArgs(), scope);

        } else {
            for (Node *child : node->getChildren())
                expression(child, scope);
        }
    }

    bool hasConstFields(
        const string &type,
        set<string> visited = {}
    ) {
        if (
            !declared_types.contains(type)
            || !visited.insert(type).second
        ) {
            return false;
        }

        for (
            Node *node :
            declared_types[type]->getFields()->getChildren()
        ) {
            auto *field = dynamic_cast<VariableDecl*>(node);

            if (
                field
                && (
                    field->isSourceConst()
                    || hasConstFields(field->getTypeName(), visited)
                )
            ) {
                return true;
            }
        }

        return false;
    }

    void statements(
        Node *node,
        Scope &scope,
        bool global = false
    ) {
        if (!node)
            return;

        if (auto *decl = dynamic_cast<VariableDecl*>(node)) {
            checkQualifiers(node, global);

            if (
                node->isSourceConst()
                && declared_types.contains(decl->getTypeName())
            ) {
                throw cwhile::ValidationError{
                    node,
                    "declaration: const aggregate initialization "
                    "is not supported in this increment"
                };
            }

            scope[decl->getName()] = {
                decl->getTypeName(),
                decl->isSourceConst()
            };

            expression(decl->getIndex(), scope);
            expression(decl->getValue(), scope);

        } else if (auto *branch = dynamic_cast<IfStmt*>(node)) {
            expression(branch->getCondition(), scope);

            Scope a = scope;
            Scope b = scope;

            statements(branch->getIfBody(), a);
            statements(branch->getElseBody(), b);

        } else if (auto *loop = dynamic_cast<While*>(node)) {
            expression(loop->getCondition(), scope);

            Scope body = scope;

            statements(loop->getBody(), body);
            statements(loop->getUpdate(), scope);

        } else if (auto *store = dynamic_cast<Store*>(node)) {
            requireWritable(store->getLeft(), scope);

            expression(store->getLeft(), scope);
            expression(store->getValue(), scope);

        } else if (dynamic_cast<UnaryAttribution*>(node)) {
            expression(node, scope);

        } else if (auto *ret = dynamic_cast<Return*>(node)) {
            expression(ret->getExpr(), scope);

        } else if (auto *call = dynamic_cast<FunctionCall*>(node)) {
            expression(call, scope);

        } else if (auto *decl = dynamic_cast<InitializedType*>(node)) {
            checkQualifiers(node, global);

            if (node->isSourceConst())
                throw cwhile::ValidationError{
                    node,
                    "declaration: const aggregate initialization "
                    "is not supported in this increment"
                };

            if (hasConstFields(decl->getTypeName()))
                throw cwhile::ValidationError{
                    node,
                    "declaration: initialization of a struct with const fields "
                    "is not supported in this increment"
                };

            scope[decl->getName()] = {
                decl->getTypeName(),
                false
            };

            expression(decl->getValues(), scope);

        } else if (auto *decl = dynamic_cast<StructVariableDecl*>(node)) {
            checkQualifiers(node, global);

            if (node->isSourceConst())
                throw cwhile::ValidationError{
                    node,
                    "declaration: const struct arrays "
                    "are not supported in this increment"
                };

            if (hasConstFields(decl->getTypeName()))
                throw cwhile::ValidationError{
                    node,
                    "declaration: initialization of a struct with const fields "
                    "is not supported in this increment"
                };

            scope[decl->getName()] = {
                decl->getTypeName(),
                false
            };

            expression(decl->getIndex(), scope);
            expression(decl->getValue(), scope);

        } else if (auto *type = dynamic_cast<Type*>(node)) {
            for (Node *field : type->getFields()->getChildren()) {
                if (field->isSourceStatic())
                    throw cwhile::ValidationError{
                        field,
                        "declaration: static is not allowed on a struct field"
                    };

                checkQualifiers(field, true);
            }

        } else {
            for (Node *child : node->getChildren())
                statements(child, scope, global);
        }
    }

public:
    void run(Node *program) {
        for (Node *node : program->getChildren())
            if (!dynamic_cast<Function*>(node))
                statements(node, globals, true);

        for (Node *node : program->getChildren()) {
            auto *fn = dynamic_cast<Function*>(node);

            if (!fn)
                continue;

            Scope scope = globals;

            for (Node *node : fn->getArgs()->getChildren()) {
                auto *arg = static_cast<FuncArg*>(node);

                checkQualifiers(arg);

                if (
                    arg->isSourcePointer()
                    && arg->isSourceConst()
                ) {
                    throw cwhile::ValidationError{
                        arg,
                        "declaration: qualified pointer parameters "
                        "are not supported in this increment"
                    };
                }

                scope[arg->getName()] = {
                    arg->getTypeName(),
                    arg->isSourceConst()
                };
            }

            statements(fn->getBody(), scope);
        }
    }
};

} // namespace cqualifier

inline bool validateQualifierProgram(Node *program) {
    try {
        cqualifier::Validator validator;
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