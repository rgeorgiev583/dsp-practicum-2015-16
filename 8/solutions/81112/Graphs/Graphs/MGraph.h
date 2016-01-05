#pragma once
#include <vector>
const int INITIAL_CAPACITY = 11;

struct Pair
{
	int a;
	int b;
	Pair(int x, int y) :a(x), b(y) {}
};

class LGraph;

class MGraph
{
private:
	int** M;
	int size;
	int capacity;

	int** multiplyMatrix(int);

	void resize();

	void destroy();

	Pair find_two_vertices(int, int, int**, int)const;
public:
	friend class LGraph;
	friend class NLGraph;

	void print()const;

	MGraph();

	MGraph(const LGraph&);

	~MGraph();

	void addVertex(int);

	void addEdge(int, int);

	bool areNeightbours(int, int)const;

	bool isRoute(std::vector<int> path)const;

	bool isPath(int, int);
};

