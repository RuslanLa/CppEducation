cmake_minimum_required(VERSION 3.14)
project(CppEducationTests)

set(CMAKE_CXX_STANDARD 17)

include(cmake/Catch.cmake)

find_package(Catch2 REQUIRED)
include_directories("contrib")
add_subdirectory(arrays_and_strings)