#ifndef EDGE_LIST_H_INCLUDED
#define EDGE_LIST_H_INCLUDED

#include <list>
#include <utility>
#include <vector>

class ALGraph;
class IMGraph;

using namespace std;

class ELGraph{
private:
    list<pair<int,int>> edges;
public:
    ELGraph(){}
    friend class ALGraph;
    friend class IMGraph;

    void push_edge(pair<int,int> );
    bool are_adjacent(int, int );
    bool has_path(vector<int> );
    bool has_path(list<int> );

    list<int> collect_vertices_for(int );
    vector<int> collect_all_vertices();
    ALGraph transform_to_ALGraph();
    IMGraph transform_to_IMGraph();

    void print();
};

#endif // EDGE_LIST_H_INCLUDED
