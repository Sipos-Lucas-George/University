cmake_minimum_required(VERSION 3.21)
project(A4)

set(CMAKE_CXX_STANDARD 14)

add_executable(A4 App.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.h
        ExtendedTest.cpp
        ShortTest.h
        ShortTest.cpp
        )
