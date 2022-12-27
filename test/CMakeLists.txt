cmake_minimum_required(VERSION 3.24)
project(DS_test C)

set(CMAKE_C_STANDARD 11)

add_executable(DS_test test_main.c)
target_link_libraries(DS_test DS_lib)