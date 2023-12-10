cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

project(Application C)

# location of source code files
include_directories( Include )

# search for clang-tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)

# setup clang-tidy command from executable + options
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")

# Docs only available if this is the main app
find_package(Doxygen)
add_subdirectory(Docs)

# tell cmake where to put the executables that it creates
file( MAKE_DIRECTORY bin )    
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin )

# where to put the object files it creates
file( MAKE_DIRECTORY lib )
SET( LIBRARY_OUTPUT_PATH lib )

add_library( candata SHARED Src/candata.c )
target_include_directories( candata PUBLIC Include )

add_executable( Application Src/Application.c )
set_property(TARGET Application PROPERTY ENABLE_EXPORTS 1)
target_link_libraries( Application PUBLIC candata )

target_include_directories(Application PUBLIC ${CMAKE_CURRENT_LIST_DIR})

set_target_properties(Application PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")

include(CTest)
add_subdirectory(Test)






