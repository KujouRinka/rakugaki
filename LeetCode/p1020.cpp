class Solution {
public:
    int numEnclaves(vector<vector<int>> &grid) {
        y_size = grid.size();
        x_size = grid[0].size();
        for (int i = 0; i < x_size; ++i) {
            if (grid[0][i] == 1)
                bfs(grid, i, 0);
            if (grid[y_size - 1][i] == 1)
                bfs(grid, i, y_size - 1);
        }
        for (int i = 0; i < y_size; ++i) {
            if (grid[i][0] == 1)
                bfs(grid, 0, i);
            if (grid[i][x_size - 1] == 1)
                bfs(grid, x_size - 1, i);
        }

        int enclaves = 0;
        for (auto &vec: grid) {
            for (int i: vec)
                enclaves += (i == 1 ? 1 : 0);
        }
        return enclaves;
    }

private:
    int x_size, y_size;
    static const int dirs[4][2];
    
    void bfs(vector<vector<int>> &grid, int x, int y) {
        ++grid[y][x];
        for (auto dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (isValid(nx, ny) && grid[ny][nx] == 1)
                bfs(grid, nx, ny);
        }
    }
    
    inline bool isValid(int x, int y) {
        return x >= 0 && x < x_size && y >= 0 && y < y_size;
    }
};

const int Solution::dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

