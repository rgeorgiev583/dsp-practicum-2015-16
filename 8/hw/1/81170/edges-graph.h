//
// Created by Dimitar Uzunov on 12/25/15.
//

#ifndef EDGES_GRAPH_H
#define EDGES_GRAPH_H

#include <vector>
#include <utility>
#include <iostream>
#include "lists-graph.h"
#include "matrix-graph.h"

using std::vector;
using std::pair;
using std::ostream;

class ListsGraph;
class MatrixGraph;

class EdgesGraph {
  vector<pair<size_t, size_t>> edges;

public:

  EdgesGraph(const vector<pair<size_t, size_t>>& edges);
  EdgesGraph(const ListsGraph& lg);
  EdgesGraph(const MatrixGraph& mg);

  const vector<pair<size_t, size_t>>& getEdges() const;
  size_t vertexCount() const;
  size_t edgesCount() const;
  bool adjacent(size_t v1, size_t v2) const;
  bool isPath(const vector<size_t>& vs) const;
};

ostream& operator<<(ostream& os, const EdgesGraph& g);

#endif