cmake_minimum_required(VERSION 3.13)
project(CppEducation)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES ArraysAndStrings/Q02.cpp ArraysAndStrings/Q01.cpp ArraysAndStrings/Q03.cpp ArraysAndStrings/Q04.cpp ArraysAndStrings/Q05.cpp ArraysAndStrings/Q06.cpp ArraysAndStrings/Q07.cpp rraysAndStrings/Q08.cpp)

add_executable(Q02 ArraysAndStrings/Q02.cpp ArraysAndStrings/ArrayUtils.cpp ArraysAndStrings/ArrayUtils.h)
add_executable(Q01 ArraysAndStrings/Q01.cpp ArraysAndStrings/ArrayUtils.cpp ArraysAndStrings/ArrayUtils.h)
add_executable(Q03 ArraysAndStrings/Q03.cpp ArraysAndStrings/ArrayUtils.cpp ArraysAndStrings/ArrayUtils.h)
add_executable(Q04 ArraysAndStrings/Q04.cpp ArraysAndStrings/ArrayUtils.cpp ArraysAndStrings/ArrayUtils.h)
add_executable(Q05 ArraysAndStrings/Q05.cpp ArraysAndStrings/ArrayUtils.cpp ArraysAndStrings/ArrayUtils.h)
add_executable(Q06 ArraysAndStrings/Q06.cpp ArraysAndStrings/ArrayUtils.cpp ArraysAndStrings/ArrayUtils.h)
add_executable(Q07 ArraysAndStrings/Q07.cpp ArraysAndStrings/ArrayUtils.cpp ArraysAndStrings/ArrayUtils.h)
add_executable(Q08 ArraysAndStrings/Q08.cpp ArraysAndStrings/ArrayUtils.cpp ArraysAndStrings/ArrayUtils.h)