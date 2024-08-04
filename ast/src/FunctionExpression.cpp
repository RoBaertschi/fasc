//
// Created by robin on 04.08.24.
//

#include "fas/ast/FunctionExpression.hpp"

#include <sstream>


namespace fas::ast {
    FunctionExpression::FunctionExpression(Token token,
                                           const std::vector<std::pair<Identifier, Identifier> > &parameters,
                                           BlockStatement body,
                                           std::optional<Identifier> return_type =
                                                   std::nullopt): token(std::move(token)),
                                                                  parameters(parameters),
                                                                  body(std::move(body)),
                                                                  return_type_(std::move(return_type)) {
    }

    std::string FunctionExpression::to_string() {
        std::stringstream out{};

        std::string params{};

        for (const auto &[first, second]: parameters) {
            params.append(first.value).append(": ").append(second.value).append(", ");
        }

        out << "fn ";
        out << token_literal();
        out << "(";
        out << params;
        out << ") ";
        if (return_type.has_value()) {
            out << "-> " << return_type.value().value << " ";
        }
        out << body.to_string();

        return out.str();
    }

    std::string FunctionExpression::token_literal() {
        return token.literal;
    }
}
