class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        auto sz = strs.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        auto[zero, one] = formCount(strs[0]);
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j)
                dp[0][i][j] = (i >= zero && j >= one) ? 1 : 0;
        }
        for (int i = 1; i < sz; ++i) {
            auto[zero, one] = formCount(strs[i]);
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zero && k >= one)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zero][k - one] + 1);
                }
            }
        }
        return dp[sz - 1][m][n];
    }

private:
    static inline pair<int, int> formCount(const string &s) {
        int zero = 0, one = 0;
        for (char ch: s)
            ++(ch == '0' ? zero : one);
        return {zero, one};
    }
};

