class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int len = 1; i - len > 0; ++len)
                dp[i] = max(dp[i], max(dp[i - len] * len, (i - len) * len));
        }
        return dp[n];
    }
};

