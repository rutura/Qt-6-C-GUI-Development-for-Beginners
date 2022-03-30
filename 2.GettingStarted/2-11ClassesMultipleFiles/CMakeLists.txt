cmake_minimum_required(VERSION 3.5)

project(2-11ClassesMultipleFiles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2-11ClassesMultipleFiles
                main.cpp
                rectangle.h
                box.h
                rectangle.cpp
                box.cpp)
