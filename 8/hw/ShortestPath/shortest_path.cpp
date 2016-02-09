#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Edge {
	int from;
	int to;

	Edge(int _from = 0, int _to = 0): from(_from), to(_to) { }
};

struct TestCase {
	int nodes_count;
	int edges_count;
	vector<Edge> edges;
	int start;

	TestCase(int _nodes_count = 0, int _edges_count = 0, vector<Edge> _edges = vector<Edge>(), int _start = 0):
		nodes_count(_nodes_count), edges_count(_edges_count), edges(_edges), start(_start) { }
};

vector<TestCase> read_input() {
	string line;
	vector<string> lines;
	while( getline(cin, line)) {
		lines.push_back(line);
	}

	vector<TestCase> cases;
	int number_of_cases = atoi(lines[0].c_str());
	int current_line = 1;

	for(int i = 0; i < number_of_cases; i++) {
		TestCase current;
		int number_of_nodes = atoi(lines[current_line].c_str());
		int edges_start = 0;
		while(lines[current_line][edges_start] != ' ') {
			edges_start++;
		}

		int number_of_edges = atoi(lines[current_line].substr(edges_start, lines[current_line].size() - edges_start).c_str());

		current.nodes_count = number_of_nodes;
		current.edges_count = number_of_edges;
		current_line++;

		for(int j = 0; j < current.edges_count; j++) {
			Edge current_edge;
			int from = atoi(lines[current_line].c_str());

			int to_start = 0;
			while(lines[current_line][to_start] != ' ') {
				to_start++;
			}

			int to = atoi(lines[current_line].substr(to_start, lines[current_line].size() - to_start).c_str());
			current_edge.from = from;
			current_edge.to = to;

			current.edges.push_back(current_edge);
			current_line++;
		}
		current.start = atoi(lines[current_line].c_str());
		current_line++;
		cases.push_back(current);
	}

	return cases;
}

void bfs(int start, int range, vector<Edge> edges) {
	vector<int> distances(range + 1, -1);

	queue<int> q;
	q.push(start);

	while(!q.empty()) {
		int current_node = q.front();
		q.pop();

		for (int i = 0; i < edges.size(); i++) {
			if (edges[i].from == current_node && distances[edges[i].to] == -1 && edges[i].to != start) {
				q.push(edges[i].to);
				if(distances[current_node] == -1) {
					distances[edges[i].to] = 6;
				} else {
					distances[edges[i].to] = distances[current_node] + 6;
				}
			} else if (edges[i].to == current_node && distances[edges[i].from] == -1 && edges[i].from != start) {
				q.push(edges[i].from);
				if (distances[current_node] == -1) {
					distances[edges[i].from] = 6;
				} else {
					distances[edges[i].from] = distances[current_node] + 6;
				}
			}
		}
	}

	distances.erase(distances.begin() + start);

	for (int i = 1; i < distances.size(); i++) {
		cout << distances[i] << " ";
	}
	cout << endl;
}

void process_cases(vector<TestCase> cases) {
	for(int i = 0; i < cases.size(); i++) {
		TestCase current_case = cases[i];

		bfs(current_case.start, current_case.nodes_count, current_case.edges);
	}
}

int main() {
	vector<TestCase> cases = read_input();
	process_cases(cases);
}