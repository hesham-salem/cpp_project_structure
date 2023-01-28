project(testing)

find_package(GTest REQUIRED)

add_executable(unit_test calculator_test.cpp)
include_directories(${CMAKE_SOURCE_DIR}/include)
target_link_libraries(unit_test PUBLIC calculator GTest::GTest)

add_test(NAME unit_test COMMAND unit_test)
