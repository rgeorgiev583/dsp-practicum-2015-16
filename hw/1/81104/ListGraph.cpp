#include "ListGraph.h"

ListGraph::ListGraph(int vertexCount) : neighbourLists(vertexCount) {}

ListGraph::ListGraph(const vector<list<int> >& neighbourLists) :
  neighbourLists(neighbourLists) {}

ListGraph::ListGraph(const MatrixGraph& matrixGraph) {
  int vertexCount = matrixGraph.vertexCount();
  neighbourLists = vector<list<int> >(vertexCount, list<int>());
  for (int j = 0, edgesCount = matrixGraph.edgesCount(); j < edgesCount; ++j) {
    int v1;
    int v2;
    for (int i = 0; i < vertexCount; ++i) {
      if (matrixGraph.getMatrix()[i][j] == -1) {
        v1 = i;
      } else if (matrixGraph.getMatrix()[i][j] == 1) {
        v2 = i;
      }
    }
    neighbourLists[v1].push_back(v2);
  }
}

ListGraph::ListGraph(const EdgeGraph& edgeGraph) {
  neighbourLists = vector<list<int> >(edgeGraph.vertexCount(), list<int>());
  for (auto edge : edgeGraph.getEdges()) {
    neighbourLists[edge.first].push_back(edge.second);
  }
}

const vector<list<int> >& ListGraph::getLists() const {
  return neighbourLists;
}

int ListGraph::vertexCount() const {
  return neighbourLists.size();
}

int ListGraph::edgesCount() const {
  int sum = 0;
  for (auto l : neighbourLists) {
    sum += l.size();
  }
  return sum;
}

void ListGraph::addVertex(const list<int>& neighbourList) {
  neighbourLists.push_back(neighbourList);
}

void ListGraph::addEdge(int from, int to) {
  neighbourLists[from].push_back(to);
}

bool ListGraph::neighbour(int v1, int v2) const {
  for (auto v : neighbourLists[v1]) {
    if (v2 == v) {
      return true;
    }
  }
  return false;
}

bool ListGraph::isPath(const vector<int>& vertices) const {
  auto last = --(vertices.end());
  auto it = vertices.begin();

  while (it != last) {
    if (!neighbour(*it, *(++it))) {
      return false;
    }
  }

  return true;
}

ostream& operator<<(ostream& os, const ListGraph& listGraph) {
  for (int i = 0, len = listGraph.vertexCount(); i < len; ++i) {
    os << i << ": ";
    for (auto v : listGraph.getLists()[i]) {
      os << v << ' ';
    }
    os << '\n';
  }

  return os;
}
