# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/leonardodalcin/CLionProjects/Compiladores

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/leonardodalcin/CLionProjects/Compiladores/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Compiladores.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Compiladores.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Compiladores.dir/flags.make

CMakeFiles/Compiladores.dir/main.c.o: CMakeFiles/Compiladores.dir/flags.make
CMakeFiles/Compiladores.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leonardodalcin/CLionProjects/Compiladores/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Compiladores.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Compiladores.dir/main.c.o   -c /Users/leonardodalcin/CLionProjects/Compiladores/main.c

CMakeFiles/Compiladores.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Compiladores.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/leonardodalcin/CLionProjects/Compiladores/main.c > CMakeFiles/Compiladores.dir/main.c.i

CMakeFiles/Compiladores.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Compiladores.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/leonardodalcin/CLionProjects/Compiladores/main.c -o CMakeFiles/Compiladores.dir/main.c.s

CMakeFiles/Compiladores.dir/main.c.o.requires:

.PHONY : CMakeFiles/Compiladores.dir/main.c.o.requires

CMakeFiles/Compiladores.dir/main.c.o.provides: CMakeFiles/Compiladores.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Compiladores.dir/build.make CMakeFiles/Compiladores.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Compiladores.dir/main.c.o.provides

CMakeFiles/Compiladores.dir/main.c.o.provides.build: CMakeFiles/Compiladores.dir/main.c.o


CMakeFiles/Compiladores.dir/hash.c.o: CMakeFiles/Compiladores.dir/flags.make
CMakeFiles/Compiladores.dir/hash.c.o: ../hash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leonardodalcin/CLionProjects/Compiladores/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Compiladores.dir/hash.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Compiladores.dir/hash.c.o   -c /Users/leonardodalcin/CLionProjects/Compiladores/hash.c

CMakeFiles/Compiladores.dir/hash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Compiladores.dir/hash.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/leonardodalcin/CLionProjects/Compiladores/hash.c > CMakeFiles/Compiladores.dir/hash.c.i

CMakeFiles/Compiladores.dir/hash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Compiladores.dir/hash.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/leonardodalcin/CLionProjects/Compiladores/hash.c -o CMakeFiles/Compiladores.dir/hash.c.s

CMakeFiles/Compiladores.dir/hash.c.o.requires:

.PHONY : CMakeFiles/Compiladores.dir/hash.c.o.requires

CMakeFiles/Compiladores.dir/hash.c.o.provides: CMakeFiles/Compiladores.dir/hash.c.o.requires
	$(MAKE) -f CMakeFiles/Compiladores.dir/build.make CMakeFiles/Compiladores.dir/hash.c.o.provides.build
.PHONY : CMakeFiles/Compiladores.dir/hash.c.o.provides

CMakeFiles/Compiladores.dir/hash.c.o.provides.build: CMakeFiles/Compiladores.dir/hash.c.o


# Object files for target Compiladores
Compiladores_OBJECTS = \
"CMakeFiles/Compiladores.dir/main.c.o" \
"CMakeFiles/Compiladores.dir/hash.c.o"

# External object files for target Compiladores
Compiladores_EXTERNAL_OBJECTS =

Compiladores: CMakeFiles/Compiladores.dir/main.c.o
Compiladores: CMakeFiles/Compiladores.dir/hash.c.o
Compiladores: CMakeFiles/Compiladores.dir/build.make
Compiladores: CMakeFiles/Compiladores.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/leonardodalcin/CLionProjects/Compiladores/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Compiladores"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Compiladores.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Compiladores.dir/build: Compiladores

.PHONY : CMakeFiles/Compiladores.dir/build

CMakeFiles/Compiladores.dir/requires: CMakeFiles/Compiladores.dir/main.c.o.requires
CMakeFiles/Compiladores.dir/requires: CMakeFiles/Compiladores.dir/hash.c.o.requires

.PHONY : CMakeFiles/Compiladores.dir/requires

CMakeFiles/Compiladores.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Compiladores.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Compiladores.dir/clean

CMakeFiles/Compiladores.dir/depend:
	cd /Users/leonardodalcin/CLionProjects/Compiladores/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leonardodalcin/CLionProjects/Compiladores /Users/leonardodalcin/CLionProjects/Compiladores /Users/leonardodalcin/CLionProjects/Compiladores/cmake-build-debug /Users/leonardodalcin/CLionProjects/Compiladores/cmake-build-debug /Users/leonardodalcin/CLionProjects/Compiladores/cmake-build-debug/CMakeFiles/Compiladores.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Compiladores.dir/depend

