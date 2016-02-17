#pragma once
#include <list>
#include <iostream>

using namespace std;

template <typename T>
struct Node { 
	T value;
	list<Node> neighbours;

	Node(T _value = T(), list<Node> _neighbours = list<Node>()) : value(_value), neighbours(_neighbours) { }
};

template <typename T>
struct Edge { 
	Node<T> from;
	Node<T> to;

	Edge(Node<T> _from = Node<T>(), Node<T> _to = Node<T>()) : from(_from), to(_to) { }
};

template <typename T>
class Graph
{
private:
	void printPath(list<Node<T>> path) const { 
		for(auto i = path.begin(); i != path.end(); i++) { 
			cout << " -> " << (*i).value;
		}
	} 
public:
	virtual bool areAdjacent(Node<T>, Node<T>) const = 0;

	bool isPath(list<Node<T>> path) const { 
		for (auto i = path.begin(); i != prev(path.end(), 1); i++) {
			if(!areAdjacent((*i), (*next(i,1)))) { 
				printPath(path);
				cout << " is not a valid path" << endl;
				return false;
			} 
		}
		printPath(path);
		cout << " is a valid path" << endl;
		return true;
	}
	virtual void print() const = 0;

	virtual ~Graph() { }
};

