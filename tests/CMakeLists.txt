add_executable(test_graph_laplace
  test_graph_laplace.cpp)

set_property(TARGET test_graph_laplace PROPERTY CXX_STANDARD 11)
set_property(TARGET test_graph_laplace PROPERTY CXX_STANDARD_REQUIRED ON)

add_dependencies(test_graph_laplace graph_laplace)
target_include_directories(test_graph_laplace
  PRIVATE "${CMAKE_SOURCE_DIR}/src" ${Boost_INCLUDE_DIRS})
target_link_libraries(test_graph_laplace graph_laplace ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME unit_tests COMMAND test_graph_laplace)
