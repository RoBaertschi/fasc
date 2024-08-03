//
// Created by rtmba on 03.08.2024.
//

#include <map>
#include "Token.hpp"

static std::map<std::string, TokenType> keywords{
        {"fn", TokenType::Fn},
        {"extern", TokenType::Extern},
};

TokenType Token::LookupIdent(std::string ident) {
    if(keywords.contains(ident)) {
        return keywords[ident];
    }
    return TokenType::Identifier;
}
