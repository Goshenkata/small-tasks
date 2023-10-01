cmake_minimum_required(VERSION 3.26)
project(libtest)

set(CMAKE_CXX_STANDARD 17)

add_executable(libtest main.cpp)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})
target_link_libraries(libtest PRIVATE ${PNG_LIBRARY})