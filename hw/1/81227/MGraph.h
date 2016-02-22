#pragma once
#include "Graph.h"
#include <vector>

using namespace std;

template <typename T>
class MGraph : public Graph<T>
{
private:
	vector<vector<bool>> matrix;
public:

	vector<vector<bool>> getMatrix() const { return matrix; }

	MGraph(vector<vector<bool>> _matrix = vector<vector<bool>>()) : matrix(_matrix) { }

	bool areAdjacent(Node<T> first, Node<T> second) const { 
		return matrix[first.value][second.value];
	}

	void print() const { 
		for(int i = 0; i < matrix.size(); i++) { 
			for(int j = 0; j < matrix.size(); j++) { 
				if(matrix[i][j]){ 
					cout << "[" << i << "]" << "[" << j << "]" << " = true" << endl;
				}
			}
		}
	}

	~MGraph(void)
	{
	}
};

