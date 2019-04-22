cmake_minimum_required(VERSION 3.13)
project(CppEducation)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES ArraysAndStrings/Q02.cpp ArraysAndStrings/Q01.cpp ArraysAndStrings/Q03.cpp ArraysAndStrings/Q04.cpp)

add_executable(Q02 ArraysAndStrings/Q02.cpp)
add_executable(Q01 ArraysAndStrings/Q01.cpp)
add_executable(Q03 ArraysAndStrings/Q03.cpp)
add_executable(Q04 ArraysAndStrings/Q04.cpp)