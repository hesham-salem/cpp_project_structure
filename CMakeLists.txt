cmake_minimum_required(VERSION 3.10)
project(calculatorX)

add_executable(calculatorX app/app.cpp)
target_include_directories(calculatorX PUBLIC include/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(calculatorX PUBLIC calculator)

find_package(fmt REQUIRED CONFIG)
target_link_libraries(calculatorX PUBLIC fmt::fmt)