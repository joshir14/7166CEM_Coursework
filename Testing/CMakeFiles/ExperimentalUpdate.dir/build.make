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

# Utility rule file for ExperimentalUpdate.

# Include the progress variables for this target.
include Testing/CMakeFiles/ExperimentalUpdate.dir/progress.make

Testing/CMakeFiles/ExperimentalUpdate:
	cd /home/pi/Desktop/7166CEM/Testing && /usr/bin/ctest -D ExperimentalUpdate

ExperimentalUpdate: Testing/CMakeFiles/ExperimentalUpdate
ExperimentalUpdate: Testing/CMakeFiles/ExperimentalUpdate.dir/build.make

.PHONY : ExperimentalUpdate

# Rule to build all files generated by this target.
Testing/CMakeFiles/ExperimentalUpdate.dir/build: ExperimentalUpdate

.PHONY : Testing/CMakeFiles/ExperimentalUpdate.dir/build

Testing/CMakeFiles/ExperimentalUpdate.dir/clean:
	cd /home/pi/Desktop/7166CEM/Testing && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalUpdate.dir/cmake_clean.cmake
.PHONY : Testing/CMakeFiles/ExperimentalUpdate.dir/clean

Testing/CMakeFiles/ExperimentalUpdate.dir/depend:
	cd /home/pi/Desktop/7166CEM && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM/Testing /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM/Testing /home/pi/Desktop/7166CEM/Testing/CMakeFiles/ExperimentalUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Testing/CMakeFiles/ExperimentalUpdate.dir/depend

