#include "stdafx.h"
#include "GraphEL.h"
#include <list>
#include <vector>
#include <algorithm>
#include "GraphNL.h"
#include "GraphIM.h"

bool GraphEL::neighbours(vertex v1, vertex v2)
{
	for (list<edge>::iterator iter = graph.begin(); iter != graph.end(); iter++)
	{
		if ((*iter).first == v1 && (*iter).second == v2)
		{
			return true;
		}
	}
	return false;
}

bool GraphEL::path(vector<vertex> vertices)
{
	for (int i = 0; i < (vertices.size() - 1); i++)
	{
		if (!neighbours(vertices[i], vertices[i + 1]))
			return false;
	}
	return true;
}

GraphNL GraphEL::convertToNL()
{
	return convertToIM().convertToNL();
}

GraphIM GraphEL::convertToIM()
{
	vector<vertex> order;
	vector<vector<int> > g;

	for (list<edge>::iterator iter = graph.begin(); iter != graph.end(); iter++)
	{
		if (find(order.begin(), order.end(), (*iter).first) == order.end())
			order.push_back((*iter).first);
	}

	for (list<edge>::iterator iter = graph.begin(); iter != graph.end(); iter++)
	{
		vector<int> e;
		for (int i = 0; i < order.size(); i++)
		{
			if (order[i] == (*iter).first)
				e.push_back(-1);
			else if (order[i] == (*iter).second)
				e.push_back(1);
			else
				e.push_back(0);
		}
		g.push_back(e);
	}
	return GraphIM(g, order);
}