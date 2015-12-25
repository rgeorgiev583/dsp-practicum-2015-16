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
  vector<vector<bool>> adjMatrix;

public:

  MatrixGraph(const vector<vector<bool>>& adjMatrix);
  MatrixGraph(const ListsGraph& lg);
  MatrixGraph(const EdgesGraph& eg);

  const vector<vector<bool>>& getMatrix() const;
  size_t vertexCount() const;
  bool adjacent(size_t v1, size_t v2) const;
  bool isPath(const vector<size_t>& vs) const;
};

ostream& operator<<(ostream& os, const MatrixGraph& g);

#endif