cmake_minimum_required(VERSION 3.16)
project(Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR};${CMAKE_MODULE_PATH}")

set(PROJECT_NAME "Test")

add_executable(${PROJECT_NAME}
        main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Quaternion)

find_package(GTest REQUIRED)
if(GTest_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${GTest_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${GTest_LIBRARIES})
endif()