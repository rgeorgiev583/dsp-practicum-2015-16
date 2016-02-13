#include <iostream>
#include "graph_matrix.h"
#include "edge_graph.h"
#include "neighbours_list_graph.h"

using namespace std;

GraphMatrix::GraphMatrix() : matrix( vector<vector<int> >() )
{
	vector<int> row1;
	row1.push_back( -1 );
	matrix.push_back( row1 );
}

GraphMatrix::GraphMatrix( NeighbourListGraph const& nlg ) : matrix( vector<vector<int> >() )
{
	vector<int> row1;
	row1.push_back( -1 );
	matrix.push_back( row1 );
	for( auto i = nlg.neighbours_list.begin(); i != nlg.neighbours_list.end(); i++ )
		addNewVertex( (*i).front() );
	for( auto i = nlg.neighbours_list.begin(); i != nlg.neighbours_list.end(); i++ )
		for( auto it = ++(*i).begin(); it != (*i).end(); it++ )
			addEdge( (*i).front(), (*it) );
}

GraphMatrix::GraphMatrix( EdgeGraph const& eg )
{
	matrix = GraphMatrix( NeighbourListGraph(eg) ).matrix;
}

void GraphMatrix::addNewVertex( int vertex )
{
	matrix[0].push_back( vertex );
	vector<int> newRow;
	size_t cnt = getCountVertices();
	newRow.push_back( vertex );
	matrix.push_back( newRow );
	for( size_t i = 1; i <= cnt; i++ )
	{
		matrix[cnt].push_back( 0 );
	}
	for( size_t i = 1; i < cnt; i++ )
	{
		matrix[i].push_back( 0 );
	}
}

void GraphMatrix::addEdge( int from, int to )
{
	size_t col = 0, row = 0;
	for( size_t i = 1; i < matrix[0].size(); i++ )
	{
		if( matrix[0][i] == to )
			col = i;
		if( matrix[0][i] == from )
			row = i;
	}
	matrix[row][col]++;
}

int GraphMatrix::elemAt( int row, int col ) const
{
	return matrix[row][col];
}

bool GraphMatrix::areNeighbours( int a, int b ) const
{
	size_t col = 0, row = 0;
	for( size_t i = 1; i < matrix[0].size(); i++ )
	{
		if( matrix[0][i] == a )
			col = i;
		if( matrix[0][i] == b )
			row = i;
	}
	return matrix[row][col] + matrix[col][row] > 0;
}

bool GraphMatrix::hasPath( vector<int> path ) const
{
	size_t pathSize = path.size();
	for( size_t i = 0; i < pathSize - 1; i++ )
	{
		if( !hasPathFromTo( path[i], path[i + 1] ) )
			return false;
	}
	return true;
}

bool GraphMatrix::hasPathFromTo( int a, int b ) const
{
	size_t col = 0, row = 0;
	for( size_t i = 1; i < matrix[0].size(); i++ )
	{
		if( matrix[0][i] == b )
			col = i;
		if( matrix[0][i] == a )
			row = i;
	}
	return matrix[row][col] > 0;
}