class Solution {
 public:
  bool checkValidGrid(vector<vector<int>> &grid) {
    if (grid[0][0] != 0) {
      return false;
    }
    int x = 0, y = 0;
    int next = 1;
    int x_size = grid.size();
    int y_size = grid[0].size();
    int end = x_size * y_size;
    int mp[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    for (; next != end; ++next) {
      bool ok = false;
      for (auto [x_off, y_off] : mp) {
        int nx = x + x_off, ny = y + y_off;
        if (nx >= 0 && nx < x_size && ny >= 0 && ny < y_size) {
          if (grid[nx][ny] == next) {
            x = nx;
            y = ny;
            ok = true;
            break;
          }
        }
      }
      if (!ok) {
        return false;
      }
    }
    return true;
  }
};

