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
CMAKE_SOURCE_DIR = /home/pi/Desktop/7166CEM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Desktop/7166CEM

# Utility rule file for clangformat.

# Include the progress variables for this target.
include CMakeFiles/clangformat.dir/progress.make

CMakeFiles/clangformat:
	/usr/bin/clang-format -style=LLVM -i /home/pi/Desktop/7166CEM/CMakeFiles/3.13.4/CompilerIdC/CMakeCCompilerId.c /home/pi/Desktop/7166CEM/CMakeFiles/feature_tests.c /home/pi/Desktop/7166CEM/Include/Application.h /home/pi/Desktop/7166CEM/Include/can_wrap.h /home/pi/Desktop/7166CEM/Include/candata.h /home/pi/Desktop/7166CEM/Src/Application.c /home/pi/Desktop/7166CEM/Src/candata.c /home/pi/Desktop/7166CEM/Test/TestApplication.c /home/pi/Desktop/7166CEM/Test/Unity/unity.c /home/pi/Desktop/7166CEM/Test/Unity/unity.h /home/pi/Desktop/7166CEM/Test/Unity/unity_internals.h

clangformat: CMakeFiles/clangformat
clangformat: CMakeFiles/clangformat.dir/build.make

.PHONY : clangformat

# Rule to build all files generated by this target.
CMakeFiles/clangformat.dir/build: clangformat

.PHONY : CMakeFiles/clangformat.dir/build

CMakeFiles/clangformat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clangformat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clangformat.dir/clean

CMakeFiles/clangformat.dir/depend:
	cd /home/pi/Desktop/7166CEM && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM/CMakeFiles/clangformat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clangformat.dir/depend

