cmake_minimum_required(VERSION 3.21)
project(libcircuit)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/main)
include_directories(src/main/c)

add_executable(libcircuit
        src/main/Equation.cc
        src/main/Equation.h
        src/main/main.cpp
        src/main/MNA.h
        src/main/MNACircuit.cc
        src/main/MNACircuit.h
        src/main/MNAComponent.cc
        src/main/MNAComponent.h
        src/main/MNASolution.cc
        src/main/MNASolution.h
        src/main/Term.cc
        src/main/Term.h
        src/main/Unknown.cc
        src/main/Unknown.h
        )

set(EIGEN3_ROOT ${CMAKE_SOURCE_DIR}/lib/eigen)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/lib)

find_package(Eigen3 3.3.9 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})