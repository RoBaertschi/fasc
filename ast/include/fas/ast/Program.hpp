//
// Created by robin on 04.08.24.
//

#ifndef PROGRAM_HPP
#define PROGRAM_HPP
#include <memory>
#include <vector>

#include "Statement.hpp"

namespace fas::ast {

class Program final : public Node {
public:
    explicit Program(std::vector<std::unique_ptr<Statement>> statements);

    std::string to_string() override;

    std::string token_literal() override;

    std::vector<std::unique_ptr<Statement>> statements;
};

} // fas::ast

#endif //PROGRAM_HPP
