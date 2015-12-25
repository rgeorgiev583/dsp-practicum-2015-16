//
// Created by Dimitar Uzunov on 12/25/15.
//

#include "matrix-graph.h"

MatrixGraph::MatrixGraph(const vector<vector<bool>>& adjMatrix) : adjMatrix(adjMatrix) {}

MatrixGraph::MatrixGraph(const ListsGraph& lg) {
  for (size_t i = 0, len = lg.vertexCount(); i < len; ++i) {
    adjMatrix.push_back(vector<bool>(len, false));

    for (auto v : lg.getLists()[i]) {
      adjMatrix[i][v] = true;
    }
  }
}

MatrixGraph::MatrixGraph(const EdgesGraph& eg) {
  size_t len = eg.vertexCount();

  adjMatrix = vector<vector<bool>>(len, vector<bool>(len, false));
  for (auto edge : eg.getEdges()) {
    adjMatrix[edge.first][edge.second] = true;
  }
}

const vector<vector<bool>>& MatrixGraph::getMatrix() const {
  return adjMatrix;
}

size_t MatrixGraph::vertexCount() const {
  return adjMatrix.size();
}

bool MatrixGraph::adjacent(size_t v1, size_t v2) const {
  return adjMatrix[v1][v2];
}

bool MatrixGraph::isPath(const vector<size_t>& vs) const {
  auto last = --(vs.end());
  auto it = vs.begin();

  while (it != last) {
    if (!adjacent(*it, *(++it))) {
      return false;
    }
  }

  return true;
}

ostream& operator<<(ostream& os, const MatrixGraph& g) {
  size_t len = g.vertexCount();
  for (size_t i = 0; i < len; ++i) {
    for (size_t j = 0; j < len; ++j) {
      os << g.getMatrix()[i][j] << ' ';
    }
    os << '\n';
  }

  return os;
}