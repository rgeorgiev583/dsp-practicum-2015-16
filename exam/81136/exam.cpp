
#include<iostream>
#include <list>
#include <map>
using namespace std;

struct Tree {
	int root;
	list<Tree> successors;

	Tree() : root(0) {}
	bool noSuccs() { return successors.empty(); }
};

bool member(Tree t, int& x) { 
	if (t.root == x) return true;
	for (list<Tree>::iterator it = t.successors.begin(); it != t.successors.end(); ++it) {
		member(*it, x);
	}
}

void mycountingSort(list<int> l, map<int,int>& m) {
	int curr = 0;
	while (!l.empty()) {
		curr = l.back();
		if (m.count(curr) > 0)
			m[curr] += 1;
		else
			m[curr] = 1;
		l.pop_back();
	}
}

void generateTwo(map<int,int>&m ,list<int>& l1, list<int>& l2) {
	bool pushInFirst = true;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
		for (int i = 1; i <= it->second; i++) {
			if (pushInFirst)
				l1.push_back(it->first);
			else
				l2.push_back(it->first);
			pushInFirst = !pushInFirst;
		}
	}	
}

bool mycomparison(double first, double second)
{
	return (int(first)<int(second));
}

void combineTwo(list<int> l1, list<int> l2, list<int>& l) {
	//l1.merge(l2);
	//l = l1;
	bool getFromFirst = true;
	while (!l2.empty()) {
		if (getFromFirst) {
			l.push_back(l1.front());
			l1.pop_front();
		}
		else {
			l.push_back(l2.front());
			l2.pop_front();
		}
		getFromFirst = !getFromFirst;
	}
}

void zad2() {
	list<int> l, l1, l2, lC;
	map<int, int> m;
	int r;

	for (int i = 0; i < 100; i++) {
		r = rand() % 10000 + 1;
		l.push_back(r);
	}

	mycountingSort(l, m);
	cout << "sorted map" << endl;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
		cout << it->first << " => " << it->second << '\n';


	generateTwo(m, l1, l2);

	cout << "list 1" << endl;
	for (list<int>::iterator it1 = l1.begin(); it1 != l1.end(); ++it1)
		cout << *it1 << ' ';
	cout << endl << "list 2" << endl;
	for (list<int>::iterator it2 = l2.begin(); it2 != l2.end(); ++it2)
		cout << *it2 << ' ';

	cout << endl << "Combined list" << endl;

	combineTwo(l1, l2, lC);


	for (list<int>::iterator itC = lC.begin(); itC != lC.end(); ++itC)
		cout << *itC << ' ';
}

int main()
{
	zad2();

	getchar();

    return 0;
}

