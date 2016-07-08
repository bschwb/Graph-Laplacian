#ifndef GRAPH_LAPLACIAN_HPP_
#define GRAPH_LAPLACIAN_HPP_

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/numeric/ublas/matrix.hpp>

using Graph = boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS>;
using Matrix = boost::numeric::ublas::matrix<int>;

Matrix graph_laplacian(const Graph& g)
{
  using size_type = graph_traits<Graph>::vertices_size_type;

  const size_type nv = num_vertices(g);
  return Matrix(nv, nv, 0);
}

#endif  // GRAPH_LAPLACIAN_HPP_
