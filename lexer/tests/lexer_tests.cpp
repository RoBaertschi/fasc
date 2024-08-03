//
// Created by robin on 03.08.24.
//

#include <Lexer.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test Comments", "[lexer]") {
    auto lexer = Lexer("// Test");
    REQUIRE(lexer.nextToken().type == TokenType::Eof);
}

struct TestCase {
    std::string input;
    std::vector<Token> expectedTokens;
};

TEST_CASE("Test valid tokens", "[lexer]") {
    for (std::vector<TestCase> testCases{
             {
                 "",
                 {{"",TokenType::Eof}}
             }
         }; auto [input, expectedTokens]: testCases) {
        auto lexer = Lexer(input);

        int i = 0;
        for (const auto token = lexer.nextToken(); token.type != TokenType::Eof; i++) {
           REQUIRE(token.type == expectedTokens[i].type);
           REQUIRE(token.literal == expectedTokens[i].literal);
        }

        REQUIRE(i + 1 == expectedTokens.size());
   }
}