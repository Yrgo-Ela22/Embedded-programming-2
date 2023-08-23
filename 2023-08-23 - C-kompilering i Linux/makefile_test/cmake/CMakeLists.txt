cmake_minimum_required(VERSION 3.20)                   # Minimum compatible CMake version set to 3.20.
project(makefile_test)                                 # Setting project name to makefile_test.
include_directories(../inc)                            # Includes directory inc in build.
add_executable(run_test ../src/main.c)                 # Creates executable run_test.
target_compile_options(run_test PRIVATE -Wall -Werror) # Compile options set locally for run_test.
target_link_libraries(run_test gpiod)                  # Links external library gpiod to run_test.