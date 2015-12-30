#ifndef NEIGHBORGRAPH_H_
#define NEIGHBORGRAPH_H_

#include"Graph.h"

template<typename T>
class NeighborGraph: public Graph<T> {
private:
	list<Node<T> > nodes;
	bool hasNode(Node<T>) const;
public:
	NeighborGraph();
	NeighborGraph(NeighborGraph const&);
	NeighborGraph& operator=(NeighborGraph const&);
	~NeighborGraph() {}

	NeighborGraph(list<Node<T> >);
	bool areNeighbor(Node<T>, Node<T>);
};

#endif /* NEIGHBORGRAPH_H_ */
