#define BOOST_TEST_MODULE GraphLaplacian
#include <boost/test/unit_test.hpp>

#include <utility>
#include <vector>

#include <boost/graph/adjacency_list.hpp>

#include <boost/numeric/ublas/assignment.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include <graph_laplacian.hpp>


// An matrix equality check copied from: http://lists.boost.org/Archives/boost/2005/11/96235.php
template<class E>
bool equal(boost::numeric::ublas::matrix<E> lhs, boost::numeric::ublas::matrix<E> rhs)
{
  if (&lhs == &rhs) { return true; }
  if (lhs.size1() != rhs.size1()) { return false; }
  if (lhs.size2() != rhs.size2()) { return false; }
  typename boost::numeric::ublas::matrix<E>::iterator1 l(lhs.begin1());
  typename boost::numeric::ublas::matrix<E>::iterator1 r(rhs.begin1());
  while (l != lhs.end1()) {
    if (*l != *r) { return false; }
    ++l;
    ++r;
  }
  return true;
}

using Graph = boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS>;

BOOST_AUTO_TEST_SUITE(TestGraphLaplacian)

// An empty graph produces an empty matrix
BOOST_AUTO_TEST_CASE(EmptyGraphTest)
{
  Graph g;

  BOOST_CHECK(equal(graph_laplacian(g), boost::numeric::ublas::matrix<int>(0, 0)));
}

// A graph with n vertices and no edges produces an (n x n)-zero matrix
BOOST_AUTO_TEST_CASE(NoEdgesTest)
{
  Graph g(5);

  BOOST_CHECK(equal(graph_laplacian(g), boost::numeric::ublas::matrix<int>(5, 5, 0)));
}

// A graph with two vertices and an edge connecting them produces the following Laplacian matrix:
//  1 -1
// -1  1
BOOST_AUTO_TEST_CASE(TwoVerticesOneEdgeGraphTest)
{
  using Edge = std::pair<int, int>;
  std::vector<Edge> edges { Edge(0, 1) };
  Graph g(edges.begin(), edges.end(), 2);

  boost::numeric::ublas::matrix<int> expected_mat(2, 2);
  expected_mat <<=  1, -1,
                   -1,  1;

  BOOST_CHECK(equal(graph_laplacian(g), expected_mat));
}

// A free tree on 3 vertices (vertex 1 is the center vertex) produces following Laplacian matrix:
//  1 -1  0
// -1  2 -1
//  0 -1  1
BOOST_AUTO_TEST_CASE(ThreeVerticesFreeTreeTest)
{
  using Edge = std::pair<int, int>;
  std::vector<Edge> edges { Edge(0, 1), Edge(1, 2) };
  Graph g(edges.begin(), edges.end(), 3);

  boost::numeric::ublas::matrix<int> expected_mat(3, 3);
  expected_mat <<=  1, -1,  0,
                   -1,  2, -1,
                    0, -1,  1;

  BOOST_CHECK(equal(graph_laplacian(g), expected_mat));
}

// A free tree on 4 vertices (vertices 1, 2 are the middle vertices) produces following
// Laplacian matrix:
//  1 -1  0  0
// -1  2 -1  0
//  0 -1  2 -1
//  0  0 -1  1
BOOST_AUTO_TEST_CASE(FourVerticesFreeTreeTest)
{
  using Edge = std::pair<int, int>;
  std::vector<Edge> edges { Edge(0, 1), Edge(1, 2), Edge(2, 3) };
  Graph g(edges.begin(), edges.end(), 4);

  boost::numeric::ublas::matrix<int> expected_mat(4, 4);
  expected_mat <<=  1, -1,  0,  0,
                   -1,  2, -1,  0,
                    0, -1,  2, -1,
                    0,  0, -1,  1;

  BOOST_CHECK(equal(graph_laplacian(g), expected_mat));
}

// A graph forming a square with 4 vertices produces follwoing Laplacian matrix:
//  2 -1  0 -1
// -1  2 -1  0
//  0 -1  2 -1
// -1  0 -1  2
BOOST_AUTO_TEST_CASE(SquareTest)
{
  using Edge = std::pair<int, int>;
  std::vector<Edge> edges { Edge(0, 1), Edge(1, 2), Edge(2, 3), Edge(3, 0) };
  Graph g(edges.begin(), edges.end(), 4);

  boost::numeric::ublas::matrix<int> expected_mat(4, 4);
  expected_mat <<=  2, -1,  0, -1,
                   -1,  2, -1,  0,
                    0, -1,  2, -1,
                   -1,  0, -1,  2;

  BOOST_CHECK(equal(graph_laplacian(g), expected_mat));
}

BOOST_AUTO_TEST_SUITE_END()  // TestGraphLaplacian
