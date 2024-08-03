//
// Created by rtmba on 03.08.2024.
//

#include <map>
#include "Token.hpp"

#include <sstream>

static std::map<std::string, TokenType> keywords{
        {"fn", TokenType::Fn},
        {"extern", TokenType::Extern},
};

std::string token_type_to_string(TokenType token) {
    switch (token) {
        case TokenType::Illegal:
            return "Illegal";
        case TokenType::Eof:
            return "Eof";
        case TokenType::Fn:
            return "Fn";
        case TokenType::Extern:
            return "Extern";
        case TokenType::Identifier:
            return "Identifier";
        case TokenType::Number:
            return "Number";
        default:
            throw std::runtime_error("Invalid token supplied, please check your program");
    }
}

std::string Token::to_string() const {
    std::stringstream stream{};
    stream << "Literal: " << literal << "\n";
    stream << "Type: " << token_type_to_string(type) << std::endl;
    return stream.str();
}

TokenType Token::LookupIdent(const std::string &ident) {
    if(keywords.contains(ident)) {
        return keywords[ident];
    }
    return TokenType::Identifier;
}
