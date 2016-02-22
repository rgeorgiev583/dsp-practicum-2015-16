#include <iostream>
#include <vector>
#include "Graphs.h"
using std::cout;
using std::endl;
using std::vector;

void testGrapgAL()
{
	GraphAL superLegit;

	Vertex one(1);
	one.pushNeighbour(2);
	one.pushNeighbour(3);
	one.pushNeighbour(4);

	Vertex two(2);
	two.pushNeighbour(1);

	Vertex three(3);
	three.pushNeighbour(2);
	three.pushNeighbour(4);

	Vertex four(4);
	four.pushNeighbour(2);
	four.pushNeighbour(3);

	superLegit.pushVertex(one);
	superLegit.pushVertex(two);
	superLegit.pushVertex(three);
	superLegit.pushVertex(four);


	superLegit.printGraph();

	cout << endl
		<< "Vertices 1 and 4 are"
		<< (superLegit.areAdjacent(1, 4) ? " " : "n't ") << "adjacent."
		<< endl;

	cout << "Vertices 3 and 1 are"
		<< (superLegit.areAdjacent(3, 1) ? " " : "n't ") << "adjacent."
		<< endl;


	vector<int> path1 = { 1, 4, 2, 1, 2 };
	vector<int> path2 = { 1, 4, 3, 1, 2 };

	cout << endl
		<< "The path 1 -> 4 -> 2 -> 1 -> 2 is"
		<< (superLegit.isPassable(path1) ? " " : "n't ") << "passable."
		<< endl;

	cout << endl
		<< "The path 1 -> 4 -> 3 -> 1 -> 2 is"
		<< (superLegit.isPassable(path2) ? " " : "n't ") << "passable."
		<< endl;

	cout << endl << endl;

	// преминаване към представяне чрез списък от ребра
	superLegit.toGraphEL().printGraph();

	cout << endl << endl;

	// преминаване към представяне чрез матрица на инцидентност
	(superLegit.toGraphEL()).toGraphIM().printGraph();

	cout << endl;
}

void testGraphEL()
{
	GraphEL twoAM;
	twoAM.pushEdge(Edge('a', 1, 3));
	twoAM.pushEdge(Edge('b', 2, 3));
	twoAM.pushEdge(Edge('c', 2, 4));
	twoAM.pushEdge(Edge('d', 4, 2));
	twoAM.pushEdge(Edge('e', 1, 2));
	twoAM.pushEdge(Edge('z', 3, 1));

	twoAM.printGraph();

	cout << endl
		<< "Vertices 1 and 4 are"
		<< (twoAM.areAdjacent(1, 4) ? " " : "n't ") << "adjacent."
		<< endl;

	cout << "Vertices 3 and 1 are"
		<< (twoAM.areAdjacent(3, 1) ? " " : "n't ") << "adjacent."
		<< endl;


	vector<int> path1 = { 1, 3, 1, 2, 1 };
	vector<int> path2 = { 1, 3, 1, 2, 4 };

	cout << endl
		<< "The path 1 -> 4 -> 2 -> 1 -> 2 is"
		<< (twoAM.isPassable(path1) ? " " : "n't ") << "passable."
		<< endl;

	cout << endl
		<< "The path 1 -> 4 -> 3 -> 1 -> 2 is"
		<< (twoAM.isPassable(path2) ? " " : "n't ") << "passable."
		<< endl;

	cout << endl << endl;

	// преминаване към представяне чрез матрица на инцидентност
	twoAM.toGraphIM().printGraph();

	cout << endl << endl;

	// преминаване към представяне чрез списъци на съседство
	twoAM.toGraphAL().printGraph();

	cout << endl;
}

void testGraphIM()
{
	GraphIM Puppies;

	Puppies.pushEdge('a', 1, 2);
	Puppies.pushEdge('b', 2, 3);
	Puppies.pushEdge('c', 3, 2);
	Puppies.pushEdge('z', 1, 4);

	Puppies.printGraph();

	cout << endl
		<< "Vertices 1 and 4 are"
		<< (Puppies.areAdjacent(1, 4) ? " " : "n't ") << "adjacent."
		<< endl;

	cout << "Vertices 3 and 1 are"
		<< (Puppies.areAdjacent(3, 1) ? " " : "n't ") << "adjacent."
		<< endl;


	vector<int> path1 = { 1, 2, 3, 2 };
	vector<int> path2 = { 1, 2, 3, 4 };

	cout << endl
		<< "The path 1 -> 4 -> 2 -> 1 -> 2 is"
		<< (Puppies.isPassable(path1) ? " " : "n't ") << "passable."
		<< endl;

	cout << endl
		<< "The path 1 -> 4 -> 3 -> 1 -> 2 is"
		<< (Puppies.isPassable(path2) ? " " : "n't ") << "passable."
		<< endl;

	cout << endl << endl;

	// преминаване към представяне чрез списък от ребра
	Puppies.toGraphEL().printGraph();

	cout << endl << endl;

	// преминаване към представяне чрез списъци на съседство
	(Puppies.toGraphEL()).toGraphAL().printGraph();

	cout << endl;
}

int main()
{
	// testGrapgAL();
	// testGraphEL();
	// testGraphIM();

	return 0;
}