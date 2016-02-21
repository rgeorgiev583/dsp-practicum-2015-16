#include <iostream>
#include "adjacency_list.h"
#include "incidence_matrix.h"
#include "edge_list.h"
#include <vector>
#include <utility>
#include <list>

using namespace std;

void testAL(){
    list<int> list1;
    list1.push_back(2);
    list1.push_back(5);
    list1.push_back(4);

    list<int> list2;
    list2.push_back(1);

    list<int> list3;
    list3.push_back(4);

    list<int> list4;
    list4.push_back(1);
    list4.push_back(5);
    list4.push_back(3);

    list<int> list5;
    list5.push_back(1);
    list5.push_back(4);

    list<int> baba;
    baba.push_back(2);
    baba.push_back(4);
    baba.push_back(5);

    ALGraph graphh;
    graphh.push_vertex(1, list1);
    graphh.push_vertex(2, list2);
    graphh.push_vertex(3, list3);
    graphh.push_vertex(4, list4);
    graphh.push_vertex(5, list5);

    graphh.print();
    cout << endl;

    cout << "Adjacency testing" << endl;

    cout << graphh.are_adjacent(1, 2) << endl;
    cout << graphh.are_adjacent(1, 4) << endl;
    cout << graphh.are_adjacent(1, 3) << endl;
    cout << graphh.are_adjacent(2, 3) << endl;
    cout << graphh.are_adjacent(4, 5) << endl;
    cout << graphh.are_adjacent(7, 1) << endl;
    cout << graphh.are_adjacent(5, 1) << endl;
    cout << endl;

    cout << "Paths testing" << endl;
    list<int> test1;
    test1.push_back(4);
    test1.push_back(1);
    test1.push_back(5);

    list<int> test2;
    test2.push_back(3);
    test2.push_back(2);
    test2.push_back(4);

    list<int> test3;
    test3.push_back(2);
    test3.push_back(1);
    test3.push_back(5);
    test3.push_back(4);
    test3.push_back(3);

    cout << graphh.has_path(test1) << endl;
    cout << graphh.has_path(test2) << endl;
    cout << graphh.has_path(test3) << endl;
    cout << endl;

    vector<int> test4 = {4, 1, 5};
    vector<int> test5 = {3, 2, 4};
    vector<int> test6 = {2, 1, 5, 4, 3};

    cout << graphh.has_path(test4) << endl;
    cout << graphh.has_path(test5) << endl;
    cout << graphh.has_path(test6) << endl;
    cout << endl;

    cout << "Transformed to EL Graph: " << endl;
    graphh.transform_to_ELGraph().print();
    cout << endl;
    cout << endl;
    cout << "Transformed to IM Graph: " << endl;
    graphh.transform_to_IMGraph().print();
}

void testIM(){
    IMGraph graphh;
    vector<int> vertices;
    vertices.push_back(1);
    vertices.push_back(2);
    vertices.push_back(3);
    vertices.push_back(4);
    vertices.push_back(5);

    graphh.set_vertices(vertices);
    graphh.set_edge(1, 2);
    graphh.set_edge(2, 3);
    graphh.set_edge(1, 3);
    graphh.set_edge(4, 5);
    graphh.set_edge(1, 5);
    graphh.set_edge(2, 4);
    graphh.print();
    cout << endl;

    cout << "Adjacency testing" << endl;
    cout << graphh.are_adjacent(1,2) << endl;
    cout << graphh.are_adjacent(1,3) << endl;
    cout << graphh.are_adjacent(1,5) << endl;
    cout << graphh.are_adjacent(4,2) << endl;
    cout << endl;

    cout << "Paths testing" << endl;
    list<int> test1;
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(4);
    test1.push_back(5);

    list<int> test2;
    test2.push_back(1);
    test2.push_back(2);
    test2.push_back(3);
    test2.push_back(4);

    list<int> test3;
    test3.push_back(1);
    test3.push_back(2);
    test3.push_back(3);

    list<int> test4;
    test4.push_back(4);
    test4.push_back(5);
    test4.push_back(1);
    test4.push_back(3);
    test4.push_back(2);

    cout << graphh.has_path(test1) << endl;
    cout << graphh.has_path(test2) << endl;
    cout << graphh.has_path(test3) << endl;
    cout << graphh.has_path(test4) << endl;
    cout << endl;

    vector<int> test5 = {1, 2, 4, 5};
    vector<int> test6 = {1, 2, 3, 4};
    vector<int> test7 = {1, 2, 3};
    vector<int> test8 = {4, 5, 1, 3, 2};

    cout << graphh.has_path(test5) << endl;
    cout << graphh.has_path(test6) << endl;
    cout << graphh.has_path(test7) << endl;
    cout << graphh.has_path(test8) << endl;
    cout << endl;

    cout << "Transformed to EL Graph: " << endl;
    graphh.transform_to_ELGraph().print();
    cout << endl;
    cout << endl;

    cout << "Transformed to AL Graph: " << endl;
    graphh.transform_to_ALGraph().print();
}

void testEL(){
    ELGraph graphh;
    pair<int,int> e1(2,3);
    graphh.push_edge(e1);
    pair<int,int> e2(4,3);
    graphh.push_edge(e2);
    pair<int,int> e3(4,2);
    graphh.push_edge(e3);
    pair<int,int> e4(1,2);
    pair<int,int> e5(1,5);
    pair<int,int> e6(5,4);
    graphh.push_edge(e4);
    graphh.push_edge(e5);
    graphh.push_edge(e6);
    graphh.print();
    cout << endl;

    cout << "Adjacency testing" << endl;
    cout << graphh.are_adjacent(2,3) << endl;
    cout << graphh.are_adjacent(4,3) << endl;
    cout << graphh.are_adjacent(4,2) << endl;
    cout << graphh.are_adjacent(1,3) << endl;
    cout << endl;

    cout << "Paths testing" << endl;
    list<int> test1;
    test1.push_back(1);
    test1.push_back(5);
    test1.push_back(4);
    test1.push_back(2);
    test1.push_back(3);

    list<int> test2;
    test2.push_back(1);
    test2.push_back(2);
    test2.push_back(3);
    test2.push_back(4);

    list<int> test3;
    test3.push_back(2);
    test3.push_back(3);
    test3.push_back(5);

    list<int> test4;
    test4.push_back(1);
    test4.push_back(2);
    test4.push_back(3);

    cout << graphh.has_path(test1) << endl;
    cout << graphh.has_path(test2) << endl;
    cout << graphh.has_path(test3) << endl;
    cout << graphh.has_path(test4) << endl;

    vector<int> test5 = {1, 5, 4, 2, 3};
    vector<int> test6 = {1, 2, 3, 4};
    vector<int> test7 = {2, 3, 5};
    vector<int> test8 = {1, 2, 3};
    cout << endl;

    cout << graphh.has_path(test5) << endl;
    cout << graphh.has_path(test6) << endl;
    cout << graphh.has_path(test7) << endl;
    cout << graphh.has_path(test8) << endl;
    cout << endl;

    cout << "Transformed to AL Graph: " << endl;
    graphh.transform_to_ALGraph().print();

    cout << "Transformed to IM Graph: " << endl;
    graphh.transform_to_IMGraph().print();
}

int main()
{
    testAL();   //checked
    //testIM(); //checked
    //testEL(); //checked

    return 0;
}
