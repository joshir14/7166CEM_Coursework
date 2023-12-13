# tell cmake where to put the executables that it creates
#   also creates the directory if needed
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)    
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin ) 


# where to put the object files it creates
file( MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib )
SET( LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib )

include_directories( Unity )
include_directories( ${PROJECT_SOURCE_DIR}/Include )
include_directories( ${PROJECT_SOURCE_DIR}/Src_autogen )

# tell cmake where to find the unity library
set(UNITY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Unity/unity)
add_library(Unity INTERFACE)
target_include_directories(Unity INTERFACE ${UNITY_INCLUDE_DIR})

set(CANDATA_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Src_autogen/candata)
add_library(candata1 INTERFACE)
target_include_directories(candata1 INTERFACE ${CANDATA_INCLUDE_DIR})

set(APPLICATION_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/Include)
add_library(Application1 INTERFACE)
target_include_directories(Application1 INTERFACE ${APPLICATION_INCLUDE_DIR})

# create the tests
#   test files start with "test_" and end in ".cpp"
#   create a seperate executable for each test file
enable_testing()  

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/Test_*.c")
foreach(filename ${files})
    # if test file is "test_thingy.cpp" then created test will be called "test_thingy"        
    get_filename_component(THIS_TEST ${filename} NAME_WE)
    set(TEST_RUNNER ${THIS_TEST})

    # create the executable, include the Unity library
    add_executable(${TEST_RUNNER} ${filename} ${HEADERS})
    target_link_libraries(${TEST_RUNNER} Unity)
  
    # say that this executable is a test so that ctest will run it
    add_test(NAME ${THIS_TEST}
       COMMAND ${TEST_RUNNER} )
endforeach()









