#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  Solution() = default;

  void run() {
    int max_stop, train_cnt;
    cin >> max_stop >> train_cnt;
    vector<vector<bool>> g(max_stop + 1, vector<bool>(max_stop + 1, false));
    vector<int> cur_stop;
    vector<int> cur_add;
    cur_stop.reserve(train_cnt);
    cur_add.reserve(train_cnt);
    for (int i = 0; i < train_cnt; ++i) {
      int stop;
      cin >> stop;
      cur_stop.clear();
      cur_add.clear();
      while (stop--) {
        int cur;
        cin >> cur;
        cur_stop.push_back(cur);
      }
      int first = cur_stop[0];
      for (auto it = cur_stop.begin() + 1; it != cur_stop.end(); ++it) {
        for (int k = first + 1; k < *it; ++k)
          cur_add.push_back(k);
        first = *it;
      }
      for (int from : cur_stop) {
        for (int to : cur_add)
          g[from][to] = true;
      }
    }
    queue<int> q;
    vector<int> ins(max_stop + 1);
    for (int i = 1; i <= max_stop; ++i) {
      for (int j = 1; j <= max_stop; ++j) {
        if (g[j][i])
          ++ins[i];
      }
    }
    for (int i = 1; i <= max_stop; ++i) {
      if (ins[i] == 0)
        q.push(i);
    }
    int ret = 0;
    while (!q.empty()) {
      ++ret;
      for (int i = q.size(); i > 0; --i) {
        int e = q.front();
        q.pop();
        for (int j = 0; j <= max_stop; ++j) {
          if (g[e][j] && --ins[j] == 0)
            q.push(j);
        }
      }
    }
    cout << ret << endl;
  }
};

int main() {
  Solution().run();
  return 0;
}

