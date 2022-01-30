class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>> &obstacleGrid) {
        auto y_sz = obstacleGrid.size();
        auto x_sz = obstacleGrid[0].size();
        vector<vector<int>> dp(y_sz, vector<int>(x_sz, 0));
        for (int i = 0; i < x_sz && obstacleGrid[0][i] == 0; ++i)
            dp[0][i] = 1;
        for (int i = 0; i < y_sz && obstacleGrid[i][0] == 0; ++i)
            dp[i][0] = 1;
        for (int i = 1; i < y_sz; ++i) {
            for (int j = 1; j < x_sz; ++j)
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp.back().back();
    }
};

