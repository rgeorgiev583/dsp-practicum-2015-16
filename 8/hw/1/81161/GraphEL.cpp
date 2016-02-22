#include <iostream>
#include "Graphs.h"
using std::cout;
using std::endl;

char Edge::getData() const
{
	return data;
}

int Edge::getFrom() const
{
	return from;
}

int Edge::getTo() const
{
	return to;
}

void Edge::printEdge() const
{
	cout << "Edge \'" << data << "\' from vertex " << from << " to vertex " << to << "." << endl;
}

void GraphEL::pushEdge(const Edge& aedge)
{
	edges.push_back(aedge);
}

void GraphEL::printGraph() const
{
	for (unsigned i = 0; i < edges.size(); i++)
		edges[i].printEdge();
}

bool GraphEL::hasNeighbour(int aVer, int bVer) const
{
	for (unsigned i = 0; i < edges.size(); i++)
	if ((edges[i].getFrom() == aVer && edges[i].getTo() == bVer))
		return true;

	return false;
}

bool GraphEL::areAdjacent(int aVer, int bVer) const
{
	return hasNeighbour(aVer, bVer) || hasNeighbour(bVer, aVer);
}

bool GraphEL::isPassable(vector<int> avertices) const
{
	for (unsigned i = 1; i < avertices.size(); i++)
	    if(!hasNeighbour(avertices[i - 1], avertices[i]))
	    	return false;

	return true;
}

GraphAL GraphEL::toGraphAL() const
{
	GraphAL tmp;

	for (unsigned i = 0; i < edges.size(); i++)
	{
		if (tmp.findVertexPosition(edges[i].getFrom()) == -1)
			tmp.pushVertex(Vertex(edges[i].getFrom()));

		tmp.pushVertexNeighbour(edges[i].getFrom(), edges[i].getTo());
	}
	return tmp;
}

GraphIM GraphEL::toGraphIM() const
{
	GraphIM tmp;
	for (unsigned i = 0; i < edges.size(); i++)
		tmp.pushEdge(edges[i].getData(), edges[i].getFrom(), edges[i].getTo());

	return tmp;
}