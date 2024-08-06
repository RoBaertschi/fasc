cmake_minimum_required(VERSION 3.28)
project(fasc LANGUAGES CXX)

if (NOT WIN32)
    add_compile_options(-Wall -Wextra -pedantic -Werror)
else ()
    add_compile_definitions(/W4)
endif ()

# Dependencies
add_subdirectory(deps)

set(CMAKE_CXX_STANDARD 20)

# Libs
add_subdirectory(lexer)
add_subdirectory(ast)
add_subdirectory(parser)

add_executable(fasc main.cpp)
target_link_libraries(fasc PRIVATE lexer)

# Tests
include(CTest)
enable_testing()

include(Catch)
add_subdirectory(lexer/tests)