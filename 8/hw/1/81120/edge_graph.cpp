#ifndef EDGE_GRAPH_CPP
#define EDGE_GRAPH_CPP

#include<iostream>
#include"graph.cpp"

using namespace std;

template <typename T>
class EdgeGraph:public Graph<T> {
private:
    list<Edge<T> > edges;
public:
    EdgeGraph();
    EdgeGraph(list<Edge<T> >);
    EdgeGraph(EdgeGraph const&);
    EdgeGraph(MatrixGraph<T>&);
    EdgeGraph(AdjacencyGraph<T>&);
    EdgeGraph& operator=(EdgeGraph const&);
    ~EdgeGraph();

    bool areAdjacent(Node<T>, Node<T>);

    list<Edge<T> > getEdges();
    void print();
};

template <typename T>
EdgeGraph<T>::EdgeGraph() {
    edges = list<Edge<T> >();
}

template <typename T>
EdgeGraph<T>::EdgeGraph(list<Edge<T> > l = list<Edge<T> >()): edges(l) {}

template <typename T>
EdgeGraph<T>::EdgeGraph(EdgeGraph<T> const& g): edges(g.edges) {}

template <typename T>
EdgeGraph<T>& EdgeGraph<T>::operator=(EdgeGraph<T> const& g) {
    if(this != &g){
        edges = g.edges;
    }
    return *this;
}

template <typename T>
EdgeGraph<T>::EdgeGraph(MatrixGraph<T>& mg) {
    auto matrix = mg.getMatrix();
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j  < matrix.size(); j++){
            if(matrix[i][j]){
                Node<int> _from(i);
                Node<int> _to(j);
                Edge<int> newEdge(_from, _to);
                edges.push_back(newEdge);
            }
        }
    }
}

template <typename T>
EdgeGraph<T>::EdgeGraph(AdjacencyGraph<T> & ag) {
    auto nodes = ag.getNodes();
    for(auto i = nodes.begin(); i != nodes.end(); i++){
        auto neighbours = (*i).neighbours;
        for(auto j = neighbours.begin(); j != neighbours.end(); j++){
            Node<T> _from((*i).value);
            Node<T> _to(*j);
            Edge<T> newEdge(_from, _to);
            edges.push_back(newEdge);
        }
    }
}

template <typename T>
EdgeGraph<T>::~EdgeGraph() {}


template <typename T>
bool EdgeGraph<T>::areAdjacent(Node<T> first, Node<T> second) {
    for(auto i = edges.begin(); i != edges.end(); i++){
        if((*i).from.value == first.value && (*i).to.value == second.value) return true;
    }
    return false;
}

template <typename T>
list<Edge<T> > EdgeGraph<T>::getEdges() {
    return edges;
}

template <typename T>
void EdgeGraph<T>::print() {
    for(auto it = edges.begin(); it != edges.end(); it++){
            cout<<"( "<<(*it).from.value<<" , "<<(*it).to.value<<" )"<<endl;
    }
}

//template <typename T>
//void EdgeGraph<T>::print() {
//
//}

#endif // EDGE_GRAPH_CPP
