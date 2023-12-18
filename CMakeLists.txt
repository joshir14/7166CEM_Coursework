cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

project(Application C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wvla -Werror=vla")

file( MAKE_DIRECTORY Src_autogen )  
add_custom_command( OUTPUT Src_autogen/candata.h Src_autogen/candata.c
        COMMAND python3 -m cantools generate_c_source candata.dbc -o Src_autogen
        MAIN_DEPENDENCY candata.dbc
        COMMENT "Auto code generation from DBC file" )

find_package(Doxygen)
add_subdirectory(Docs)

include_directories( Include )
include_directories( Src_autogen )

file( MAKE_DIRECTORY bin )    
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin )

file( MAKE_DIRECTORY lib )
SET( LIBRARY_OUTPUT_PATH lib )

add_library( candata SHARED Src_autogen/candata.c )
target_include_directories( candata PUBLIC Src_autogen )

add_executable( Application Src/Application.c )
target_link_libraries( Application PUBLIC candata )

enable_testing() 
add_subdirectory(Testing)





