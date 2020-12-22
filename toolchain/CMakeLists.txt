cmake_minimum_required (VERSION 2.8) 
project (cpu_toolchain)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Build the compiler.

FLEX_TARGET(CompilerLexer compiler/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/compiler_lexer.cpp)
BISON_TARGET(CompilerParser compiler/parser.y ${CMAKE_CURRENT_BINARY_DIR}/compiler_parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(CompilerLexer CompilerParser)

include_directories(./ ./compiler/include/ ./compiler)
add_executable(compiler
               compiler/asmgenerator.cpp
               compiler/stackframe.cpp
               compiler/asmgenerator.cpp
               compiler/astnode.cpp
               compiler/astbeginendblocknode.cpp
               compiler/astbufferreadnode.cpp
               compiler/astbufferwritenode.cpp
               compiler/astconditionalnode.cpp
               compiler/astconditionnode.cpp
               compiler/astexpressionnode.cpp
               compiler/astprocedurecallnode.cpp
               compiler/astprocedurenode.cpp
               compiler/astrootnode.cpp
               compiler/asttermnode.cpp
               compiler/astvariableassignmentnode.cpp
               compiler/astvariabledeclarationnode.cpp
               compiler/astwhileloopnode.cpp
               compiler/astinlineassemblynode.cpp
               ${BISON_CompilerParser_OUTPUTS}
               ${FLEX_CompilerLexer_OUTPUTS})
target_link_libraries(compiler
                      ${FLEX_LIBRARIES})

# Build the disassembler.

include_directories(./)
add_executable(disassembler
               disassembler/disassembler.c)

# Build the assembler.

find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)

FLEX_TARGET(AssemblerLexer assembler/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/assembler_lexer.c)
BISON_TARGET(AssemblerParser assembler/parser.y ${CMAKE_CURRENT_BINARY_DIR}/assembler_parser.c)
ADD_FLEX_BISON_DEPENDENCY(AssemblerLexer AssemblerParser)

include_directories(./ ${GLIB_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})
add_executable(assembler
               ${BISON_AssemblerParser_OUTPUTS}
               ${FLEX_AssemblerLexer_OUTPUTS})
add_definitions(${GLIB_CFLAGS_OTHER})
target_link_libraries(assembler
                      ${GLIB_LIBRARIES}
                      ${FLEX_LIBRARIES})

# Build the emulator

include_directories(./)
add_executable(emulator
               emulator/emulator.c)
