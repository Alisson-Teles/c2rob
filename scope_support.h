#pragma once

// Resolve C names before loop validation or ROB emission. A container groups
// declarations but does not introduce a C block; branch and loop bodies do.
namespace cscope {

struct Error {
    Node *node;
    string message;
};

class Resolver {
    using Names = map<string, string>;
    vector<Names> frames;
    set<string> used;
    set<string> globals;
    set<string> occupied;
    unsigned nextName = 0;

    void remember(const string &name) {
        if (!name.empty()) used.insert(name);
    }

    // Include source references and type names when reserving generated names.
    void collect(Node *node) {
        if (!node) return;
        remember(node->getName());
        if (auto *ident = dynamic_cast<Ident*>(node)) remember(ident->getText());
        if (auto *decl = dynamic_cast<VariableDecl*>(node)) {
            globals.insert(decl->getTypeName());
            collect(decl->getIndex());
            collect(decl->getValue());
        } else if (auto *decl = dynamic_cast<InitializedType*>(node)) {
            globals.insert(decl->getTypeName());
            collect(decl->getValues());
        } else if (auto *decl = dynamic_cast<StructVariableDecl*>(node)) {
            globals.insert(decl->getTypeName());
            collect(decl->getIndex());
            collect(decl->getValue());
        } else if (auto *arg = dynamic_cast<FuncArg*>(node)) {
            globals.insert(VariableDecl::convertTypeToRob(arg->getTypeName()));
        } else if (auto *function = dynamic_cast<Function*>(node)) {
            collect(function->getArgs());
            collect(function->getBody());
        } else if (auto *branch = dynamic_cast<IfStmt*>(node)) {
            collect(branch->getCondition());
            collect(branch->getIfBody());
            collect(branch->getElseBody());
        } else if (auto *loop = dynamic_cast<While*>(node)) {
            collect(loop->getCondition());
            collect(loop->getBody());
            collect(loop->getUpdate());
        } else if (auto *store = dynamic_cast<Store*>(node)) {
            collect(store->getLeft());
            collect(store->getValue());
        } else if (auto *ret = dynamic_cast<Return*>(node)) {
            collect(ret->getExpr());
        } else if (auto *call = dynamic_cast<FunctionCall*>(node)) {
            collect(call->getArgs());
        } else if (auto *array = dynamic_cast<LoadArray*>(node)) {
            remember(array->getArrayName());
            collect(array->getIndex());
        } else if (auto *field = dynamic_cast<LoadArrayField*>(node)) {
            remember(field->getBaseName());
            collect(field->getIndex());
        } else if (auto *field = dynamic_cast<LoadField*>(node)) {
            remember(field->getBaseName());
        } else if (auto *paren = dynamic_cast<Parenthesis*>(node)) {
            collect(paren->getValue());
        } else if (auto *type = dynamic_cast<Type*>(node)) {
            collect(type->getFields());
        } else {
            for (Node *child : node->getChildren()) collect(child);
        }
    }

    string reference(const string &text) const {
        // The lexer can store s.field as a single Ident. Only rename its base.
        size_t dot = text.find('.');
        string base = text.substr(0, dot);
        for (auto frame = frames.rbegin(); frame != frames.rend(); ++frame) {
            auto found = frame->find(base);
            if (found != frame->end())
                return found->second + (dot == string::npos ? "" : text.substr(dot));
        }
        return text;
    }

    string bind(const string &source, Node *node) {
        Names &current = frames.back();
        if (current.contains(source))
            throw Error{node, "[C2ROB_SCOPE_REDECLARATION] name already declared in this scope: " + source};
        string target = source;
        if (occupied.contains(target)) {
            do {
                target = "__c2rob_scope_" + to_string(nextName++) + "_" + source;
            } while (used.contains(target));
            used.insert(target);
        }
        current[source] = target;
        occupied.insert(target);
        return target;
    }

