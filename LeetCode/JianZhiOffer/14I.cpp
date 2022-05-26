class Solution {
public:
    int cuttingRope(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i)
            dp[1][i] = i;
        for (int i = 2; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int len = 1; j - len > 0; ++len)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - len] * len);
            }
        }
        int m = 0;
        for (int i = 1; i <= n; ++i) {
            m = max(m, dp[i][n]);
        }
        return m;
    }
};

