//
// Created by rtmba on 03.08.2024.
//

#include "fas/lexer/Lexer.hpp"

#include <stdexcept>

namespace fas::lexer
{



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
    return ('0' <= ch && ch <= '9');
}

#define SIMPLE_TOKEN(ch, ty) case ch: {\
    tok.type = ty;\
    tok.literal = std::string{ch};\
    break;\
    }

token::Token Lexer::nextToken() {
    token::Token tok{};

    skipWhitespace();
    switch (ch) {
        SIMPLE_TOKEN('(', token::TokenType::LParent)
        SIMPLE_TOKEN(')', token::TokenType::RParent)
        SIMPLE_TOKEN('{', token::TokenType::LBraket)
        SIMPLE_TOKEN('}', token::TokenType::RBraket)
        SIMPLE_TOKEN(':', token::TokenType::Colon)

    case '.': {
            if (!isDigit(peekChar())) {
                tok.literal = ".";
                tok.type = token::TokenType::Dot;
            } else {
                tok = readNumber();
            }
            break;
        }

        // Comment
        case '/': {
            if (peekChar() == '/') {
                readChar();
                while (ch != '\n' && ch != 0) {
                    readChar();
                }
                // TODO: Maybe add a Comment token instead of reading the next token
                return nextToken();
            }
            tok.type = token::TokenType::Illegal;
            tok.literal = "/";
            break;
        }

        case '-': {
            if (peekChar() == '>') {
                readChar();
                tok.literal = "->";
                tok.type = token::TokenType::Arrow;
            } else {
                tok.literal = std::string{static_cast<char>(ch)};
                tok.type = token::TokenType::Illegal;
            }
            break;
        }
        // EOF
        case 0: {
            tok.literal = "";
            tok.type = token::TokenType::Eof;
            break;
        }
        default: {
            if (isLetter(ch)) {
                tok.literal = readIdentifier();
                tok.type = token::Token::LookupIdent(tok.literal);
                return tok;
            } else if (isDigit(ch)) {
                tok = readNumber();
                return tok;
            } else {
                tok.type = token::TokenType::Illegal;
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

token::Token Lexer::readNumber() {
    const auto pos = position;
    bool foundDot = false;

    while(isDigit(ch) || ch == '.') {
        // std::cout << "ch: " << ch << "\n";
        if (ch == '.') {
            foundDot = true;
            if (peekChar() == '.') {
                readChar();
                // std::cout << "ch: " << ch << " peekChar: " << peekChar() << "\n" << input << " | " << pos << ":" << position << " | " << input.substr(pos, position - pos);
                break;
            }
        }
        readChar();
    }

    return token::Token{
        input.substr(pos, position - pos),
        foundDot ? token::TokenType::Float : token::TokenType::Integer
    };
};

}