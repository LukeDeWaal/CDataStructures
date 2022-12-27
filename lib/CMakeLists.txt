cmake_minimum_required(VERSION 3.24)
project(DS_lib C)

set(CMAKE_C_STANDARD 11)

set(LIST_FILES lists/list_helpers.c lists/list_helpers.h datatypes.h lists/node.c lists/node.h lists/list_sll.c lists/list_sll.h lists/list_dll.c lists/list_dll.h lists/list_cll.c lists/list_cll.h lists/lists.h)

add_library(DS_lib library.c ${LIST_FILES})
