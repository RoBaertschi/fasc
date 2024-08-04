//
// Created by robin on 04.08.24.
//

#ifndef INTEGEREXPRESSION_HPP
#define INTEGEREXPRESSION_HPP
#include "Expression.hpp"
#include "Token.hpp"

namespace fas::ast {

class IntegerExpression final : public Expression {
public:
    IntegerExpression(const std::string &string, Token token);

    IntegerExpression(int64_t value, Token token);

    std::string to_string() override;

    std::string token_literal() override;

    Token token;
    int64_t value;
};

} // fas::ast

#endif //INTEGEREXPRESSION_HPP
