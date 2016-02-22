#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int EdgeLength = 6;

void bfs(int start, vector<vector<int> > graph) {
	queue<int> Q;
	vector<int> distance(graph.size());
	for (int i = 0; i < graph.size(); i++) {
		distance[i] = -1;
	}
	distance[start] = 0;
	Q.push(start);
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		for (int i = 0; i < graph[curr].size(); i++) {
			int connection = graph[curr][i];
			if (distance[connection] == -1){
				distance[connection] = distance[curr] + EdgeLength;
				Q.push(connection);
			}
		}
	}

	for (int i = 1; i < graph.size(); i++) {
		if (i != start) {
			cout << distance[i] << " ";
		}
	}
	cout << endl;
}

int main() {
	int testCases = 0;
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		int nodes = 0;
		int edges = 0;
		cin >> nodes;
		cin >> edges;
		vector<vector<int> > graph(nodes + 1);
		for (int j = 0; j < edges; j++) {
			int start = 0;
			int end = 0;
			cin >> start;
			cin >> end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}
		int start = 0;
		cin >> start;
		bfs(start, graph);
	}
	return 0;
}