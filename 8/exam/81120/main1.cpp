#include<iostream>
#include<vector>
#include<ctime>
#include<map>
#include"node.h"
using namespace std;

const int MaxElements = 100;

map<int, int> countingSort(vector<int> list) {
	map<int, int>  result;
	for (int i = 0; i < MaxElements; i++) {
		auto it = result.find(list[i]);
		if (it != result.end()) {
			result[list[i]] += 1;
		}
		else {
			result[list[i]] = 1;
		}
	}
	return result;

}

map<int, int> merge(map<int, int> fst, map<int, int> snd) {
	map<int, int> result;
	for (auto it = fst.begin(); it != fst.end(); it++) {
		result[(*it).first] = (*it).second;
	}
	for (auto it = snd.begin(); it != snd.end(); it++) {
		int keyToFind = (*it).first;
		auto rit = result.find(keyToFind);
		if (it != result.end()) {
			(*it).second += (*it).second;
		} else 
			result[keyToFind] = (*it).second;
	}
	return result;
}

void zad2() {
	srand(time(NULL));
	vector<int> list;
	for (int i = 0; i < MaxElements; i++) {
		list.push_back(rand() % 10000 + 1);
	}
	//a
	map<int, int> result = countingSort(list);

	//б
	map<int, int> firstSorted;
	map<int, int> secondSorted;
	int i = 0;
	for (auto it = result.begin(); it != result.end(); it++, i++) {
		if (i % 2 == 0) {
			firstSorted[(*it).first] = (*it).second;
		}
		else secondSorted[(*it).first] = (*it).second;
	}
	map<int, int> merged = merge(firstSorted, secondSorted);
	

}

int main() {
	cout << 5;
	zad2();
	cin.get();
	return 0;
}