//
// Created by robin on 04.08.24.
//

#ifndef BLOCKSTATEMENT_HPP
#define BLOCKSTATEMENT_HPP
#include <vector>

#include "Statement.hpp"
#include "Token.hpp"


namespace fas::ast {

class BlockStatement final : public Statement {
public:
    BlockStatement(Token token);
    BlockStatement(Token token, const std::vector<Statement> &statements);

    std::string to_string() override;

    std::string token_literal() override;

    Token token;
    std::vector<Statement> statements;
};

}

#endif //BLOCKSTATEMENT_HPP
