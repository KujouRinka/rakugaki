class Solution {
public:
    int getMaximumGold(const vector<vector<int>> &grid) {
        m_result = 0;
        raw_data = grid;
        x_size = grid[0].size();
        y_size = grid.size();
        visited = vector<vector<bool>>(y_size, vector<bool>(y_size, false));
        for (int i = 0; i < y_size; ++i) {
            for (int j = 0; j < x_size; ++j)
                if (raw_data[i][j] != 0) {
                    visited[i][j] = true;
                    backtracking(j, i, raw_data[i][j]);
                    visited[i][j] = false;
                }
        }
        return m_result;
    }

private:
    int m_result;
    size_t x_size;
    size_t y_size;
    vector<vector<int>> raw_data;
    vector<vector<bool>> visited;

    static int dirs[4][2];

    void backtracking(int x, int y, int sum) {
        u_int valid_dirs = getDirs(x, y);
        if (valid_dirs == 0) {
            m_result = max(m_result, sum);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            if ((valid_dirs >> i) & 1) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                visited[ny][nx] = true;
                backtracking(nx, ny, sum + raw_data[ny][nx]);
                visited[ny][nx] = false;
            }
        }
    }

    u_int getDirs(int x, int y) const {
        u_int d = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (isValid(nx, ny) && raw_data[ny][nx] != 0 && !visited[ny][nx])
                d |= (1 << i);
        }
        return d;
    }

    inline bool isValid(int x, int y) const {
        return x >= 0 && x < x_size && y >= 0 && y < y_size;
    }
};

int Solution::dirs[4][2] = {{0,  -1},
                            {0,  1},
                            {-1, 0},
                            {1,  0}};

