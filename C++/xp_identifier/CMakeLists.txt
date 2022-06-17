cmake_minimum_required(VERSION 3.22)
project(xp_identifier)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(xp_identifier main.cpp)
