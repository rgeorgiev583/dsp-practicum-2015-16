#include <iostream>
#include "adjacency_list.h"
#include "edge_list.h"
#include "incidence_matrix.h"
#include <set>
#include <vector>
#include <list>
#include <utility>

using namespace std;

ALGraphElement::ALGraphElement(int _current_vertex, list<int> _adjacency_list){
    current_vertex = _current_vertex;
    adjacency_list = _adjacency_list;
}

void ALGraph::push_vertex(int vertex, list<int> neighbours){
    ALGraphElement temp(vertex, neighbours);
    elements.push_back(temp);
}

vector<int> ALGraph::collect_all_vertices(){
    vector<int> result;
    set<int> helper;
    for(auto it = elements.begin(); it != elements.end(); it++){
        if(helper.count(*&it->current_vertex) == 0)
            helper.insert(*&it->current_vertex);
        list<int> temp = *&it->adjacency_list;
        for(auto deeper = temp.begin(); deeper != temp.end(); deeper++){
            if(helper.count(*deeper) == 0)
                helper.insert(*deeper);
        }
    }
    for(auto it = helper.begin(); it != helper.end(); it++){
        result.push_back(*it);
    }
    return result;
}

bool ALGraph::are_adjacent(int vertex1, int vertex2){
    for(auto printit = elements.begin(); printit != elements.end(); printit++){
        if (*&printit->current_vertex == vertex1){
            list<int> temp = *&printit->adjacency_list;
            for(auto go_deeper = temp.begin(); go_deeper != temp.end(); go_deeper++){
                if( *go_deeper == vertex2) return true;
            }
        }
    }
    return false;
}

bool ALGraph::has_path(vector<int> path){
    if (path.size() == 1) return true;

    int vertex1 = path.back();
    path.pop_back();
    int vertex2 = path.back();

    if (are_adjacent(vertex1, vertex2)){
        return has_path(path);
    }else
        return false;
}

bool ALGraph::has_path(list<int> path){
    if (path.size() == 1) return true;

    int vertex1 = path.front();
    path.pop_front();
    int vertex2 = path.front();

    if (are_adjacent(vertex1, vertex2)){
        return has_path(path);
    }else
        return false;
}

ELGraph ALGraph::transform_to_ELGraph(){
    ELGraph transformed;
    for(auto helper = elements.begin(); helper != elements.end(); helper++){
        ALGraphElement temp = *helper;
        for( auto go_deeper = temp.adjacency_list.begin(); go_deeper != temp.adjacency_list.end(); go_deeper++){
            pair<int,int> new_edge(temp.current_vertex, *go_deeper);
            transformed.push_edge(new_edge);
        }
    }
    return transformed;
}

IMGraph ALGraph::transform_to_IMGraph(){
    IMGraph transformed;
    vector<int> vertices_collector = collect_all_vertices();
    transformed.set_vertices(vertices_collector);
    for(auto helper = elements.begin(); helper != elements.end(); helper++){
        list<int> temp = *&(*helper).adjacency_list;
        for(auto it = temp.begin(); it != temp.end(); it++){
            transformed.set_edge(*&(*helper).current_vertex,*it);
        }
    }
    return transformed;
}

bool ALGraph::hasVertex(int vertex){
    for(auto helper = elements.begin(); helper != elements.end(); helper++){
        if( *&(*helper).current_vertex == vertex )
            return true;
    }
    return false;
}

void  ALGraph::print(){
    for(auto printit = elements.begin(); printit != elements.end(); printit++){
        ALGraphElement temp = *printit;
        cout << temp.current_vertex << ": ";
        for( auto go_deeper = temp.adjacency_list.begin(); go_deeper != temp.adjacency_list.end(); go_deeper++){
            cout << *go_deeper << " ";
        }
        cout << endl;
    }
}
