#include "MatrixGraph.h"

template<typename T>
MatrixGraph<T>::MatrixGraph() {
	matrix = vector<vector<bool> >();
}

template<typename T>
MatrixGraph<T>::MatrixGraph(MatrixGraph<T> const& g) :
		matrix(g.matrix) {}

template<typename T>
MatrixGraph<T>& MatrixGraph<T>::operator=(MatrixGraph<T> const& g) {
	if (this != &g) {
		matrix = g.matrix;
	}
	return *this;
}

template<typename T>
MatrixGraph<T>::MatrixGraph(vector<vector<bool> > m = vector<vector<bool> >()) :
		matrix(m) {}


template<typename T>
bool MatrixGraph<T>::areNeighbor(Node<T> first, Node<T> second) {
		return matrix[first.value][second.value] == 1;
}
