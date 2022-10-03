#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
 public:
  Solution() = default;

  void run() {
    int n_type, cnt;
    cin >> n_type >> cnt;
    used.reserve(n_type);
    g.resize(n_type + 1);
    ins.resize(n_type + 1);
    outs.resize(n_type + 1);
    for (int i = 1; i <= cnt; ++i) {
      char less, great;
      cin >> less >> great >> great;
      less -= 'A';
      great -= 'A';
      g[great].push_back(less);
      used.insert(less);
      used.insert(great);
      ++outs[great];
      ++ins[less];
      if (!loopCheck()) {
        printf("Inconsistency found after %d relations.\n", i);
        return;
      } else if (string s; used.size() == n_type && !(s = chainCheck()).empty()) {
        printf("Sorted sequence determined after %d relations: ", i);
        // TODO: print chain
        cout << s << '.' << endl;
        return;
      }
    }
    printf("Sorted sequence cannot be determined.\n");
  }

 private:
  unordered_set<int> used;
  vector<vector<int>> g;
  vector<int> ins;
  vector<int> outs;

  bool loopCheck() {  // return false if there is a loop
    queue<int> q;
    int visited = 0;
    auto ins_cp = ins;
    for (int i : used) {
      if (ins[i] == 0)
        q.push(i);
    }
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      ++visited;
      for (int next : g[node]) {
        if (--ins_cp[next] == 0)
          q.push(next);
      }
    }
    return visited == used.size();
  }

  string chainCheck() {   // return false if current sequence cannot be determined.
    queue<int> q;
    auto ins_cp = ins;
    for (int i : used) {
      if (ins[i] == 0)
        q.push(i);
    }
    string s;
    s.reserve(used.size());
    while (q.size() == 1) {
      int node = q.front();
      q.pop();
      s.push_back(node + 'A');
      for (int next : g[node]) {
        if (--ins_cp[next] == 0)
          q.push(next);
      }
    }
    reverse(s.begin(), s.end());
    return q.empty() ? s : "";
  }
};

int main() {
  Solution().run();
  return 0;
}

