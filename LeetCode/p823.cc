class Solution {
 public:
  int numFactoredBinaryTrees(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    vector<long long> dp(arr.size(), 1);
    long long ret = 0, mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); ++i) {
      for (int left = 0, right = i - 1; left <= right; ++left) {
        while (left <= right && static_cast<long long>(arr[left]) * arr[right] > arr[i]) {
          --right;
        }
        if (left <= right && static_cast<long long>(arr[left]) * arr[right] == arr[i]) {
          dp[i] = (dp[i] + dp[left] * dp[right] * (1 + (left == right ? 0 : 1))) % mod;
        }
      }

      ret = (ret + dp[i]) % mod;
    }
    return static_cast<int>(ret);
  }
};

