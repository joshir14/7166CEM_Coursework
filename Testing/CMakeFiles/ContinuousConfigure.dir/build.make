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

# Utility rule file for ContinuousConfigure.

# Include the progress variables for this target.
include Testing/CMakeFiles/ContinuousConfigure.dir/progress.make

Testing/CMakeFiles/ContinuousConfigure:
	cd /home/pi/Desktop/7166CEM/Testing && /usr/bin/ctest -D ContinuousConfigure

ContinuousConfigure: Testing/CMakeFiles/ContinuousConfigure
ContinuousConfigure: Testing/CMakeFiles/ContinuousConfigure.dir/build.make

.PHONY : ContinuousConfigure

# Rule to build all files generated by this target.
Testing/CMakeFiles/ContinuousConfigure.dir/build: ContinuousConfigure

.PHONY : Testing/CMakeFiles/ContinuousConfigure.dir/build

Testing/CMakeFiles/ContinuousConfigure.dir/clean:
	cd /home/pi/Desktop/7166CEM/Testing && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousConfigure.dir/cmake_clean.cmake
.PHONY : Testing/CMakeFiles/ContinuousConfigure.dir/clean

Testing/CMakeFiles/ContinuousConfigure.dir/depend:
	cd /home/pi/Desktop/7166CEM && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM/Testing /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM/Testing /home/pi/Desktop/7166CEM/Testing/CMakeFiles/ContinuousConfigure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Testing/CMakeFiles/ContinuousConfigure.dir/depend

