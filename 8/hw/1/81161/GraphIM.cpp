#include <iostream>
#include <iomanip>
#include "Graphs.h"
using std::cout;
using std::endl;
using std::setw;

void GraphIM::pushEdge(char data, int from, int to)
{
	if (from == to)
		return;

	edges.push_back(data);
	int positionFrom = findVertexPosition(from);
	int positionTo = findVertexPosition(to);

	if (positionFrom == -1)
	{
		vertices.push_back(from);
		matrix.push_back(vector<int>());
		for (unsigned i = 0; i < edges.size() - 1; i++)
			matrix[matrix.size() - 1].push_back(0);
	}

	if (positionTo == -1)
	{
		vertices.push_back(to);
		matrix.push_back(vector<int>());
		for (unsigned i = 0; i < edges.size() - 1; i++)
			matrix[matrix.size() - 1].push_back(0);
	}

	for (unsigned i = 0; i < matrix.size(); i++)
	{
		if (vertices[i] == from)
			matrix[i].push_back(-1);
		else
		if (vertices[i] == to)
			matrix[i].push_back(1);
		else
			matrix[i].push_back(0);
	}
}

int GraphIM::findVertexPosition(int aVer) const
{
	for (unsigned i = 0; i < vertices.size(); i++)
	if (aVer == vertices[i])
		return i;

	return -1;
}

void GraphIM::printGraph() const
{
	cout << setw(1) << "";
	for (unsigned i = 0; i < edges.size(); i++)
		cout << setw(5) << edges[i];

	for (unsigned i = 0; i < matrix.size(); i++)
	{
		cout << endl << vertices[i];
		for (unsigned j = 0; j < edges.size(); j++)
		{
			cout << setw(5) << matrix[i][j];
		}
	}
	cout << endl;
}

bool GraphIM::hasNeighbour(int aVer, int bVer) const
{
	int positiona = findVertexPosition(aVer);
	int positionb = findVertexPosition(bVer);

	if (positiona == -1 || positionb == -1)
		return false;

	for (unsigned i = 0; i < edges.size(); i++)
	{
		if ((matrix[positiona][i] == -1 && matrix[positionb][i] == 1))
			return true;
	}
	return false;
}

bool GraphIM::areAdjacent(int aVer, int bVer) const
{
	return hasNeighbour(aVer, bVer) || hasNeighbour(bVer, aVer);
}

bool GraphIM::isPassable(vector<int> avertices) const
{
	for (unsigned i = 1; i < avertices.size(); i++)
	if (!hasNeighbour(avertices[i - 1], avertices[i]))
		return false;

	return true;
}

GraphEL GraphIM::toGraphEL() const
{
	GraphEL tmp;
	int from, to;
	for (unsigned i = 0; i < edges.size(); i++)
	{
		from = 0;
		to = 0;
		for (unsigned j = 0; j < matrix.size(); j++)
		{
			if (matrix[j][i] == -1)
				from = vertices[j];
			if (matrix[j][i] == 1)
				to = vertices[j];
			if (from && to)
				break;
		}
		tmp.pushEdge(Edge(edges[i], from, to));
	}
	return tmp;
}