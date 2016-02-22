#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(const vector<vector<int> >& iMatrix) :
  iMatrix(iMatrix) {}

MatrixGraph::MatrixGraph(const ListGraph& listGraph) {
  int edgesCount = listGraph.edgesCount();
  int vertexCount = listGraph.vertexCount();
  iMatrix = vector<vector<int> >(vertexCount, vector<int>(edgesCount, 0));
  int edge = 0;
  for (int i = 0; i < vertexCount; ++i) {
    for (auto v : listGraph.getLists()[i]) {
      iMatrix[i][edge] = -1;
      iMatrix[v][edge] = 1;
      ++edge;
    }
  }
}

MatrixGraph::MatrixGraph(const EdgeGraph& edgeGraph) {
  int vertexCount = edgeGraph.vertexCount();
  int edgesCount = edgeGraph.edgesCount();
  iMatrix = vector<vector<int> >(vertexCount, vector<int>(edgesCount, 0));
  int edgeIndex = 0;
  for (auto edge : edgeGraph.getEdges()) {
    iMatrix[edge.first][edgeIndex] = -1;
    iMatrix[edge.second][edgeIndex] = 1;
    ++edgeIndex;
  }
}

const vector<vector<int> >& MatrixGraph::getMatrix() const {
  return iMatrix;
}

int MatrixGraph::vertexCount() const {
  return iMatrix.size();
}

int MatrixGraph::edgesCount() const {
  return vertexCount() ? iMatrix[0].size() : 0;
}

bool MatrixGraph::neighbour(int v1, int v2) const {
  for (int i = 0, len = edgesCount(); i < len; ++i) {
    if (iMatrix[v1][i] && iMatrix[v2][i]) {
      return true;
    }
  }

  return false;
}

bool MatrixGraph::neighbourFrom(int from, int to) const {
  for (int i = 0, len = edgesCount(); i < len; ++i) {
    if (iMatrix[from][i] == -1 && iMatrix[to][i]) {
      return true;
    }
  }

  return false;
}

bool MatrixGraph::isPath(const vector<int>& vertices) const {
  auto last = --(vertices.end());
  auto it = vertices.begin();

  while (it != last) {
    if (!neighbourFrom(*it, *(++it))) {
      return false;
    }
  }

  return true;
}

ostream& operator<<(ostream& os, const MatrixGraph& matrixGraph) {
  for (int i = 0, vCount = matrixGraph.vertexCount(); i < vCount; ++i) {
    for (int j = 0, eCount = matrixGraph.edgesCount(); j < eCount; ++j) {
      os << matrixGraph.getMatrix()[i][j] << ' ';
    }
    os << '\n';
  }

  return os;
}
