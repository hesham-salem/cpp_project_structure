cmake_minimum_required(VERSION 3.10)
project(calculator_server)
option(use_myCalculator "this option used to select my calculatorlib" TRUE)

if(use_myCalculator)
    add_subdirectory(src)
    list(APPEND libs calculator)
    list(APPEND includes include/calculator )
endif()

list(APPEND includes include)

find_package(Boost REQUIRED COMPONENTS thread system serialization)

add_executable(calculator_server server.cpp)
target_include_directories(calculator_server PUBLIC ${includes})

enable_testing()
add_subdirectory(test)
include(CTest)

target_link_libraries(calculator_server PUBLIC ${libs})
find_package(fmt REQUIRED CONFIG)
target_link_libraries(calculator_server PUBLIC fmt::fmt ${Boost_LIBRARIES})

