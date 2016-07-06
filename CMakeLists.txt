cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(graph-laplace CXX)

add_subdirectory(src)

include(CTest)
add_subdirectory(tests)
