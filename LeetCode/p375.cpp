class Solution {
    static int minStep(vector<vector<int>> &dp, int lower, int upper) {
        if (lower == upper)
            return 0;
        int min_val = lower + dp[lower + 1][upper];
        for (int i = lower + 1; i < upper; ++i) {
            min_val = min(min_val, i + max(dp[lower][i - 1], dp[i + 1][upper]));
        }
        min_val = min(min_val, upper + dp[lower][upper - 1]);
        return min_val;
    }

public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int j = 2; j <= n; ++j) {
            for (int i = j - 1; i >= 1; --i) {
                dp[i][j] = minStep(dp, i, j);
            }
        }

        return dp[1][n];
    }
};
