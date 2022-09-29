#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  Solution() = default;

  void run() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1);
    memo.resize(n + 1);
    while (m--) {
      int from, to;
      cin >> from >> to;
      g[to].push_back(from);
    }
    int ok = 0;
    for (int i = n; ok < n && i > 0; --i) {
      if (memo[i] != 0)
        continue;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int me = q.front();
        q.pop();
        if (visited[me])
          continue;
        memo[me] = i;
        visited[me] = true;
        ++ok;
        for (int j : g[me])
          q.push(j);
      }
    }
    for (int i = 1; i <= n; ++i)
      cout << memo[i] << " ";
    cout << endl;
  }

 private:
  vector<vector<int>> g;
  vector<bool> visited;
  vector<int> memo;
};

int main() {
  Solution().run();
  return 0;
}

