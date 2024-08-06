//
// Created by robin on 04.08.24.
//

#include <utility>

#include "fas/ast/FloatExpression.hpp"

#include <charconv>

namespace fas::ast {
    FloatExpression::FloatExpression(const std::string &string, token::Token token) : token(std::move(token)), value(0) {
        std::from_chars(string.data(), string.data()+string.size(), value);
    }

    FloatExpression::FloatExpression(const double value, token::Token token) : token(std::move(token)), value(value) {
    }

    std::string FloatExpression::to_string() {
        return token.literal;
    }

    std::string FloatExpression::token_literal() {
        return token.literal;
    }
} // fas::ast