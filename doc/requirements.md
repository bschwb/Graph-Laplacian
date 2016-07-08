# Graph Laplace Requirements
## User Need
* The Laplacian matrix of a graph.
https://en.wikipedia.org/wiki/Laplacian_matrix

## Feature
* A function which returns the Laplacian matrix of a simple graph.

### Minimal scope:
* Take a fully specified graph and return a fully specified matrix
    - Input: BGL adjacency_list graph: `adjacency_list<setS, vecS, undirectedS>`
    - Output: uBlas dense matrix

## Feature Enhancements
* Generic input graph interface
* Concept checking
* Different kind of Laplacian matrices
  - Weighted graph
* Generic output matrix interface

## Use Case
```
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#include <boost/graph/adjacency_list.hpp>
using namespace boost;

int main()
{
  using Graph = adjacency_list<setS, vecS, undirectedS>;

  enum { A, B, C, D, E, N };
  const size_t num_vertices = N;

  using Edge = pair<int, int>;
  vector<Edge> edge_array
    { Edge(A, B), Edge(A, D), Edge(C, A), Edge(D, C), Edge(C, E), Edge(B, D), Edge(D, E) };
  Graph g(edge_array.begin(), edge_array.end(), num_vertices);

  auto laplacian_mat = graph_laplacian(g);

  cout << "Laplacian matrix of graph g: " << endl
       << laplacian_mat << endl;

}
```

## API
```
#include <boost/graph/adjacency_list.hpp>
#include <boost/numeric/ublas/matrix.hpp>

using Graph = boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS>;

boost::numeric:ublas::matrix<int> graph_laplacian(Graph g);
```
