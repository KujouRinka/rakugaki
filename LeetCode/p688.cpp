class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        m_n = n;
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, 0)));
        for (int s = 1; s <= k; ++s) {
            for (int y = 0; y < n; ++y) {
                for (int x = 0; x < n; ++x) {
                    dp[y][x][s] = (get(dp, x - 1, y - 2, s - 1)
                                  + get(dp, x - 1, y + 2, s - 1)
                                  + get(dp, x + 1, y - 2, s - 1)
                                  + get(dp, x + 1, y + 2, s - 1)
                                  + get(dp, x - 2, y - 1, s - 1)
                                  + get(dp, x - 2, y + 1, s - 1)
                                  + get(dp, x + 2, y - 1, s - 1)
                                  + get(dp, x + 2, y + 1, s - 1)) / 8.0;
                }
            }
        }

        return 1 - dp[row][column][k];
    }

private:
    int m_n;

    template<typename T>
    inline double get(const T &vec, int x, int y, int step) const {
        if (x >= 0 && x < m_n && y >= 0 && y < m_n)
            return vec[y][x][step];
        return 1;
    }
};

