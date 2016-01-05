#include "LGraph.h"



std::list<int>* LGraph::find(int x)const
{
	for (auto l : nodes) {
		if (l->front() == x)
		{
			return l;
		}
	}
	return nullptr;
}

void LGraph::destroy()
{
	for (auto l : nodes) {
		delete l;
	}
}

LGraph::LGraph()
{
}


LGraph::~LGraph()
{
	this->destroy();
}

std::list<int>* LGraph::addVertex(int x)
{
	auto doesvertexExists = this->find(x);
	if (doesvertexExists != nullptr) {
		return doesvertexExists;
	}
	std::list<int>* new_vertex_list = new std::list<int>;
	new_vertex_list->push_front(x);
	this->nodes.push_back(new_vertex_list);
	return new_vertex_list;
}

std::list<int>* LGraph::addEdge(int a, int b)
{
	auto start = this->find(a);
	auto end = this->find(b);
	if (!start || !end) {
		return nullptr;
	}
	for (auto x : *start) {
		if (x == b) {
			return start;
		}
	}
	start->push_back(b);
	return start;
}

bool LGraph::areNeightbours(int a, int b) const
{
	auto start = this->find(a);
	auto end = this->find(b);
	if (!start || !end) {
		return false;
	}
	for (auto x : *start) {
		if (x == b) {
			return true;
		}
	}
	for (auto x : *end) {
		if (x == a) {
			return true;
		}
	}
	return false;
}

bool LGraph::isRoute(std::vector<int> path) const
{
	for (int i = 0; i < path.size() - 1; i++) {
		if (!this->areNeightbours(path[i], path[i + 1])) {
			return false;
		}
	}
	return true;
}
