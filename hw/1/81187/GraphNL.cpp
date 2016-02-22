#include "stdafx.h"
#include <list>
#include <vector>
#include <algorithm>
#include "GraphNL.h"
#include "GraphIM.h"
#include "GraphEL.h"

bool GraphNL::neighbours(vertex v1, vertex v2)
{
	for (list<list<vertex> >::iterator iter = graph.begin(); iter != graph.end(); iter++)
	{
		if ((*iter).front() == v1)
		{
			return find((*iter).begin(), (*iter).end(), v2) != (*iter).end();
		}
	}
	return false;
}

bool GraphNL::path(vector<vertex> vertices)
{
	for (int i = 0; i < (vertices.size() - 1); i++)
	{
		if (!neighbours(vertices[i], vertices[i + 1]))
			return false;
	}
	return true;
}

GraphIM GraphNL::convertToIM()
{
	return convertToEL().convertToIM();
}

GraphEL GraphNL::convertToEL()
{
	list<edge> g;
	for (list<list<vertex> >::iterator iter = graph.begin(); iter != graph.end(); iter++)
	{
		for (list<vertex>::iterator it = (*iter).begin(); it != (*iter).end(); it++)
		{
			if (it != (*iter).begin())
			{
				edge e;
				e.first = (*(--it));
				e.second = (*(++it));
				g.push_back(e);
			}
		}
	}
	return GraphEL(g);
}
