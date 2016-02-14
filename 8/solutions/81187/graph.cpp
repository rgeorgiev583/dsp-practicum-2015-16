// graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

void calculateLength(list<int>* g, int* paths, int start, int nodesCount)
{
	queue<int> q;
	set<int> visited;

	for (size_t i = 0; i < nodesCount+1; i++)
	{
		paths[i] = -1;
	}

	q.push(start);
	visited.emplace(start);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		list<int>* succ = &g[v];
		for (list<int>::iterator i = succ->begin(); i != succ->end(); i++)
		{
			if (visited.find(*i) == visited.end())
			{
				q.push(*i);
				visited.emplace(*i);
				paths[*i] = paths[v] + 1;
			}
		}
	}
}

void testGraph()
{
	int numberOfCases;
	cin >> numberOfCases;
	for (size_t i = 0; i < numberOfCases; i++)
	{
		int nodesCount, edgesCount, s;
		cin >> nodesCount >>edgesCount;
		list<int>* g=new list<int>[nodesCount+1];
		for (size_t j = 0; j < edgesCount; j++)
		{
			int u, v;
			cin >> u >> v;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		cin >> s;

		int* paths = new int[nodesCount + 1];
		calculateLength(g, paths, s, nodesCount);
		for (size_t k = 1; k <= nodesCount; k++)
		{
			if (k != s)
			{
				if (paths[k] != -1)
					cout << (paths[k] + 1) * 6 << ' ';
				else
					cout << -1 << ' ';
			}
		}
		delete paths;
		cout << endl;
		delete[] g;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testGraph();
	return 0;
}
/*
1
4 2
1 2
3 2
2
*/