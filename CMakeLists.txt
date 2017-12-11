cmake_minimum_required(VERSION 2.6)
project(reversi)

include_directories(include/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)
add_executable (reversi src/main.cpp)
