//
// Created by robin on 04.08.24.
//

#include <utility>

#include "fas/ast/Identifier.hpp"


namespace fas::ast {
    Identifier::Identifier(Token token, std::string value) : token(std::move(token)), value(std::move(value)) {
    }

    std::string Identifier::to_string() {
        return value;
    }

    std::string Identifier::token_literal() {
        return token.literal;
    }
}