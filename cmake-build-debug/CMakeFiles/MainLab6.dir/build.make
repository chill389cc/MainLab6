# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chill/Documents/GitHub/MainLab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chill/Documents/GitHub/MainLab6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MainLab6.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/MainLab6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MainLab6.dir/flags.make

CMakeFiles/MainLab6.dir/main.cpp.o: CMakeFiles/MainLab6.dir/flags.make
CMakeFiles/MainLab6.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chill/Documents/GitHub/MainLab6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MainLab6.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MainLab6.dir/main.cpp.o -c /Users/chill/Documents/GitHub/MainLab6/main.cpp

CMakeFiles/MainLab6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MainLab6.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chill/Documents/GitHub/MainLab6/main.cpp > CMakeFiles/MainLab6.dir/main.cpp.i

CMakeFiles/MainLab6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MainLab6.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chill/Documents/GitHub/MainLab6/main.cpp -o CMakeFiles/MainLab6.dir/main.cpp.s

# Object files for target MainLab6
MainLab6_OBJECTS = \
"CMakeFiles/MainLab6.dir/main.cpp.o"

# External object files for target MainLab6
MainLab6_EXTERNAL_OBJECTS =

MainLab6: CMakeFiles/MainLab6.dir/main.cpp.o
MainLab6: CMakeFiles/MainLab6.dir/build.make
MainLab6: CMakeFiles/MainLab6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chill/Documents/GitHub/MainLab6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MainLab6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MainLab6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MainLab6.dir/build: MainLab6
.PHONY : CMakeFiles/MainLab6.dir/build

CMakeFiles/MainLab6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MainLab6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MainLab6.dir/clean

CMakeFiles/MainLab6.dir/depend:
	cd /Users/chill/Documents/GitHub/MainLab6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chill/Documents/GitHub/MainLab6 /Users/chill/Documents/GitHub/MainLab6 /Users/chill/Documents/GitHub/MainLab6/cmake-build-debug /Users/chill/Documents/GitHub/MainLab6/cmake-build-debug /Users/chill/Documents/GitHub/MainLab6/cmake-build-debug/CMakeFiles/MainLab6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MainLab6.dir/depend

