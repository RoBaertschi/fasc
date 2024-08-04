add_library(ast STATIC
        include/fas/ast/Node.hpp
        include/fas/ast/Statement.hpp
        include/fas/ast/Expression.hpp
        src/Program.cpp
        include/fas/ast/Program.hpp
        src/IntegerExpression.cpp
        include/fas/ast/IntegerExpression.hpp
        src/FloatExpression.cpp
        include/fas/ast/FloatExpression.hpp
        src/FunctionExpression.cpp
        include/fas/ast/FunctionExpression.hpp
        src/Identifier.cpp
        include/fas/ast/Identifier.hpp
        src/ExpressionStatement.cpp
        include/fas/ast/ExpressionStatement.hpp
        src/BlockStatement.cpp
        include/fas/ast/BlockStatement.hpp
        src/PrototypeExpression.cpp
        include/fas/ast/PrototypeExpression.hpp
)
target_include_directories(ast PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(ast PRIVATE lexer)
