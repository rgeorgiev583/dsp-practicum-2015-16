#pragma once
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
using namespace std;

template <class T>
class Graph
{
public:
	virtual bool areAdjacent(T const&, T const&) const = 0;
	virtual bool isPath(vector<T> const&) const = 0;
	virtual void printGraph(void) const = 0;
};

#endif