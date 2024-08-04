//
// Created by robin on 04.08.24.
//

#ifndef BLOCKSTATEMENT_HPP
#define BLOCKSTATEMENT_HPP
#include <memory>
#include <vector>

#include "Statement.hpp"
#include "Token.hpp"


namespace fas::ast {

class BlockStatement final : public Statement {
public:
    explicit BlockStatement(Token token);
    BlockStatement(Token token, std::vector<std::unique_ptr<Statement>> statements);

    std::string to_string() override;

    std::string token_literal() override;

    Token token;
    std::vector<std::unique_ptr<Statement>> statements;
};

}

#endif //BLOCKSTATEMENT_HPP
