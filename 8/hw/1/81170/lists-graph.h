//
// Created by Dimitar Uzunov on 12/25/15.
//

#ifndef LISTS_GRAPH_H
#define LISTS_GRAPH_H

#include <vector>
#include <list>
#include <iostream>
#include "matrix-graph.h"
#include "edges-graph.h"

using std::vector;
using std::list;
using std::ostream;

class MatrixGraph;
class EdgesGraph;

class ListsGraph {
  vector<list<size_t>> adjLists;

public:

  ListsGraph(const vector<list<size_t>>& adjLists);
  ListsGraph(const MatrixGraph& mg);
  ListsGraph(const EdgesGraph& eg);

  const vector<list<size_t>>& getLists() const;
  size_t vertexCount() const;
  bool adjacent(size_t v1, size_t v2) const;
  bool isPath(const vector<size_t>& vs) const;
};

ostream& operator<<(ostream& os, const ListsGraph& g);

#endif