//
// Created by rtmba on 03.08.2024.
//

#include "Lexer.hpp"
#include <optional>

Lexer::Lexer(std::string input) : input(std::move(input)) {
    readChar();
}

void Lexer::readChar() {
    if (readPosition >= input.length()) {
        ch = 0;
    } else {
        ch = input[readPosition];
    }

    position = readPosition;
    readPosition++;
}

static bool isLetter(const unsigned char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_';
}

static bool isDigit(const unsigned char ch) {
    return '0' <= ch && ch <= '9';
}

#define SIMPLE_TOKEN(ch, ty) case ch: {\
    tok.type = ty;\
    tok.literal = std::string{ch};\
    break;\
    }

Token Lexer::nextToken() {
    Token tok{};

    skipWhitespace();
    switch (ch) {
        SIMPLE_TOKEN('(', TokenType::LParent)
        SIMPLE_TOKEN(')', TokenType::RParent)
        SIMPLE_TOKEN(':', TokenType::Colon)

        // Comment
        case '/': {
            if (peekChar() == '/') {
                readChar();
                unsigned char pc = 0;
                while (pc = peekChar(), pc != '\n' && pc != 0) {
                    readChar();
                }
            }
            // TODO: Maybe add a Comment token instead of reading the next token
            return nextToken();
        }

        case '-': {
            if (peekChar() == '>') {
                readChar();
                tok.literal = "->";
                tok.type = TokenType::Arrow;
            } else {
                tok.literal = std::string{static_cast<char>(ch)};
                tok.type = TokenType::Illegal;
            }
            break;
        }
        // EOF
        case 0: {
            tok.literal = "";
            tok.type = TokenType::Eof;
            break;
        }
        default: {
            if (isLetter(ch)) {
                tok.literal = readIdentifier();
                tok.type = Token::LookupIdent(tok.literal);
                return tok;
            } else if (isDigit(ch)) {
                tok.type = TokenType::Number;
                tok.literal = readNumber();
            } else {
                tok.type = TokenType::Illegal;
                char character[2] = {static_cast<char>(ch), '\0'};
                tok.literal = std::string(character);
            }
        }
    }

    readChar();
    return tok;
}

void Lexer::skipWhitespace() {
    while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
        readChar();
    }
}

unsigned char Lexer::peekChar() const {
    if (readPosition >= input.length()) {
        return 0;
    }
    return input[readPosition];
}

std::string Lexer::readIdentifier() {
    const auto pos = position;
    while (isLetter(ch)) {
        readChar();
    }

    return input.substr(pos, position - pos);
}

std::string Lexer::readNumber() {
    const auto pos = position;
    while(isDigit(ch)) {
        readChar();
    }

    return input.substr(pos, position - pos);
}
