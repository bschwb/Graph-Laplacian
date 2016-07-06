add_library(graph_laplace SHARED
  graph_laplace.cpp graph_laplace.hpp)

set_property(TARGET graph_laplace PROPERTY CXX_STANDARD 11)
set_property(TARGET graph_laplace PROPERTY CXX_STANDARD_REQUIRED ON)
