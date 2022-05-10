class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size());
        dp[0] = max(0, nums[0]);
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

