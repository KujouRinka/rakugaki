class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int nums_sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums_sum & 1)
            return false;
        int half_sum = nums_sum >> 1;
        vector<vector<bool>> dp(nums.size(), vector<bool>(half_sum + 1, false));
        for (int i = 1; i <= half_sum; ++i) {
            if (nums[0] == i)
                dp[0][i] = true;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j <= half_sum; ++j) {
                if (j < nums[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else if (dp[i - 1][j] || dp[i - 1][j - nums[i]])
                    dp[i][j] = true;
                }
            }
        }
        return dp[nums.size() - 1][half_sum];
    }
};
