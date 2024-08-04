//
// Created by robin on 04.08.24.
//

#include <utility>

#include "fas/ast/BlockStatement.hpp"

#include <sstream>


namespace fas::ast {
    BlockStatement::BlockStatement(Token token): token(std::move(token)), statements({}) {
    }

    BlockStatement::BlockStatement(Token token, const std::vector<Statement> &statements) : token(std::move(token)), statements(statements) {
    }

    std::string BlockStatement::to_string() {
        std::stringstream out;

        for (auto statement: statements) {
            out << statement.to_string();
        }

        return out.str();
    }

    std::string BlockStatement::token_literal() {
        return token.literal;
    }
}
