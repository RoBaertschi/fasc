//
// Created by rtmba on 03.08.2024.
//

#include <map>
#include "fas/token/Token.hpp"

#include <sstream>

namespace fas::token
{



static std::map<std::string, TokenType> keywords{
        {"fn", TokenType::Fn},
        {"extern", TokenType::Extern},
};

std::string token_type_to_string(const TokenType token) {
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
        case TokenType::Integer:
            return "Number";
        case TokenType::Float:
            return "Float";
        case TokenType::Arrow:
            return "Arrow";
        case TokenType::LParent:
            return "LParent";
        case TokenType::RParent:
            return "RParent";
        case TokenType::Colon:
            return "Colon";
        case TokenType::LBraket:
            return "LBraket";
        case TokenType::RBraket:
            return "RBraket";
        case TokenType::Dot:
            return "Dot";
    }
    throw std::runtime_error("Invalid token supplied, please check your program");
}

std::string Token::to_string() const {
    std::stringstream stream{};
    stream << "Token{ ";
    stream << "Literal: \"" << literal << "\" ";
    stream << "Type: " << token_type_to_string(type) << " }" << std::endl;
    return stream.str();
}

TokenType Token::LookupIdent(const std::string &ident) {
    if(keywords.contains(ident)) {
        return keywords[ident];
    }
    return TokenType::Identifier;
}
}