#pragma once
#include <vector>
using std::vector;

class GraphAL;
class GraphEL;
class GraphIM;

// GraphAL - oриентиран граф, представен чрез списъци на съседство
// използва Vertex
class Vertex
{
public:
	Vertex(int adata, vector<int> aneighbours = vector<int>())
		: data(adata), neighbours(aneighbours){}

	void pushNeighbour(int aneighbour);
	int  getData() const;
	void printVertex() const;
	bool hasNeighbour(int adata) const;

	friend GraphAL;
private:
	int data;
	vector<int> neighbours;
};

class GraphAL
{
public:
	GraphAL(vector<Vertex> avertices = vector<Vertex>())
		: vertices(avertices){}

	void pushVertex(const Vertex& aVer);
	void pushVertexNeighbour(int verData, int aNeighbour);
	void printGraph() const;
	int  findVertexPosition(int adata) const;
	bool areAdjacent(int adata, int bdata) const;
	bool isPassable(vector<int> avertices) const;
	GraphEL toGraphEL() const;
private:
	vector<Vertex> vertices;
};


// GraphEL.h - oриентиран граф, представен чрез списък на ребрата
// използва Edge
class Edge
{
public:
	Edge(char adata, int afrom, int ato) : data(adata), from(afrom), to(ato){}

	char getData() const;
	int getFrom() const;
	int getTo() const;
	void printEdge() const;
private:
	char data;
	int from;
	int to;
};

class GraphEL
{
public:
	GraphEL(vector<Edge> aedges = vector<Edge>()) : edges(aedges){}

	void pushEdge(const Edge& aedge);
	void printGraph() const;
	bool hasNeighbour(int aVer, int bVer) const;
	bool areAdjacent(int aVer, int bVer) const;
	bool isPassable(vector<int> averticec) const;
	GraphAL toGraphAL() const;
	GraphIM toGraphIM() const;
private:
	vector<Edge> edges;
};


// GraphIM - oриентиран граф, представен чрез матрица на инцидентност
class GraphIM
{
public:
	GraphIM() : edges(vector<char>()), matrix(vector<vector<int>>()){}

	void pushEdge(char data, int from, int to);
	int findVertexPosition(int aVer) const;
	void printGraph() const;
	bool hasNeighbour(int aVer, int bVer) const;
	bool areAdjacent(int aVer, int bVer) const;
	bool isPassable(vector<int> avertices) const;
	GraphEL toGraphEL() const;
private:
	vector<int> vertices;
	vector<char> edges;
	vector<vector<int>> matrix;
};