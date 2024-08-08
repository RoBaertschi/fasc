project('fasc', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20', 'default_library=static'])

catch2_dep = dependency('catch2-with-main')

subdir('lexer')
subdir('ast')

executable('fasc',
           'main.cpp',
           install : true)
