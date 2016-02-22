#include <iostream>
#include <vector>
#include "Graph.h"
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	int numTestCases(0), numNodes(0), numEdges(0), startingPosition(0);
	vector<Graph> cases;
	vector<int> startingPositions;

	// input
	cin >> numTestCases;
	for (int i = 0; i < numTestCases; i++)
	{
		cin >> numNodes >> numEdges;
		Graph testGraph(numNodes);

		for (int j = 0; j < numEdges; j++)
		{
			int node1, node2;
			cin >> node1 >> node2;
			testGraph.insertEdge(--node1, --node2);
		}
		cases.push_back(testGraph);

		cin >> startingPosition;
		startingPosition -= 1;
		startingPositions.push_back(startingPosition);
	}

	// output
	for (int t = 0; t < cases.size(); t++)
	{
		vector<int> shortestDistances = cases[t].BFSShortestDistance(startingPositions[t]);
		for (int k = 0; k < shortestDistances.size(); k++)
		{
			if (k != startingPositions[t])
			{
				cout << shortestDistances[k] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}