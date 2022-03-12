int max(int a, int b, int c) {
    return std::max(a, std::max(b, c));
}

class Solution {
    enum : uint8_t {
        NO_OP = 0,
        IN,
        OUT,
        FREZ
    };
public:
    int maxProfit(const vector<int> &prices) {
        auto sz = prices.size();
        vector<vector<int>> dp(4, vector<int>(sz, 0));
        dp[IN][0] = -prices[0];
        for (int d = 1; d < sz; ++d) {
            dp[NO_OP][d] = max(dp[NO_OP][d - 1], dp[FREZ][d - 1]);
            dp[IN][d] = max(dp[FREZ][d - 1] - prices[d], dp[NO_OP][d - 1] - prices[d], dp[IN][d - 1]);
            dp[OUT][d] = dp[IN][d - 1] + prices[d];
            dp[FREZ][d] = dp[OUT][d - 1];
        }
        return max(dp[OUT][sz - 1], dp[FREZ][sz - 1], dp[NO_OP][sz - 1]);
    }
};

