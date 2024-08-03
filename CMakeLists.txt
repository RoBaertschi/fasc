cmake_minimum_required(VERSION 3.28)
project(fasc)

set(CMAKE_CXX_STANDARD 20)

add_executable(fasc main.cpp
        lexer/Lexer.cpp
        lexer/Lexer.hpp
        lexer/Token.hpp
        lexer/Globals.cpp
        lexer/Token.cpp)
