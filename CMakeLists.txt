cmake_minimum_required(VERSION 3.8)

project(projekt_2)

add_executable(graph main.cpp)
set_target_properties(graph PROPERTIES
    CXX_STANDARD 23
)