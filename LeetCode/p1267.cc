class Solution {
 public:
  int countServers(vector<vector<int>> &grid) {
    int h = grid.size(), v = grid[0].size();
    vector<int> memo;
    unordered_set<int> ok;
    for (int i = 0; i < h; ++i) {
      memo.clear();
      for (int j = 0; j < v; ++j) {
        if (grid[i][j] == 1) {
          memo.push_back(i * v + j);
        }
      }
      if (memo.size() > 1) {
        ok.insert(memo.begin(), memo.end());
      }
    }
    for (int i = 0; i < v; ++i) {
      memo.clear();
      for (int j = 0; j < h; ++j) {
        if (grid[j][i] == 1) {
          memo.push_back(j * v + i);
        }
      }
      if (memo.size() > 1) {
        ok.insert(memo.begin(), memo.end());
      }
    }
    return ok.size();
  }
};

