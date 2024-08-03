cmake_minimum_required(VERSION 3.28)
project(fasc)

add_compile_options(-Wall -Wextra -pedantic -Werror)

# Dependencies
add_subdirectory(deps)

set(CMAKE_CXX_STANDARD 20)

# Libs
add_subdirectory(lexer)

add_executable(fasc main.cpp)
target_link_libraries(fasc PRIVATE lexer)

# Tests
include(CTest)
include(Catch)
add_subdirectory(lexer/tests)