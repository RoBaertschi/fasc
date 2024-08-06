//
// Created by robin on 04.08.24.
//

#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP
#include "Expression.hpp"
#include "fas/token/Token.hpp"


namespace fas::ast {

class Identifier final : public Expression{
public:
    Identifier(token::Token token, std::string value);

    std::string to_string() override;

    std::string token_literal() override;

    token::Token token;
    std::string value;
};

}

#endif //IDENTIFIER_HPP
