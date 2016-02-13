#include <iostream>
#include "edge_graph.h"

using namespace std;

EdgeGraph::EdgeGraph( NeighbourListGraph const& nlg ) : edges( list<pair<int, int> >() )
{
	for( auto i = nlg.neighbours_list.begin(); i != nlg.neighbours_list.end(); i++ )
		for( auto it = ++(*i).begin(); it != (*i).end(); it++ )
			addEdge( (*i).front(), (*it) );
}

EdgeGraph::EdgeGraph( GraphMatrix const& gm )
{
	edges = EdgeGraph( NeighbourListGraph(gm) ).edges;
}

void EdgeGraph::addEdge( int from, int to )
{
	edges.push_back( make_pair( from, to ) );
}

bool EdgeGraph::areNeighbours( int a, int b ) const
{
	for( auto i = edges.begin(); i != edges.end(); i++ )
	{
		if( (*i).first == a && (*i).second == b )
			return true;
	}
	return false;
}

bool EdgeGraph::hasPath( vector<int> path ) const
{
	size_t pathLen = path.size();
	for( size_t i = 0; i < pathLen - 1; i++ )
	{
		if( !areNeighbours( path[i], path[i + 1] ) )
			return false;
	}
	return true;
}