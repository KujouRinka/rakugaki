class Solution {
    const vector<pair<int, int>> dirs{{0,  1},
                                      {0,  -1},
                                      {1,  0},
                                      {-1, 0}};
    unsigned int MOD = 1e9 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
        auto f = [](int &i) -> void { i++; };
        for (int i = 0; i < n; ++i) {
            for_each(dp[0][i].begin() + 1, dp[0][i].end(), f);
            for_each(dp[m - 1][i].begin() + 1, dp[m - 1][i].end(), f);
        }
        for (int i = 0; i < m; ++i) {
            for_each(dp[i][0].begin() + 1, dp[i][0].end(), f);
            for_each(dp[i][n - 1].begin() + 1, dp[i][n - 1].end(), f);
        }

        for (int move = 1; move <= maxMove; ++move) {
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    for (auto &dir : dirs) {
                        int nx = x + dir.first, ny = y + dir.second;
                        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                            continue;
                        dp[x][y][move] += dp[nx][ny][move - 1];
                        dp[x][y][move] %= MOD;
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};
