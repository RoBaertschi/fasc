//
// Created by robin on 04.08.24.
//

#include "fas/ast/IntegerExpression.hpp"

#include <charconv>
#include <utility>

namespace fas::ast {
    IntegerExpression::IntegerExpression(const std::string& string, token::Token token) : token(std::move(token)), value(0) {
        std::from_chars(string.data(), string.data()+string.size(), value);
    }

    IntegerExpression::IntegerExpression(const int64_t value, token::Token token) : token(std::move(token)), value(value){}

    std::string IntegerExpression::to_string() {
        return token.literal;
    }

    std::string IntegerExpression::token_literal() {
        return token.literal;
    }
} // fas::ast