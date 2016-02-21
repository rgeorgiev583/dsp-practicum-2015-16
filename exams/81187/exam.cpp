// SDPpract.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <list>
#include <map>
using namespace std;

//side functions
void printList(list<int>& l)
{
	for (auto element : l)
	{
		cout << element << " ";
	}
}

//task1 A
struct TreeNode
{
	int data;
	vector<TreeNode*> subNodes;
};

//task1 B
bool member(TreeNode* root, int x)
{
	if (root == NULL)
		return false;
	if ((*root).data == x)
		return true;
	for (auto node : root->subNodes)
	{
		if (member(node, x))
			return true;
	}
	return false;
}

//task1 C
void filterOdd(TreeNode* root)
{
	if (root == NULL)
		return;

	int size = root->subNodes.size();
	for (int i = 0; i < size; i++)
	{
		if (root->subNodes[i]->data % 2 != 0)
		{
			root->subNodes.erase(root->subNodes.begin() + i);
			size = root->subNodes.size();
			i--;
		}
	}
	for (int i = 0; i < root->subNodes.size(); i++)
	{
		filterOdd(root->subNodes[i]);
	}
}

//task2
list<int> generateList()
{
	list<int> l;
	for (int i = 0; i < 100; i++)
	{
		l.push_back(rand() % 10000);
	}
	return l;
}

//task2 A
map<int, int> countingSort(list<int>& l)
{
	map<int, int> sorted;
	for (auto element : l)
	{
		sorted[element]++;
	}
	return sorted;
}

//task2 B
void task2B(list<int>& l)
{
	map<int, int> m(countingSort(l));
	list<int> first, second;
	bool inFirst = true;
	for (auto num : m)
	{
		for (int i = 0; i < num.second; i++)
		{
			if (inFirst)
				first.push_back(num.first);
			else
				second.push_back(num.first);
			inFirst ? inFirst = false : inFirst = true;
		}
	}

	list<int> sorted;
	list<int>::iterator it1 = first.begin(), it2 = second.begin();
	while (it1 != first.end() && it2 != second.end())
	{
		if ((*it1) <= (*it2))
		{
			sorted.push_back(*it1);
			it1++;
		}
		else
		{
			sorted.push_back(*it2);
			it2++;
		}
	}
	while (it1 != first.end())
	{
		sorted.push_back(*it1);
		it1++;
	}
	while (it2 != second.end())
	{
		sorted.push_back(*it2);
		it2++;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

