#include <iostream>
#include <initializer_list>
#include "adjacencyListGraph.cpp"
#include "EdgeListGraph.cpp"
#include "IncidenceMatrixGraph.cpp"
using namespace std;

typedef pair<int, int> edge;

int main(void)
{
	AdjacencyListGraph<int> g;
	g.addElement(AdjacencyListElement<int>(1, list<int>({ 2,3,4,6 })));
	g.addElement(AdjacencyListElement<int>(2, list<int>({ 1,6,5 })));
	g.addElement(AdjacencyListElement<int>(3, list<int>({ 1,4,5 })));
	g.addElement(AdjacencyListElement<int>(4, list<int>({ 1,3,6 })));
	g.addElement(AdjacencyListElement<int>(5, list<int>({ 2,3 })));
	g.addElement(AdjacencyListElement<int>(6, list<int>({ 1,2,4 })));

	EdgeListGraph<int> g1;
	g1.addEdge(edge(1, 2));
	g1.addEdge(edge(1, 3));
	g1.addEdge(edge(1, 4));
	g1.addEdge(edge(1, 6));
	g1.addEdge(edge(2, 1));
	g1.addEdge(edge(2, 5));
	g1.addEdge(edge(2, 6));
	g1.addEdge(edge(3, 1));
	g1.addEdge(edge(3, 4));
	g1.addEdge(edge(3, 5));
	g1.addEdge(edge(4, 1));
	g1.addEdge(edge(4, 3));
	g1.addEdge(edge(4, 6));
	g1.addEdge(edge(5, 2));
	g1.addEdge(edge(5, 3));
	g1.addEdge(edge(6, 1));
	g1.addEdge(edge(6, 2));
	g1.addEdge(edge(6, 4));

	IncidenceMatrixGraph<int> ggg(g);
	ggg.printGraph();



	//IncidenceMatrixGraph<int> g2;
	//g2.addElements({ 1,2,3,4,5 },
	//{
	//	{1,1,0,0,0,0},
	//	{1,0,1,1,0,0},
	//	{0,1,1,0,1,0},
	//	{0,0,0,0,1,1},
	//	{0,0,0,1,0,1}
	//});

	cout << endl;
	return 0;
}