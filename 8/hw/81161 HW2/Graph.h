#pragma once
#include <vector>
#include <queue>
#include <set>
using std::vector;
using std::queue;
using std::set;

class Graph
{
public:
	Graph(int aNumNodes)
	{
		numNodes = aNumNodes;
		graph.resize(aNumNodes);
	}
	
	void insertEdge(int node1, int node2)
	{
		if (node1 < numNodes && node2 < numNodes)
		{
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}
	}

	vector<int> BFSShortestDistance(int startingPosition)
	{
		vector<int> shortestDistance(numNodes, -1);
		queue<int> toScan;
		set<int> visited;

		toScan.push(startingPosition);
		visited.insert(startingPosition);
		while (!toScan.empty())
		{
			int currentNode = toScan.front();
			toScan.pop();
			for (int i = 0; i < graph[currentNode].size(); i++)
			{
				int succ = graph[currentNode][i];
				if (visited.find(succ) == visited.end())
				{
					if (shortestDistance[currentNode] == -1)
					{
						shortestDistance[succ] = 6;
					}
					else
					{
						shortestDistance[succ] = shortestDistance[currentNode] + 6;
					}
					toScan.push(succ);
					visited.insert(succ);
				}
			}
		}
		return shortestDistance;
	}
private:
	int numNodes;
	vector<vector<int>> graph;
};