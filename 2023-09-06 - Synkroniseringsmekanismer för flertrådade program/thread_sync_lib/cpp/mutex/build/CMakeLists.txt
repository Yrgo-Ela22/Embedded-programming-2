cmake_minimum_required(VERSION 3.20)
project(mutex)
include_directories(../inc)
add_executable(run_mutex ../src/main.cpp)
target_compile_options(run_mutex PRIVATE -Wall -Werror)