parser_incdir = include_directories('include')
parser_sources = [
  'src/Parser.cpp',
]

parser_lib = library(
  'parser', parser_sources,
  include_directories : parser_incdir,
  dependencies : [lexer_dep, ast_dep],
)

parser_dep = declare_dependency(
  link_with : parser_lib, include_directories : parser_incdir,
)
