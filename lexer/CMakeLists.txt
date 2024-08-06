add_library(lexer STATIC
        src/Lexer.cpp
        include/fas/lexer/Lexer.hpp
        include/fas/token/Token.hpp
        src/Globals.cpp
        src/Token.cpp)
target_include_directories(lexer PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
