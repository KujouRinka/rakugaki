class Solution {
public:
    int maxProfit(const vector<int> &prices) {
        auto sz = prices.size();
        vector<vector<int>> dp(2, vector<int>(sz));
        // 0: have
        dp[0][0] = -prices[0];
        // dp[1][0] = 0;
        for (int i = 1; i < sz; ++i) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);
            dp[1][i] = max(dp[0][i - 1] + prices[i], dp[1][i - 1]);
        }
        return dp[1][sz - 1];
    }
};

