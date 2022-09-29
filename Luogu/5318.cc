#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
 public:
  Solution() = default;

  void run() {
    int n, m;
    cin >> n >> m;
    visited = vector<bool>(n + 1, false);
    g.resize(n + 1);
    for (int i = 0; i < m; ++i) {
      int from, to;
      cin >> from >> to;
      g[from].insert(to);
    }
    dfs(1);
    cout << "\n" << flush;
    fill(visited.begin(), visited.end(), false);
    bfs(1);
    cout << endl;
  }

 private:
  vector<set<int>> g;
  vector<bool> visited;

  void dfs(int me) {
    if (visited[me])
      return;
    cout << me << " ";
    visited[me] = true;
    for (int i : g[me]) {
      dfs(i);
    }
  }

  void bfs(int beginner) {
    queue<int> q;
    q.push(beginner);
    while (!q.empty()) {
      int me = q.front();
      q.pop();
      if (visited[me])
        continue;
      cout << me << " ";
      visited[me] = true;
      for (int j : g[me]) {
        q.push(j);
      }
    }
  }
};

int main() {
  Solution().run();
  return 0;
}

