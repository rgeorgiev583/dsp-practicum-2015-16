#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

void bfs(int S, const vector<vector<int>>& adjLists, vector<int>& results) {
  queue<int> toTraverse;
  toTraverse.push(S);

  unordered_set<int> traversed;
  traversed.emplace(S);

  while (!toTraverse.empty()) {
    int currentNode = toTraverse.front();
    toTraverse.pop();

    for (int successor : adjLists[currentNode - 1]) {
      if (traversed.find(successor) == traversed.end()) {
        toTraverse.push(successor);
        traversed.emplace(successor);
        results[successor - 1] = results[currentNode - 1] + 6;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; ++i) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjLists(N);
    for (int j = 0; j < M; ++j) {
      int x, y;
      cin >> x >> y;
      adjLists[x - 1].push_back(y);
      adjLists[y - 1].push_back(x);
    }

    int S;
    cin >> S;

    vector<int> results(N, 0);

    bfs(S, adjLists, results);

    for (int j = 0; j < N; ++j) {
      if (j + 1 == S) {
        continue;
      }

      cout << (results[j] ? results[j] : -1) << ' ';
    }
    cout << '\n';
  }

  return 0;
}