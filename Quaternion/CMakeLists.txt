cmake_minimum_required(VERSION 3.16)
project(Quaternion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR};${CMAKE_MODULE_PATH}")

set(PROJECT_NAME "Quaternion")

add_library(${PROJECT_NAME}
        Quaternion.cpp
        QuaternionSlerp.cpp
        Quaternion.h
        QuaternionSlerp.h)

target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" )
