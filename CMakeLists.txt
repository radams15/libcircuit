cmake_minimum_required(VERSION 3.9)

project(circuit VERSION 1.0.1 DESCRIPTION "MNA Circuit Solving Library" LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_SOURCES 
        src/main/Equation.cc
        src/main/Equation.h
        src/main/MNACircuit.cc
        src/main/MNACircuit.h
        src/main/MNAComponent.cc
        src/main/MNAComponent.h
        src/main/MNASolution.cc
        src/main/MNASolution.h
        src/main/MNA.h
        src/main/Unknown.cc
        src/main/Unknown.h
        src/main/Term.cc
        src/main/Term.h
)

set(API_SRC
	api/MNACircuit.h
	api/MNAComponent.h
	api/MNASolution.h
	api/Term.h
	api/Unknown.h
)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/cpp_bindgen)

add_library(circuit SHARED ${PROJECT_SOURCES})
bindgen_add_library(ccircuit SOURCES ${API_SRC})

target_compile_options(circuit PRIVATE -Wall -Wextra -Wpedantic)

set(EIGEN3_ROOT ${CMAKE_SOURCE_DIR}/lib/eigen)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/lib)

find_package(Eigen3 3.3.7 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

set_target_properties(circuit PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER src/main/MNA.h)

configure_file(circuit.pc.in circuit.pc @ONLY)

install(TARGETS circuit
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${API_SRC} DESTINATION include/circuit)

install(FILES ${CMAKE_BINARY_DIR}/circuit.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
