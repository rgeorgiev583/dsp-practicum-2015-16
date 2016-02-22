#pragma once
#include <list>
#include <vector>
class LGraph
{
private:
	std::list<std::list<int>* > nodes;

	std::list<int>* find(int)const;

	void destroy();
public:
	friend class MGraph;
	friend class NLGraph;

	LGraph();

	~LGraph();

	std::list<int>* addVertex(int);

	std::list<int>* addEdge(int, int);

	bool areNeightbours(int, int)const;

	bool isRoute(std::vector<int> path)const;
};

