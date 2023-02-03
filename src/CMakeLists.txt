
add_library(calculator calculator.cpp)
find_package(fmt)
target_link_libraries(calculator PUBLIC fmt::fmt)
target_include_directories(calculator
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include/calculator
)