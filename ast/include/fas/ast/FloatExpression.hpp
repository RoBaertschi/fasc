//
// Created by robin on 04.08.24.
//

#ifndef FLOATEXPRESSION_HPP
#define FLOATEXPRESSION_HPP
#include "Expression.hpp"
#include "fas/token/Token.hpp"

namespace fas::ast {

class FloatExpression final : public Expression {
public:
    FloatExpression(const std::string &string, token::Token token);

    FloatExpression(double value, token::Token token);

    std::string to_string() override;

    std::string token_literal() override;

    token::Token token;
    double value;
};

} // fas::ast

#endif //FLOATEXPRESSION_HPP
