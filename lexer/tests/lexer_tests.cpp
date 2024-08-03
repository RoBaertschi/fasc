//
// Created by robin on 03.08.24.
//

#include <Lexer.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test Comments", "[lexer]") {
    auto lexer = Lexer("// Test");
    REQUIRE(lexer.nextToken().type == TokenType::Eof);
}