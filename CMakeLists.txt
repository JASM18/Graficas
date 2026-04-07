cmake_minimum_required(VERSION 4.2)
project(Graficas)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Graficas
        Grafica.cpp
        Grafica.hpp
        main.cpp)
