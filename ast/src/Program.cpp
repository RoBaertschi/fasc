//
// Created by robin on 04.08.24.
//

#include "fas/ast/Program.hpp"

#include <sstream>

namespace fas::ast {
    Program::Program(std::vector<std::unique_ptr<Statement>> statements) : statements(std::move(statements)) {
    }

    std::string Program::to_string() {
        std::stringstream stream{};

        for (auto&& statement: statements) {
            stream << statement->to_string();
        }

        return stream.str();
    }

    std::string Program::token_literal() {
        if (!statements.empty()) {
            return statements[0]->token_literal();
        }
        return "";
    }
} // fas::ast