#include "MGraph.h"
#include "LGraph.h"
#include <iostream>

int** MGraph::multiplyMatrix(int degree)
{
	int** result = new int*[size];
	for (int i = 0; i < size; i++) {
		result[i] = new int[size];
		result[0][i] = this->M[0][i];
		result[i][0] = this->M[0][i];
	}
	for (int times = 1; times <= degree; times++) {
		for (int ai = 1; ai < size; ai++) {
			for (int aj = 1; aj < size; aj++) {
				int current_box = 0;
				for (int i = 1; i < size; i++) {
					current_box += M[i][aj] * M[ai][i];
				}
				result[ai][aj] = current_box;
			}
		}
	}
	return result;
}

void MGraph::resize()
{
	
	int** new_container = new int*[2*capacity];
	for (int i = 0; i < capacity * 2; i++) {
		new_container[i] = new int[capacity * 2];
	}

	for (int i = 0; i < this->capacity; i++) {
		for (int j = 0; j < this->capacity; j++) {
			new_container[i][j] = this->M[i][j];
		}
	}
	for (int i = capacity; i < this->capacity*2; i++) {
		for (int j = capacity; j < this->capacity*2; j++) {
			new_container[i][j] = 0;
		}
	}
	this->destroy();
	this->M = new_container;
	this->print();
	this->capacity *= 2;
}

void MGraph::destroy()
{
	for (int i = 0; i < capacity; i++) {
		delete[] this->M[i];
	}
	delete[] M;
}

Pair MGraph::find_two_vertices(int a, int b,int** Container, int size)const
{
	Pair pair(0,0);
	for (int i = 0; i < size && (pair.a == 0 || pair.b == 0); i++) {
		if (Container[0][i] == a) {
			pair.a = i;
		}
		if (Container[0][i] == b) {
			pair.b = i;
		}
	}

	return pair;
}

void MGraph::print() const
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << M[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

MGraph::MGraph()
{
	this->capacity = INITIAL_CAPACITY;
	this->M = new int*[capacity];
	for (int i = 0; i < capacity; i++) {
		M[i] = new int[capacity];
		for (int j = 0; j < capacity; j++) {
			M[i][j] = 0;
		}
	}
	this->M[0][0] = 0;
	this->size = 1;
}

MGraph::MGraph(const LGraph & lg)
{
	this->capacity = INITIAL_CAPACITY;
	this->M = new int*[capacity];
	for (int i = 0; i < capacity; i++) {
		M[i] = new int[capacity];
		for (int j = 0; j < capacity; j++) {
			M[i][j] = 0;
		}
	}
	this->M[0][0] = 0;
	this->size = 1;

	for (auto l : lg.nodes) {
		this->addVertex(l->front());
	}
	for (auto l : lg.nodes) {
		for (auto it = ++l->begin(); it != l->end(); it++) {
			this->addEdge(l->front(), *it);
		}
	}
}


MGraph::~MGraph()
{
	this->destroy();
}

void MGraph::addVertex(int v)
{
	if ((float)size / capacity > 0.8) {
		this->resize();
	}
	//TODO add check if this vertex already exists
	this->M[0][size] = v;
	this->M[size][0] = v;
	this->size++;
}

void MGraph::addEdge(int a, int b)
{
	Pair pair = this->find_two_vertices(a, b, this->M, this->size);
	//if the graph will be oriented remove one of the statements
	this->M[pair.a][pair.b] = 1;
}

bool MGraph::areNeightbours(int a, int b)const
{
	Pair pair = this->find_two_vertices(a, b, this->M, this->size);
	//if the graph will be oriented remove one of the statements
	return M[pair.a][pair.b] == 1 || M[pair.b][pair.a] == 1;
}

bool MGraph::isRoute(std::vector<int> path)const
{
	Pair pair(0,0);
	for (int i = 0; i < path.size() - 1; i++) {
		if (!this->areNeightbours(path[i], path[i + 1])) {
			return false;
		}
	}
	return true;
}

bool MGraph::isPath(int, int)
{
	//TODO implement path search between two vertices with random length
	return false;
}


