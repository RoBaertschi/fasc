//
// Created by robin on 04.08.24.
//

#ifndef INTEGEREXPRESSION_HPP
#define INTEGEREXPRESSION_HPP
#include "Expression.hpp"
#include "fas/token/Token.hpp"

namespace fas::ast {

class IntegerExpression final : public Expression {
public:
    IntegerExpression(const std::string &string, token::Token token);

    IntegerExpression(int64_t value, token::Token token);

    std::string to_string() override;

    std::string token_literal() override;

    token::Token token;
    int64_t value;
};

} // fas::ast

#endif //INTEGEREXPRESSION_HPP
