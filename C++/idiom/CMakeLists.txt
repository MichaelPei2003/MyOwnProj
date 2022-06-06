cmake_minimum_required(VERSION 3.21)
project(idiom)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(idiom
        idiom.cpp
        idiom.h
        main.cpp temp.h)
