//
// Created by robin on 05.08.24.
//

#include <utility>

#include "fas/ast/CallExpression.hpp"

#include <numeric>
#include <sstream>


namespace fas::ast {
    CallExpression::CallExpression(token::Token token, std::unique_ptr<Expression> function,
                                   std::vector<std::unique_ptr<Expression>> params) : token(std::move(token)), function(std::move(function)), params(std::move(params)) {
    }

    std::string CallExpression::to_string() {
        std::stringstream out{};

        out << function->to_string() << "(";

        std::vector<std::string> params{};

        for (auto&& param: this->params) {
            params.push_back(param->to_string());
        }

        out << std::accumulate(std::next(params.begin()), params.end(), params[0], [](std::string a, std::string b) {
            return a + ", " + b;
        });

        out << ")";

        return out.str();
    }

    std::string CallExpression::token_literal() {
        return token.literal;
    }
}
