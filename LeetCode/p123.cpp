class Solution {
    enum STAT : uint8_t {
        NO_OP = 0,
        FST_IN,
        FST_OUT,
        SEC_IN,
        SEC_OUT,
    };
public:
    int maxProfit(const vector<int> &prices) {
        auto sz = prices.size();
        if (sz == 0)
            return 0;
        vector<vector<int>> dp(5, vector<int>(sz));
        // some init cond
        // supposing that days before 0 with stock price 0
        // could have a better understanding of why SEC_IN
        // of day 0 are assigned value -prices[0]
        dp[FST_IN][0] = -prices[0];
        dp[SEC_IN][0] = -prices[0];
        for (int d = 1; d < sz; ++d) {
            dp[NO_OP][d] = dp[NO_OP][d - 1];    // could be removed
            dp[FST_IN][d] = max(dp[NO_OP][d - 1] - prices[d], dp[FST_IN][d - 1]);
            dp[FST_OUT][d] = max(dp[FST_IN][d - 1] + prices[d], dp[FST_OUT][d - 1]);
            dp[SEC_IN][d] = max(dp[FST_OUT][d - 1] - prices[d], dp[SEC_IN][d - 1]);
            dp[SEC_OUT][d] = max(dp[SEC_IN][d - 1] + prices[d], dp[SEC_OUT][d - 1]);
        }
        return dp[SEC_OUT][sz - 1];
    }
};

