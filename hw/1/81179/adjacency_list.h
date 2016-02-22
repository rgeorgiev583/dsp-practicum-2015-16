#ifndef ADJACENCY_LIST_H_INCLUDED
#define ADJACENCY_LIST_H_INCLUDED

#include <vector>
#include <list>

class ELGraph;
class IMGraph;

using namespace std;

struct ALGraphElement{
    int current_vertex;
    list<int> adjacency_list;
    ALGraphElement(int , list<int> );
};

class ALGraph{
private:
    vector<ALGraphElement> elements;
public:
    ALGraph(){}
    friend class ELGraph;
    friend class IMGraph;

    void push_vertex(int, list<int> );
    vector<int> collect_all_vertices();
    bool are_adjacent(int, int );
    bool has_path(vector<int> );
    bool has_path(list<int> );

    ELGraph transform_to_ELGraph();
    IMGraph transform_to_IMGraph();
    bool hasVertex(int );

    void print();
};

#endif // ADJACENCY_LIST_H_INCLUDED
