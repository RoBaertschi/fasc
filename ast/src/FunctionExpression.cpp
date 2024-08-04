//
// Created by robin on 04.08.24.
//

#include "fas/ast/FunctionExpression.hpp"

#include <sstream>


namespace fas::ast {
    FunctionExpression::FunctionExpression(std::unique_ptr<PrototypeExpression> proto,
        std::unique_ptr<BlockStatement> body) : proto(std::move(proto)), body(std::move(body)) {
    }

    std::string FunctionExpression::to_string() {
        std::stringstream out{};

        out << proto->to_string() << " ";
        out << body->to_string();

        return out.str();
    }

    std::string FunctionExpression::token_literal() {
        return proto->token_literal();
    }
}
