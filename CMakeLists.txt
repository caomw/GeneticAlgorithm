cmake_minimum_required(VERSION 2.8)

project(main)

set(CMAKE_CXX_COMPILER "clang++")

add_definitions("-std=c++11")
add_executable(main main.cpp GA.cpp GeneticOperator.cpp individual.cpp)

target_link_libraries(main)
