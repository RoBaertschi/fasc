//
// Created by robin on 06.08.24.
//
#include <catch2/catch_test_macros.hpp>
#include <fas/ast/ExpressionStatement.hpp>
#include <fas/ast/FunctionExpression.hpp>
#include <fas/ast/Program.hpp>
#include <fas/token/Token.hpp>

#include <string>

using namespace fas;

TEST_CASE("Test String", "[ast]") {
    auto statements = std::vector<std::unique_ptr<ast::Statement>>{};
    statements.push_back(std::make_unique<ast::ExpressionStatement>(
                token::Token{"fn", token::TokenType::Fn},
                std::move(std::make_unique<ast::PrototypeExpression>(
                        token::Token{"fn hello()", token::TokenType::Fn},
                        "hello",
                        std::move(
                            std::vector<std::pair<std::unique_ptr<ast::Identifier>, std::unique_ptr<ast::Identifier> > >
                            {}),
                        std::nullopt
                    )
                )
        ));

    auto program = ast::Program{std::move(statements)};

    REQUIRE(program.to_string() == "fn hello()");
}
