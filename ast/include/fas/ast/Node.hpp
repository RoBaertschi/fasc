//
// Created by robin on 04.08.24.
//

#ifndef NODE_HPP
#define NODE_HPP
#include <string>

namespace fas::ast {

class Node {
public:
    virtual ~Node() = default;
    virtual std::string to_string();
    virtual std::string token_literal();
};

} // fas::ast

#endif //NODE_HPP
