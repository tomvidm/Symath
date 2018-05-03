cmake_minimum_required(VERSION 3.0)

project("Symbolic Math")

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
set(SYMATH_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SYMATH_SRC_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(external/googletest)
add_subdirectory(src)
add_subdirectory(test)