#include"node.h"
#include<queue>
#include<map>

using namespace std;

Tree::Tree() :nodes(vector<Node>()), root(NULL) {}

bool Tree::areAdj(Node* root, int x) {
	for (int i = 0; i < root->agj.size(); i++) {
		if (root->value == x)
			return true;
	}
	return false;
}

Node* Tree::findNode(int x) {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i].value == x)
			return &nodes[i];
	}
	return NULL;
}

bool Tree::member(Node* root, int x) {
	if (root->value == x)
		return true;
	else {
		if (areAdj(root, x))
			return true;
		else {
			for (int i = 0; i < root->agj.size(); i++) {
				Node* curr = findNode(root->agj[i]);
				if (curr != NULL)
					member(curr, x);
				else return false;
			}
		}
	} 
}

void filterOdd(Tree* root) {
	root->filterOdd();
}

void Tree::filterOdd() {
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		if ((*it).value % 2 != 0) {
			nodes.erase(it);
		}
	}
}