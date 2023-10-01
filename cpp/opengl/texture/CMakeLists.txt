cmake_minimum_required(VERSION 3.26)
project(texture)

set(CMAKE_CXX_STANDARD 17)

add_executable(texture main.cpp
        Shader.cpp
        Shader.h
        stb_image_impl.cpp
)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(texture PRIVATE glfw)
find_package(glad CONFIG REQUIRED)
target_link_libraries(texture PRIVATE glad::glad)
find_package(Stb REQUIRED)
target_include_directories(texture PRIVATE ${Stb_INCLUDE_DIR})