class Solution {
 public:
  int rob(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    return max(helper(&nums[0], nums.size() - 1), helper(&nums[1], nums.size() - 1));
  }

 private:
  int helper(const int *nums, int size) {
    if (size == 0) {
      return 0;
    }
    vector<vector<int>> dp(size, vector<int>(2, 0));
    dp[0][1] = nums[0];

    for (int i = 1; i < size; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0] + nums[i];
    }
    return max(dp.back()[0], dp.back()[1]);
  }
};

