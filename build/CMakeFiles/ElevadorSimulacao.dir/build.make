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
include CMakeFiles/ElevadorSimulacao.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ElevadorSimulacao.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ElevadorSimulacao.dir/flags.make

CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.o: CMakeFiles/ElevadorSimulacao.dir/flags.make
CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.o: ../src/Andar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.o -c /home/v0id/Faculdade/Testes/Elevador/src/Andar.cpp

CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/src/Andar.cpp > CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.i

CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/src/Andar.cpp -o CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.s

CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.o: CMakeFiles/ElevadorSimulacao.dir/flags.make
CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.o: ../src/Porta.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.o -c /home/v0id/Faculdade/Testes/Elevador/src/Porta.cpp

CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/src/Porta.cpp > CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.i

CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/src/Porta.cpp -o CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.s

CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.o: CMakeFiles/ElevadorSimulacao.dir/flags.make
CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.o: ../src/SensorAndar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.o -c /home/v0id/Faculdade/Testes/Elevador/src/SensorAndar.cpp

CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/src/SensorAndar.cpp > CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.i

CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/src/SensorAndar.cpp -o CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.s

CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.o: CMakeFiles/ElevadorSimulacao.dir/flags.make
CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.o: ../src/SensorPresenca.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.o -c /home/v0id/Faculdade/Testes/Elevador/src/SensorPresenca.cpp

CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/src/SensorPresenca.cpp > CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.i

CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/src/SensorPresenca.cpp -o CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.s

CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.o: CMakeFiles/ElevadorSimulacao.dir/flags.make
CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.o: ../src/Controlador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.o -c /home/v0id/Faculdade/Testes/Elevador/src/Controlador.cpp

CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/src/Controlador.cpp > CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.i

CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/src/Controlador.cpp -o CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.s

CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.o: CMakeFiles/ElevadorSimulacao.dir/flags.make
CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.o: ../src/SensorEstadoPorta.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.o -c /home/v0id/Faculdade/Testes/Elevador/src/SensorEstadoPorta.cpp

CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/src/SensorEstadoPorta.cpp > CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.i

CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/src/SensorEstadoPorta.cpp -o CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.s

CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.o: CMakeFiles/ElevadorSimulacao.dir/flags.make
CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.o: ../src/UsuarioIA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.o -c /home/v0id/Faculdade/Testes/Elevador/src/UsuarioIA.cpp

CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/src/UsuarioIA.cpp > CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.i

CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/src/UsuarioIA.cpp -o CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.s

CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.o: CMakeFiles/ElevadorSimulacao.dir/flags.make
CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.o -c /home/v0id/Faculdade/Testes/Elevador/src/main.cpp

CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/v0id/Faculdade/Testes/Elevador/src/main.cpp > CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.i

CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/v0id/Faculdade/Testes/Elevador/src/main.cpp -o CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.s

# Object files for target ElevadorSimulacao
ElevadorSimulacao_OBJECTS = \
"CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.o" \
"CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.o" \
"CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.o" \
"CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.o" \
"CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.o" \
"CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.o" \
"CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.o" \
"CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.o"

# External object files for target ElevadorSimulacao
ElevadorSimulacao_EXTERNAL_OBJECTS =

ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/src/Andar.cpp.o
ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/src/Porta.cpp.o
ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/src/SensorAndar.cpp.o
ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/src/SensorPresenca.cpp.o
ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/src/Controlador.cpp.o
ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/src/SensorEstadoPorta.cpp.o
ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/src/UsuarioIA.cpp.o
ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/src/main.cpp.o
ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/build.make
ElevadorSimulacao: libutility.a
ElevadorSimulacao: CMakeFiles/ElevadorSimulacao.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ElevadorSimulacao"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ElevadorSimulacao.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ElevadorSimulacao.dir/build: ElevadorSimulacao

.PHONY : CMakeFiles/ElevadorSimulacao.dir/build

CMakeFiles/ElevadorSimulacao.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ElevadorSimulacao.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ElevadorSimulacao.dir/clean

CMakeFiles/ElevadorSimulacao.dir/depend:
	cd /home/v0id/Faculdade/Testes/Elevador/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/v0id/Faculdade/Testes/Elevador /home/v0id/Faculdade/Testes/Elevador /home/v0id/Faculdade/Testes/Elevador/build /home/v0id/Faculdade/Testes/Elevador/build /home/v0id/Faculdade/Testes/Elevador/build/CMakeFiles/ElevadorSimulacao.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ElevadorSimulacao.dir/depend

