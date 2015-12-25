//
// Created by Dimitar Uzunov on 12/25/15.
//

#include "lists-graph.h"

ListsGraph::ListsGraph(const vector<list<size_t>>& adjLists) : adjLists(adjLists) {}

ListsGraph::ListsGraph(const MatrixGraph& mg) {
  size_t len = mg.vertexCount();

  for (size_t i = 0; i < len; ++i) {
    adjLists.push_back(list<size_t>());

    for (size_t j = 0; j < len; ++j) {
      if (mg.adjacent(i, j)) {
        adjLists.back().push_back(j);
      }
    }
  }
}

ListsGraph::ListsGraph(const EdgesGraph& eg) {
  size_t len = eg.vertexCount();

  adjLists = vector<list<size_t>>(len, list<size_t>());
  for (auto edge : eg.getEdges()) {
    adjLists[edge.first].push_back(edge.second);
  }
}

const vector<list<size_t>>& ListsGraph::getLists() const {
  return adjLists;
}

size_t ListsGraph::vertexCount() const {
  return adjLists.size();
}

bool ListsGraph::adjacent(size_t v1, size_t v2) const {
  for (auto v : adjLists[v1]) {
    if (v2 == v) {
      return true;
    }
  }
  return false;
}

bool ListsGraph::isPath(const vector<size_t>& vs) const {
  auto last = --(vs.end());
  auto it = vs.begin();

  while (it != last) {
    if (!adjacent(*it, *(++it))) {
      return false;
    }
  }

  return true;
}

ostream& operator<<(ostream& os, const ListsGraph& g) {
  for (size_t i = 0, len = g.vertexCount(); i < len; ++i) {
    os << i << ": ";
    for (auto v : g.getLists()[i]) {
      os << v << ' ';
    }
    os << '\n';
  }

  return os;
}