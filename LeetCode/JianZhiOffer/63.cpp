class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        vector<int> m_m;
        int m = prices[0];
        for (int i: prices) {
            m = min(m, i);
            m_m.push_back(m);
        }
        vector<int> dp(prices.size());
        for (int i = 1; i < prices.size(); ++i) {
            dp[i] = max(dp[i - 1], prices[i] - m_m[i]);
        }
        return dp.back();
    }
};

