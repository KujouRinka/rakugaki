class Solution {
    using ull = unsigned long long;

public:
    int combinationSum4(const vector<int> &nums, int target) {
        vector<vector<ull>> dp(target + 1, vector<ull>(target + 1, 0));
        dp[0][0] = 1;
        int r = 0;
        for (int n = 1; n <= target; ++n) {
            for (int t = 0; t <= target; ++t) {
                for (int i: nums)
                    if (t >= i)
                        dp[n][t] += dp[n - 1][t - i];
            }
            r += dp[n][target];
        }
        return r;
    }
};

