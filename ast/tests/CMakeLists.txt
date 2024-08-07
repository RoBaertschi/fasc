add_executable(ast_tests ast_tests.cpp)
target_link_libraries(ast_tests PRIVATE Catch2::Catch2WithMain ast lexer)
catch_discover_tests(ast_tests)
