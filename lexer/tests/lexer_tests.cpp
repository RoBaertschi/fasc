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

#define _EOF {"", TokenType::Eof}
TEST_CASE("Test valid tokens", "[lexer]") {
    // ReSharper disable once CppTooWideScopeInitStatement
    std::vector<TestCase> testCases{
        {
            "",
            {_EOF}
        },
        {
            "^",
            {
                {"^", TokenType::Illegal},
                _EOF
            },
        },
        {
            "fn",
            {
                {"fn", TokenType::Fn},
                _EOF
            },
        },
        {
            "extern",
            {
                {"extern", TokenType::Extern},
                _EOF
            },
        },
        {
            "hello",
            {
                {"hello", TokenType::Identifier},
                _EOF
            },
        },
        {
            "5",
            {
                {"5", TokenType::Number},
                _EOF
            },
        },
        {
            "hello 5",
            {
                {"hello", TokenType::Identifier},
                {"5", TokenType::Number},
                _EOF
            }
        },
        {
            "fn hello(test: int) -> int {}",
            {
                {"fn", TokenType::Fn},
                {"hello", TokenType::Identifier},
                {"(", TokenType::LParent},
                {"test", TokenType::Identifier},
                {":", TokenType::Colon},
                {"int", TokenType::Identifier},
                {")", TokenType::RParent},
                {"->", TokenType::Arrow},
                {"int", TokenType::Identifier},
                {"{", TokenType::LBraket},
                {"}", TokenType::RBraket},
                _EOF
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
