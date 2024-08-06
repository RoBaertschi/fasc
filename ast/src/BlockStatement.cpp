//
// Created by robin on 04.08.24.
//

#include <utility>

#include "fas/ast/BlockStatement.hpp"

#include <sstream>


namespace fas::ast {
    BlockStatement::BlockStatement(token::Token token): token(std::move(token)) {
    }

    BlockStatement::BlockStatement(token::Token token, std::vector<std::unique_ptr<Statement>> statements) : token(std::move(token)), statements(std::move(statements)) {
    }

    std::string BlockStatement::to_string() {
        std::stringstream out;

        for (auto&& statement : statements) {
            out << statement->to_string();
        }

        return out.str();
    }

    std::string BlockStatement::token_literal() {
        return token.literal;
    }
}
