//
// Created by Dimitar Uzunov on 12/25/15.
//

#include "edges-graph.h"

EdgesGraph::EdgesGraph(const vector<pair<size_t, size_t>>& edges) : edges(edges) {}

EdgesGraph::EdgesGraph(const ListsGraph& lg) {
  for (size_t i = 0, vertexCount = lg.vertexCount(); i < vertexCount; ++i) {
    for (auto v : lg.getLists()[i]) {
      edges.push_back(pair<size_t, size_t>(i, v));
    }
  }
}

EdgesGraph::EdgesGraph(const MatrixGraph& mg) {
  size_t vertexCount = mg.vertexCount();
  for (size_t j = 0, edgesCount = mg.edgesCount(); j < edgesCount; ++j) {
    size_t v1;
    size_t v2;
    for (size_t i = 0; i < vertexCount; ++i) {
      if (mg.getMatrix()[i][j] == -1) {
        v1 = i;
      } else if (mg.getMatrix()[i][j] == 1) {
        v2 = i;
      }
    }
    edges.push_back(pair<size_t, size_t>(v1, v2));
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

size_t EdgesGraph::edgesCount() const {
  return edges.size();
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