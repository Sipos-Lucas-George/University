cmake_minimum_required(VERSION 3.21)
project(t1_916_Lucas_Sipos_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Domain)

add_executable(t1_916_Lucas_Sipos_1
        Domain/Player.cpp
        Domain/Player.h
        Repository/Repository.cpp
        Repository/Repository.h
        Repository/DynamicVector.h
        Service/Service.cpp
        Service/Service.h
        UI/UI.cpp
        UI/UI.h
        main.cpp)
