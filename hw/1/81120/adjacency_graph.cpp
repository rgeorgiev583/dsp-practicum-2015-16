
#ifndef ADJACENCY_GRAPH_CPP_INCLUDED
#define ADJACENCY_GRAPH_CPP_INCLUDED

#include<iostream>
#include"graph.cpp"

using namespace std;

template <typename T>
class AdjacencyGraph: public Graph<T>{
private:
    list<Node<T> > nodes;

    bool hasNode(Node<T>) const;
public:

    AdjacencyGraph();
    AdjacencyGraph(list<Node<T> >);
    AdjacencyGraph(EdgeGraph<T>& );
    AdjacencyGraph(MatrixGraph<T>& );
    AdjacencyGraph(AdjacencyGraph const&);
    AdjacencyGraph& operator=(AdjacencyGraph const&);
    ~AdjacencyGraph();

    bool areAdjacent(Node<T>, Node<T>);

    list<Node<T> > getNodes();
    void print();
};

template <typename T>
AdjacencyGraph<T>::AdjacencyGraph() {
    nodes = list<Node<T> >();
}

template <typename T>
AdjacencyGraph<T>::AdjacencyGraph(list<Node<T> > l = list<Node<T> >()): nodes(l) {}

template <typename T>
AdjacencyGraph<T>::AdjacencyGraph(AdjacencyGraph<T> const& g): nodes(g.nodes) {}

template <typename T>
AdjacencyGraph<T>& AdjacencyGraph<T>::operator=(AdjacencyGraph<T> const& g) {
    if(this != &g) {
        nodes = g.nodes;
    }
    return *this;
}

template <typename T>
AdjacencyGraph<T>::~AdjacencyGraph() {}

template <typename T>
AdjacencyGraph<T>::AdjacencyGraph(EdgeGraph<T>& eg) {
    auto edges = eg.getEdges();
    bool added=false;
    for(auto iEdges = edges.begin(); iEdges != edges.end(); iEdges++) {
        for(auto iNodes = nodes.begin(); iNodes != nodes.end(); iNodes++){
            if((*iNodes).value == (*iEdges).from.value) {
                (*iNodes).neighbours.push_back((*iEdges).to.value);
                added=true;
                break;
            }
        }
        if(!added) {
            Node<T> newNode((*iEdges).from.value);
            newNode.neighbours.push_back((*iEdges).to.value);
            nodes.push_back(newNode);
        }
        added=false;
    }
}

template <typename T>
AdjacencyGraph<T>::AdjacencyGraph(MatrixGraph<T>& mg) {
    auto matrix = mg.getMatrix();
    for(int i = 0; i < matrix.size(); i++) {
        Node<int> newNode(i);
        for(int j = 0; j < matrix.size(); j++){
            if(matrix[i][j]) {
                newNode.neighbours.push_back(j);
            }
        }
        nodes.push_back(newNode);
    }
}

template <typename T>
bool AdjacencyGraph<T>::areAdjacent(Node<T> firstVertex, Node<T> secondVertex) {
    for(typename list<Node<T> >::iterator i = nodes.begin(); i != nodes.end(); i++) {
        if ((*i).value == firstVertex.value) {
            for (typename list<T>::iterator j = (*i).neighbours.begin(); j != (*i).neighbours.end(); j++) {
                if (*j == secondVertex.value) {
                    return true;
                }
            }
        }
    }
    return false;
}

template <typename T>
bool AdjacencyGraph<T>::hasNode(Node<T> node) const {
    for(auto i = nodes.begin(); i != nodes.end(); i++) {
        if((*i).value == node.value && (*i).neighbours == node.neighbours) return true;
    }
    return false;
}

template <typename T>
list<Node<T> > AdjacencyGraph<T>::getNodes() {
    return nodes;
}

template <typename T>
void AdjacencyGraph<T>::print() {
    for(auto i = nodes.begin(); i != nodes.end(); i++) {
        cout<<(*i).value<<" -> ";
        auto listNeigh = (*i).neighbours;
        for(auto j = listNeigh.begin(); j != listNeigh.end(); j++) {
            cout<<(*j)<<" ";
        }
        cout<<endl;
    }
}

#endif // ADJACENCY_GRAPH_CPP_INCLUDED

