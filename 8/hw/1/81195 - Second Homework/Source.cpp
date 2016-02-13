#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int a;
	int b;

	Edge(int _a = 0, int _b = 0) :a(_a), b(_b) {}
};

struct BFSData
{
	vector<Edge> edges;
	int count;
	int start;

	BFSData(const vector<Edge>& _edges, int _c, int _s) :edges(_edges), count(_c), start(_s) {}
};

void BFS(const BFSData& data)
{
	vector<int> distances(data.count+1, -1);

	queue<int> q;
	distances[data.start] = 0;
	q.push(data.start);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int i = 0; i < data.edges.size(); ++i)
		{
			if (data.edges[i].a == current && distances[data.edges[i].b] == -1 && data.edges[i].b != data.start)
			{
				distances[data.edges[i].b] = distances[current] + 6;
				q.push(data.edges[i].b);
			}
			else if(data.edges[i].b == current && distances[data.edges[i].a] == -1 && data.edges[i].a != data.start)
			{
				distances[data.edges[i].a] = distances[current] + 6;
				q.push(data.edges[i].a);
			}
		}
	}

	for (int i = 1; i <= data.count; ++i)
	{
		if (i != data.start)
			cout << distances[i] << " ";
	}
}

int main(void)
{
	int testCasesNum;
	cin >> testCasesNum;

	vector<BFSData> tests;

	for (int i = 0; i < testCasesNum; ++i)
	{
		vector<Edge> tmp;
		int n, m, a, b, s;

		cin >> n >> m;
		for (int j = 0; j < m; ++j)
		{
			cin >> a >> b;
			tmp.push_back(Edge(a, b));
		}
		cin >> s;

		BFSData data(tmp, n, s);
		tests.push_back(data);
	}

	for (int i = 0; i < tests.size(); ++i)
	{
		BFS(tests[i]);
		cout << endl;
	}
	return 0;
}