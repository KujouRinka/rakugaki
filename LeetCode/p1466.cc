class Solution {
 public:
  int minReorder(int n, vector<vector<int>> &connections) {
    ret = 0;
    g.resize(n);
    for (auto &conn : connections) {
      g[conn[0]].push_back(conn[1]);
      g[conn[1]].push_back(-conn[0]);
    }
    dfs(0, -1);
    return ret;
  }

 private:
  int ret;
  vector<vector<int>> g;

  void dfs(int cur, int from) {
    if (g[cur].size() == 1 && abs(g[cur][0]) == from) {
      return;
    }
    for (int node : g[cur]) {
      int next = node;
      if (node < 0) {
        next = -node;
      }
      if (next == from) {
        continue;
      }
      if (node > 0) {
        ++ret;
      }

      dfs(next, cur);
    }
  }
};

