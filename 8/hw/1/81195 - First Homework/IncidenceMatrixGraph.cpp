#ifndef INCMATRIXGRAPH_CPP_
#define INCMATRIXGRAPH_CPP_

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "Graph.h"

using namespace std;

template<class T>
class AdjacencyListGraph;
template<class T>
struct AdjacencyListElement;

template<class T>
class EdgeListGraph;

template<class T>
class IncidenceMatrixGraph : public Graph<T>
{
public:
	IncidenceMatrixGraph() {}
	IncidenceMatrixGraph(const EdgeListGraph<T>&);
	IncidenceMatrixGraph(const AdjacencyListGraph<T>& g) : IncidenceMatrixGraph(EdgeListGraph<T>(g)) {}

	void addElements(const vector<T>& el, const vector<vector<int>>& edges);

	vector<T> getElements(void) const { return elements; }
	vector<vector<int>> getMatrix(void) const { return mat; }

	virtual bool areAdjacent(const T&, const T&) const;
	virtual bool isPath(vector<T> const&) const;
	virtual void printGraph(void) const;
private:
	vector<T> elements;
	vector<vector<int>> mat;
};

template<class T>
IncidenceMatrixGraph<T>::IncidenceMatrixGraph(const EdgeListGraph<T>& g)
{
	list<pair<T, T>> edges = g.getList();
	set<T> vertice;

	for (list<pair<T, T>>::iterator it = edges.begin(); it != edges.end(); ++it)
	{
		vertice.insert(it->first);
	}

	list<pair<T, T>>::iterator it = edges.begin();
	while (it != edges.end())
	{
		list<pair<T, T>>::iterator jt = edges.begin();
		while (jt != edges.end())
		{
			if (jt->second == it->first && jt->first == it->second)
				edges.erase(jt++);
			else
				jt++;
		}
		it++;
	}

	for (set<T>::iterator it = vertice.begin(); it != vertice.end(); ++it)
		elements.push_back(*it);

	vector<vector<int>> row(vertice.size(), vector<int>(edges.size(), 0));
	int j(0), i(0);
	for (list<pair<T, T>>::iterator jt = edges.begin(); jt != edges.end(); ++jt)
	{
		i = 0;
		for (set<T>::iterator it = vertice.begin(); it != vertice.end();++it)
		{
			if (jt->first == *it || jt->second == *it)
				row[i][j] = 1;

			i++;
		}
		j++;
	}
	mat = row;
}

template<class T>
void IncidenceMatrixGraph<T>::addElements(const vector<T>& el, const vector<vector<int>>& edges)
{
	elements = el;
	mat = edges;
}

template<class T>
bool IncidenceMatrixGraph<T>::areAdjacent(const T& a, const T& b) const
{
	vector<int> e;
	for (int i = 0; i < elements.size(); ++i)
	{
		if (elements[i] == a)
		{
			for (int j = 0; j < mat[i].size(); ++j)
			{
				if (mat[i][j] == 1)
					e.push_back(j);
			}
		}
	}
	if (e.size() == 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < elements.size(); ++i)
		{
			if (elements[i] == b)
			{
				for (int j = 0; j < e.size(); ++j)
				{
					if (mat[i][e[j]] == 1)
						return true;
				}
			}
		}
	}

	return false;
}

template <class T>
bool IncidenceMatrixGraph<T>::isPath(const vector<T>& els) const
{
	for (int i = 0; i < els.size() - 1; ++i)
	{
		if (!areAdjacent(els[i], els[i + 1]))
			return false;
	}
	return true;
}

template<class T>
void IncidenceMatrixGraph<T>::printGraph(void) const
{
	cout << "Elements: ";
	for (int i = 0; i < elements.size(); ++i)
		cout << elements[i] << " ";
	cout << endl << "Matrix: " << endl;

	for (int i = 0; i < mat.size(); ++i)
	{
		for (int j = 0; j < mat[i].size(); ++j)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

#endif