//
// Created by robin on 04.08.24.
//

#ifndef FUNCTIONEXPRESSION_HPP
#define FUNCTIONEXPRESSION_HPP
#include <optional>
#include <utility>
#include <vector>

#include "BlockStatement.hpp"
#include "Expression.hpp"
#include "Identifier.hpp"
#include "Token.hpp"


namespace fas::ast {

class FunctionExpression final : public Expression {
public:
    FunctionExpression(Token token, const std::vector<std::pair<Identifier, Identifier>> &parameters, BlockStatement body, std::optional<Identifier> return_type);

    std::string to_string() override;

    std::string token_literal() override;

    Token token;
    std::vector<std::pair<Identifier, Identifier>> parameters;
    BlockStatement body;
    std::optional<Identifier> return_type;
    std::optional<Identifier> return_type_;
};

}

#endif //FUNCTIONEXPRESSION_HPP
