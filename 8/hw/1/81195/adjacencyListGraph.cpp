#ifndef ADJLISTGRAPH_CPP_
#define ADJLISTGRAPH_CPP_

#include <list>
#include <iostream>
#include<set>
#include "Graph.h"
#include "EdgeListGraph.cpp"
#include "IncidenceMatrixGraph.cpp"
using namespace std;

template <class T>
struct AdjacencyListElement
{
	T element;
	list<T> neighbours;

	AdjacencyListElement(T el = T(), list<T> n = list<T>()) :element(el), neighbours(n) {}
};

template<class T>
class AdjacencyListGraph : public Graph<T>
{
public:
	AdjacencyListGraph() {}
	AdjacencyListGraph(const EdgeListGraph<T>&);
	AdjacencyListGraph(const IncidenceMatrixGraph<T>&);

	void addElement(const AdjacencyListElement<T>&);
	list<AdjacencyListElement<T>> getAdjList(void) const { return adjList; }

	virtual bool areAdjacent(const T&, const T&) const;
	virtual bool isPath(vector<T> const&) const;
	virtual void printGraph(void) const;
private:
	list<AdjacencyListElement<T>> adjList;
};

template<class T>
AdjacencyListGraph<T>::AdjacencyListGraph(const EdgeListGraph<T>& g)
{
	set<T> s;
	list<pair<T, T>> edgeList = g.getList();
	for (list<pair<T, T>>::iterator it = edgeList.begin(); it != edgeList.end(); ++it)
	{
		s.insert(it->first);
	}

	AdjacencyListElement<T> el;
	for (set<T>::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		el.element = *it;

		list<T> l;
		for (list<pair<T, T>>::const_iterator jt = edgeList.begin(); jt != edgeList.end(); ++jt)
		{
			if (*it == jt->first)
				l.push_back(jt->second);
		}

		el.neighbours = l;
		adjList.push_back(el);
	}
}

template<class T>
AdjacencyListGraph<T>::AdjacencyListGraph(const IncidenceMatrixGraph<T>& g)
{
	vector<T> els = g.getElements();
	vector<vector<int>> mat = g.getMatrix();

	AdjacencyListElement<T> curr;

	for (int i = 0; i < els.size(); ++i)
	{
		curr.element = els[i];
		list<T> n;

		vector<int> adjacent;
		for (int j = 0; j < mat[i].size(); j++)
		{
			if (mat[i][j] == 1)
				adjacent.push_back(j);
		}

		for (int j = 0; j < mat.size(); ++j)
		{
			if (j != i)
			{
				for (int k = 0; k < adjacent.size(); ++k)
				{
					if (mat[j][adjacent[k]] == 1)
						n.push_back(els[j]);
				}
			}
		}

		curr.neighbours = n;
		adjList.push_back(curr);
	}
}

template<class T>
void AdjacencyListGraph<T>::addElement(const AdjacencyListElement<T>& el)
{
	adjList.push_back(el);
}

template<class T>
bool AdjacencyListGraph<T>::areAdjacent(const T& v1, const T& v2) const
{
	for (list<AdjacencyListElement<T>>::const_iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		if (it->element == v1)
		{
			for (list<T>::const_iterator jt = it->neighbours.begin(); jt != it->neighbours.end(); ++jt)
			{
				if (*jt == v2)
					return true;
			}
		}
	}
	return false;
}

template<class T>
bool AdjacencyListGraph<T>::isPath(const vector<T>& vertice) const
{
	for (int i = 0; i < vertice.size() - 1; ++i)
	{
		if (!areAdjacent(vertice[i], vertice[i + 1]))
			return false;
	}

	return true;
}
template<class T>
void AdjacencyListGraph<T>::printGraph(void) const
{
	for (list<AdjacencyListElement<T>>::const_iterator it = adjList.begin(); it != adjList.end(); ++it)
	{
		cout << it->element << " -> ";
		for (list<T>::const_iterator jt = it->neighbours.begin(); jt != it->neighbours.end(); ++jt)
		{
			cout << *jt << " ";
		}
		cout << endl;
	}
}

#endif