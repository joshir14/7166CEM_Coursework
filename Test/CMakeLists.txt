
# location of source code files
include_directories( Unity )

# tell cmake where to put the executables that it creates
file( MAKE_DIRECTORY bin )    
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin )

add_library( Unity SHARED Unity/unity.c )
add_library( TestApplication SHARED TestApplication.c )

target_link_libraries( TestApplication PRIVATE Unity )