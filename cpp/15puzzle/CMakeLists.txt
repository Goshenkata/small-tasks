cmake_minimum_required(VERSION 3.26)
project(15puzzle)

set(CMAKE_CXX_STANDARD 17)

add_executable(15puzzle main.cpp
        Game.cpp
        Game.h
)
