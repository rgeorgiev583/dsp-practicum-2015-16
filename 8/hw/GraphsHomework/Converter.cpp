#include "EGraph.h"
#include "LGraph.h"
#include "MGraph.h"
using namespace std;

template<typename T>
EGraph<T> LtoE(LGraph<T>& lg) {
		auto edges = list<Edge<T>>();
		auto adjList = lg.getAdjList();
		for(auto i = adjList.begin(); i != adjList.end(); i++) { 
			auto neighbours = (*i).neighbours;
			for(auto j = neighbours.begin(); j != neighbours.end(); j++) { 
				edges.push_back(Edge<T>((*i), (*j)));
			}
		}
		EGraph<T> result(edges);
		return result;
}

template<typename T>
MGraph<T> EtoM(EGraph<T>& eg) { 
		auto matrix = vector<vector<bool>>();
		auto edges = eg.getEdges();
		int biggestValue = 0;

		for(auto i = edges.begin(); i != edges.end(); i++) {
			if((*i).from.value > biggestValue) biggestValue = (*i).from.value;
			if((*i).to.value > biggestValue) biggestValue = (*i).to.value;
		}

		for(auto i = 0; i <= biggestValue; i++) {
			matrix.push_back(vector<bool>());
			for(auto j = 0; j <= biggestValue; j++) { 
				matrix[i].push_back(false);
			}
		}

		for(auto k = edges.begin(); k != edges.end(); k++) {
			auto from = (*k).from.value;
			auto to = (*k).to.value;
			matrix[from][to] = true;
		}

		MGraph<T> result(matrix);
		return result;
}

template<typename T>
LGraph<T> MtoL(MGraph<T>& mg) { 
	auto matrix = mg.getMatrix();
	list<Node<T>> nodes;
	for(int i = 0; i < matrix.size(); i++) {
		nodes.push_back(Node<T>(i));
	}

	for(auto i = nodes.begin(); i != nodes.end(); i++) {
		auto currentNode = (*i);
		for(auto j = nodes.begin(); j != nodes.end(); j++) { 
			if(matrix[(*i).value][(*j).value]) { 
				(*i).neighbours.push_back((*j));
			}
		}
	}

	LGraph<T> result(nodes);
	return result;
}

// Will be included in v1.1
//template<typename T>
//MGraph<T> LtoM(LGraph<T>& lg) {
//	MGraph<T> result = EtoM(LtoE(lg));
//	return result
//}

// Will be included in v1.1
//template<typename T>
//EGraph<T> MtoE(MGraph<T>& mg) {
//	LGraph<T>& firstStep = MtoL(mg);
//	EGraph<T> result = LtoE(firstStep);
//	return result;
//}

// Will be included in v1.1
//template<typename T>
//LGraph<T> EtoL(EGraph<T>& eg) { 
//	LGraph<T> result = MtoL(EtoM(eg));
//	return result;
//}