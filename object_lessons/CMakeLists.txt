cmake_minimum_required(VERSION 3.20)

# set the project name
project(CppObjectLessons VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(object_lesson01_c object_lesson01.cc)
add_executable(object_lesson01 object_lesson01.cpp)
add_executable(object_lesson02 object_lesson02.cpp)
add_executable(object_lesson03 object_lesson03.cpp)
