#include "NeighborGraph.h"

template<typename T>
NeighborGraph<T>::NeighborGraph() {
	nodes = list<Node<T> >();
}

template<typename T>
NeighborGraph<T>::NeighborGraph(NeighborGraph<T> const& g) :
		nodes(g.nodes) {}

template<typename T>
NeighborGraph<T>& NeighborGraph<T>::operator=(NeighborGraph<T> const& g) {
	if (this != &g) {
		nodes = g.nodes;
	}
	return *this;
}

template<typename T>
NeighborGraph<T>::NeighborGraph(list<Node<T> > l = list<Node<T> >()) :
		nodes(l) {}

template<typename T>
bool NeighborGraph<T>::areNeighbor(Node<T> first, Node<T> second) {
	for (typename list<Node<T> >::iterator i = nodes.begin(); i != nodes.end(); i++) {
		if ((*i).value == first.value) {
			for (typename list<T>::iterator j = (*i).neighbours.begin(); j != (*i).neighbours.end(); j++) {
				if (*j == second.value) {
					return true;
				}
			}
		}
	}
	return false;
}

template<typename T>
bool NeighborGraph<T>::hasNode(Node<T> node) const {
	for (auto i = nodes.begin(); i != nodes.end(); i++) {
		if ((*i).value == node.value && (*i).neighbours == node.neighbours)
			return true;
	}
	return false;
}


