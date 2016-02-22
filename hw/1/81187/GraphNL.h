#ifndef _GRAPHNL_H
#define _GRAPHNL_H

#include "stdafx.h"
#include <list>
#include <vector>

#include "GraphIM.h"
#include "GraphEL.h"

using namespace std;

typedef char vertex;
typedef pair<vertex, vertex> edge;

class GraphIM;
class GraphEL;

class GraphNL
{
	list<list<vertex> > graph;

public:
	GraphNL(list<list<vertex> > _graph) : graph(_graph) {}

	bool neighbours(vertex, vertex);
	bool path(vector<vertex>);
	GraphIM convertToIM();
	GraphEL convertToEL();
};

#endif