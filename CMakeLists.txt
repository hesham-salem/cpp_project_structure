cmake_minimum_required(VERSION 3.10)
project(calculatorX)
option(use_myCalculator "this option used to select my calculatorlib" TRUE)

if(use_myCalculator)
    add_subdirectory(src)
    list(APPEND libs calculator)
    list(APPEND includes include/calculator include/app)
endif()

list(APPEND includes include)

add_executable(calculatorX app/app.cpp)
target_include_directories(calculatorX PUBLIC ${includes})

enable_testing()
add_subdirectory(test)
include(CTest)

target_link_libraries(calculatorX PUBLIC ${libs})
find_package(fmt REQUIRED CONFIG)
target_link_libraries(calculatorX PUBLIC fmt::fmt)