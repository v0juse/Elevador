# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/v0id/Faculdade/Testes/Elevador

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/v0id/Faculdade/Testes/Elevador/build

# Include any dependencies generated for this target.
include CMakeFiles/AndarTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AndarTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AndarTest.dir/flags.make

CMakeFiles/AndarTest.dir/src/Andar.cpp.o: CMakeFiles/AndarTest.dir/flags.make
CMakeFiles/AndarTest.dir/src/Andar.cpp.o: ../src/Andar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AndarTest.dir/src/Andar.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AndarTest.dir/src/Andar.cpp.o -c /home/v0id/Faculdade/Testes/Elevador/src/Andar.cpp

CMakeFiles/AndarTest.dir/src/Andar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AndarTest.dir/src/Andar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/src/Andar.cpp > CMakeFiles/AndarTest.dir/src/Andar.cpp.i

CMakeFiles/AndarTest.dir/src/Andar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AndarTest.dir/src/Andar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/src/Andar.cpp -o CMakeFiles/AndarTest.dir/src/Andar.cpp.s

CMakeFiles/AndarTest.dir/testes/Andar_test.cc.o: CMakeFiles/AndarTest.dir/flags.make
CMakeFiles/AndarTest.dir/testes/Andar_test.cc.o: ../testes/Andar_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AndarTest.dir/testes/Andar_test.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AndarTest.dir/testes/Andar_test.cc.o -c /home/v0id/Faculdade/Testes/Elevador/testes/Andar_test.cc

CMakeFiles/AndarTest.dir/testes/Andar_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AndarTest.dir/testes/Andar_test.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/testes/Andar_test.cc > CMakeFiles/AndarTest.dir/testes/Andar_test.cc.i

CMakeFiles/AndarTest.dir/testes/Andar_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AndarTest.dir/testes/Andar_test.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/testes/Andar_test.cc -o CMakeFiles/AndarTest.dir/testes/Andar_test.cc.s

# Object files for target AndarTest
AndarTest_OBJECTS = \
"CMakeFiles/AndarTest.dir/src/Andar.cpp.o" \
"CMakeFiles/AndarTest.dir/testes/Andar_test.cc.o"

# External object files for target AndarTest
AndarTest_EXTERNAL_OBJECTS =

AndarTest: CMakeFiles/AndarTest.dir/src/Andar.cpp.o
AndarTest: CMakeFiles/AndarTest.dir/testes/Andar_test.cc.o
AndarTest: CMakeFiles/AndarTest.dir/build.make
AndarTest: lib/libgtest_main.a
AndarTest: libutility.a
AndarTest: lib/libgtest.a
AndarTest: CMakeFiles/AndarTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AndarTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AndarTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AndarTest.dir/build: AndarTest

.PHONY : CMakeFiles/AndarTest.dir/build

CMakeFiles/AndarTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AndarTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AndarTest.dir/clean

CMakeFiles/AndarTest.dir/depend:
	cd /home/v0id/Faculdade/Testes/Elevador/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/v0id/Faculdade/Testes/Elevador /home/v0id/Faculdade/Testes/Elevador /home/v0id/Faculdade/Testes/Elevador/build /home/v0id/Faculdade/Testes/Elevador/build /home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles/AndarTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AndarTest.dir/depend

