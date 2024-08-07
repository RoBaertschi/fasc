//
// Created by robin on 04.08.24.
//

#include "fas/ast/PrototypeExpression.hpp"

#include <numeric>
#include <sstream>
#include <utility>


namespace fas::ast {
    PrototypeExpression::PrototypeExpression(token::Token token, std::string name,
                                             std::vector<std::pair<std::unique_ptr<Identifier>, std::unique_ptr<
                                                 Identifier> > > parameters,
                                             std::optional<std::unique_ptr<Identifier> > return_type): token(std::move(
            token)),
        name(std::move(name)),
        parameters(std::move(parameters)),
        return_type(std::move(return_type)) {
    }

    std::string PrototypeExpression::to_string() {
        std::stringstream out{};

        std::vector<std::string> params{};

        for (const auto &[first, second]: parameters) {
            params.push_back(first->value + ": " + second->value);
        }

        out << "fn ";
        out << name;
        out << "(";
        if (!params.empty()) {
            out << std::accumulate(std::next(params.begin()), params.end(), params[0],
                                   [](std::string a, std::string b) {
                                       return a + ", " + b;
                                   });
        }
        out << ")";
        if (return_type.has_value()) {
            out << " -> " << return_type.value()->value;
        }
        return out.str();
    }

    std::string PrototypeExpression::token_literal() {
        return token.literal;
    }
}
