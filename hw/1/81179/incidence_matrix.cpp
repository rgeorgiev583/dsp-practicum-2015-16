#include <iostream>
#include "incidence_matrix.h"
#include "edge_list.h"
#include "adjacency_list.h"
#include <utility>
#include <vector>

using namespace std;

void IMGraph::set_vertices(vector<int> _vertices){
    vertices = _vertices;
}

void IMGraph::set_edge(int vertex1, int vertex2){
    list<int> vertex_column;
    for(auto it = vertices.begin(); it != vertices.end(); it++){
        if(*it == vertex1) vertex_column.push_back(-1);
        if(*it == vertex2) vertex_column.push_back(1);
        if(*it != vertex1 && *it != vertex2) vertex_column.push_back(0);
    }
    matrix.push_back(vertex_column);
}

list<int> IMGraph::collect_vertices_for(int vertex){
    list<int> result;
    for(auto it = vertices.begin(); it != vertices.end(); it++){
        if(are_adjacent(vertex,*it))
            result.push_back(*it);
    }
    return result;
}

bool IMGraph::are_adjacent(int vertex1, int vertex2){
    for(auto helper = matrix.begin(); helper != matrix.end(); helper++){
        list<int> help_find = *helper;
        auto it = vertices.begin();
        bool beginning = false;
        bool ending = false;
        for (auto position = help_find.begin(); position != help_find.end(); position++, it++){
            if(*it == vertex1 && *position == -1) beginning = true;
            if(*it == vertex2 && *position == 1)  ending = true;
        }
        if(beginning && ending) return true;
    }
    return false;
}

bool IMGraph::has_path(vector<int> path){
    for(auto searcher = path.begin(); searcher != path.end() - 1; searcher++){
        int vertex_one = *searcher;
        searcher++;
        int vertex_two = *searcher;
        searcher--;
        if (!are_adjacent(vertex_one, vertex_two))
            return false;
    }
    return true;
}

bool IMGraph::has_path(list<int> path){
    if (path.size() == 1) return true;

    int vertex1 = path.front();
    path.pop_front();
    int vertex2 = path.front();

    if (are_adjacent(vertex1, vertex2)){
        return has_path(path);
    }else
        return false;
}

ELGraph IMGraph::transform_to_ELGraph(){
    ELGraph transformed;
    for(auto it = matrix.begin(); it != matrix.end(); it++){
        list<int> temp = *it;
        int vertex1, vertex2;
        auto helper = vertices.begin();
        for(auto searcher = temp.begin(); searcher != temp.end(); searcher++, helper++){
            if(*searcher == -1) vertex1 = *helper;
            if(*searcher == 1)  vertex2 = *helper;
        }
        pair<int,int> pusher(vertex1,vertex2);
        transformed.push_edge(pusher);
    }
    return transformed;
}

ALGraph IMGraph::transform_to_ALGraph(){
    ALGraph transformed;
    for(auto it = vertices.begin(); it != vertices.end(); it++){
        list<int> temp = collect_vertices_for(*it);
        transformed.push_vertex(*it, temp);
    }
    return transformed;
}

void IMGraph::print(){
    cout << "Vertices: ";
    for(auto it = vertices.begin(); it != vertices.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;
    for(auto printit = matrix.begin(); printit != matrix.end(); printit++){
        list<int> printer = *printit;
        cout << "          ";
        for(auto deeper = printer.begin(); deeper != printer.end(); deeper++){
            if (*deeper == 0 || *deeper == 1) cout << *deeper << "  ";
            else cout << *deeper << " ";
        }
        cout << endl;
    }
}
