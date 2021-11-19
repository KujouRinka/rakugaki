class Solution {
public:
    int integerReplacement(int n) {
        int sz = (n & 1) ? n + 1 : n;
        int max_loop = sz >> 1;
        vector<int> dp(sz + 1);
        // dp[1] = 0;
        dp[2] = 1;
        for (int i = 2; i <= max_loop; ++i) {
            int base = i * 2;
            dp[base] = dp[i] + 1;
            dp[base - 1] = min(dp[base], dp[base - 2]) + 1;
        }
        return dp[n];
    }
};