    void expression(Node *node) {
        if (!node) return;
        if (dynamic_cast<IntegerToken*>(node)) return;
        if (auto *ident = dynamic_cast<Ident*>(node)) {
            ident->setText(reference(ident->getText()));
        } else if (auto *array = dynamic_cast<LoadArray*>(node)) {
            array->setArrayName(reference(array->getArrayName()));
            expression(array->getIndex());
        } else if (auto *field = dynamic_cast<LoadArrayField*>(node)) {
            field->setBaseName(reference(field->getBaseName()));
            expression(field->getIndex());
        } else if (auto *field = dynamic_cast<LoadField*>(node)) {
            field->setBaseName(reference(field->getBaseName()));
        } else if (auto *call = dynamic_cast<FunctionCall*>(node)) {
            call->setName(reference(call->getName()));
            expression(call->getArgs());
        } else if (auto *paren = dynamic_cast<Parenthesis*>(node)) {
            expression(paren->getValue());
        } else {
            for (Node *child : node->getChildren()) expression(child);
        }
    }

    void block(Node *node) {
        frames.emplace_back();
        statements(node);
        frames.pop_back();
    }

    void statements(Node *node) {
        if (!node) return;
        if (auto *decl = dynamic_cast<VariableDecl*>(node)) {
            // C scope begins after the declarator, before its initializer.
            expression(decl->getIndex());
            decl->setName(bind(decl->getName(), decl));
            expression(decl->getValue());
        } else if (auto *decl = dynamic_cast<InitializedType*>(node)) {
            decl->setName(bind(decl->getName(), decl));
            expression(decl->getValues());
        } else if (auto *decl = dynamic_cast<StructVariableDecl*>(node)) {
            expression(decl->getIndex());
            decl->setName(bind(decl->getName(), decl));
            expression(decl->getValue());
        } else if (auto *branch = dynamic_cast<IfStmt*>(node)) {
            expression(branch->getCondition());
            block(branch->getIfBody());
            block(branch->getElseBody());
        } else if (auto *loop = dynamic_cast<While*>(node)) {
            expression(loop->getCondition());
            block(loop->getBody());
            // for's update belongs to the enclosing scope, not its body's.
            statements(loop->getUpdate());
        } else if (auto *store = dynamic_cast<Store*>(node)) {
            expression(store->getLeft());
            expression(store->getValue());
        } else if (auto *ret = dynamic_cast<Return*>(node)) {
            expression(ret->getExpr());
        } else if (auto *update = dynamic_cast<UnaryAttribution*>(node)) {
            expression(update->getValue());
        } else if (auto *call = dynamic_cast<FunctionCall*>(node)) {
            expression(call);
        } else if (!dynamic_cast<Type*>(node)) {
            // Plain Node and Container lists retain the current C scope.
            for (Node *child : node->getChildren()) statements(child);
        }
    }

public:
    void run(Node *program) {
        collect(program);
        // C struct tags use a separate namespace; ROB type names do not.
        for (const auto &entry : declared_types) globals.insert(entry.first);
        vector<Node*> top;
        for (Node *node : program->getChildren()) {
            if (auto *list = dynamic_cast<Container*>(node)) {
                for (Node *decl : list->getChildren()) top.push_back(decl);
            } else {
                top.push_back(node);
            }
        }
        Names globalNames;
        for (Node *node : top) {
            string name = node->getName();
            if (!name.empty()) {
                globalNames[name] = name;
                globals.insert(name);
            }
        }
        frames.push_back(globalNames);
        for (Node *node : top) {
            auto *function = dynamic_cast<Function*>(node);
            if (!function || !function->getBody()) continue;
            occupied = globals;
            frames.emplace_back();
            if (function->getArgs()) {
                for (Node *node : function->getArgs()->getChildren()) {
                    auto *arg = static_cast<FuncArg*>(node);
                    arg->setName(bind(arg->getName(), arg));
                }
            }
            // Parameters and the outermost body share the same C scope.
            statements(function->getBody());
            frames.pop_back();
        }
        frames.pop_back();
    }
};

} // namespace cscope

inline bool resolveScopeProgram(Node *program) {
    try {
        cscope::Resolver resolver;
        resolver.run(program);
        return true;
    } catch (const cscope::Error &error) {
        fprintf(stderr, "%s:%d: %s\n", build_file_name,
                error.node ? error.node->getLineNo() : yylineno, error.message.c_str());
        errorcount++;
        return false;
    }
}
