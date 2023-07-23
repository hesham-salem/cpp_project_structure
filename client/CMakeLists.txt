cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)





project(
  client
  VERSION 0.1.0
  DESCRIPTION "Short description"
  HOMEPAGE_URL "https://example.com/"
  LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----
#add_library(
 # rrr_lib OBJECT
  #source/lib.cpp
#)

#target_include_directories(
 # V ${warning_guard}
 # PUBLIC
 # "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
#)

#target_compile_features(V PUBLIC cxx_std_17)

find_package(nlohmann_json)
find_package(httplib)
find_package(fmt REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread system serialization)
add_executable(client source/client.cpp)
target_link_libraries(client PRIVATE fmt::fmt nlohmann_json::nlohmann_json httplib::httplib ${Boost_LIBRARIES})

# ---- Declare executable ----

#add_executable(rrr::exe ALIAS rrr_exe)
target_include_directories(client PUBLIC ${nlohmann_json_INCLUDE_DIRS} ${httplib_INCLUDE_DIRS})

#set_property(TARGET rrr_exe PROPERTY OUTPUT_NAME rrr)

target_compile_features(client PRIVATE cxx_std_17)

#target_link_libraries(client PRIVATE client_lib)

# ---- Install rules ----
#if(NOT CMAKE_SKIP_INSTALL_RULES)
 # include(cmake/install-rules.cmake)
#endif()

# ---- Developer mode ----
#if(NOT rrr_DEVELOPER_MODE)
 # return()
#elseif(NOT PROJECT_IS_TOP_LEVEL)
 # message(
  #  AUTHOR_WARNING
   # "Developer mode is intended for developers of rrr"
  #)
#endif()

#include(cmake/dev-mode.cmake)
