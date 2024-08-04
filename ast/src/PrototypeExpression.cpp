//
// Created by robin on 04.08.24.
//

#include "fas/ast/PrototypeExpression.hpp"

#include <sstream>
#include <utility>


namespace fas::ast {
    PrototypeExpression::PrototypeExpression(Token token,
                                             std::vector<std::pair<std::unique_ptr<Identifier>, std::unique_ptr<
                                                 Identifier> > > parameters,
                                             std::optional<std::unique_ptr<Identifier> > return_type): token(std::move(
            token)),
        parameters(std::move(parameters)),
        return_type(std::move(return_type)) {
    }

    std::string PrototypeExpression::to_string() {
        std::stringstream out{};

        std::string params{};

        for (const auto &[first, second]: parameters) {
            params.append(first->value).append(": ").append(second->value).append(", ");
        }

        out << "fn ";
        out << token_literal();
        out << "(";
        out << params;
        out << ") ";
        if (return_type.has_value()) {
            out << "-> " << return_type.value()->value;
        }
        return out.str();
    }

    std::string PrototypeExpression::token_literal() {
        return token.literal;
    }
}
