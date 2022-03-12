class Solution {
public:
    int maxProfit(const vector<int> &prices, int fee) {
        auto sz = prices.size();
        vector<vector<int>> dp(2, vector<int>(sz));
        dp[1][0] = -prices[0];
        for (int d = 1; d < sz; ++d) {
            dp[0][d] = max(dp[0][d - 1], dp[1][d - 1] + prices[d] - fee);
            dp[1][d] = max(dp[0][d - 1] - prices[d], dp[1][d - 1]);
        }
        return dp[0][sz - 1];
    }
};

