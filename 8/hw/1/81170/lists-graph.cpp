//
// Created by Dimitar Uzunov on 12/25/15.
//

#include "lists-graph.h"

ListsGraph::ListsGraph(size_t vertexCount) : adjLists(vertexCount) {}

ListsGraph::ListsGraph(const vector<list<size_t>>& adjLists) :
  adjLists(adjLists) {}

ListsGraph::ListsGraph(const MatrixGraph& mg) {
  size_t vertexCount = mg.vertexCount();
  adjLists = vector<list<size_t>>(vertexCount, list<size_t>());
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
    adjLists[v1].push_back(v2);
  }
}

ListsGraph::ListsGraph(const EdgesGraph& eg) {
  adjLists = vector<list<size_t>>(eg.vertexCount(), list<size_t>());
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

size_t ListsGraph::edgesCount() const {
  size_t sum = 0;
  for (auto l : adjLists) {
    sum += l.size();
  }
  return sum;
}

void ListsGraph::addVertex(const list<size_t>& adjList) {
  adjLists.push_back(adjList);
}

void ListsGraph::addEdge(size_t from, size_t to) {
  adjLists[from].push_back(to);
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