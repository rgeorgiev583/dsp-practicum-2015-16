#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <map>

using namespace std;

struct TreeNode {
	int data;
	vector<TreeNode*> children;
	TreeNode(int _data) :data(_data) {}
};

bool member(TreeNode* root, int x) {
	if (root == nullptr) {
		return false;
	}
	if (root->data == x) {
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
	if (root->data % 2 != 0) {
		delete root;
		root = nullptr;
	}
	if (root == nullptr) {
		return;
	}
	for (int i = 0; i < root->children.size(); i++) {
		TreeNode* current = root->children[i];

		if (current->data % 2 != 0) {
			//delete current;
			root->children.erase(root->children.begin() + i);
			continue;
		}
		filterOdd(*(root->children.begin() + i));
	}
}
void test_zad1() {
	TreeNode c2(2);
	TreeNode c3(3);
	TreeNode c4(4);
	TreeNode c5(5);
	TreeNode c6(6);
	TreeNode father(8);
	father.children.push_back(&c2);
	father.children.push_back(&c3);
	father.children.push_back(&c4);
	father.children.push_back(&c5);
	father.children.push_back(&c6);

	filterOdd(&father);
	return;
}

void printMap(map<int, int> data) {
	for (auto it = data.begin(); it != data.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}
}

void CountingSort(list<int>& data) {
	map<int, int> container;
	//list<int> result;

	for (auto x : data) {
		if (container[x] == 0) {
			container[x] = 1;
		}
		else {
			container[x]++;
		}
	}

	data.clear();

	for (auto it = container.begin(); it != container.end(); it++) {
		for (int i = 0; i < (*it).second; i++) {
			data.push_back((*it).first);
		}
	}

	//data = result;
	return;
}

void split(list<int>& container, list<int>& first, list<int>& second) {
	bool insertFirst = true;
	first.clear();
	second.clear();

	for (auto x : container) {
		if (insertFirst) {
			first.push_back(x);
		}
		else {
			second.push_back(x);
		}

		insertFirst = !insertFirst;
	}
}

list<int> merge(list<int>& first, list<int>& second) {
	list<int> result;
	auto firstIt = first.begin();
	auto secondIt = second.begin();
	while (firstIt != first.end() && secondIt != second.end()) {
		if ((*firstIt) <= (*secondIt)) {
			result.push_back((*firstIt));
			firstIt++;
		}
		else {
			result.push_back((*secondIt));
			secondIt++;
		}
	}
	//at this point either first or second is traversed
	for (firstIt; firstIt != first.end(); firstIt++) {
		result.push_back(*firstIt);
	}
	for (secondIt; secondIt != second.end(); secondIt++) {
		result.push_back(*secondIt);
	}

	return result;
}

void zad2() {
	srand(time(0));
	list<int> data;
	map<int, int> result;
	for (int i = 0; i < 100; i++) {
		data.push_back(rand() % 10000 + 1);
	}

	CountingSort(data);
	for (auto x : data) {
		cout << x << endl;
	}
	cout << endl;

	list<int> first, second;
	split(data, first, second);

	cout << (data == merge(first, second)) << endl;

}
int main()
{
	test_zad1();
	//zad2();
    return 0;
}
