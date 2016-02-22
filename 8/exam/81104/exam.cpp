#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <map>

using namespace std;

//task 1A
struct Node{
    int data;
    vector<Node*> children;
};

//task 1B
bool member(Node* root, int x){
    if (root == NULL) return false;
    if (root->data == x) return true;
    for (auto n : root->children){
        if (member(n, x)) return true;
    }
    return false;
}

//task 1C
void filterOdd(Node* root){
    if (root == NULL) return;
    if (root->data % 2 == 1) root = NULL;
    for (auto n : root -> children){
        filterOdd(n);
    }
}

//task 2A
int findMinInList(list<int>& myList){
    auto it = myList.begin();
    int minimal = *it;
    for (it; it != myList.end(); it++){
        if (*it < minimal) minimal = *it;
    }
    return minimal;
}

map<int, int>& countingSort(list<int>& myList){
    map<int, int> myMap;
    int minCounter, minimal;
    while (!myList.empty()){
        minCounter = 0;
        minimal = findMinInList(myList);
        for (auto it = myList.begin(); it != myList.end(); it++){
            if (*it == minimal) minCounter++;
        }
        myMap.insert( pair<int, int>(minimal, minCounter) );
        for (auto it = myList.begin(); it != myList.end(); it++){
            if (*it == minimal) myList.erase(it);
        }
    }
    return myMap;
}

//task 2B
list<int>& splitSort(map<int, int>& myMap){
    //split in two
    int turn = 0;
    list<int> list1;
    list<int> list2;
    while (!myMap.empty()){
        auto it = myMap.begin();
        while ((*it).second > 0){
            if (turn % 2 == 0){
                list1.push_back((*it).first);
                myMap[(*it).first] = ((*it).second) - 1;
            }
            if (turn % 2 == 1){
                list2.push_back((*it).first);
                myMap[(*it).first] = ((*it).second) - 1;
            }
            turn++;
        }
        myMap.erase(it);
    }
    //combine into sorted list
    list<int> sortedList;
    auto it1 = list1.begin();
    auto it2 = list2.begin();
    while (!list1.empty() && !list2.empty()){
        if (*it1 <= *it2){
            sortedList.push_back(*it1);
            list1.erase(it1);
        }
        else{
            sortedList.push_back(*it2);
            list2.erase(it2);
        }
    }
    while (!list1.empty()){
        sortedList.push_back(*it1);
        list1.erase(it1);
    }
    while (!list2.empty()){
        sortedList.push_back(*it2);
        list2.erase(it2);
    }
    return sortedList;
}

int main()
{
    list<int> myList;
    for (int i = 0; i < 10; i++){
        myList.push_back(rand()%10000);
    }
    return 0;
}
