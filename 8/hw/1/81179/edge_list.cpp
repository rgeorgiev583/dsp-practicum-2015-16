#include <iostream>
#include "edge_list.h"
#include "adjacency_list.h"
#include "incidence_matrix.h"
#include <set>
#include <list>
#include <utility>
#include <vector>

void ELGraph::push_edge(pair<int,int> edge){
    edges.push_back(edge);
}

bool ELGraph::are_adjacent(int vertex1, int vertex2){
    for(auto printit = edges.begin(); printit != edges.end(); printit++){
        if (*&(*printit).first == vertex1 && *&(*printit).second == vertex2)
            return true;
    }
    return false;
}

bool ELGraph::has_path(vector<int> path){
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

bool ELGraph::has_path(list<int> path){
    if (path.size() == 1) return true;

    int vertex1 = path.front();
    path.pop_front();
    int vertex2 = path.front();

    if (are_adjacent(vertex1, vertex2)){
        return has_path(path);
    }else
        return false;
}

list<int> ELGraph::collect_vertices_for(int vertex){
    list<int> result;
    for(auto helper = edges.begin(); helper != edges.end(); helper++){
        if (*&(*helper).first == vertex){
            result.push_back(*&(*helper).second);
        }
    }
    return result;
}

vector<int> ELGraph::collect_all_vertices(){
    set<int> temp;
    for(auto helper = edges.begin(); helper != edges.end(); helper++){
        if(temp.count(*&(*helper).first) == 0)
            temp.insert(*&(*helper).first);
        if(temp.count(*&(*helper).second) == 0)
            temp.insert(*&(*helper).second);
    }
    vector<int> result;
    for(auto it = temp.begin(); it != temp.end(); it++){
        result.push_back(*it);
    }
    return result;
}

ALGraph ELGraph::transform_to_ALGraph(){
    ALGraph transformed;
    for(auto helper = edges.begin(); helper != edges.end(); helper++){
        if (!transformed.hasVertex(*&(*helper).first)){
            list<int> temp = collect_vertices_for(*&(*helper).first);
            transformed.push_vertex(*&(*helper).first, temp);
        }
    }
    return transformed;
}

IMGraph ELGraph::transform_to_IMGraph(){
    IMGraph transformed;
    vector<int> collector = collect_all_vertices();
    transformed.set_vertices(collector);
    for(auto helper = edges.begin(); helper != edges.end(); helper++){
        transformed.set_edge(*&(*helper).first,*&(*helper).second);
    }
    return transformed;
}

void ELGraph::print(){
    cout << "( ";
    for(auto printit = edges.begin(); printit != edges.end(); printit++){
        cout << "[" << *&(*printit).first << "," <<  *&(*printit).second << "]";
        cout << " ";
    }
    cout << ")";
}
