#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> v[i][j];
    }
  }
  vector<vector<int>> hs(n + 1, vector<int>(n + 1));
  vector<vector<int>> vs(n + 1, vector<int>(n + 1));
  vector<vector<int>> ts(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      hs[i][j] = hs[i][j - 1] + v[i - 1][j - 1];
      vs[j][i] = vs[j - 1][i] + v[j - 1][i - 1];
    }
  }
  ts = vs;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ts[i][j] += ts[i][j - 1];
    }
  }
  int ret = 0;
  for (int x1 = 0; x1 <= n; ++x1) {
    for (int y1 = 0; y1 <= n; ++y1) {
      for (int x2 = x1 + 1; x2 <= n; ++x2) {
        for (int y2 = y1 + 1; y2 <= n; ++y2) {
          ret = max(ret, ts[y2][x2] - ts[y2][x1] - ts[y1][x2] + ts[y1][x1]);
        }
      }
    }
  }
  cout << ret << endl;
  return 0;
}

