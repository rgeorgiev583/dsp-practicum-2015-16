#pragma once

#include <iostream>
#include<vector>

using namespace std;

struct Node {
	int value;
	vector<int> agj;

	Node(int r = 0, vector<int> a = vector<int>()) : value(r), agj(a) {};
};

class Tree {
private:
	vector<Node> nodes;
	Node* root;

public:
	Tree();
	bool member(Node* root, int x);
	bool areAdj(Node* root, int x);
	Node* findNode(int x);
	void filterOdd();
};