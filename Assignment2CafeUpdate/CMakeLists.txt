cmake_minimum_required(VERSION 2.8)

project(Assignment2CafeUpdate)

INCLUDE_DIRECTORIES(includes/)

SET(CMAKE_CXX_FLAGS -std=c++11)

add_executable(app main.cpp Cafe.cpp)