#ifndef GRAPH_LAPLACIAN_HPP_
#define GRAPH_LAPLACIAN_HPP_

#include <type_traits>
#include <tuple>

#include <boost/mpl/not.hpp>
#include <boost/concept_check.hpp>
#include <boost/graph/graph_concepts.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/numeric/ublas/matrix.hpp>

using Matrix = boost::numeric::ublas::matrix<int>;

template <typename VertexListGraph>
Matrix graph_laplacian(const VertexListGraph& g)
{
  using namespace boost;

  BOOST_CONCEPT_ASSERT(( VertexListGraphConcept<VertexListGraph> ));
  static_assert(
      is_undirected_graph<VertexListGraph>::value,
      "Directed graphs are not supported.");
  static_assert(
      boost::mpl::not_<is_multigraph<VertexListGraph>>::value,
      "Multigraphs are not supported.");

  using GraphTraits = graph_traits<VertexListGraph>;

  const auto nv = num_vertices(g);
  Matrix mat(nv, nv, 0);

  auto index = get(vertex_index, g);

  using vertex_iter = typename GraphTraits::vertex_iterator;
  vertex_iter vi, vi_end;

  using adj_iter = typename GraphTraits::adjacency_iterator;
  adj_iter ai, ai_end;

  for (std::tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi) {
    auto v = *vi;
    auto v_index = index[v];
    mat(v_index, v_index) = static_cast<int>(degree(v, g));
    for (std::tie(ai, ai_end) = adjacent_vertices(v, g); ai != ai_end; ++ai) {
      mat(v_index, index[*ai]) = -1;
    }
  }

  return mat;
}

#endif  // GRAPH_LAPLACIAN_HPP_
