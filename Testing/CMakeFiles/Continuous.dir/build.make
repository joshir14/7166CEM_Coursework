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

# Utility rule file for Continuous.

# Include the progress variables for this target.
include Testing/CMakeFiles/Continuous.dir/progress.make

Testing/CMakeFiles/Continuous:
	cd /home/pi/Desktop/7166CEM/Testing && /usr/bin/ctest -D Continuous

Continuous: Testing/CMakeFiles/Continuous
Continuous: Testing/CMakeFiles/Continuous.dir/build.make

.PHONY : Continuous

# Rule to build all files generated by this target.
Testing/CMakeFiles/Continuous.dir/build: Continuous

.PHONY : Testing/CMakeFiles/Continuous.dir/build

Testing/CMakeFiles/Continuous.dir/clean:
	cd /home/pi/Desktop/7166CEM/Testing && $(CMAKE_COMMAND) -P CMakeFiles/Continuous.dir/cmake_clean.cmake
.PHONY : Testing/CMakeFiles/Continuous.dir/clean

Testing/CMakeFiles/Continuous.dir/depend:
	cd /home/pi/Desktop/7166CEM && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM/Testing /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM/Testing /home/pi/Desktop/7166CEM/Testing/CMakeFiles/Continuous.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Testing/CMakeFiles/Continuous.dir/depend
