cmake_minimum_required(VERSION 3.13)
project(Alghoritms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
add_executable(Alghoritms
        InsertionSortDescEnumerator.cpp
        InsertionSortDescEnumerator.h
        InsertionSortEnumerator.cpp
        InsertionSortEnumerator.h
        InsertionSorter.cpp
        InsertionSorter.h
        LifeUniverseEverythingMirror.cpp
        LifeUniverseEverythingMirror.h
        main.cpp)
