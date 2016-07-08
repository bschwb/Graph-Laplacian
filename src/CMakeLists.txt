add_library(graph_laplacian SHARED
  graph_laplacian.cpp graph_laplacian.hpp)

set_property(TARGET graph_laplacian PROPERTY CXX_STANDARD 11)
set_property(TARGET graph_laplacian PROPERTY CXX_STANDARD_REQUIRED ON)
