cmake_minimum_required(VERSION 3.28)
project(auto)

set(CMAKE_CXX_STANDARD 17)

add_executable(auto main.cpp
        Vozilo.cpp
        Vozilo.h
        Auto.cpp
        Auto.h
        PorodicnoAuto.cpp
        PorodicnoAuto.h
        SportskoAuto.cpp
        SportskoAuto.h
        Autokuca.cpp
        Autokuca.h)
