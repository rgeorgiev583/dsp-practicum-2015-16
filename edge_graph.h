#ifndef EDGE_GRAPH_H
#define EDGE_GRAPH_H

#include <list>

using namespace std;

class GraphMatrix;
class NeighbourListGraph;

class EdgeGraph
{
private:
	list< pair<int, int> > edges;
public:
	EdgeGraph( list<pair<int, int> > _edges ) : edges(_edges) {}
	EdgeGraph() : edges( list<pair<int, int> >() ) {}
	EdgeGraph( GraphMatrix const& );
	EdgeGraph( NeighbourListGraph const& );

	void addEdge( int, int );

	bool areNeighbours( int, int ) const;
	bool hasPath( vector<int> ) const;

	friend ostream& operator<<( ostream&, EdgeGraph const& );
	friend class NeighbourListGraph;
};

ostream& operator<<( ostream& os, EdgeGraph const& gr )
{
	for( auto i = gr.edges.begin(); i != gr.edges.end(); i++ )
	{
		os << '(' << (*i).first << ", " << (*i).second << ')' << endl;
	}
	return os;
}

#endif