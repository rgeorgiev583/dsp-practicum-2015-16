#include <list>
#include <map>
#include <cstdlib>
#include <iostream>
using std::list;
using std::map;
using std::rand;
using std::pair;
using std::cout;
using std::endl;

void split(list<int>& firstList, list<int>& secondList, list<int>& toSplit)
{
	int count = 0;
	for (list<int>::iterator i = toSplit.begin(); i != toSplit.end(); i++)
	{
		if (count % 2 == 0)
		{
			firstList.push_back(*i);
		}
		else
		{
			secondList.push_back(*i);
		}
		++count;
	}
}

list<int> merge(list<int>& firstList, list<int>& secondList)
{
	list<int> mergedList;

	while (!firstList.empty() && !secondList.empty())
	{
		if (firstList.front() < secondList.front())
		{
			mergedList.push_back(firstList.front());
			firstList.pop_front();
		}
		else
		{
			mergedList.push_back(secondList.front());
			secondList.pop_front();
		}
	}

	while (!firstList.empty())
	{
		mergedList.push_back(firstList.front());
		firstList.pop_front();
	}

	while (!secondList.empty())
	{
		mergedList.push_back(secondList.front());
		secondList.pop_front();
	}

	return mergedList;
}

int main()
{
	list<int> testList;
	for (int i = 0; i < 100; i++)
	{
		testList.push_back((rand() % 10000) + 1);
	}

	map<int, int> countingSort;
	for (list<int>::iterator i = testList.begin(); i != testList.end(); i++)
	{
		map<int, int>::iterator pos = countingSort.find(*i);
		if (pos != countingSort.end())
		{
			(*pos).second += 1;
		}
		else
		{
			countingSort.insert((*i), 1);
		}
	}

	list<int> sortedList;
	for (map<int, int>::iterator i = countingSort.begin(); i != countingSort.end(); i++)
	{
		for (int j = 0; j < (*i).second; j++)
		{
			sortedList.push_back((*i).first);
		}
	}

	list<int> firstList, secondList;
	split(firstList, secondList, sortedList);
	list<int> newSortedList = merge(firstList, secondList);

	return 0;
}
