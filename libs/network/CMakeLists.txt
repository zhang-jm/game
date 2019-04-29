cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
cmake_policy(VERSION 3.2)

set(NETWORK_HEADERS "incl")

file(GLOB NETWORK_SOURCES src/*.cpp)
add_library(network ${NETWORK_SOURCES})

target_include_directories(network PRIVATE ${NETWORK_HEADERS})