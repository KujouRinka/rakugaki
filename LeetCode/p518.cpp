class Solution {
public:
    int change(int amount, vector<int> &coins) {
        auto sz = coins.size();
        vector<vector<int>> dp(sz, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; ++i) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }

        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j] + (j >= coins[i] ? dp[i][j - coins[i]] : 0);
            }
        }
        return dp[sz - 1][amount];
    }
};

