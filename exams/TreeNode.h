#pragma once
#include <vector>

using namespace std;

struct TreeNode
{
	// value
	// children
	// is_leaf = children.size() == 0

	int value;
	vector<TreeNode*> children;

	void add_child(TreeNode* child) { 
		children.push_back(child);
	}

	TreeNode(int _value = 0, vector<TreeNode*> _children = vector<TreeNode*>()):
		value(_value), children(_children) {}
};

