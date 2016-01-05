#include "NLGraph.h"



NLGraph::NLGraph()
{
}


NLGraph::~NLGraph()
{
}

void NLGraph::addEdge(int start, int end)
{
	Edge new_edge;
	new_edge.start = start;
	new_edge.end = end;
	this->nodes.push_back(new_edge);
}

bool NLGraph::areNeightbours(int a, int b) const
{
	for (auto edge : nodes) {
		//Resolve specifically for oriented graphs
		if ((edge.start == a && edge.end == b)
			|| (edge.start == b && edge.start == a)) {
			return true;
		}
	}
	return false;
}

bool NLGraph::isRoute(std::vector<int> path) const
{
	for (int i = 0; i < path.size() - 1; i++) {
		if (!this->areNeightbours(path[i], path[i + 1])) {
			return false;
		}
	}
	return true;
}
