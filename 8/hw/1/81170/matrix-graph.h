//
// Created by Dimitar Uzunov on 12/25/15.
//

#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include "lists-graph.h"
#include "edges-graph.h"

using std::vector;
using std::list;
using std::pair;
using std::ostream;

class ListsGraph;
class EdgesGraph;

class MatrixGraph {
  vector<vector<int>> incMatrix;

public:

  MatrixGraph(const vector<vector<int>>& incMatrix);
  MatrixGraph(const ListsGraph& lg);
  MatrixGraph(const EdgesGraph& eg);

  const vector<vector<int>>& getMatrix() const;
  size_t vertexCount() const;
  size_t edgesCount() const;
  bool adjacent(size_t v1, size_t v2) const;
  bool adjacentFrom(size_t from, size_t to) const;
  bool isPath(const vector<size_t>& vs) const;
};

ostream& operator<<(ostream& os, const MatrixGraph& g);

#endif