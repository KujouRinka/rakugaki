#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
 public:
  Solution(int _n, int _m, int _x, int _y)
      : n(_n), m(_m), x(_x - 1), y(_y - 1),
        _g(n, vector<int>(m, -1)) {
    _g[x][y] = 0;
  }

  void run() {
    _q.push({x, y});
    bfs();
    for (auto &v : _g) {
      for (int i : v)
        cout << i << " ";
      cout << endl;
    }
  }

 private:
  int n, m, x, y;
  vector<vector<int>> _g;
  queue<pair<int, int>> _q;

  void bfs() {
    int step = 0;
    while (!_q.empty()) {
      ++step;
      for (int sz = _q.size(); sz > 0; --sz) {
        auto [tx, ty] = _q.front();
        _q.pop();
        for (auto [x_off, y_off] : offset) {
          int nx = tx + x_off, ny = ty + y_off;
          if (isValid(nx, ny) && (_g[nx][ny] == -1 || _g[nx][ny] > step)) {
            _g[nx][ny] = step;
            _q.push({nx, ny});
          }
        }
      }
    }
  }

  inline bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  static int offset[8][2];
};

int Solution::offset[8][2] = {
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
};

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  Solution(n, m, x, y).run();
  return 0;
}

