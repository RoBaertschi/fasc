//
// Created by robin on 04.08.24.
//

#include <utility>

#include "fas/ast/ExpressionStatement.hpp"


namespace fas::ast {
    ExpressionStatement::ExpressionStatement(token::Token token) : token(std::move(token)) {
    }

    ExpressionStatement::ExpressionStatement(token::Token token,
                                             std::unique_ptr<Expression> expression) : token(std::move(token)),
                                                                                       expression(std::make_optional(std::move(expression))) {
    }

    std::string ExpressionStatement::to_string() {
        if (expression.has_value()) {
            return expression.value()->to_string();
        }
        return "";
    }

    std::string ExpressionStatement::token_literal() {
        return token.literal;
    }
}
