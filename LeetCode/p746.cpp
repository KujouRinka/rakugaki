class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        auto sz = cost.size();
        vector<int> dp(sz + 1);
        for (int i = 2; i < sz + 1; ++i)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        return dp[sz];
    }
};

