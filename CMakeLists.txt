cmake_minimum_required(VERSION 3.5.0)
project(P3 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(P3 grafo.cpp main.cpp)

include(CTest)
enable_testing()

