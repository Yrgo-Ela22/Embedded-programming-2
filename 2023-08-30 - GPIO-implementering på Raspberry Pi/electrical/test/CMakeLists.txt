cmake_minimum_required(VERSION 3.20) # Mimimum compatile CMake version set to 3.20.
project(electrical_test)             # Project named electrical_test.
find_package(GTest REQUIRED)         # Localises the GTest package (mandatory to run the program).
include_directories(../inc ${GTEST_INCLUDE_DIRS}) 
add_executable(run_electrical_test electrical_test.cpp ../src/electrical.c)
target_compile_options(run_electrical_test PRIVATE -Wall -Werror)
target_link_libraries(run_electrical_test ${GTEST_LIBRARIES} pthread)
set_target_properties(run_electrical_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../)