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

# Include any dependencies generated for this target.
include Test/CMakeFiles/Test_BatteryFrameProcessing.dir/depend.make

# Include the progress variables for this target.
include Test/CMakeFiles/Test_BatteryFrameProcessing.dir/progress.make

# Include the compile flags for this target's objects.
include Test/CMakeFiles/Test_BatteryFrameProcessing.dir/flags.make

Test/CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.o: Test/CMakeFiles/Test_BatteryFrameProcessing.dir/flags.make
Test/CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.o: Test/Test_BatteryFrameProcessing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/7166CEM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Test/CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.o"
	cd /home/pi/Desktop/7166CEM/Test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.o   -c /home/pi/Desktop/7166CEM/Test/Test_BatteryFrameProcessing.c

Test/CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.i"
	cd /home/pi/Desktop/7166CEM/Test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Desktop/7166CEM/Test/Test_BatteryFrameProcessing.c > CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.i

Test/CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.s"
	cd /home/pi/Desktop/7166CEM/Test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Desktop/7166CEM/Test/Test_BatteryFrameProcessing.c -o CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.s

# Object files for target Test_BatteryFrameProcessing
Test_BatteryFrameProcessing_OBJECTS = \
"CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.o"

# External object files for target Test_BatteryFrameProcessing
Test_BatteryFrameProcessing_EXTERNAL_OBJECTS =

Test/bin/Test_BatteryFrameProcessing: Test/CMakeFiles/Test_BatteryFrameProcessing.dir/Test_BatteryFrameProcessing.c.o
Test/bin/Test_BatteryFrameProcessing: Test/CMakeFiles/Test_BatteryFrameProcessing.dir/build.make
Test/bin/Test_BatteryFrameProcessing: Test/CMakeFiles/Test_BatteryFrameProcessing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Desktop/7166CEM/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/Test_BatteryFrameProcessing"
	cd /home/pi/Desktop/7166CEM/Test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test_BatteryFrameProcessing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Test/CMakeFiles/Test_BatteryFrameProcessing.dir/build: Test/bin/Test_BatteryFrameProcessing

.PHONY : Test/CMakeFiles/Test_BatteryFrameProcessing.dir/build

Test/CMakeFiles/Test_BatteryFrameProcessing.dir/clean:
	cd /home/pi/Desktop/7166CEM/Test && $(CMAKE_COMMAND) -P CMakeFiles/Test_BatteryFrameProcessing.dir/cmake_clean.cmake
.PHONY : Test/CMakeFiles/Test_BatteryFrameProcessing.dir/clean

Test/CMakeFiles/Test_BatteryFrameProcessing.dir/depend:
	cd /home/pi/Desktop/7166CEM && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM/Test /home/pi/Desktop/7166CEM /home/pi/Desktop/7166CEM/Test /home/pi/Desktop/7166CEM/Test/CMakeFiles/Test_BatteryFrameProcessing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Test/CMakeFiles/Test_BatteryFrameProcessing.dir/depend

