#include "neighbours_list_graph.h"

using namespace std;

NeighbourListGraph::NeighbourListGraph( EdgeGraph const& eg ) : neighbours_list( vector<list<int> >() )
{
	for( auto i = eg.edges.begin(); i != eg.edges.end(); i++ )
	{
		if( !isVertex( (*i).first ) )
			addNewVertex( (*i).first );
		if( !isVertex( (*i).second ) )
			addNewVertex( (*i).second );
		addEdge( (*i).first, (*i).second );
	}
}

NeighbourListGraph::NeighbourListGraph( GraphMatrix const& gm ) : neighbours_list( vector<list<int> >() )
{
	size_t vertCount = gm.getCountVertices();
	for( size_t i = 1; i <= vertCount; i++ )
		addNewVertex( gm.matrix[0][i] );
	for( size_t i = 1; i <= vertCount; i++ )
	{
		for( size_t j = 1; j <= vertCount; j++ )
			if( gm.matrix[i][j] > 0 )
				addEdge( gm.matrix[0][i], gm.matrix[0][j] );
	}
}

void NeighbourListGraph::addNewVertex( int vertex )
{
	list<int> newVert;
	newVert.push_front( vertex );
	neighbours_list.push_back( newVert );
}

void NeighbourListGraph::addEdge( int from, int to )
{
	size_t vertices = neighbours_list.size();
	for( size_t i = 0; i < vertices; i++ )
	{
		if( neighbours_list[i].front() == from )
		{
			neighbours_list[i].push_back( to );
		}
	}
}

bool NeighbourListGraph::areNeighbours( int a, int b ) const
{
	size_t vertices = neighbours_list.size();
	for( size_t i = 0; i < vertices; i++ )
	{
		if( neighbours_list[i].front() == a )
		{
			list<int> vertList = neighbours_list[i];
			for( std::list<int>::iterator i = ++vertList.begin(); i != vertList.end(); i++ )
			{
				if( *i == b )
					return true;
			}
		}
	}
	return false;
}

bool NeighbourListGraph::hasPath( vector<int> path ) const
{
	size_t pathLen = path.size();
	for( size_t i = 0; i < pathLen - 1; i++ )
	{
		if( !areNeighbours( path[i], path[i + 1] ) )
			return false;
	}
	return true;
}

bool NeighbourListGraph::isVertex( int x ) const
{
	size_t vertNum = neighbours_list.size(), i = 0;
	while( i < vertNum )
	{
		if( neighbours_list[i++].front() == x )
			return true;
	}
	return false;
}