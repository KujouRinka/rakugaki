class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color) {
        m_color = color;
        m_ori_color = grid[row][col];
        m_x_size = grid[0].size();
        m_y_size = grid.size();
        result = vector<vector<int>>(m_y_size, vector<int>(m_x_size, 0));
        dfsAndColor(grid, col, row);
        for (int i = 0; i < m_y_size; ++i) {
            for (int j = 0; j < m_x_size; ++j) {
                if (result[i][j] == 0)
                    result[i][j] = grid[i][j];
            }
        }
        return result;
    }

private:
    int m_color;
    int m_ori_color;
    int m_x_size;
    int m_y_size;
    static int dir_maps[4][2];
    vector<vector<int>> result;

    void dfsAndColor(vector<vector<int>> &grid, int x, int y) {
        if (checkAround(grid, x, y))
            result[y][x] = m_color;
        else
            result[y][x] = grid[y][x];
        for (auto &dir_map: dir_maps) {
            int nx = x + dir_map[0];
            int ny = y + dir_map[1];
            if (isValidIdx(nx, ny) && result[ny][nx] == 0 && grid[ny][nx] == m_ori_color)
                dfsAndColor(grid, nx, ny);
        }
    }

    bool isValidIdx(int x, int y) {
        return x >= 0 && x < m_x_size && y >= 0 && y < m_y_size;
    }

    bool checkAround(vector<vector<int>> &grid, int x, int y) {
        for (auto &dir_map: dir_maps) {
            int nx = x + dir_map[0];
            int ny = y + dir_map[1];
            if (!isValidIdx(nx, ny) || grid[ny][nx] != m_ori_color)
                return true;
        }
        return false;
    }
};

int Solution::dir_maps[4][2] = {{1,  0},
                                {-1, 0},
                                {0,  1},
                                {0,  -1}};

