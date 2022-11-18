class Solution {
  const static int MOD = 1e9 + 7;
 public:
  int sumSubseqWidths(vector<int> &nums) {
    vector<int> two_pow(nums.size() + 1);
    two_pow[0] = 1;
    for (int i = 1; i < two_pow.size(); ++i)
      two_pow[i] = (two_pow[i - 1] << 1) % MOD;
    sort(nums.begin(), nums.end());
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      ret += (two_pow[i] - two_pow[nums.size() - i - 1]) * 1LL * nums[i] % MOD;
      ret %= MOD;
    }
    return ret;
  }
};

