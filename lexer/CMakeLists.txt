add_library(lexer STATIC
        Lexer.cpp
        Lexer.hpp
        Token.hpp
        Globals.cpp
        Token.cpp)
target_include_directories(lexer PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
