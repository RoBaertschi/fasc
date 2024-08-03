//
// Created by robin on 03.08.24.
//

#include <iostream>
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

#define EEOF {"", TokenType::Eof}
TEST_CASE("Test valid tokens", "[lexer]") {
    // ReSharper disable once CppTooWideScopeInitStatement
    std::vector<TestCase> testCases{
        {
            "",
            {EEOF}
        },
        {
            "^",
            {
                {"^", TokenType::Illegal},
                EEOF
            },
        },
        {
            "fn",
            {
                {"fn", TokenType::Fn},
                EEOF
            },
        },
        {
            "extern",
            {
                {"extern", TokenType::Extern},
                EEOF
            },
        },
        {
            "hello",
            {
                {"hello", TokenType::Identifier},
                EEOF
            },
        },
        {
            "5",
            {
                {"5", TokenType::Number},
                EEOF
            },
        },
        {
            "hello 5",
            {
                {"hello", TokenType::Identifier},
                {"5", TokenType::Number},
                EEOF
            }
        },
        {
            "fn hello",
            {
                {"hello", TokenType::Identifier},
                {"5", TokenType::Number},
                EEOF
            }
        },
    };
    for (auto [input, expectedTokens]: testCases) {
        auto lexer = Lexer(input);

        unsigned int i = 0;
        Token token;
        do {
            token = lexer.nextToken();
            INFO(token.to_string());
            REQUIRE(token.type == expectedTokens[i].type);
            REQUIRE(token.literal == expectedTokens[i].literal);
        } while (i++, token.type != TokenType::Eof);

        REQUIRE(i == expectedTokens.size());
    }
}
