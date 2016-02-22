#ifndef MATRIXGRAPH_H_INCLUDED
#define MATRIXGRAPH_H_INCLUDED

#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include "ListGraph.h"
#include "EdgeGraph.h"

using namespace std;

class ListGraph;
class EdgeGraph;

class MatrixGraph {
  vector<vector<int> > iMatrix;

public:

  MatrixGraph(const vector<vector<int> >&);
  MatrixGraph(const ListGraph&);
  MatrixGraph(const EdgeGraph&);

  const vector<vector<int> >& getMatrix() const;
  int vertexCount() const;
  int edgesCount() const;
  bool neighbour(int, int) const;
  bool neighbourFrom(int, int) const;
  bool isPath(const vector<int>&) const;
};

ostream& operator<<(ostream&, const MatrixGraph&);

#endif // MATRIXGRAPH_H_INCLUDED
