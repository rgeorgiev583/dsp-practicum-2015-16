#include "stdafx.h"
#include <list>
#include <vector>
#include "GraphIM.h"
#include "GraphNL.h"
#include "GraphEL.h"

bool GraphIM::neighbours(vertex v1, vertex v2)
{
	return convertToEL().neighbours(v1, v2);
}

bool GraphIM::path(vector<vertex> vertices)
{
	return convertToEL().path(vertices);
}

GraphNL GraphIM::convertToNL()
{
	vector<list<vertex> > g;
	for (int i = 0; i < order.size(); i++)
	{
		g[i].push_back(order[i]);
	}

	for (int j = 0; j < graph.size(); j++)
	{
		int index;
		vertex v;
		for (int i = 0; i < order.size(); i++)
		{
			if (graph[j][i] == -1)
				index = i;
			if (graph[j][i] == 1)
				v = order[i];
		}
		g[index].push_back(v);
	}

	list<list<vertex> >newGraph;
	for (int i = 0; i < g.size(); i++)
	{
		if (g[i].size()>1)
			newGraph.push_back(g[i]);
	}

	return GraphNL(newGraph);
}

GraphEL GraphIM::convertToEL()
{
	return (GraphEL)convertToNL().convertToEL();
}