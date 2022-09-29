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
    g = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    memo.resize(n + 1, -1);
    for (int i = 0; i < m; ++i) {
      int from, to, weight;
      cin >> from >> to >> weight;
      g[from][to] = max(g[from][to], weight);
    }
    queue<int> q;
    memo[1] = 0;
    q.push(1);
    while (!q.empty()) {
      int me = q.front();
      q.pop();
      for (int to = 1; to <= n; ++to) {
        if (g[me][to] != -1 && memo[me] + g[me][to] > memo[to]) {
          memo[to] = memo[me] + g[me][to];
          q.push(to);
        }
      }
    }
    cout << memo[n] << endl;
  }

 private:
  vector<vector<int>> g;
  vector<int> memo;
};

int main() {
  Solution().run();
  return 0;
}

