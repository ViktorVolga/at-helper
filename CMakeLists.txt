cmake_minimum_required(VERSION 3.22)

project(at-helper VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_CXX_FLAGS -Wall)
enable_testing()

add_subdirectory(tests)

add_subdirectory(src)

add_executable(
    at-helper
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)