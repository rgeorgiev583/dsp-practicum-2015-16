#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;

/// for commentaries i use bulgarian and encoding is UTF - 8


/// връх в граф
template <typename T>
struct graphNode
{
    T data;

    graphNode(T data = T())
    {
        this->data = data;
    }

    bool operator==(graphNode node)
    {
        return this->data == node.data;
    }

    friend ostream& operator<<(ostream& os, graphNode node)
    {
        return os << node.data;
    }
};

/// ребро в граф
template <typename T>
struct graphLink
{
    graphNode<T> from, to;

    graphLink(graphNode<T> from = graphNode<T>(), graphNode<T> to = graphNode<T>())
    {
        this->from = from;
        this->to = to;
    }
};

/// граф чрез списък на съседство
template <typename T>
class graphNeighborList
{
    vector<graphNode<T> > nodes; /// върховете на графа
    list<list<graphNode<T> > > neighborList; /// списъка на съседство

public:

    /// конструктор чрез масив от върхове и списък на съседство
    graphNeighborList(vector<graphNode<T> > nodes, list<list<graphNode<T> > > neighborList)
    {
        this->nodes = nodes;
        this->neighborList = neighborList;
    }

    /// конструктор чрез масив от върхове и матрица на инцидентност
    graphNeighborList(vector<graphNode<T> > nodes, vector<vector<int> > incidence)
    {
        list<graphLink<T> > links;
        for(int i = 0; i < incidence[0].size(); i++)
        {
            graphLink<T> newLink;
            for(int j = 0; j < incidence.size(); j++)
                switch(incidence[i][j])
                {
                    case -1:
                        newLink.from = nodes[i];
                        break;
                    case 1:
                        newLink.to = nodes[j];
                        break;
                }
            links.push_back(newLink);
        }
        this->graphNeighborList(nodes, links);
    }

    /// конструктор чрез масив от върхове и списък на ребрата
    graphNeighborList(vector<graphNode<T> > nodes, list<graphLink<T> > listneighbor)
    {
        this->nodes = nodes;
        for(int i = 0; i < nodes.size(); i++)
        {
            list<graphNode<T> > neighbor;
            for(int j = 0; j < listneighbor.size(); j++)
            {
                graphLink<T> newLink = listneighbor.front();
                listneighbor.pop_front();
                if(newLink.from == this->nodes[i])
                    neighbor.push_back(newLink.to);
                listneighbor.push_back(newLink);
            }
            this->neighborList.push_back(neighbor);
        }
    }

    /// проверява дали двата връха са съседни
    bool isneighbor(graphNode<T> from, graphNode<T> to)
    {
        bool isneighbor = false;
        for(int i = 0; i < this->nodes.size(); i++)
        {
            list<graphNode<T> > newList = this->neighborList.front();
            this->neighborList.pop_front();
            if(from == this->nodes[i])
                for(int j = 0; j < newList.size(); j++)
                {
                    graphNode<T> newNode = newList.front();
                    newList.pop_front();
                    if(to == newNode)
                        isneighbor = true;
                    newList.push_back(newNode);
                }
            this->neighborList.push_back(newList);
        }
        return isneighbor;
    }

    /// проверява дали масива от върхове е път в графа
    bool isRoad(vector<graphNode<T> > road)
    {
        for(int i = 1; i < road.size(); i++)
            if(!this->isneighbor(road[i - 1], road[i]))
                return false;
        return true;
    }

    /// принтира графа като отпечатва върх и на следващите редове
    /// се опечатва "->" и връх което показа към кои върхове има
    /// ребро от първоначалния връх
    void print()
    {
        for(int i = 0; i < this->nodes.size(); i++)
        {
            cout<<nodes[i]<<endl;
            list<graphNode<T> > newList = this->neighborList.front();
            this->neighborList.pop_front();
            for(int j = 0; j < newList.size(); j++)
            {
                graphNode<T> newNode = newList.front();
                newList.pop_front();
                cout<<" -> "<<newNode<<endl;
                newList.push_back(newNode);
            }
            this->neighborList.push_back(newList);
            cout<<endl;
        }
    }
};

/// създава граф чрез кнструктора с масив от върхове и списък
/// от ребра и преверява два пътя дали съществуват и накрая
/// отпечатва графа
void testGraph()
{
    graphNode<int> a1 = graphNode<int>(1);
    graphNode<int> a2 = graphNode<int>(2);
    graphNode<int> a3 = graphNode<int>(3);
    graphNode<int> a4 = graphNode<int>(4);
    graphNode<int> a5 = graphNode<int>(5);
    graphNode<int> a7 = graphNode<int>(7);

    vector<graphNode<int> > nodes;

    nodes.push_back(a1);
    nodes.push_back(a2);
    nodes.push_back(a3);
    nodes.push_back(a4);
    nodes.push_back(a5);
    nodes.push_back(a7);

    graphLink<int> b1 = graphLink<int>(a1, a2);
    graphLink<int> b2 = graphLink<int>(a1, a4);
    graphLink<int> b3 = graphLink<int>(a1, a5);
    graphLink<int> b4 = graphLink<int>(a2, a1);
    graphLink<int> b5 = graphLink<int>(a2, a3);
    graphLink<int> b6 = graphLink<int>(a2, a5);
    graphLink<int> b7 = graphLink<int>(a3, a2);
    graphLink<int> b8 = graphLink<int>(a3, a5);
    graphLink<int> b9 = graphLink<int>(a4, a1);
    graphLink<int> b10 = graphLink<int>(a4, a5);
    graphLink<int> b11 = graphLink<int>(a5, a2);

    list<graphLink<int> > links;

    links.push_back(b1);
    links.push_back(b2);
    links.push_back(b3);
    links.push_back(b4);
    links.push_back(b5);
    links.push_back(b6);
    links.push_back(b7);
    links.push_back(b8);
    links.push_back(b9);
    links.push_back(b10);
    links.push_back(b11);

    graphNeighborList<int> graph = graphNeighborList<int>(nodes, links);

    vector<graphNode<int> > v1;

    v1.push_back(a1);
    v1.push_back(a2);
    v1.push_back(a5);
    v1.push_back(a2);
    v1.push_back(a3);
    v1.push_back(a5);
    v1.push_back(a2);
    v1.push_back(a1);
    v1.push_back(a4);
    v1.push_back(a5);

    cout<<"the road:"<<endl;
    for(int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i];
        if(i != v1.size() - 1)
            cout<<" -> ";
        else
            cout<<endl;
    }
    if(graph.isRoad(v1))
        cout<<"is valid road"<<endl;
    else
        cout<<"is invalid road"<<endl;

    cout<<"----------------------------------------------"<<endl;

    vector<graphNode<int> > v2;

    v2.push_back(a1);
    v2.push_back(a2);
    v2.push_back(a5);
    v2.push_back(a7);

    cout<<"the road:"<<endl;
    for(int i = 0; i < v2.size(); i++)
    {
        cout<<v2[i];
        if(i != v2.size() - 1)
            cout<<" -> ";
        else
            cout<<endl;
    }
    if(graph.isRoad(v2))
        cout<<"is valid road"<<endl;
    else
        cout<<"is invalid road"<<endl;

    cout<<"----------------------------------------------"<<endl;

    graph.print();

    cout<<"----------------------------------------------"<<endl;
}

int main()
{
    testGraph();
    return 0;
}
