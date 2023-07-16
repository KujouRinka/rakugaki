class Solution {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    if (edges.size() != n - 1) {
      throw runtime_error("invalid edges");
    }
    if (n == 1) {
      return {0};
    }
    g = vector<vector<int>>(n);
    child_cnt = vector<int>(n, 0);
    child_point = vector<int>(n);
    ret = vector<int>(n);
    for_each(edges.begin(), edges.end(), [this](auto &v) {
      for (int i : v) {
        for (int j : v) {
          if (i == j) {
            continue;
          }
          g[i].push_back(j);
        }
      }
    });

    used = vector<bool>(n, false);
    dfs1(0, 1, -1);
    fill(used.begin(), used.end(), false);
    dfs2(0, -1);
    return std::move(ret);
  }

 private:
  vector<vector<int>> g;
  vector<int> child_cnt;
  vector<int> child_point;
  vector<int> ret;
  vector<bool> used;

  void dfs1(int cur, int depth, int from) {
    if (used[cur]) {
      return;
    }
    used[cur] = true;
    for_each(g[cur].begin(), g[cur].end(), [this, cur, depth, from](int i) {
      if (i == from) {
        return;
      }
      dfs1(i, depth + 1, cur);
      child_point[cur] += child_point[i] + child_cnt[i] + 1;
      child_cnt[cur] += child_cnt[i] + 1;
    });
  }

  void dfs2(int cur, int from) {
    if (used[cur]) {
      return;
    }
    used[cur] = true;
    int child_c = 0;
    for (int i : g[cur]) {
      if (i == from) {
        continue;
      }
      ret[cur] += child_point[i] + child_cnt[i] + 1;
      child_c += child_cnt[i] + 1;
    }
    if (from != -1) {
      ret[cur] += ret[from] - (child_point[cur] + child_cnt[cur] + 1);
      ret[cur] += ret.size() - child_c - 1;
    }
    for (int i : g[cur]) {
      if (i == from) {
        continue;
      }
      dfs2(i, cur);
    }
  }
};

