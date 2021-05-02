cmake_minimum_required(VERSION 3.19)
project(people)

set(CMAKE_CXX_STANDARD 20)

add_executable(people main.cpp Person.cpp Person.hpp)