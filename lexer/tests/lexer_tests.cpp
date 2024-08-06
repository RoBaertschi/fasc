//
// Created by robin on 03.08.24.
//

#include <iostream>
#include <fas/lexer/Lexer.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace fas;

TEST_CASE("Test Comments", "[lexer]") {
    auto lexer = lexer::Lexer("fn// Test");
    auto nToken = lexer.nextToken();
    INFO(nToken.to_string());
    REQUIRE(nToken.type == token::TokenType::Fn);
    nToken = lexer.nextToken();
    INFO(nToken.to_string());
    REQUIRE(nToken.type == token::TokenType::Eof);
}

struct TestCase {
    std::string input;
    std::vector<token::Token> expectedTokens;
};

#define _EOF {"", token::TokenType::Eof}
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
                {"^", token::TokenType::Illegal},
                _EOF
            },
        },
        {
            "fn",
            {
                {"fn", token::TokenType::Fn},
                _EOF
            },
        },
        {
            "extern",
            {
                {"extern", token::TokenType::Extern},
                _EOF
            },
        },
        {
            "hello",
            {
                {"hello", token::TokenType::Identifier},
                _EOF
            },
        },
        {
            "5",
            {
                {"5", token::TokenType::Integer},
                _EOF
            },
        },
        {
            "hello 5",
            {
                {"hello", token::TokenType::Identifier},
                {"5", token::TokenType::Integer},
                _EOF
            }
        },
        {
            "fn hello(test: int) -> int {}",
            {
                {"fn", token::TokenType::Fn},
                {"hello", token::TokenType::Identifier},
                {"(", token::TokenType::LParent},
                {"test", token::TokenType::Identifier},
                {":", token::TokenType::Colon},
                {"int", token::TokenType::Identifier},
                {")", token::TokenType::RParent},
                {"->", token::TokenType::Arrow},
                {"int", token::TokenType::Identifier},
                {"{", token::TokenType::LBraket},
                {"}", token::TokenType::RBraket},
                _EOF
            },
        },
            {
            "1.2 1. .3 43.. 43..4",
                {
                    {"1.2", token::TokenType::Float},
                    {"1.", token::TokenType::Float},
                    {".3", token::TokenType::Float},
                    {"43.", token::TokenType::Float},
                    {".", token::TokenType::Dot},
                    {"43.", token::TokenType::Float},
                    {".4", token::TokenType::Float},
                    _EOF
                }
            },
    };
    for (auto [input, expectedTokens]: testCases) {
        auto lexer = lexer::Lexer(input);

        unsigned int i = 0;
        token::Token token;
        do {
            token = lexer.nextToken();
            INFO(token.to_string() + expectedTokens[i].to_string());
            REQUIRE(token.type == expectedTokens[i].type);
            REQUIRE(token.literal == expectedTokens[i].literal);
        } while (i++, token.type != token::TokenType::Eof);

        REQUIRE(i == expectedTokens.size());
    }
}
