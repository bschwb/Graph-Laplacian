cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(graph-laplace CXX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS graph unit_test_framework REQUIRED)

add_subdirectory(src)

include(CTest)
add_subdirectory(tests)
