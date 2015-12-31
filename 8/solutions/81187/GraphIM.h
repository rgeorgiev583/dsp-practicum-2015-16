#ifndef _GRAPHIM_H
#define _GRAPHIM_H

#include "stdafx.h"
#include <list>
#include <vector>

#include "GraphNL.h"
#include "GraphEL.h"

using namespace std;

typedef char vertex;
typedef pair<vertex, vertex> edge;

class GraphNL;
class GraphEL;
class GraphIM
{
	vector<vector<int>> graph;
	vector<vertex> order;

public:
	GraphIM(vector<vector<int> > _graph, vector<vertex> _order) :graph(_graph), order(_order) {}

	bool neighbours(vertex, vertex);
	bool path(vector<vertex>);

	GraphNL convertToNL();
	GraphEL convertToEL();
};
#endif

