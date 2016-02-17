#pragma once
#include <list>
#include <vector>

struct Edge
{
	int start;
	int end;
};

class NLGraph
{
private:
	std::list<Edge> nodes;
public:
	NLGraph();
	~NLGraph();

	void addEdge(int, int);

	bool areNeightbours(int, int)const;

	bool isRoute(std::vector<int> path)const;
};

