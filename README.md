# Graph-Laplacian
Calculate the Laplacian matrix for a BGL-Graph.

## Usage
As the function resides in a header file you can use it without building anything.
Just copy the file from [here](header/graph_laplacian.hpp) or clone the repository
and find the file in the `header` subdirectory
```
git clone git@github.com:BerndSchwarzenbacher/Graph-Laplacian.git
cd Graph-Laplacian/header
```

## Tests
To build and run the tests follow these steps:
```
git clone git@github.com:BerndSchwarzenbacher/Graph-Laplacian.git
cd Graph-Laplacian
mkdir build
cd build
cmake ../
make
ctest
```
