cmake_minimum_required(VERSION 3.21)
project(Snake C)

set(CMAKE_C_STANDARD 99)

add_executable(Snake main.c Snake.h Console_Operations.h)
