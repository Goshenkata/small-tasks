cmake_minimum_required(VERSION 3.26)
project(opptest)

set(CMAKE_CXX_STANDARD 17)

add_executable(opptest main.cpp
        Date.cpp
        Date.h)
