#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
void test_case() {
	int n, m, x, y, s, level = 0;
	cin >> n >> m;
	int graph[n][n];
	int results[n];
	queue<int> bfs;
	memset(graph, 0, sizeof(graph[0][0]) * n * n);
	memset(results, -1, sizeof(results[0]) * n);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x - 1][y - 1] = 1;
		graph[y - 1][x - 1] = 1;
	}
	cin >> s;
	bfs.push(-1);
	bfs.push(s - 1);
	while (!bfs.empty()) {
		if (level >= n - 1) {
			break;
		}
		if (bfs.front() == -1) {
			bfs.pop();
			if (bfs.empty()) {
				break;
			}
			bfs.push(-1);
			level++;
		}
		for (int i = 0; i < n; i++) {
			if (graph[bfs.front()][i]) {
				bfs.push(i);
				graph[bfs.front()][i] = 0;
				graph[i][bfs.front()] = 0;
				if (results[i] == -1) {
					results[i] = 6 * level;
				}
			}
		}
		bfs.pop();
	}
	for (int i = 0; i < n; i++) {
		if (i == s - 1) {
			continue;
		}
		cout << results[i] << " ";
	}
	cout << endl;
}

int main() {
	int number_of_test_cases;
	cin >> number_of_test_cases;
	for (int i = 0; i < number_of_test_cases; i++) {
		test_case();
	}
}