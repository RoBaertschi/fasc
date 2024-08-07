add_library(parser STATIC Parser.cpp Parser.hpp)
target_include_directories(parser PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(parser PRIVATE lexer ast)