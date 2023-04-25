cmake_minimum_required(VERSION 3.22)
project(test1)

set(CMAKE_CXX_STANDARD 14)

add_executable(test1 main.cpp)
add_executable(clion_opencv main.cpp)
set(OpenCV_DIR D:/OpenCV-MinGW-Build-OpenCV-4.5.5-x64)
find_package(OpenCV REQUIRED)
target_link_libraries(clion_opencv ${OpenCV_LIBS})