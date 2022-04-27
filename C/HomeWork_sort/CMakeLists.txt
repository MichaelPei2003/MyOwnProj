cmake_minimum_required(VERSION 3.21)
project(HomeWork_sort C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,999999999")

add_executable(HomeWork_sort main.c)
