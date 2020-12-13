# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oliver/Projects/FPGA_Projects/CPU/toolchain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build

# Include any dependencies generated for this target.
include CMakeFiles/compiler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/compiler.dir/flags.make

compiler_parser.cpp: ../compiler/parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][CompilerParser] Building parser with bison 3.3.2"
	cd /home/oliver/Projects/FPGA_Projects/CPU/toolchain && /usr/bin/bison -d -o /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp compiler/parser.y

compiler_parser.hpp: compiler_parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate compiler_parser.hpp

compiler_lexer.cpp: ../compiler/lexer.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][CompilerLexer] Building scanner with flex 2.6.4"
	cd /home/oliver/Projects/FPGA_Projects/CPU/toolchain && /usr/bin/flex -o/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_lexer.cpp compiler/lexer.l

CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.o: ../compiler/asmgenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/asmgenerator.cpp

CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/asmgenerator.cpp > CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.i

CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/asmgenerator.cpp -o CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.s

CMakeFiles/compiler.dir/compiler/stackframe.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/stackframe.cpp.o: ../compiler/stackframe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/compiler.dir/compiler/stackframe.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/stackframe.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/stackframe.cpp

CMakeFiles/compiler.dir/compiler/stackframe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/stackframe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/stackframe.cpp > CMakeFiles/compiler.dir/compiler/stackframe.cpp.i

CMakeFiles/compiler.dir/compiler/stackframe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/stackframe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/stackframe.cpp -o CMakeFiles/compiler.dir/compiler/stackframe.cpp.s

CMakeFiles/compiler.dir/compiler/astnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astnode.cpp.o: ../compiler/astnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/compiler.dir/compiler/astnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astnode.cpp

CMakeFiles/compiler.dir/compiler/astnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astnode.cpp > CMakeFiles/compiler.dir/compiler/astnode.cpp.i

CMakeFiles/compiler.dir/compiler/astnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astnode.cpp -o CMakeFiles/compiler.dir/compiler/astnode.cpp.s

CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.o: ../compiler/astbeginendblocknode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astbeginendblocknode.cpp

CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astbeginendblocknode.cpp > CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.i

CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astbeginendblocknode.cpp -o CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.s

CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.o: ../compiler/astbufferreadnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astbufferreadnode.cpp

CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astbufferreadnode.cpp > CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.i

CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astbufferreadnode.cpp -o CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.s

CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.o: ../compiler/astbufferwritenode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astbufferwritenode.cpp

CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astbufferwritenode.cpp > CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.i

CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astbufferwritenode.cpp -o CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.s

CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.o: ../compiler/astconditionalnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astconditionalnode.cpp

CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astconditionalnode.cpp > CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.i

CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astconditionalnode.cpp -o CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.s

CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.o: ../compiler/astconditionnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astconditionnode.cpp

CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astconditionnode.cpp > CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.i

CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astconditionnode.cpp -o CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.s

CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.o: ../compiler/astexpressionnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astexpressionnode.cpp

CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astexpressionnode.cpp > CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.i

CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astexpressionnode.cpp -o CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.s

CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.o: ../compiler/astprocedurecallnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astprocedurecallnode.cpp

CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astprocedurecallnode.cpp > CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.i

CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astprocedurecallnode.cpp -o CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.s

CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.o: ../compiler/astprocedurenode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astprocedurenode.cpp

CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astprocedurenode.cpp > CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.i

CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astprocedurenode.cpp -o CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.s

CMakeFiles/compiler.dir/compiler/astrootnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astrootnode.cpp.o: ../compiler/astrootnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/compiler.dir/compiler/astrootnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astrootnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astrootnode.cpp

CMakeFiles/compiler.dir/compiler/astrootnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astrootnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astrootnode.cpp > CMakeFiles/compiler.dir/compiler/astrootnode.cpp.i

CMakeFiles/compiler.dir/compiler/astrootnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astrootnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astrootnode.cpp -o CMakeFiles/compiler.dir/compiler/astrootnode.cpp.s

CMakeFiles/compiler.dir/compiler/asttermnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/asttermnode.cpp.o: ../compiler/asttermnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/compiler.dir/compiler/asttermnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/asttermnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/asttermnode.cpp

