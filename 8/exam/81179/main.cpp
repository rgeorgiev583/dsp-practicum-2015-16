#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <map>

using namespace std;

//ex1

class Node{
private:
    int x;
    vector<Node*> adjacentNodes;
public:
    Node(int _x): x(_x){}

    void push_adjacent_node(Node* _x){
        adjacentNodes.push_back(_x);
    }

    vector<Node*> getNodes() const{
        return adjacentNodes;
    }

    void deleteOddNodes(){
        vector<Node*> result;

        for(auto it = adjacentNodes.begin(); it != adjacentNodes.end(); it++){
            if((*it)->x % 2 == 0)
                result.push_back(*it);
        }

        adjacentNodes = result;
    }

    bool member(Node* root, int _x){
        if(root->x == _x)
            return true;
        else{
            for(auto it = root->getNodes().begin(); it != root->getNodes().end(); it++){
                member((*it),_x);
            }
        }
        return false;
    }

    void filterOdd (Node* root){
        if(root->x % 2 != 0)
            delete root;
        for(size_t i = 0; i < root->adjacentNodes.size(); i++){
            root->deleteOddNodes();
        }
        vector<Node*> nodes = root->getNodes();
        for(size_t i = 0; i < nodes.size(); i++){
            filterOdd(nodes[i]);
        }
    }

};

int main()
{
    //tests for ex1
    Node a(5);
    Node b(4);
    Node c(3);

    a.push_adjacent_node(&b);
    a.push_adjacent_node(&c);

    cout << a.getNodes().size() << endl;

    cout << a.member(&b, 4) << endl;
    cout << a.member(&b, 5) << endl;

    a.deleteOddNodes();
    cout << a.getNodes().size() << endl;


    //ex2
    list<int> random_nums;
    for(int i = 0; i < 100; i++){
        random_nums.push_back(rand() % 10000 + 1);
    }

    map<int,int> countingSort;
    for(auto it = random_nums.begin(); it != random_nums.end(); it++){
        countingSort[(*it)] += 1;
    }

    for(auto it = countingSort.begin(); it != countingSort.end(); it++){
       cout << (*it).first << " " << (*it).second << endl;
    }

    cout << endl << endl;

    list<int> first_list;
    list<int> second_list;

    for(auto it = countingSort.begin(); it != countingSort.end(); it++){
        int repetition = countingSort[(*it).first];

        if(repetition >= 2){
            for(int i = 0; i < repetition / 2; i++){
                first_list.push_back((*it).first);
                second_list.push_back((*it).first);
            }
        }

        if(repetition % 2 != 0 && first_list.size() < second_list.size()){
            first_list.push_back((*it).first);
        }else{
            if(repetition % 2 != 0)
                second_list.push_back((*it).first);
        }
    }

    cout  << endl;

    for(auto it = first_list.begin(); it != first_list.end(); it++){
        cout << *it << " ";
    }
    cout  << endl;
    cout  << endl;

    for(auto it = second_list.begin(); it != second_list.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Size of lists" << endl;
    cout << "first: " << first_list.size() << endl;
    cout << "second: " << second_list.size() << endl;

    list<int> merged_list;
    int temp;
    while(first_list.size() > 0 && second_list.size() > 0){
        if(first_list.front() <= second_list.front()){
            temp = first_list.front();
            merged_list.push_back(temp);
            first_list.pop_front();
        }else{
            temp = second_list.front();
            merged_list.push_back(temp);
            second_list.pop_front();
        }
    }

    if(first_list.size() > 0){
        temp = first_list.front();
        merged_list.push_back(temp);
        first_list.pop_front();
    }

    if(second_list.size() > 0){
        temp = second_list.front();
        merged_list.push_back(temp);
        second_list.pop_front();
    }

    cout << endl;
    cout << "Merged list:" << endl;
    for(auto it = merged_list.begin(); it != merged_list.end(); it++){
        cout << *it << " ";
    }

    return 0;
}
