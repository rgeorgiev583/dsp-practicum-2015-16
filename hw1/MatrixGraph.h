#ifndef MATRIXGRAPH_H_
#define MATRIXGRAPH_H_

#include"Graph.h"

template<typename T>
class MatrixGraph: public Graph<T> {
private:
	vector<vector<bool> > matrix;
public:
	MatrixGraph();
	MatrixGraph(MatrixGraph const&);
	MatrixGraph& operator=(MatrixGraph const&);
	~MatrixGraph() {}

	MatrixGraph(vector<vector<bool> >);
	bool areNeighbor(Node<T>, Node<T>);
};

#endif /* MATRIXGRAPH_H_ */