CMakeFiles/compiler.dir/compiler/asttermnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/asttermnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/asttermnode.cpp > CMakeFiles/compiler.dir/compiler/asttermnode.cpp.i

CMakeFiles/compiler.dir/compiler/asttermnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/asttermnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/asttermnode.cpp -o CMakeFiles/compiler.dir/compiler/asttermnode.cpp.s

CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.o: ../compiler/astvariableassignmentnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astvariableassignmentnode.cpp

CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astvariableassignmentnode.cpp > CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.i

CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astvariableassignmentnode.cpp -o CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.s

CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.o: ../compiler/astvariabledeclarationnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astvariabledeclarationnode.cpp

CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astvariabledeclarationnode.cpp > CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.i

CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astvariabledeclarationnode.cpp -o CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.s

CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.o: ../compiler/astwhileloopnode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astwhileloopnode.cpp

CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astwhileloopnode.cpp > CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.i

CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astwhileloopnode.cpp -o CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.s

CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.o: ../compiler/astinlineassemblynode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astinlineassemblynode.cpp

CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astinlineassemblynode.cpp > CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.i

CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/compiler/astinlineassemblynode.cpp -o CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.s

CMakeFiles/compiler.dir/compiler_parser.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler_parser.cpp.o: compiler_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/compiler.dir/compiler_parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler_parser.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp

CMakeFiles/compiler.dir/compiler_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler_parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp > CMakeFiles/compiler.dir/compiler_parser.cpp.i

CMakeFiles/compiler.dir/compiler_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler_parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_parser.cpp -o CMakeFiles/compiler.dir/compiler_parser.cpp.s

CMakeFiles/compiler.dir/compiler_lexer.cpp.o: CMakeFiles/compiler.dir/flags.make
CMakeFiles/compiler.dir/compiler_lexer.cpp.o: compiler_lexer.cpp
CMakeFiles/compiler.dir/compiler_lexer.cpp.o: compiler_parser.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/compiler.dir/compiler_lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compiler.dir/compiler_lexer.cpp.o -c /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_lexer.cpp

CMakeFiles/compiler.dir/compiler_lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compiler.dir/compiler_lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_lexer.cpp > CMakeFiles/compiler.dir/compiler_lexer.cpp.i

CMakeFiles/compiler.dir/compiler_lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compiler.dir/compiler_lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/compiler_lexer.cpp -o CMakeFiles/compiler.dir/compiler_lexer.cpp.s

# Object files for target compiler
compiler_OBJECTS = \
"CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.o" \
"CMakeFiles/compiler.dir/compiler/stackframe.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astrootnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/asttermnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.o" \
"CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.o" \
"CMakeFiles/compiler.dir/compiler_parser.cpp.o" \
"CMakeFiles/compiler.dir/compiler_lexer.cpp.o"

# External object files for target compiler
compiler_EXTERNAL_OBJECTS =

compiler: CMakeFiles/compiler.dir/compiler/asmgenerator.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/stackframe.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astbeginendblocknode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astbufferreadnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astbufferwritenode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astconditionalnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astconditionnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astexpressionnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astprocedurecallnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astprocedurenode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astrootnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/asttermnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astvariableassignmentnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astvariabledeclarationnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astwhileloopnode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler/astinlineassemblynode.cpp.o
compiler: CMakeFiles/compiler.dir/compiler_parser.cpp.o
compiler: CMakeFiles/compiler.dir/compiler_lexer.cpp.o
compiler: CMakeFiles/compiler.dir/build.make
compiler: /usr/lib/x86_64-linux-gnu/libfl.so
compiler: CMakeFiles/compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Linking CXX executable compiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/compiler.dir/build: compiler

.PHONY : CMakeFiles/compiler.dir/build

CMakeFiles/compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/compiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/compiler.dir/clean

CMakeFiles/compiler.dir/depend: compiler_parser.cpp
CMakeFiles/compiler.dir/depend: compiler_parser.hpp
CMakeFiles/compiler.dir/depend: compiler_lexer.cpp
	cd /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oliver/Projects/FPGA_Projects/CPU/toolchain /home/oliver/Projects/FPGA_Projects/CPU/toolchain /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build /home/oliver/Projects/FPGA_Projects/CPU/toolchain/build/CMakeFiles/compiler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/compiler.dir/depend

