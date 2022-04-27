cmake_minimum_required(VERSION 3.21)
project(price_prediction C)

set(CMAKE_C_STANDARD 99)

add_executable(price_prediction main.c known_data.h)
