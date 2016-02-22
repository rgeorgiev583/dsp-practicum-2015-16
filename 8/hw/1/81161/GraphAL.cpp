#include <iostream>
#include "Graphs.h"
using std::cout;
using std::endl;

void Vertex::pushNeighbour(int aneighbour)
{
	neighbours.push_back(aneighbour);
}

int Vertex::getData() const
{
	return data;
}

void Vertex::printVertex() const
{
	cout << "Vertex " << data << " is adjacent with vertices: ";
	for (unsigned j = 0; j < neighbours.size(); j++)
		cout << neighbours[j] << " ";                                     
	cout << endl;
}

bool Vertex::hasNeighbour(int adata) const
{
	for (unsigned i = 0; i < neighbours.size(); i++)
	if (neighbours[i] == adata)
		return true;

	return false;
}

void GraphAL::pushVertex(const Vertex& aVer)
{
	vertices.push_back(aVer);
}

void GraphAL::pushVertexNeighbour(int verData, int aNeighbour)
{
	vertices[findVertexPosition(verData)].pushNeighbour(aNeighbour);
}

void GraphAL::printGraph() const
{
	for (unsigned i = 0; i < vertices.size(); i++)
		vertices[i].printVertex();
}

int GraphAL::findVertexPosition(int adata) const
{
	for (unsigned i = 0; i < vertices.size(); i++)
	if (vertices[i].getData() == adata)
		return i;
	return -1;
}

bool GraphAL::areAdjacent(int adata, int bdata) const 
{
	int positiona = findVertexPosition(adata);
	int positionb = findVertexPosition(bdata);

	if (positiona == -1 || positionb == -1)
		return false;

	return vertices[positiona].hasNeighbour(bdata) || vertices[positionb].hasNeighbour(adata);
}

bool GraphAL::isPassable(vector<int> avertices) const 
{
	int curr, next, index(0);

	do
	{
		curr = findVertexPosition(avertices[index++]);
		next = findVertexPosition(avertices[index]);
		if (curr == -1 || next == -1)
			return false;
	} while (index < (avertices.size() - 1) && vertices[curr].hasNeighbour(vertices[next].getData()));

	if (index == (avertices.size() - 1) && vertices[curr].hasNeighbour(vertices[next].getData()))
		return true;
	return false;
}

GraphEL GraphAL::toGraphEL() const
{
	GraphEL tmp;
	int asciiIndex = 65;
	for (unsigned i = 0; i < vertices.size(); i++)
	{
		for (unsigned j = 0; j < vertices[i].neighbours.size(); j++)
		{
			tmp.pushEdge(Edge(static_cast<char>(asciiIndex++), vertices[i].getData(), vertices[i].neighbours[j]));
		}
	}
	return tmp;
}