#include "TreeNode.h"
#include <iostream>

using namespace std;

bool member(TreeNode* root, int x) { 
	if (root->value == x) { 
		return true;
	}

	for (int i = 0; i < root->children.size(); i++) { 
		if (member(root->children[i], x)) { 
			return true;
		}
	}
	
	return false;
}

void filterOdd(TreeNode* root) {
	// In case root value is odd - erase it
	if (root->value % 2 != 0) { 
		root = NULL;
		return;
	}
	// Remove all nodes with odd root values
	for (int i = 0; i < root->children.size(); i++) {
		vector<TreeNode*> children = root->children;
		if (children[i]->value % 2 != 0) { 
			root->children.erase(root->children.begin() + i);
		}
	}

	// Call the filter funciton for all nodes with even root values
	for(int i = 0; i < root->children.size(); i++) {
		filterOdd(root->children[i]);
	}
}

int main() { 
	TreeNode a(6);
	TreeNode b(2);
	TreeNode c(9);
	TreeNode d(12);
	TreeNode e(13);

	a.add_child(&b);
	a.add_child(&c);
	b.add_child(&d);
	b.add_child(&e);

	filterOdd(&a);

	cout << member(&a, 13);

	cin.get();
}