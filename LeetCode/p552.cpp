class Solution {
    static int64_t MOD;
public:
    int checkRecord(int n) {
        uint64_t dp[2][3] = {0};
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            uint64_t tmp[2][3] = {0};
            tmp[0][0] = (dp[0][0] + dp[0][1] + dp[0][2]) % MOD;
            tmp[1][0] =
                    (dp[1][0] % MOD + dp[1][1] % MOD + dp[1][2] % MOD + +dp[0][0] % MOD +
                     dp[0][1] % MOD + dp[0][2] % MOD) % MOD;
            tmp[0][1] = (dp[0][0]) % MOD;
            tmp[0][2] = (dp[0][1]) % MOD;
            tmp[1][1] = (dp[1][0]) % MOD;
            tmp[1][2] = (dp[1][1]) % MOD;

            memcpy(dp, tmp, sizeof(dp));
        }
        int64_t sum = 0;
        for (int i = 0; i <= 1; ++i)
            for (int j = 0; j <= 2; ++j)
                sum += dp[i][j] % MOD;

        return sum % MOD;
    }
};

int64_t Solution::MOD = 1e9 + 7;
