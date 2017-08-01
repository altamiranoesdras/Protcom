cmake_minimum_required(VERSION 3.6)
project(protCom)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT_PATH .)

add_executable(Inicio Inicio.cpp)
add_executable(Interfaz Interfaz.cpp)
add_executable(Emisor Emisor.cpp)
add_executable(Receptor Receptor.cpp)
add_executable(Ejecutor Ejecutor.cpp)