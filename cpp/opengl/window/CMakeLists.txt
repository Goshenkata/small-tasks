cmake_minimum_required(VERSION 3.26)
project(window)

set(CMAKE_CXX_STANDARD 17)

add_executable(window main.cpp)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(window PRIVATE glfw)
find_package(glad CONFIG REQUIRED)
target_link_libraries(window PRIVATE glad::glad)
