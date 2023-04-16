cmake_minimum_required(VERSION 3.1)

project(client)

set(CMAKE_CXX_STANDARD 11)
find_package(Boost REQUIRED COMPONENTS thread system serialization)

add_executable(client client.cpp)

target_link_libraries(client PUBLIC ${Boost_LIBRARIES})
