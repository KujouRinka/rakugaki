class Solution {
    const int MOD = 1e9 + 7;

public:
    int countVowelPermutation(int n) {
        // 0: a, 1: e, 2: i, 3: o, 4: u
        vector<vector<int>> dp(n + 1, vector<int>(5));
        for (int i = 0; i < 5; ++i)
            dp[1][i] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i][0] = ((dp[i - 1][1] + dp[i - 1][2]) % MOD + dp[i - 1][4]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }

        int result = 0;
        for (int i = 0; i < 5; ++i)
            result = (result + dp[n][i] % MOD) % MOD;
        return result;
    }
};

