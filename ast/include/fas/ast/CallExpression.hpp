//
// Created by robin on 05.08.24.
//

#ifndef CALLEXPRESSION_HPP
#define CALLEXPRESSION_HPP
#include <memory>
#include <vector>

#include "Identifier.hpp"


namespace fas::ast {

class CallExpression final : Expression {
public:
    CallExpression(Token  token, std::unique_ptr<Expression> function, std::vector<std::unique_ptr<Expression>> params);

    std::string to_string() override;

    std::string token_literal() override;

    Token token;
    std::unique_ptr<Expression> function;
    std::vector<std::unique_ptr<Expression>> params;
};

}

#endif //CALLEXPRESSION_HPP
