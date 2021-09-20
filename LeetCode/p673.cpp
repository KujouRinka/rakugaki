class Solution {
    static int max(int a, int b) {
        return a > b ? a : b;
    }

public:
    int findNumberOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);

        int maxV = -1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < dp[j] + 1)
                        count[i] = count[j];
                    else if (dp[i] == dp[j] + 1)
                        count[i] += count[j];
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxV = max(maxV, dp[i]);
        }

        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (dp[i] == maxV)
                result += count[i];

        return result;
    }
};
