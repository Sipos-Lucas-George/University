cmake_minimum_required(VERSION 3.21)
project(A3)

set(CMAKE_CXX_STANDARD 14)

add_executable(A3 App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        MultiMap.cpp
        MultiMap.h
        MultiMapIterator.cpp
        MultiMapIterator.h
        ShortTest.cpp
        ShortTest.h
        )
