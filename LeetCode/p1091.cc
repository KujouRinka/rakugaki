class Solution {
 public:
  int shortestPathBinaryMatrix(const vector<vector<int>> &grid) {
    if (grid.empty())
      return 0;
    vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size()));
    queue<pair<int, int>> q;
    int i = 1;
    if (grid[0][0] == 0) {
      q.emplace(0, 0);
      used[0][0] = true;
    }
    for (; !q.empty(); ++i) {
      for (int j = q.size(); j > 0; --j) {
        auto [x, y] = q.front();
        if (x == used[0].size() - 1 && y == used.size() - 1)
          return i;
        q.pop();
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0)
              continue;
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= used[0].size() || ny < 0 || ny >= used.size())
              continue;
            if (grid[ny][nx] != 0 || used[ny][nx])
              continue;
            used[ny][nx] = true;
            q.emplace(nx, ny);
          }
        }
      }
    }
    return -1;
  }
};

