cmake_minimum_required(VERSION 3.16.5)

project(at-helper VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 23)

enable_testing()

add_subdirectory(tests)

add_subdirectory(src)

add_executable(
    at-helper
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_include_directories(at-helper PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(at-helper io)

install(TARGETS at-helper RUNTIME DESTINATION bin)