cmake_minimum_required(VERSION 3.16)
project(calculator)

add_executable(calculator.bin app/app.cpp)
target_include_directories(calculator.bin PUBLIC include/)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(calculator.bin PUBLIC add)

find_package(fmt REQUIRED CONFIG)
target_link_libraries(calculator.bin PUBLIC fmt::fmt)