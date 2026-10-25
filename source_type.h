#pragma once

#include <algorithm>
#include <cstdint>
#include <limits>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// The source C data model is independent of the machine running C2ROB.
// ILP32 is the default for the current STM32F1 tests. LP64 is explicit.
enum class SourceAbi { ILP32, LP64 };
inline SourceAbi sourceAbi = SourceAbi::ILP32;

struct DeclarationSpecifiers {
    std::vector<std::string> words;
    std::string type;
    bool isConst = false;
    bool isVolatile = false;
    bool isStatic = false;

    explicit DeclarationSpecifiers(const std::string &word) : words{word} {}

    DeclarationSpecifiers *append(const std::string &word) {
        words.push_back(word);
        return this;
    }

    DeclarationSpecifiers *append(const DeclarationSpecifiers *other) {
        words.insert(words.end(), other->words.begin(), other->words.end());
        return this;
    }

    void resolve();
};

inline std::map<std::string, DeclarationSpecifiers> sourceTypedefs;

inline bool isBuiltinSpecifier(const std::string &word) {
    static const std::vector<std::string> names = {
        "void", "char", "short", "int", "long",
        "signed", "unsigned", "float", "double", "_Bool"
    };

    return std::find(names.begin(), names.end(), word) != names.end();
}

inline void DeclarationSpecifiers::resolve() {
    std::map<std::string, int> count;
    std::vector<std::string> names;

    type.clear();
    isConst = isVolatile = isStatic = false;

    for (const auto &word : words) {
        if (word == "const") {
            isConst = true;
        } else if (word == "volatile") {
            isVolatile = true;
        } else if (word == "static") {
            if (isStatic) {
                throw std::runtime_error(
                    "declaration: duplicate storage-class specifier"
                );
            }
            isStatic = true;
        } else if (isBuiltinSpecifier(word)) {
            ++count[word];
        } else {
            names.push_back(word);
        }
    }

    auto invalid = [] {
        throw std::runtime_error(
            "declaration: invalid type specifier combination"
        );
    };

    if (!names.empty()) {
        if (names.size() != 1 || !count.empty()) {
            invalid();
        }

        auto alias = sourceTypedefs.find(names[0]);

        if (alias != sourceTypedefs.end()) {
            type = alias->second.type;
            isConst |= alias->second.isConst;
            isVolatile |= alias->second.isVolatile;
        } else {
            type = names[0];
        }

        return;
    }

    if (count.empty()) {
        invalid();
    }

    for (const auto &[word, amount] : count) {
        if (amount > (word == "long" ? 2 : 1)) {
            invalid();
        }
    }

    if ((count["signed"] && count["unsigned"]) ||
        (count["short"] && count["long"])) {
        invalid();
    }

    int baseCount =
        count["void"] +
        count["char"] +
        count["float"] +
        count["double"] +
        count["_Bool"];

    if (baseCount > 1 || (baseCount && count["int"])) {
        invalid();
    }

    if (count["void"] || count["float"] || count["_Bool"]) {
        if (count["signed"] || count["unsigned"] ||
            count["short"] || count["long"]) {
            invalid();
        }

        if (count["_Bool"]) {
            throw std::runtime_error(
                "declaration: _Bool is not supported in this increment"
            );
        }

        type = count["void"] ? "void" : "float";
    } else if (count["double"]) {
        if (count["signed"] || count["unsigned"] ||
            count["short"] || count["long"] > 1) {
            invalid();
        }

        if (count["long"]) {
            throw std::runtime_error(
                "declaration: long double is not supported in this increment"
            );
        }

        type = "double";
    } else if (count["char"]) {
        if (count["short"] || count["long"]) {
            invalid();
        }

        type = count["signed"] ? "int8" :
               count["unsigned"] ? "uint8" :
               sourceAbi == SourceAbi::ILP32 ? "char" : "int8";
    } else {
        unsigned bits =
            count["short"] ? 16 :
            count["long"] == 2 ? 64 :
            count["long"] && sourceAbi == SourceAbi::LP64 ? 64 : 32;

        type =
            (count["unsigned"] ? "uint" : "int") +
            std::to_string(bits);
    }
}

inline std::string normalizeBuiltinType(const std::string &text) {
    std::istringstream input(text);
    std::string word;
    std::vector<std::string> words;

    while (input >> word) {
        words.push_back(word);
    }

    if (words.empty() || !isBuiltinSpecifier(words[0])) {
        return text;
    }

    DeclarationSpecifiers spec(words[0]);

    for (size_t i = 1; i < words.size(); ++i) {
        spec.append(words[i]);
    }

    spec.resolve();
    return spec.type;
}
struct IntegerLiteralInfo {
    std::string digits;
    std::string type;
};

inline IntegerLiteralInfo sourceIntegerLiteral(
    const std::string &text
) {
    size_t end = text.size();
    bool isUnsigned = false;
    unsigned longs = 0;

    while (
        end
        && (
            text[end - 1] == 'u'
            || text[end - 1] == 'U'
            || text[end - 1] == 'l'
            || text[end - 1] == 'L'
        )
    ) {
        char c = text[--end];

        if (c == 'u' || c == 'U')
            isUnsigned = true;
        else
            ++longs;
    }

    std::string digits = text.substr(0, end);

    size_t consumed;
    unsigned long long value;

    try {
        value = std::stoull(digits, &consumed, 0);
    } catch (const std::exception &) {
        throw std::runtime_error(
            "declaration: invalid or out-of-range integer literal: "
            + text
        );
    }

    if (consumed != digits.size())
        throw std::runtime_error(
            "declaration: invalid integer literal: " + text
        );

    bool decimal = digits[0] != '0' || digits == "0";

    std::string robDigits = std::to_string(value);

    // Avoid precision loss in Robcmp's decimal-token reader.
    if (value > 9007199254740991ULL) {
        std::ostringstream hex;
        hex << "0x" << std::hex << value;
        robDigits = hex.str();
    }

    unsigned first =
        longs == 2 ? 64 :
        longs && sourceAbi == SourceAbi::LP64 ? 64 :
        32;

    for (unsigned bits : {first, 64u}) {
        unsigned long long signedMax =
            bits == 32 ? INT32_MAX : INT64_MAX;

        unsigned long long unsignedMax =
            bits == 32 ? UINT32_MAX : UINT64_MAX;

        if (!isUnsigned && value <= signedMax)
            return {
                robDigits,
                "int" + std::to_string(bits)
            };

        if (
            (isUnsigned || !decimal)
            && value <= unsignedMax
        ) {
            return {
                robDigits,
                "uint" + std::to_string(bits)
            };
        }
    }

    throw std::runtime_error(
        "declaration: integer literal exceeds supported C integer types: "
        + text
    );
}