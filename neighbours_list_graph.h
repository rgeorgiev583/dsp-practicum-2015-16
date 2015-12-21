#ifndef NEIGH_LIST_GRAPH_H
#define NEIGH_LIST_GRAPH_H

#include <vector>
#include <list>
#include "edge_graph.h"
#include "graph_matrix.h"

using namespace std;

class NeighbourListGraph
{
private:
	vector<list<int> > neighbours_list;

public:
	NeighbourListGraph() : neighbours_list( vector<list<int> >() ) {}
	NeighbourListGraph( vector<list<int> > nList ) : neighbours_list( nList ) {}
	NeighbourListGraph( EdgeGraph const& );
	NeighbourListGraph( GraphMatrix const& );

	void addNewVertex( int );
	void addEdge( int, int );

	size_t getCountVertices() const { return neighbours_list.size(); }

	bool areNeighbours( int, int ) const;
	bool hasPath( vector<int> ) const;
	bool isVertex( int ) const;

	friend ostream& operator<<( ostream& os, NeighbourListGraph const& gr );
	friend class GraphMatrix;
	friend class EdgeGraph;
};

ostream& operator<<( ostream& os, NeighbourListGraph const& gr )
{
	size_t len = gr.getCountVertices();
	for( size_t i = 0; i < len; i++ )
	{
		list<int> vertList = gr.neighbours_list[i];
		for( std::list<int>::iterator i = vertList.begin(); i != vertList.end(); i++ )
		{
			if( i == vertList.begin() )
				os << *i <<" -> ";
			else
				os << *i <<' ';
		}
		os << endl;
	}
	return os;
}

#endif