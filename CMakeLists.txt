cmake_minimum_required(VERSION 3.6)
project(protCom)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Interfaz.cpp Emisor.cpp)
add_executable(protCom ${SOURCE_FILES})