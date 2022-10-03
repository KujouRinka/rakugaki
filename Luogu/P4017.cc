#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  Solution() = default;

  void run() {
    int n_type, cnt;
    cin >> n_type >> cnt;
    vector<int> memo(n_type + 1);
    vector<vector<int>> relation(n_type + 1);
    vector<int> ins(n_type + 1);
    vector<int> outs(n_type + 1);
    for (int i = 0; i < cnt; ++i) {
      int eaten, eat;
      cin >> eaten >> eat;
      relation[eaten].push_back(eat);
      ++ins[eat];
      ++outs[eaten];
    }
    queue<int> wait_list;
    for (int i = 1; i <= n_type; ++i) {
      if (ins[i] == 0) {
        wait_list.push(i);
        memo[i] = 1;
      }
    }
    while (!wait_list.empty()) {
      int node = wait_list.front();
      wait_list.pop();
      for (int next : relation[node]) {
        memo[next] = (memo[next] + memo[node]) % 80112002;
        if (--ins[next] == 0)
          wait_list.push(next);
      }
    }
    int ret = 0;
    for (int i = 1; i <= n_type; ++i) {
      if (outs[i] == 0)
        ret = (ret + memo[i]) % 80112002;
    }
    cout << ret << endl;
  }
};

int main() {
  Solution().run();
  return 0;
}

