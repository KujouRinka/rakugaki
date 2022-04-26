class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m1, m2;
        m1 = m2 = 0;
        int s = 0;
        auto sz = grid.size();
        for (int i = 0; i < sz; ++i) {
            m1 = m2 = 0;
            for (int j = 0; j < sz; ++j) {
                m1 = max(m1, grid[i][j]);
                m2 = max(m2, grid[j][i]);
                if (grid[i][j] > 0)
                    ++s;
            }
            s += m1 + m2;
        }
        return s;
    }
};

