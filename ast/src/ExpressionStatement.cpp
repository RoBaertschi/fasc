//
// Created by robin on 04.08.24.
//

#include <utility>

#include "fas/ast/ExpressionStatement.hpp"


namespace fas::ast {
    ExpressionStatement::ExpressionStatement(Token token) : token(std::move(token)) {
    }

    ExpressionStatement::ExpressionStatement(Token token, Expression expression) : token(std::move(token)), expression(std::make_optional(expression)) {
    }

    std::string ExpressionStatement::to_string() {
        if (expression.has_value()) {
            return expression->to_string();
        }
        return "";
    }

    std::string ExpressionStatement::token_literal() {
        return token.literal;
    }
}
