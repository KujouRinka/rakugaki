class Solution {
public:
    int coinChange(const vector<int> &coins, int amount) {
        vector<unsigned long long> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int s = 1; s <= amount; ++s) {
            for (int coin: coins) {
                if (s >= coin) {
                    int ts = dp[s - coin];
                    if (dp[s] == -1)
                        dp[s] = ts;
                    else
                        dp[s] = min(dp[s], ts + 1ull);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

