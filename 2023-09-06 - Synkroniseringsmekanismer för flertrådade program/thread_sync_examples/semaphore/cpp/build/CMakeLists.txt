cmake_minimum_required(VERSION 3.20)
project(semaphore_cpp)
include_directories(../inc)
add_executable(run_semaphore_cpp ../src/main.cpp ../src/semaphore.c)
target_compile_options(run_semaphore_cpp PRIVATE -Wall -Werror)
target_link_libraries(run_semaphore_cpp pthread)
set_target_properties(run_semaphore_cpp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../)