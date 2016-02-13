#ifndef _GRAPHEL_H
#define _GRAPHEL_H

#include "stdafx.h"
#include <list>
#include <vector>

#include "GraphNL.h"
#include "GraphIM.h"

using namespace std;

typedef char vertex;
typedef pair<vertex, vertex> edge;

class GraphNL;
class GraphIM;
class GraphEL
{
	list<edge> graph;

public:
	GraphEL(list<edge> _graph) :graph(_graph) {}

	bool neighbours(vertex, vertex);
	bool path(vector<vertex>);
	GraphNL convertToNL();
	GraphIM convertToIM();
};

#endif