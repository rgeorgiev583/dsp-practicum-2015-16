#ifndef LISTGRAPH_H_INCLUDED
#define LISTGRAPH_H_INCLUDED

#include <vector>
#include <list>
#include <iostream>
#include "MatrixGraph.h"
#include "EdgeGraph.h"

using namespace std;

class MatrixGraph;
class EdgeGraph;

class ListGraph {
  vector<list<int> > neighbourLists;
public:
  ListGraph(int vertexCount = 0);
  ListGraph(const vector<list<int> >&);
  ListGraph(const MatrixGraph&);
  ListGraph(const EdgeGraph&);
  const vector<list<int> >& getLists() const;
  int vertexCount() const;
  int edgesCount() const;
  void addVertex(const list<int>& neighbourList = list<int>());
  void addEdge(int, int);
  bool neighbour(int, int) const;
  bool isPath(const vector<int>&) const;
};

ostream& operator<<(ostream& os, const ListGraph& g);

#endif // LISTGRAPH_H_INCLUDED
