cmake_minimum_required (VERSION 2.8) 
project (main)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

FLEX_TARGET(MyScanner src/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
BISON_TARGET(MyParser src/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

include_directories(src/ ../)
add_executable(main 
               src/ast.cpp
               ${BISON_MyParser_OUTPUTS}
               ${FLEX_MyScanner_OUTPUTS})
target_link_libraries(main
                      ${FLEX_LIBRARIES})
