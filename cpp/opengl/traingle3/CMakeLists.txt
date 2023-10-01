cmake_minimum_required(VERSION 3.26)
project(traingle2)

set(CMAKE_CXX_STANDARD 17)

add_executable(traingle2 main.cpp
        Shader.cpp
        Shader.h
        stb_image_impl.cpp
)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(traingle2 PRIVATE glfw)
find_package(glad CONFIG REQUIRED)
target_link_libraries(traingle2 PRIVATE glad::glad)
find_package(Stb REQUIRED)
target_include_directories(traingle2 PRIVATE ${Stb_INCLUDE_DIR})