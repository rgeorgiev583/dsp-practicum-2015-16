#include "Converter.cpp"
#include <iostream>

using namespace std;

int main() {
	typedef Node<int> Node;
	typedef Edge<int> Edge;

	/// Adjacency list graph test
	cout << "Adjacency list graph test ---------------------------" << endl;
	Node a(5);
	Node b(6);
	Node c(7);
	Node d(14);
	Node e(42);
	Node f(31);
	Node g(23);
	a.neighbours.push_back(b);
	a.neighbours.push_back(c);
	a.neighbours.push_back(f);
	c.neighbours.push_back(d);
	c.neighbours.push_back(e);
	e.neighbours.push_back(g);

	list<Node> adjList;
	adjList.push_back(a);
	adjList.push_back(b);
	adjList.push_back(c);
	adjList.push_back(d);
	adjList.push_back(e);
	adjList.push_back(f);
	adjList.push_back(g);

	LGraph<int> ltest(adjList);
	ltest.print();

	list<Node> truePath;
	truePath.push_back(a);
	truePath.push_back(c);
	truePath.push_back(e);
	truePath.push_back(g);

	list<Node> falsePath;
	falsePath.push_back(a);
	falsePath.push_back(f);
	falsePath.push_back(e);

	ltest.isPath(truePath);
	ltest.isPath(falsePath);

	/// Graph constructed by edges
	cout << "Edges graph test -----------------------------------" << endl;
	Edge e1(a,b);
	Edge e2(a,c);
	Edge e3(a,f);
	Edge e4(c,e);
	Edge e5(c,d);
	Edge e6(e,g);
	list<Edge> edges;
	edges.push_back(e1);
	edges.push_back(e2);
	edges.push_back(e3);
	edges.push_back(e4);
	edges.push_back(e5);
	edges.push_back(e6);

	EGraph<int> etest(edges);
	etest.print();

	etest.isPath(truePath);
	etest.isPath(falsePath);



	
	///Graph constructed by an adjacency matrix
	cout << "Matrix graph test ----------------------------------" << endl;
	vector<vector<bool>> matrix;

	for(int i = 0; i < 43; i++) {
		matrix.push_back(vector<bool>());
		for(int j = 0; j < 43; j++) { 
			matrix[i].push_back(false);
		}
	}
	matrix[5][6] = true;
	matrix[5][7] = true;
	matrix[5][31] = true;
	matrix[7][42] = true;
	matrix[7][14] = true;
	matrix[42][23] = true;

	MGraph<int> mtest(matrix);
	mtest.print();
	mtest.isPath(truePath);
	mtest.isPath(falsePath);


	/// Conversion between Adjacency list graph and Edges graph
	cout << "Conversion between Adjacency list graph and Edges graph ------------------" << endl;
	EGraph<int> cetest = LtoE(ltest);
	cetest.print();
	cetest.isPath(truePath);
	cetest.isPath(falsePath);

	/// Conversion between Edges graph and Matrix graph
	cout << "Conversion between Edges graph and Matrix graph --------------------------" << endl;
	MGraph<int> cmtest = EtoM(etest);
	cmtest.print();
	cmtest.isPath(truePath);
	cmtest.isPath(falsePath);

	/// Conversion between Matrix graph and Adjacency list graph
	cout << "Conversion between Matrix graph and Adjacency list graph -----------------" << endl;
	LGraph<int> cltest = MtoL(mtest);
	// For the sake of staying in good mental shape, don't print this
	//cltest.print();
	cltest.isPath(truePath);
	cltest.isPath(falsePath);

	cin.get();
	return 0;
}