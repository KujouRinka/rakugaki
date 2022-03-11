class Solution {
public:
    int maxProfit(int k, const vector<int> &prices) {
        auto sz = prices.size();
        if (sz == 0)
            return 0;
        int stat_cnt = k * 2 + 1;
        vector<vector<int>> dp(stat_cnt, vector<int>(sz));
        for (int i = 1; i < stat_cnt; i += 2)
            dp[i][0] = -prices[0];
        for (int d = 1; d < sz; ++d) {
            for (int j = 1; j <= k; ++j) {
                dp[j * 2 - 1][d] = max(dp[j * 2 - 1][d - 1], dp[j * 2 - 2][d - 1] - prices[d]);
                dp[j * 2][d] = max(dp[j * 2][d - 1], dp[j * 2 - 1][d - 1] + prices[d]);
            }
        }
        return dp[stat_cnt - 1][sz - 1];
    }
};

