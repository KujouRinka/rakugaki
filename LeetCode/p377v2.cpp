class Solution {
public:
    int combinationSum4(const vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; ++t) {
            for (int n: nums) {
                if (t >= n)
                    dp[t] = (static_cast<unsigned long long>(dp[t]) + dp[t - n]) % INT_MAX;
            }
        }
        return dp[target];
    }
};

