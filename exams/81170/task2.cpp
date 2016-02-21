#include <list>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

list<int> mergeSortedLists(list<int>& l1, list<int>& l2) {
  list<int> result;

  list<int>::iterator it1 = l1.begin();
  list<int>::iterator it2 = l2.begin();
  while (it1 != l1.end() && it2 != l2.end()) {
    if (*it1 < *it2) {
      result.push_back(*it1);
      ++it1;
    } else {
      result.push_back(*it2);
      ++it2;
    }
  }
  while (it1 != l1.end()) {
    result.push_back(*it1);
    ++it1;
  }
  while (it2 != l2.end()) {
    result.push_back(*it2);
    ++it2;
  }

  return result;
}

list<int> generateRandomList() {
  srand(time(NULL));

  list<int> linkedList(100);

  for (int i = 0; i < 100; ++i) {
    int random = rand() % 10000 + 1;
    linkedList.push_back(random);
  }

  return linkedList;
}

vector<int> countingSort(list<int>& linkedList) {
  vector<int> count(10000, 0);

  for (list<int>::iterator it = linkedList.begin();
       it != linkedList.end(); ++it) {
    count[*it - 1]++;
  }

  return count;
}

void generateSortedLists(list<int>& linkedList, vector<int>& count,
                         list<int>& l1, list<int>& l2) {
  int turn = 0;

  for (int i = 0; i < 10000; ++i) {
    int currentCount = count[i];

    while (currentCount) {
      if (turn % 2 == 0) {
        l1.push_back(i + 1);
      } else {
        l2.push_back(i + 1);
      }

      --currentCount;
      ++turn;
    }
  }
}

int main() {
  list<int> linkedList = generateRandomList();

  vector<int> count = countingSort(linkedList);

  list<int> l1;
  list<int> l2;
  generateSortedLists(linkedList, count, l1, l2);

  list<int> merged = mergeSortedLists(l1, l2);

  for (list<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
    cout << *it << ' ';
  }
  cout << '\n';

  for (list<int>::iterator it = l2.begin(); it != l2.end(); ++it) {
    cout << *it << ' ';
  }
  cout << '\n';

  for (list<int>::iterator it = merged.begin(); it != merged.end(); ++it) {
    cout << *it << ' ';
  }
  cout << '\n';

  return 0;
}