#include <map>
#include <random>
#include <vector>
#include <iostream>

using namespace std;

void sort_list(vector<int> list) { 
	map<int, int> count_occurences;
	
	// Counting occurences of each element in the input list
	for(int i = 0; i < list.size(); i++) { 
		count_occurences[list[i]]++;
	}

	vector<int> sorted_list;

	// Generating sorted list based on the occurences of each element in the input
	for (auto it = count_occurences.begin(); it != count_occurences.end(); it++) { 
		for(int i = 0; i < (*it).second; i++) { 
			sorted_list.push_back((*it).first);
		}
	}

	vector<int> first_sorted_list;
	vector<int> second_sorted_list;

	vector<int> combined_sorted_list;


	// Splitting the sorted list in two
	for (int i = 0; i < sorted_list.size(); i++) { 
		if (i % 2 == 0) { 
			first_sorted_list.push_back(sorted_list[i]);
		} else { 
			second_sorted_list.push_back(sorted_list[i]);
		}
	}

	// Creating a sored list from the above generated two lists
	for(int i = 0; i < sorted_list.size() / 2; i++) { 
		combined_sorted_list.push_back(first_sorted_list[i]);
		combined_sorted_list.push_back(second_sorted_list[i]);
	}


	// Comparing the sorted lists - on the left side is the combination between the split lists,
	// And on the right is the initial sorted list based on the occurences of elements in the input
	for (int i = 0; i < combined_sorted_list.size(); i++) { 
		cout << combined_sorted_list[i] << " - " << sorted_list[i] << endl;
	}
}

vector<int>& random_list_sort() { 
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> range(1, 10000); // 1: 10-000

	vector<int> output(100);

	for(int i = 0; i < 100; i++) {
		output[i] = (range(mt));
	}

	sort_list(output);

	return output;
}
// Uncomment for awesomeness
//int main() { 
//	vector<int> test = random_list_sort();
//
//	cin.get();
//}