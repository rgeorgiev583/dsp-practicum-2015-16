#pragma once
#include "Graph.h"
using namespace std;

template <typename T>
class EGraph : public Graph<T>
{
private:
	list<Edge<T>> edges;
public:

	list<Edge<T>> getEdges() const { return edges;}

	EGraph(list<Edge<T>> _edges = list<Edge<T>>()) : edges(_edges) { }

	bool areAdjacent(Node<T> first, Node<T> second) const { 
		for (auto i = edges.begin(); i != edges.end(); i++) {
			if (((*i).from.value == first.value && (*i).to.value == second.value) ||
				((*i).from.value == second.value && (*i).to.value == first.value)) return true;
		}
		return false;
	}

	void print() const { 
		for(auto i = edges.begin(); i != edges.end(); i++) { 
			cout << "(" << (*i).from.value << " -> " << (*i).to.value << ")" << endl;
		}
	}

	~EGraph()
	{
	}
};

