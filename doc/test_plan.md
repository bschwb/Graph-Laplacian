# Graph Laplacian Test Plan
## Feature Check
* Dimension checks
* Direct equality tests against handwritten result matrices for:
    - empty graph -> empty matrix
    - graphs without edges -> zero matrix

## Possible Errors
* Wrong input graph
  - How to check for multiedges in the graph?
      * Start off with `setS` for `OutEdgeList` template parameter and thus multigraphs won't
          compile
  - How to check for loops in the graph?

## Test Enhancements
* QuickCheck-like property testing with randomized test data where sensible
  - Dimension checks
