//
// Created by robin on 04.08.24.
//

#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP
#include "Expression.hpp"
#include "Token.hpp"

namespace fas {
namespace ast {

class Identifier final : public Expression{
public:
    Identifier(Token token, std::string value);

    std::string to_string() override;

    std::string token_literal() override;

    Token token;
    std::string value;
};

} // ast
} // fas

#endif //IDENTIFIER_HPP
