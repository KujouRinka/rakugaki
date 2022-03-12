class Solution {
public:
    int findLengthOfLCIS(const vector<int> &nums) {
        int result = 1;
        auto sz = nums.size();
        vector<int> dp(sz, 0);
        dp[0] = 1;
        for (int i = 1; i < sz; ++i) {
            dp[i] = (nums[i] > nums[i - 1] ? dp[i - 1] : 0) + 1;
            result = max(result, dp[i]);
        }
        return result;
    }
};

