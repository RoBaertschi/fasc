//
// Created by rtmba on 03.08.2024.
//

#ifndef FASC_TOKEN_HPP
#define FASC_TOKEN_HPP

#include <string>
#include <variant>

enum class TokenType {
    Illegal,
    Eof,


    // keywords
    Fn,
    Extern, // Extern, but is sadly reserved

    // identifiers and literals
    Identifier,
    Number,
};

struct Token {
    std::string literal;
    TokenType   type;

    static TokenType LookupIdent(std::string ident);
};

#endif //FASC_TOKEN_HPP
