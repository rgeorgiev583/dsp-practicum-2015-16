#include <iostream>
#include <list>
#include <map>
#include <random>
using namespace std;

bool odd(int x)
{
	return x % 2;
}

int main(void)
{
	list<int> l;

	//Creating list with 100 random numbers from 1 to 10000
	mt19937 engine;
	engine.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> distributor(1, 10000);

	for (int i = 0; i < 100; ++i)
	{
		l.push_back(distributor(engine));
	}

	//Sorting count with ordered map
	map<int, size_t> sortingMap;
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		sortingMap[*it]++;
	}

	//Building 2 sorted lists out of the sorted map
	list<int> sortedList1, sortedList2;
	int i = 0;
	bool flag = true;
	for (auto it = sortingMap.begin(); it != sortingMap.end(); ++it)
	{
		for (int i = 0; i < it->second; ++i)
		{
			if (flag)
			{
				sortedList1.push_back(it->first);
				flag = !flag;
			}
			else
			{
				sortedList2.push_back(it->first);
				flag = !flag;
			}
		}
	}

	//Merging the 2 sorted lists into 1
	list<int> mergedSortedList;
	list<int>::iterator it1 = sortedList1.begin(), it2 = sortedList2.begin();
	while ((it1 != sortedList1.end()) || (it2 != sortedList2.end()))
	{
		int toPush;
		if (it1!=sortedList1.end() && it2!=sortedList2.end())
		{
			if (*it1 < *it2)
			{
				toPush = *it1++;
			}
			else
			{
				toPush = *it2++;
			}
		}
		else if (it1 == sortedList1.end())
		{
			toPush = *it2++;
		}
		else
		{
			toPush == *it1++;
		}
		mergedSortedList.push_back(toPush);
	}

	return 0;
}