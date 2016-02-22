#ifndef GRAPH_CPP_INCLUDED
#define GRAPH_CPP_INCLUDED

#include<list>
#include<vector>

using namespace std;

template <typename T>
struct Node{
    T value;
    list<T> neighbours;
    Node(T v = T(), list<T> n = list<T>() ): value(v), neighbours(n) {}
};

template <typename T>
struct Edge {
    Node<T> from;
    Node<T> to;
    Edge(Node<T> _from, Node<T> _to):from(_from), to(_to) {}
};

template <typename T>
class Graph{
public:
    virtual bool areAdjacent(Node<T> firstVertex, Node<T> secondVertex) = 0;
    bool isPath(list<Node<T> > path);
    bool isPath(vector<Node<T> > path);
    virtual void print() = 0;
    virtual ~Graph() {}

};

template <typename T>
bool Graph<T>::isPath(list<Node<T> > path) {
    for(typename list<Node<T> >::iterator i = path.begin(); i!=prev(path.end(),1); i++){
        if(!areAdjacent(*i, *(next(i,1)))) return false;
    }
    return true;
}

template <typename T>
bool Graph<T>::isPath(vector<Node<T> > path) {
    for(int i = 0; i < path.size() - 1 ; i++){
        if(!areAdjacent(path[i], path[i+1]))
            return false;
    }
    return true;
}

template <typename T>
class AdjacencyGraph;

template <typename T>
class EdgeGraph;

template <typename T>
class MatrixGraph;

#endif // GRAPH_CPP_INCLUDED

