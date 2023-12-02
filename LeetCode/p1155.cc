class Solution {
  const int MOD = 1e9 + 7;
 public:
  int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));
    // dp[dice no][target]
    // dp[i][j] = dp[i-1][j-1...k]
    for (int i = 1; i <= k && i <= target; ++i) {
      dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) { // dice no
      for (int j = 1; j <= target; ++j) {    // target
        for (int kk = 1; kk <= k; ++kk) {
          int t = j - kk;
          if (t >= 0) {
            dp[i][j] = (dp[i][j] + dp[i - 1][t]) % MOD;
          }
        }
      }
    }
    return dp[n][target];
  }
};

