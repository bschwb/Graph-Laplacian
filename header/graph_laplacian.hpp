#ifndef GRAPH_LAPLACIAN_HPP_
#define GRAPH_LAPLACIAN_HPP_

#include <tuple>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/numeric/ublas/matrix.hpp>

using Graph = boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS>;
using Matrix = boost::numeric::ublas::matrix<int>;

Matrix graph_laplacian(const Graph& g)
{
  using namespace boost;
  const auto nv = num_vertices(g);
  Matrix mat(nv, nv, 0);

  auto index = get(vertex_index, g);

  using vertex_iter = graph_traits<Graph>::vertex_iterator;
  vertex_iter vi, vi_end;

  using adj_iter = graph_traits<Graph>::adjacency_iterator;
  adj_iter ai, ai_end;

  for (std::tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi) {
    auto v = *vi;
    auto v_index = index[v];
    mat(v_index, v_index) = degree(v, g);
    for (std::tie(ai, ai_end) = adjacent_vertices(v, g); ai != ai_end; ++ai) {
      mat(v_index, index[*ai]) = -1;
    }
  }

  return mat;
}

#endif  // GRAPH_LAPLACIAN_HPP_
