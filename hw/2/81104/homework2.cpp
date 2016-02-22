#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <utility>

using namespace std;

typedef vector<vector<int> > Graph;

int findShortestPath(const Graph &graph, int source, int target) {
    if (source == target) return 0;
    if (graph[target].empty() == true || graph[source].empty() == true) return -1;
    vector<int> min_distance( graph.size(), INT_MAX );
    min_distance[source] = 0;
    set<pair<int, int> > active_vertices;
    active_vertices.insert({0,source});
    while (!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        if (where == target) return min_distance[where];
        active_vertices.erase( active_vertices.begin() );
        for (auto edge : graph[where]){
            if (min_distance[edge] > min_distance[where] + 6) {
                active_vertices.erase( { min_distance[edge], edge } );
                min_distance[edge] = min_distance[where] + 6;
                active_vertices.insert( { min_distance[edge], edge } );
            }
        }
    }
    return -1;
}

int main()
{
    int t, n, m, x, y, s;
    Graph results;
    vector<int> temp;
    cin >> t;
    for (int i = 0; i < t; i++){
        results.push_back(temp);
        Graph g;
        cin >> n >> m;
        for (int j = 0; j <= n; j++) g.push_back(temp);
        for (int j = 0; j < m; j++){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cin >> s;
        for (int j = 1; j <= n; j++){
            if (j == s) continue;
            results[i].push_back(findShortestPath(g, s, j));
        }
    }
    for (int i = 0; i < t; i++){
        for (int j = 0; j < results[i].size(); j++) cout << results[i][j] << " ";
        cout << endl;
    }
    return 0;
}
