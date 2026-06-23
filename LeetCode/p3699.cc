uint64_t MOD = static_cast<uint64_t>(1e9 + 7);

class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    r -= l;
    l = 0;
    if (n == 1) {
      return r - n + 1;
    }

    vector dp(2, vector(r + 1, 0));
    vector<int> dp0(r + 1);
    vector<int> dp1(r + 1);
    for (int i = l; i <= r; ++i) {
      dp[0][i] = 1;
      dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
      int s0 = 0;
      for (int idx = r; idx >= l; --idx) {
        dp1[idx] = s0;
        s0 = (s0 + dp[0][idx]) % MOD;
      }

      int s1 = 0;
      for (int idx = l; idx <= r; ++idx) {
        dp0[idx] = s1;
        s1 = (s1 + dp[1][idx]) % MOD;
      }
      dp0.swap(dp[0]);
      ranges::fill(dp0, 0);
      dp1.swap(dp[1]);
      ranges::fill(dp1, 0);
    }

    int ret = 0;
    for (int i = l; i <= r; ++i) {
      ret = (ret + dp[0][i]) % MOD;
      ret = (ret + dp[1][i]) % MOD;
    }
    return ret;
  }
};

