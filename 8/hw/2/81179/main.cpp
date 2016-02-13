#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <utility>

const int LENGTH = 6;

using namespace std;

void push_to_queue(int current_node, queue<int> &to_check, unordered_set<int> &current_set,
                   unordered_set<int> &reached, unordered_set<int> &in_queue,unordered_map<int,int> &result){

    for(auto it = current_set.begin(); it != current_set.end(); it++){
        if(in_queue.count(*it) == 0 && reached.count(*it) == 0){
            to_check.push(*it);
            in_queue.insert(*it);
            result[*it] = result[current_node] + LENGTH;
        }
    }
}

unordered_map<int,int> collect_lengths(int start, unordered_map<int,unordered_set<int>> &graph){
    unordered_set<int> reached;
    reached.insert(start);

    queue<int> to_check;
    to_check.push(start);

    unordered_map<int,int> result;
    result[start] = 0;

    unordered_set<int> in_queue;
    push_to_queue(start, to_check, graph[start], reached, in_queue, result);

    while(to_check.size() > 0){
        start = to_check.front();
        to_check.pop();
        unordered_set<int> current_level = graph[start];

        for(auto it = current_level.begin(); it != current_level.end(); it++){
            if(reached.count(*it) == 0){
                reached.insert(*it);
            }
        }

        for(auto it = current_level.begin(); it != current_level.end(); it++){
            push_to_queue((*it), to_check, graph[*it], reached, in_queue,result);
        }
    }

    return result;
}

int main(){
    vector<pair<int,unordered_map<int,unordered_set<int>>>> test_graphs;
    int cases;
    cin >> cases;

    while(cases > 0){
        int nodes, vertices;
        cin >> nodes >> vertices;
        unordered_map<int,unordered_set<int>> test;

        for(int i = 1; i < nodes + 1; i++){
            unordered_set<int> adjacent;
            test[i] = adjacent;
        }

        int v1, v2;
        for(int i = 0; i < vertices; i++){
            cin >> v1 >> v2;
            test[v1].insert(v2);
            test[v2].insert(v1);
        }

        int start;
        cin >> start;

        pair<int,unordered_map<int,unordered_set<int>>> ready_for_testing(start,test);
        test_graphs.push_back(ready_for_testing);

        cases--;
    }

    for(auto it = test_graphs.begin(); it != test_graphs.end(); it++){
        int start_point = (*it).first;
        unordered_map<int,unordered_set<int>> graph = (*it).second;
        unordered_map<int,int> BFS_table = collect_lengths(start_point, graph);

        for(int i = 1; i <= graph.size(); i++){
            if(i != start_point){
                if(BFS_table[i] == 0)
                    cout << -1 << " ";
                else
                    cout << BFS_table[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
