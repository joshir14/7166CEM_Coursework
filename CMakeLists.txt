cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

project(Application C)

# location of source code files
include_directories( Include )

# tell cmake where to put the executables that it creates
file( MAKE_DIRECTORY bin )    
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin )

# where to put the object files it creates
file( MAKE_DIRECTORY lib )
SET( LIBRARY_OUTPUT_PATH lib )

add_library( candata SHARED Src/candata.c )
target_include_directories( candata PUBLIC Include )

add_executable( Application Src/Application.c )
target_link_libraries( Application PRIVATE candata )

add_subdirectory(Test)



