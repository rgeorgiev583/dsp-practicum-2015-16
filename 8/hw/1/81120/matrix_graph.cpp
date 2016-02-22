#ifndef MATRIX_GRAPH_CPP
#define MATRIX_GRAPH_CPP

#include<iostream>
#include"graph.cpp"

using namespace std;

template <typename T>
class MatrixGraph:public Graph<T> {
private:
    vector<vector<bool> > matrix;
public:
    MatrixGraph();
    MatrixGraph(vector<vector<bool> > );
    MatrixGraph(AdjacencyGraph<T>& );
    MatrixGraph(EdgeGraph<T>&);
    MatrixGraph(MatrixGraph const& );
    MatrixGraph& operator=(MatrixGraph const&);
    ~MatrixGraph();

    bool areAdjacent(Node<T>, Node<T>);

    vector<vector<bool> > getMatrix() const;
    void print();
};

template <typename T>
MatrixGraph<T>::MatrixGraph() {
    matrix = vector<vector<bool> >();
}

template <typename T>
MatrixGraph<T>::MatrixGraph(vector<vector<bool> > m = vector<vector<bool> >()): matrix(m) {}

template <typename T>
MatrixGraph<T>::MatrixGraph(MatrixGraph<T> const& g): matrix(g.matrix) {}

template <typename T>
MatrixGraph<T>& MatrixGraph<T>::operator=(MatrixGraph<T> const& g) {
    if(this != &g){
        matrix = g.matrix;
    }
    return *this;
}

template <typename T>
MatrixGraph<T>::MatrixGraph(AdjacencyGraph<T>& ag):matrix(vector<vector<bool> >()) {
    auto nodes = ag.getNodes();
    for(int i = 0; i < nodes.size(); i++){
            vector<bool> vec;
        for(int j = 0; j < nodes.size(); j++){
            vec.push_back(0);
        }
        matrix.push_back(vec);
    }

    for(auto i = nodes.begin(); i != nodes.end(); i++) {
        auto neighbour = (*i).neighbours;
        for(auto j = neighbour.begin(); j != neighbour.end(); j++){
            matrix[(*i).value][(*j)]=true;
        }
    }
}

template <typename T>
MatrixGraph<T>::MatrixGraph(EdgeGraph<T>& eg):matrix(vector<vector<bool> >()) {
    int biggestNode = 0;
    auto edges = eg.getEdges();
    for(auto i = edges.begin(); i != edges.end(); i++) {
        int curr = (*i).from.value;
        if(curr > biggestNode)
            biggestNode = curr;
        curr = (*i).to.value;
        if(curr > biggestNode)
            biggestNode = curr;
    }
    for(int i = 0; i <= biggestNode; i++){
            vector<bool> vec;
        for(int j = 0; j <= biggestNode; j++){
            vec.push_back(0);
        }
        matrix.push_back(vec);
    }
    for(auto i = edges.begin(); i != edges.end(); i++) {
        int fst = (*i).from.value;
        int snd = (*i).to.value;
        matrix[fst][snd]=true;
    }
}

template <typename T>
MatrixGraph<T>::~MatrixGraph() {}

template <typename T>
bool MatrixGraph<T>::areAdjacent(Node<T> first, Node<T> second) {
    if(matrix[first.value][second.value]==1) return true;
    else return false;
}

template <typename T>
 vector<vector<bool> > MatrixGraph<T>::getMatrix() const {
    return matrix;
 }

template <typename T>
void MatrixGraph<T>::print() {
    for(int i = 0; i < matrix.size(); i++ ){
        for(int j = 0; j < matrix.size(); j++){
            cout<< matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

#endif // MATRIX_GRAPH_CPP
