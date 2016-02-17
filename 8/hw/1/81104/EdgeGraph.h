#ifndef EDGEGRAPH_H_INCLUDED
#define EDGEGRAPH_H_INCLUDED

#include <vector>
#include <utility>
#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"

using namespace std;

class ListGraph;
class MatrixGraph;

class EdgeGraph {
  vector<pair<int, int> > edges;

public:

  EdgeGraph(const vector<pair<int, int> >&);
  EdgeGraph(const ListGraph&);
  EdgeGraph(const MatrixGraph&);

  const vector<pair<int, int>>& getEdges() const;
  int vertexCount() const;
  int edgesCount() const;
  bool neighbour(int, int) const;
  bool isPath(const vector<int>&) const;
};

ostream& operator<<(ostream&, const EdgeGraph&);

#endif // EDGEGRAPH_H_INCLUDED
