//
// Created by robin on 04.08.24.
//

#ifndef PROTOTYPEEXPRESSION_HPP
#define PROTOTYPEEXPRESSION_HPP
#include <memory>
#include <optional>
#include <vector>

#include "BlockStatement.hpp"
#include "Expression.hpp"
#include "Identifier.hpp"
#include "fas/token/Token.hpp"


namespace fas::ast {

class PrototypeExpression final : public Expression {
public:
    PrototypeExpression(token::Token token,
                        std::vector<std::pair<std::unique_ptr<Identifier>, std::unique_ptr<Identifier>>> parameters,
                        std::optional<std::unique_ptr<Identifier>> return_type);

    std::string to_string() override;

    std::string token_literal() override;

    token::Token token;
    std::vector<std::pair<std::unique_ptr<Identifier>, std::unique_ptr<Identifier>>> parameters;
    std::optional<std::unique_ptr<Identifier>> return_type;
};

}

#endif //PROTOTYPEEXPRESSION_HPP
