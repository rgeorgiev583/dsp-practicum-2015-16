#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include<iostream>
#include <vector>
#include <iomanip>

class EdgeGraph;
class NeighbourListGraph;

using namespace std;

class GraphMatrix
{
private:
	vector<vector<int> > matrix;
	
public:
	GraphMatrix( vector<vector<int> > matr ) : matrix( matr ) {}
	GraphMatrix( EdgeGraph const& );
	GraphMatrix( NeighbourListGraph const& );
	GraphMatrix();
	size_t getCountVertices() const { return matrix[0].size() - 1; }
	void addNewVertex( int );
	void addEdge( int, int );
	int elemAt(int, int) const;

	bool areNeighbours( int, int ) const;
	bool hasPathFromTo( int, int ) const;
	bool hasPath( vector<int> ) const;

	friend class NeighbourListGraph;
};

ostream& operator<<( ostream& os, GraphMatrix const& gr )
{
	size_t len = gr.getCountVertices() + 1;
	for( size_t i = 0; i < len; i++ )
	{
		for( size_t j = 0; j < len; j++ )
			os << setw(2) << gr.elemAt( i, j ) <<' ';
		os << endl;
	}
	return os;
}

#endif