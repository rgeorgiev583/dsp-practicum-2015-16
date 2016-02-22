#include "EdgeGraph.h"

EdgeGraph::EdgeGraph(const vector<pair<int, int> >& edges) : edges(edges) {}

EdgeGraph::EdgeGraph(const ListGraph& listGraph) {
  for (int i = 0, vertexCount = listGraph.vertexCount(); i < vertexCount; ++i) {
    for (auto v : listGraph.getLists()[i]) {
      edges.push_back(pair<int, int>(i, v));
    }
  }
}

EdgeGraph::EdgeGraph(const MatrixGraph& matrixGraph) {
  int vertexCount = matrixGraph.vertexCount();
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
    edges.push_back(pair<int, int>(v1, v2));
  }
}

const vector<pair<int, int> >& EdgeGraph::getEdges() const {
  return edges;
}

int EdgeGraph::vertexCount() const {
  if (edges.size() == 0) {
    return 0;
  }

  int count = edges[0].first;

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

int EdgeGraph::edgesCount() const {
  return edges.size();
}

bool EdgeGraph::neighbour(int v1, int v2) const {
  for (auto edge : edges) {
    if (v1 == edge.first && v2 == edge.second) {
      return true;
    }
  }

  return false;
}

bool EdgeGraph::isPath(const vector<int>& vertices) const {
  auto last = --(vertices.end());
  auto it = vertices.begin();

  while (it != last) {
    if (!neighbour(*it, *(++it))) {
      return false;
    }
  }

  return true;
}

ostream& operator<<(ostream& os, const EdgeGraph& edgeGraph) {
  for (auto edge : edgeGraph.getEdges()) {
    os << edge.first << " -> " << edge.second << '\n';
  }

  return os;
}
