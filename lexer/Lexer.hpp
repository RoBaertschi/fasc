//
// Created by rtmba on 03.08.2024.
//

#ifndef FASC_LEXER_HPP
#define FASC_LEXER_HPP

#include <string>
#include <utility>
#include <cstdint>

#include "Token.hpp"

class Lexer {
    std::string     input;
    std::uint32_t   position        = 0;
    std::uint32_t   readPosition    = 0;
    unsigned char   ch              = 0;
    void readChar();
    unsigned char peekChar() const;
    void skipWhitespace();
    std::string readIdentifier();

    Token readNumber();

public:
    explicit Lexer(std::string input);
    Token nextToken();
};


#endif //FASC_LEXER_HPP
