#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	vector<Node*> children;

	Node(int x) :data(x) {}
};

bool member(Node* root, int x)
{
	if (!root)
		return false;

	bool found = false;
	if (x == root->data)
		found = true;

	for (int i = 0; i < root->children.size() && !found; ++i)
	{
		found = member(root->children[i], x);
	}

	return found;
}

void printTree(Node* root)
{
	if (root)
	{
		cout << root->data << " ";
		for (int i = 0; i < root->children.size(); ++i)
			printTree(root->children[i]);
	}
}

bool odd(int x)
{
	return x % 2;
}

void deleteTree(Node*& root)
{
	for (int i = 0; i < root->children.size(); ++i)
		if(root->children[i]!=nullptr)
			deleteTree(root->children[i]);

	delete root;
	root = nullptr;
}

void filterOdd(Node*& root)
{
	if (root)
	{
		if (odd(root->data)) {
			deleteTree(root);
			return;
		}

		for (int i = 0; i < root->children.size(); ++i)
		{
			filterOdd(root->children[i]);
		}
	}
}

int main(void)
{
	Node* root = new Node(6);
	for (int i = 7; i < 13; ++i)
		root->children.push_back(new Node(i));
	root->children.push_back(new Node(10));

	for (int i = 0; i < 100; i = i++) root->children[3]->children.push_back(new Node(i));

	cout << member(root, 101);
	cout << endl;

	printTree(root);
	filterOdd(root); cout << endl;
	printTree(root);

	deleteTree(root);
	cout << endl;
	return 0;
}