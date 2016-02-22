#include "Graph.h"

template<typename T>
bool Graph<T>::isPath(list<Node<T> > path) {
	for (typename list<Node<T> >::iterator i = path.begin();
			i != prev(path.end(), 1); i++) {
		if (!areNeighbor(*i, *(next(i, 1))))
			return false;
	}
	return true;
}

template<typename T>
bool Graph<T>::isPath(vector<Node<T> > path) {
	for (int i = 0; i < path.size() - 1; i++) {
		if (!areNeighbor(path[i], path[i + 1]))
			return false;
	}
	return true;
}
