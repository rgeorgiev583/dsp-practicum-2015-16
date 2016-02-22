#ifndef GRAPH_H_
#define GRAPH_H_

#include<list>
#include<vector>
using namespace std;

template<typename T>
struct Node {
	T value;
	list<T> neighbours;
	Node(T v = T(), list<T> n = list<T>()) :
			value(v), neighbours(n) {}
};

template<typename T>
struct Rib {
	Node<T> from;
	Node<T> to;
	Rib(Node<T> _from, Node<T> _to) :
			from(_from), to(_to) {}
};

template<typename T>
class Graph {
public:
	virtual bool areNeighbor(Node<T> firstVertex, Node<T> secondVertex) = 0;
	bool isPath(list<Node<T> > path);
	bool isPath(vector<Node<T> > path);
	virtual void print() = 0;
	virtual ~Graph() {}
};

#endif /* GRAPH_H_ */
