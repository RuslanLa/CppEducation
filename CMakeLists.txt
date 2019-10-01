cmake_minimum_required(VERSION 3.14)
project(CppEducationTests)

set(CMAKE_CXX_STANDARD 17)

include(cmake/Catch.cmake)

find_package(Catch2 REQUIRED)
include_directories("contrib")
include_directories("util")
add_subdirectory(arrays_and_strings)
add_subdirectory(linked_list)