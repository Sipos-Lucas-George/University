cmake_minimum_required(VERSION 3.21)
project(Practice)

set(CMAKE_CXX_STANDARD 14)

add_executable(Practice main.cpp Block.cpp Block.h House.cpp House.h Buildings.cpp Buildings.h Service.cpp Service.h UI.cpp UI.h)
