cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(graph-laplacian CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wnon-virtual-dtor -pedantic -Wshadow \
-Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wconversion -Wsign-conversion \
-Wmisleading-indentation -Weffc++")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS graph unit_test_framework REQUIRED)

include(CTest)
add_subdirectory(tests)
