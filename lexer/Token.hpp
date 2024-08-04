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

    // Operators
    Arrow,      // ->
    LParent,    // (
    RParent,    // )
    LBraket,    // {
    RBraket,    // }
    Colon,      // :

    // keywords
    Fn,
    Extern,     // Extern, but is sadly reserved

    // identifiers and literals
    Identifier,
    Number,
};

std::string token_type_to_string(TokenType token);

struct Token {
    std::string literal;
    TokenType   type;
    std::string to_string() const;

    static TokenType LookupIdent(const std::string &ident);
};

#endif //FASC_TOKEN_HPP
