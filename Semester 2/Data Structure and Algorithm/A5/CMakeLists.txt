cmake_minimum_required(VERSION 3.21)
project(A5)

set(CMAKE_CXX_STANDARD 14)

add_executable(A5 App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMMIterator.cpp
        SMMIterator.h
        SortedMultiMap.cpp
        SortedMultiMap.h)
