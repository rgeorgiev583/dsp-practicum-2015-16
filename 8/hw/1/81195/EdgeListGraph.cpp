#ifndef EDGLISTGRAPH_CPP_
#define EDGLISTGRAPH_CPP_

#include <iostream>
#include <list>
#include <vector>
#include "Graph.h"
using namespace std;

template<class T>
class AdjacencyListGraph;
template <class T>
struct AdjacencyListElement;

template <class T>
class IncidenceMatrixGraph;

template<class T>
class EdgeListGraph : public Graph<T>
{
public:
	EdgeListGraph() {}
	EdgeListGraph(const AdjacencyListGraph<T>&);
	EdgeListGraph(const IncidenceMatrixGraph<T>&);

	void addEdge(const pair<T, T>& edge);
	list<pair<T, T>> getList(void) const;

	virtual bool areAdjacent(const T&, const T&) const;
	virtual bool isPath(const vector<T>&) const;
	virtual void printGraph(void) const;

private:
	list<pair<T,T>> edgeList;
};

template<class T>
EdgeListGraph<T>::EdgeListGraph(const AdjacencyListGraph<T>& g)
{
	list<AdjacencyListElement<T>> l = g.getAdjList();

	for (list<AdjacencyListElement<T>>::iterator it = l.begin(); it != l.end(); ++it)
	{
		T vert = it->element;
		for (list<T>::iterator jt = it->neighbours.begin(); jt != it->neighbours.end(); ++jt)
		{
			addEdge(pair<T,T>(vert, *jt));
		}
	}
}

template <class T>
EdgeListGraph<T>::EdgeListGraph(const IncidenceMatrixGraph<T>& g)
{
	vector<T> els = g.getElements();
	vector<vector<int>> mat = g.getMatrix();

	for (int i = 0; i < els.size(); ++i)
	{
		vector<int> pos, edgesTo;
		for (int j = 0; j < mat[i].size(); ++j)
		{
			if (mat[i][j] == 1)
				pos.push_back(j);
		}

		for (int j = 0; j < mat.size(); j++)
		{
			if (j != i)
			{
				for (int k = 0; k < pos.size(); ++k)
				{
					if (mat[j][pos[k]] == 1)
						edgesTo.push_back(els[j]);
				}
			}
		}

		for (int j = 0; j < edgesTo.size(); ++j)
		{
			addEdge(pair<T,T>(els[i], edgesTo[j]));
		}

	}
}

template <class T>
void EdgeListGraph<T>::addEdge(const pair<T, T>& edge)
{
	edgeList.push_back(edge);
}

template <class T>
list<pair<T, T>> EdgeListGraph<T>::getList(void) const
{
	return edgeList;
}

template <class T>
bool EdgeListGraph<T>::areAdjacent(const T& a, const T& b) const
{
	for (list<pair<T, T>>::const_iterator it = edgeList.begin(); it != edgeList.end(); ++it)
	{
		if (a == it->first && b == it->second)
			return true;
	}

	return false;
}

template <class T>
bool EdgeListGraph<T>::isPath(const vector<T>& els) const
{
	for (int i = 0; i < els.size()-1; ++i)
	{
		if (!areAdjacent(els[i], els[i + 1]))
			return false;
	}

	return true;
}

template <class T>
void EdgeListGraph<T>::printGraph(void) const
{
	for (list<pair<T, T>>::const_iterator it = edgeList.begin(); it != edgeList.end(); ++it)
	{
		cout << it->first << " - " << it->second << endl;
	}
}

#endif