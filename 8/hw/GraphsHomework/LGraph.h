#pragma once
#include "Graph.h"
using namespace std;

template <typename T>
class LGraph : public Graph<T>
{
private:
	list<Node<T>> adjList;
public:
	LGraph(list<Node<T>> _adjList = list<Node<T>>()) : adjList(_adjList) { }

	bool areAdjacent(Node<T> first, Node<T> second) const { 
		for (auto i = adjList.begin(); i != adjList.end(); i++) {
			if ((*i).value == first.value) {
				for (auto j = (*i).neighbours.begin(); j != (*i).neighbours.end(); j++) {
					if ((*j).value == second.value) return true;
				}
			}
		}
		return false;
	}

	list<Node<T>> getAdjList() const { return adjList; }

	void print() const { 
		for(auto i = adjList.begin(); i != adjList.end(); i++) {
			if((*i).neighbours.empty()) { cout << "Node " << (*i).value << " has no successors" << endl; }
			else {
				cout << "Node " << (*i).value << " is adjacent to " << endl;
				for(auto j = (*i).neighbours.begin(); j != (*i).neighbours.end(); j++) { 
					cout << "    " << (*j).value << endl;
				}
			}
		}
	}

	~LGraph()
	{
	}
};

