ast_incdir = include_directories('include')
ast_sources = [
  'src/Program.cpp',
  'src/IntegerExpression.cpp',
  'src/FloatExpression.cpp',
  'src/FunctionExpression.cpp',
  'src/Identifier.cpp',
  'src/ExpressionStatement.cpp',
  'src/BlockStatement.cpp',
  'src/PrototypeExpression.cpp',
  'src/CallExpression.cpp',
]
ast_lib = library(
  'ast', ast_sources,
  include_directories : ast_incdir,
  dependencies : [lexer_dep],
)

ast_dep = declare_dependency(
  link_with : ast_lib, include_directories : ast_incdir,
)

ast_test = executable(
  'ast_test',
  'tests/ast_tests.cpp',
  dependencies : [catch2_dep, ast_dep, lexer_dep]
)
test('ast_test', ast_test)
