#define BOOST_TEST_MODULE GraphLaplacian
#include <boost/test/unit_test.hpp>

#include <utility>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
using namespace boost;

#include <boost/numeric/ublas/assignment.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
using namespace boost::numeric::ublas;

#include <graph_laplacian.hpp>

using Graph = adjacency_list<setS, vecS, undirectedS>;

BOOST_AUTO_TEST_SUITE(TestGraphLaplacian)

//// An empty graph produces an empty matrix
//BOOST_AUTO_TEST_CASE(EmptyGraphTest)
//{
  //Graph g();

  //BOOST_CHECK_EQUAL(graph_laplacian(g), matrix<int>(0, 0));
//}

//// A graph with n vertices and no edges produces an (n x n)-zero matrix
//BOOST_AUTO_TEST_CASE(NoEdgesTest)
//{
  //Graph g(5);

  //BOOST_CHECK_EQUAL(graph_laplacian(g), zero_matrix<int>(5, 5));
//}

//// A graph with two vertices and an edge connecting them produces the following Laplacian matrix:
////  1 -1
//// -1  1
//BOOST_AUTO_TEST_CASE(TwoVerticesOneEdgeGraphTest)
//{
  //using Edge = std::pair<int, int>;
  //std::vector<Edge> edges { Edge(0, 1) };
  //Graph g(edges.begin(), edges.end(), 2);

  //matrix<int> expected_mat(2, 2);
  //expected_mat <<=  1, -1,
                   //-1,  1;

  //BOOST_CHECK_EQUAL(graph_laplacian(g), expected_mat);
//}

//// A free tree on 3 vertices (vertex 1 is the center vertex) produces following Laplacian matrix:
////  1 -1  0
//// -1  2 -1
////  0 -1  1
//BOOST_AUTO_TEST_CASE(ThreeVerticesFreeTreeTest)
//{
  //using Edge = std::pair<int, int>;
  //std::vector<Edge> edges { Edge(0, 1), Edge(1, 2) };
  //Graph g(edges.begin(), edges.end(), 3);

  //matrix<int> expected_mat(3, 3);
  //expected_mat <<=  1, -1,  0,
                   //-1,  2, -1,
                    //0, -1,  1;

  //BOOST_CHECK_EQUAL(graph_laplacian(g), expected_mat);
//}

//// A free tree on 4 vertices (vertices 1, 2 are the middle vertices) produces following
//// Laplacian matrix:
////  1 -1  0  0
//// -1  2 -1  0
////  0 -1  2 -1
////  0  0 -1  1
//BOOST_AUTO_TEST_CASE(FourVerticesFreeTreeTest)
//{
  //using Edge = std::pair<int, int>;
  //std::vector<Edge> edges { Edge(0, 1), Edge(1, 2), Edge(2, 3) };
  //Graph g(edges.begin(), edges.end(), 4);

  //matrix<int> expected_mat(4, 4);
  //expected_mat <<=  1, -1,  0,  0,
                   //-1,  2, -1,  0,
                    //0, -1,  2, -1,
                    //0,  0, -1,  1;

  //BOOST_CHECK_EQUAL(graph_laplacian(g), expected_mat);
//}

//// A graph forming a square with 4 vertices produces follwoing Laplacian matrix:
////  2 -1  0 -1
//// -1  2 -1  0
////  0 -1  2 -1
//// -1  0 -1  2
//BOOST_AUTO_TEST_CASE(SquareTest)
//{
  //using Edge = std::pair<int, int>;
  //std::vector<Edge> edges { Edge(0, 1), Edge(1, 2), Edge(2, 3) };
  //Graph g(edges.begin(), edges.end(), 4);

  //matrix<int> expected_mat(4, 4);
  //expected_mat <<=  2, -1,  0, -1,
                   //-1,  2, -1,  0,
                    //0, -1,  2, -1,
                   //-1,  0, -1,  2;

  //BOOST_CHECK_EQUAL(graph_laplacian(g), expected_mat);
//}

BOOST_AUTO_TEST_SUITE_END()  // TestGraphLaplacian
