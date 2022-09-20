#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1, vector<int>(n + 1));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i != j) g[i][j] = 0x7fffffff / 4;
    }
  }
  for (int i = 1; i < n; ++i) {
    int ch, pa;
    cin >> ch >> pa;
    g[ch][pa] = 1;
    g[pa][ch] = 2;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
      }
    }
  }

  int from, to;
  cin >> from >> to;
  int depth = 0, width = 0;
  unordered_map<int, int> width_memo;
  for (int i = 1; i <= n; ++i) {
    depth = max(depth, g[1][i]);
    width = max(width, ++width_memo[g[1][i]]);
  }
  cout << depth + 1 << "\n" << width << "\n" << g[from][to] << endl;
}

