cmake_minimum_required(VERSION 3.10)
project(A5_6)

set(CMAKE_CXX_STANDARD 14)

add_executable(A5_6
        main.cpp
        UI/UI.cpp
        UI/UI.h
        Domain/Movie.cpp
        Domain/Movie.h
        Repository/Repository.cpp
        Repository/Repository.h
        Repository/DynamicVector.h
        Service/Service.cpp
        Service/Service.h
        Repository/WatchList.cpp
        Repository/WatchList.h
        Tests/Tests.cpp
        Tests/Tests.h
        )
