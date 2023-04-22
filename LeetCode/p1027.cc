class Solution {
 public:
  int longestArithSeqLength(vector<int> &nums) {
    int ret = 1;
    vector<vector<int>> dp(nums.size(), vector<int>(1001, 1));
    for (size_t i = 1; i < nums.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        auto delta = idx(nums[i] - nums[j]);
        dp[i][delta] = max(dp[i][delta], dp[j][delta] + 1);
        ret = max(ret, dp[i][delta]);
      }
    }
    return ret;
  }

 private:
  static size_t idx(int x) {
    return x + 500;
  }
};

