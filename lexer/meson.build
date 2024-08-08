lexer_incdir = include_directories('include')
lexer_sources = [
  'src/Lexer.cpp',
  'src/Token.cpp',
  'src/Globals.cpp',
]
lexer_lib = library(
  'lexer', lexer_sources, include_directories : lexer_incdir
)

lexer_dep = declare_dependency(link_with : lexer_lib, include_directories : lexer_incdir)

lexer_test = executable(
  'linker_test',
  'tests/lexer_tests.cpp',
  dependencies : [catch2_dep, lexer_dep],
)
test('lexer_test', lexer_test)
