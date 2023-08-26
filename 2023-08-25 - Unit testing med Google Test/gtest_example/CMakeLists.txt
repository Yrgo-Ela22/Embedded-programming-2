cmake_minimum_required(VERSION 3.20)                            # Minimum compatible CMake version.
project(gtest_example)                                          # Project named gtest_example.
find_package(GTest REQUIRED)                                    # Finds the GTest library (required for build).
include_directories(${GTEST_INCLUDE_DIRS})                      # Includes GTest header files.
add_executable(run_unit_test unit_test.cpp)                     # Creates executable run_gtest_example.
target_compile_options(run_unit_test PRIVATE -Wall -Werror)     # Sets local compile options.   
target_link_libraries(run_unit_test ${GTEST_LIBRARIES} pthread) # Links external libraries GTest and pthread. 