#ifndef INCIDENCE_MATRIX_H_INCLUDED
#define INCIDENCE_MATRIX_H_INCLUDED

#include <vector>
#include <list>

class ALGraph;
class ELGraph;

using namespace std;

class IMGraph{
private:
    vector<int> vertices;
    list<list<int>> matrix;
public:
    IMGraph(){}
    friend class ALGraph;
    friend class ELGraph;

    void set_vertices(vector<int> );
    void set_edge(int, int );
    list<int> collect_vertices_for(int );

    bool are_adjacent(int, int );
    bool has_path(vector<int> );
    bool has_path(list<int> );

    ALGraph transform_to_ALGraph();
    ELGraph transform_to_ELGraph();

    void print();

};

#endif // INCIDENCE_MATRIX_H_INCLUDED
