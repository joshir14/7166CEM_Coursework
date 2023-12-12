cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

project(Application C)

file( MAKE_DIRECTORY Src_autogen )  
add_custom_command( OUTPUT Src_autogen/candata.h Src_autogen/candata.c
        COMMAND python3 -m cantools generate_c_source candata.dbc -o Src_autogen
        MAIN_DEPENDENCY candata.dbc
        COMMENT "Autogenerate code from DBC file" )

# location of source code files
include_directories( Include )

# search for clang-tidy
#find_program(CLANG_TIDY_EXE NAMES "clang-tidy" REQUIRED)

# setup clang-tidy command from executable + options
#set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*")

find_program(CMAKE_CXX_CLANG_TIDY NAMES clang-tidy)
if(CMAKE_CXX_CLANG_TIDY)
    list(APPEND CMAKE_CXX_CLANG_TIDY 
        "-checks=*,-fuchsia-trailing-return,-modernize-use-trailing-return-type")
endif()

# Docs only available if this is the main app
find_package(Doxygen)
add_subdirectory(Docs)

# tell cmake where to put the executables that it creates
file( MAKE_DIRECTORY bin )    
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin )

# where to put the object files it creates
file( MAKE_DIRECTORY lib )
SET( LIBRARY_OUTPUT_PATH lib )

add_library( candata SHARED Src_autogen/candata.c )
target_include_directories( candata PUBLIC Src_autogen )

add_executable( Application Src/Application.c )
target_link_libraries( Application PUBLIC candata )




include(CTest)
add_subdirectory(Test)






