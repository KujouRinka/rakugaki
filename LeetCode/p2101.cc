class Solution {
 public:
  int maximumDetonation(vector<vector<int>> &bombs) {
    this->bombs.swap(bombs);

    len = this->bombs.size();
    used = vector<bool>(len, false);

    g.resize(len);
    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < len; ++j) {
        if (i == j || !can_fuse(i, j)) {
          continue;
        }
        g[i].push_back(j);
      }
    }

    int ret = dfs();

    this->bombs.swap(bombs);

    return ret;
  }

 private:
  vector<vector<int>> g;
  vector<vector<int>> bombs;
  vector<bool> used;

  int len;

  int dfs() {
    int memo;
    int r = 0;
    for (int i = 0; i < len; ++i) {
      memo = 1;
      used[i] = true;
      dfs_helper(i, memo);
      fill(used.begin(), used.end(), false);
      r = max(r, memo);
    }
    return r;
  }

  void dfs_helper(int i, int &c) {
    for (auto node : g[i]) {
      if (used[node]) {
        continue;
      }
      ++c;
      used[node] = true;
      dfs_helper(node, c);
    }
  }

  bool can_fuse(int s, int d) {
    return pow(bombs[s][0] - bombs[d][0], 2) + pow(bombs[s][1] - bombs[d][1], 2) <= pow(bombs[s][2], 2);
  }
};

