# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/build

# Include any dependencies generated for this target.
include CMakeFiles/P3LAREVANCHA.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/P3LAREVANCHA.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/P3LAREVANCHA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P3LAREVANCHA.dir/flags.make

CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.o: CMakeFiles/P3LAREVANCHA.dir/flags.make
CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.o: /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/grafo.cpp
CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.o: CMakeFiles/P3LAREVANCHA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.o -MF CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.o.d -o CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.o -c /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/grafo.cpp

CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/grafo.cpp > CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.i

CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/grafo.cpp -o CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.s

CMakeFiles/P3LAREVANCHA.dir/main.cpp.o: CMakeFiles/P3LAREVANCHA.dir/flags.make
CMakeFiles/P3LAREVANCHA.dir/main.cpp.o: /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/main.cpp
CMakeFiles/P3LAREVANCHA.dir/main.cpp.o: CMakeFiles/P3LAREVANCHA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/P3LAREVANCHA.dir/main.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/P3LAREVANCHA.dir/main.cpp.o -MF CMakeFiles/P3LAREVANCHA.dir/main.cpp.o.d -o CMakeFiles/P3LAREVANCHA.dir/main.cpp.o -c /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/main.cpp

CMakeFiles/P3LAREVANCHA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/P3LAREVANCHA.dir/main.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/main.cpp > CMakeFiles/P3LAREVANCHA.dir/main.cpp.i

CMakeFiles/P3LAREVANCHA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/P3LAREVANCHA.dir/main.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/main.cpp -o CMakeFiles/P3LAREVANCHA.dir/main.cpp.s

# Object files for target P3LAREVANCHA
P3LAREVANCHA_OBJECTS = \
"CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.o" \
"CMakeFiles/P3LAREVANCHA.dir/main.cpp.o"

# External object files for target P3LAREVANCHA
P3LAREVANCHA_EXTERNAL_OBJECTS =

libP3LAREVANCHA.a: CMakeFiles/P3LAREVANCHA.dir/grafo.cpp.o
libP3LAREVANCHA.a: CMakeFiles/P3LAREVANCHA.dir/main.cpp.o
libP3LAREVANCHA.a: CMakeFiles/P3LAREVANCHA.dir/build.make
libP3LAREVANCHA.a: CMakeFiles/P3LAREVANCHA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libP3LAREVANCHA.a"
	$(CMAKE_COMMAND) -P CMakeFiles/P3LAREVANCHA.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P3LAREVANCHA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P3LAREVANCHA.dir/build: libP3LAREVANCHA.a
.PHONY : CMakeFiles/P3LAREVANCHA.dir/build

CMakeFiles/P3LAREVANCHA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P3LAREVANCHA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P3LAREVANCHA.dir/clean

CMakeFiles/P3LAREVANCHA.dir/depend:
	cd /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/build /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/build /ens/home01/n/nicolas.serra/p4gr33_soft/P3Nico/build/CMakeFiles/P3LAREVANCHA.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/P3LAREVANCHA.dir/depend

