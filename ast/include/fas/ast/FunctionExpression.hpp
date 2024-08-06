//
// Created by robin on 04.08.24.
//

#ifndef FUNCTIONEXPRESSION_HPP
#define FUNCTIONEXPRESSION_HPP
#include <memory>

#include "BlockStatement.hpp"
#include "Expression.hpp"
#include "PrototypeExpression.hpp"


namespace fas::ast {

class FunctionExpression final : public Expression {
public:
    FunctionExpression(std::unique_ptr<PrototypeExpression> proto, std::unique_ptr<BlockStatement> body);

    std::string to_string() override;

    std::string token_literal() override;

    std::unique_ptr<PrototypeExpression> proto;
    std::unique_ptr<BlockStatement> body;
};

}

#endif //FUNCTIONEXPRESSION_HPP
