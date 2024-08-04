//
// Created by robin on 04.08.24.
//

#ifndef EXPRESSIONSTATEMENT_HPP
#define EXPRESSIONSTATEMENT_HPP
#include <memory>
#include <optional>

#include "Expression.hpp"
#include "Statement.hpp"
#include "Token.hpp"


namespace fas::ast {

class ExpressionStatement final : public Statement {
public:
    explicit ExpressionStatement(Token token);
    ExpressionStatement(Token token, std::unique_ptr<Expression> expression);

    std::string to_string() override;

    std::string token_literal() override;

    Token token;
    std::optional<std::unique_ptr<Expression>> expression;
};

}

#endif //EXPRESSIONSTATEMENT_HPP
