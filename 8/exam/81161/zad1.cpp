#include <vector>
using std::vector;

struct Node
{
	int data;
	vector<Node*> successors;

	Node(int aData, const vector<Node*>& aSuccessors = vector<Node*>()) 
		                            : data(aData), successors(aSuccessors) {}
};

bool member(const Node* root, int x)
{
	if (root->data == x)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < root->successors.size(); i++)
		{
			member(root->successors[i], x);
		}
	}
}

void deleteNode(Node*& root)
{
	for (int i = 0; i < root->successors.size(); i++)
	{
		deleteNode(root->successors[i]);
	}
	delete root;
	root = nullptr;
}

void filterOdd(Node* root)
{
	if ((root->data) % 2 == 1)
	{
		deleteNode(root);
	}
	else
	{
		for (int i = 0; i < root->successors.size(); i++)
		{
			filterOdd(root->successors[i]);
		}
	}
}
