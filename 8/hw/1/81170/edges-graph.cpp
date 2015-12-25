//
// Created by Dimitar Uzunov on 12/25/15.
//

#include "edges-graph.h"

EdgesGraph::EdgesGraph(const vector<pair<size_t, size_t>>& edges) : edges(edges) {}

EdgesGraph::EdgesGraph(const MatrixGraph& mg) {
  size_t len = mg.vertexCount();

  for (size_t i = 0; i < len; ++i) {
    for (size_t j = 0; j < len; ++j) {
      if (mg.adjacent(i, j)) {
        edges.push_back(pair<size_t, size_t>(i, j));
      }
    }
  }
}

EdgesGraph::EdgesGraph(const ListsGraph& lg) {
  for (size_t i = 0, len = lg.vertexCount(); i < len; ++i) {
    for (auto v : lg.getLists()[i]) {
      edges.push_back(pair<size_t, size_t>(i, v));
    }
  }
}

const vector<pair<size_t, size_t>>& EdgesGraph::getEdges() const {
  return edges;
}

size_t EdgesGraph::vertexCount() const {
  if (edges.size() == 0) {
    return 0;
  }

  size_t count = edges[0].first;

  for (auto edge : edges) {
    if (edge.first > count) {
      count = edge.first;
    }
    if (edge.second > count) {
      count = edge.second;
    }
  }

  return count + 1;
}

bool EdgesGraph::adjacent(size_t v1, size_t v2) const {
  for (auto edge : edges) {
    if (v1 == edge.first && v2 == edge.second) {
      return true;
    }
  }
  return false;
}

bool EdgesGraph::isPath(const vector<size_t>& vs) const {
  auto last = --(vs.end());
  auto it = vs.begin();

  while (it != last) {
    if (!adjacent(*it, *(++it))) {
      return false;
    }
  }

  return true;
}

ostream& operator<<(ostream& os, const EdgesGraph& g) {
  for (auto edge : g.getEdges()) {
    os << edge.first << " -> " << edge.second << '\n';
  }

  return os;
}