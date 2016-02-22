#include<iostream>
#include<vector>
#include<list>
#include"graph.cpp"
#include"adjacency_graph.cpp"
#include"edge_graph.cpp"
#include"matrix_graph.cpp"

using namespace std;

int main(){
    typedef Node<int> Node;
    typedef Edge<int> Edge;

    ///граф със списък на съседство
    cout<<"Neighbours Graph!\n"<<endl;
    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);
    Node e(5);
    Node f(6);
    Node o(0);
    a.neighbours.push_back(5);
    a.neighbours.push_back(6);
    b.neighbours.push_back(1);
    c.neighbours.push_back(1);
    d.neighbours.push_back(5);
    f.neighbours.push_back(5);
    f.neighbours.push_back(6);
    o.neighbours.push_back(1);

    list<Node> nodes;
    nodes.push_back(o);
    nodes.push_back(a);
    nodes.push_back(b);
    nodes.push_back(c);
    nodes.push_back(d);
    nodes.push_back(e);
    nodes.push_back(f);

    AdjacencyGraph<int> g(nodes);
    g.print();
//    cout<<a.value<<" and "<<b.value<<" adjacent? "<<g.areAdjacent(a,b)<<endl;
//    cout<<a.value<<" and "<<f.value<<" adjacent? "<<g.areAdjacent(a,f)<<endl;
//    cout<<f.value<<" and "<<e.value<<" adjacent? "<<g.areAdjacent(f,e)<<endl;
//    cout<<a.value<<" and "<<e.value<<" adjacent? "<<g.areAdjacent(a,e)<<endl;
//
//    list<Node> path;
//    path.push_back(a);
//    path.push_back(f);
//    path.push_back(e);
//    cout<<"path? "<<g.isPath(path)<<endl;
//
//    list<Node> wrongPath;
//    wrongPath.push_back(f);
//    wrongPath.push_back(e);
//    wrongPath.push_back(d);
//    wrongPath.push_back(c);
//    cout<<"path? (no) "<<g.isPath(wrongPath)<<endl;
//
//    vector<Node> pathVec;
//    pathVec.push_back(a);
//    pathVec.push_back(f);
//    pathVec.push_back(e);
//    cout<<"path with vector? "<<g.isPath(pathVec)<<endl;
//
//    vector<Node> wrongPathVec;
//    wrongPathVec.push_back(f);
//    wrongPathVec.push_back(e);
//    wrongPathVec.push_back(d);
//    cout<<"path with vector? (no) "<<g.isPath(wrongPathVec)<<endl;

    ///граф чрез списък на ребрата
    cout<<"--------------\n\nEdge Graph!\n"<<endl;
    Edge first(a,f);
    Edge second(f,e);
    Edge third(a,e);
    Edge fourth(d,e);
    Edge fifth(c,a);
    Edge sixth(b,a);
    Edge seventh(o,a);
    Edge eight(f,f);

    list<Edge> edges;
    edges.push_back(first);
    edges.push_back(second);
    edges.push_back(third);
    edges.push_back(fourth);
    edges.push_back(fifth);
    edges.push_back(sixth);
    edges.push_back(seventh);
    edges.push_back(eight);

    EdgeGraph<int> eg(edges);
    eg.print();

//    cout<<endl;
//    cout<<a.value<<" and "<<b.value<<" adjacent? "<<eg.areAdjacent(a,b)<<endl;
//    cout<<a.value<<" and "<<f.value<<" adjacent? "<<eg.areAdjacent(a,f)<<endl;
//    cout<<f.value<<" and "<<e.value<<" adjacent? "<<eg.areAdjacent(f,e)<<endl;
//    cout<<a.value<<" and "<<e.value<<" adjacent? "<<eg.areAdjacent(a,e)<<endl;
//
//    cout<<"path? "<<eg.isPath(path)<<endl;
//    cout<<"path? (no) "<<eg.isPath(wrongPath)<<endl;
//    cout<<"path with vector? "<<eg.isPath(pathVec)<<endl;
//    cout<<"path with vector? (no) "<<eg.isPath(wrongPathVec)<<endl;
//

    ///граф чрез матрица на съседство
    cout<<"--------------\n\nMatrix Graph!\n"<<endl;

    vector<vector<bool> > matrix;
    for(int i = 0; i < 7; i++){
            vector<bool> vec;
            matrix.push_back(vec);
        for(int j = 0; j < 7; j++){
            matrix[i].push_back(0);
        }
    }
    matrix[0][1]=true;
    matrix[1][5]=true;
    matrix[1][6]=true;
    matrix[2][1]=true;
    matrix[3][1]=true;
    matrix[4][5]=true;
    matrix[6][5]=true;
    matrix[6][6]=true;

    MatrixGraph<int> mg(matrix);
    mg.print();
//    cout<<a.value<<" and "<<b.value<<" adjacent? "<<mg.areAdjacent(a,b)<<endl;
//    cout<<a.value<<" and "<<f.value<<" adjacent? "<<mg.areAdjacent(a,f)<<endl;
//    cout<<f.value<<" and "<<e.value<<" adjacent? "<<mg.areAdjacent(f,e)<<endl;
//    cout<<a.value<<" and "<<e.value<<" adjacent? "<<mg.areAdjacent(a,e)<<endl;
//
//    cout<<"path? "<<mg.isPath(path)<<endl;
//    path.push_front(o);
//    cout<<"path? "<<mg.isPath(path)<<endl;
//    cout<<"path? (no) "<<mg.isPath(wrongPath)<<endl;
//    cout<<"path with vector? "<<mg.isPath(pathVec)<<endl;
//    cout<<"path with vector? (no) "<<mg.isPath(wrongPathVec)<<endl;
//

///тестване на променянето на представянето на граф

//    cout<<endl<<endl<<"Testing AdjGraph from EdgeGraph!\n"<<endl;
//    AdjacencyGraph<int> AGfromEG(eg);
//    AGfromEG.print();
//
//    cout<<endl<<endl<<"Testing AdjGraph from MatrixGraph!\n"<<endl;
//    AdjacencyGraph<int> AGfromMG(mg);
//    AGfromMG.print();
//
//    cout<<endl<<endl<<"Testing EdgeGraph from MatrixGraph!\n"<<endl;
//    EdgeGraph<int> EGfromMG(mg);
//    EGfromMG.print();
//
//    cout<<endl<<endl<<"Testing EdgeGraph from AdjGraph!\n"<<endl;
//    EdgeGraph<int> EGfromAG(g);
//    EGfromAG.print();
//
//    cout<<endl<<endl<<"Testing MatrixGraph from AdjGraph!\n"<<endl;
//    MatrixGraph<int> MGfromAG(g);
//    MGfromAG.print();
//
//    cout<<endl<<endl<<"Testing MatrixGraph from EdgeGraph!\n"<<endl;
//    MatrixGraph<int> MGfromEG(eg);
//    MGfromEG.print();

    return 0;
}
