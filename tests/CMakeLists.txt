add_executable(test_graph_laplacian
  test_graph_laplacian.cpp)

set_property(TARGET test_graph_laplacian PROPERTY CXX_STANDARD 11)
set_property(TARGET test_graph_laplacian PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(test_graph_laplacian
  PRIVATE "${CMAKE_SOURCE_DIR}/header" ${Boost_INCLUDE_DIRS})
target_link_libraries(test_graph_laplacian ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME unit_tests COMMAND test_graph_laplacian)
