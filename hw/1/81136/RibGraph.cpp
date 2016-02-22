#include "RibGraph.h"

template<typename T>
RibGraph<T>::RibGraph() {
	edges = list<Rib<T> >();
}

template<typename T>
RibGraph<T>::RibGraph(RibGraph<T> const& g) :
		edges(g.edges) {}

template<typename T>
RibGraph<T>& RibGraph<T>::operator=(RibGraph<T> const& g) {
	if (this != &g) {
		edges = g.edges;
	}
	return *this;
}

template<typename T>
RibGraph<T>::RibGraph(list<Rib<T> > l = list<Rib<T> >()) :
		edges(l) {}

template<typename T>
bool RibGraph<T>::areNeighbor(Node<T> first, Node<T> second) {
	for (auto i = edges.begin(); i != edges.end(); i++) {
		if ((*i).from.value == first.value && (*i).to.value == second.value)
			return true;
	}
	return false;
}
