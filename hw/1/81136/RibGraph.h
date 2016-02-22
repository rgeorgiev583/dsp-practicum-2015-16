#ifndef RIBGRAPH_H_
#define RIBGRAPH_H_

#include "Graph.h"

template<typename T>
class RibGraph: public Graph<T> {
private:
	list<Rib<T> > edges;
public:
	RibGraph();
	RibGraph(RibGraph const&);
	RibGraph& operator=(RibGraph const&);
	~RibGraph(){}

	RibGraph(list<Rib<T> >);
	bool areNeighbor(Node<T>, Node<T>);

};

#endif /* RIBGRAPH_H_ */
