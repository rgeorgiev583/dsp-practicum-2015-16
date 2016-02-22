//
// Created by Dimitar Uzunov on 12/25/15.
//

#include "matrix-graph.h"

MatrixGraph::MatrixGraph(const vector<vector<int>>& incMatrix) :
  incMatrix(incMatrix) {}

MatrixGraph::MatrixGraph(const ListsGraph& lg) {
  size_t edgesCount = lg.edgesCount();
  size_t vertexCount = lg.vertexCount();
  incMatrix = vector<vector<int>>(vertexCount, vector<int>(edgesCount, 0));
  size_t edge = 0;
  for (size_t i = 0; i < vertexCount; ++i) {
    for (auto v : lg.getLists()[i]) {
      incMatrix[i][edge] = -1;
      incMatrix[v][edge] = 1;
      ++edge;
    }
  }
}

MatrixGraph::MatrixGraph(const EdgesGraph& eg) {
  size_t vertexCount = eg.vertexCount();
  size_t edgesCount = eg.edgesCount();
  incMatrix = vector<vector<int>>(vertexCount, vector<int>(edgesCount, 0));
  size_t edgeIndex = 0;
  for (auto edge : eg.getEdges()) {
    incMatrix[edge.first][edgeIndex] = -1;
    incMatrix[edge.second][edgeIndex] = 1;
    ++edgeIndex;
  }
}

const vector<vector<int>>& MatrixGraph::getMatrix() const {
  return incMatrix;
}

size_t MatrixGraph::vertexCount() const {
  return incMatrix.size();
}

size_t MatrixGraph::edgesCount() const {
  return vertexCount() ? incMatrix[0].size() : 0;
}

bool MatrixGraph::adjacent(size_t v1, size_t v2) const {
  for (size_t i = 0, len = edgesCount(); i < len; ++i) {
    if (incMatrix[v1][i] && incMatrix[v2][i]) {
      return true;
    }
  }

  return false;
}

bool MatrixGraph::adjacentFrom(size_t from, size_t to) const {
  for (size_t i = 0, len = edgesCount(); i < len; ++i) {
    if (incMatrix[from][i] == -1 && incMatrix[to][i]) {
      return true;
    }
  }

  return false;
}

bool MatrixGraph::isPath(const vector<size_t>& vs) const {
  auto last = --(vs.end());
  auto it = vs.begin();

  while (it != last) {
    if (!adjacentFrom(*it, *(++it))) {
      return false;
    }
  }

  return true;
}

ostream& operator<<(ostream& os, const MatrixGraph& g) {
  for (size_t i = 0, vCount = g.vertexCount(); i < vCount; ++i) {
    for (size_t j = 0, eCount = g.edgesCount(); j < eCount; ++j) {
      os << g.getMatrix()[i][j] << ' ';
    }
    os << '\n';
  }

  return os;
}