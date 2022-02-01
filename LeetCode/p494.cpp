class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        auto sz = nums.size();
        nums_sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > abs(nums_sum))
            return 0;
        x_size = nums_sum * 2 + 1;
        vector<vector<int>> dp(sz, vector<int>(x_size, 0));
        dp[0][toIdx(-nums[0])] += 1;
        dp[0][toIdx(nums[0])] += 1;

        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < x_size; ++j) {
                if (isValid(j - nums[i]))
                    dp[i][j] += dp[i - 1][j - nums[i]];
                if (isValid(j + nums[i]))
                    dp[i][j] += dp[i - 1][j + nums[i]];
            }
        }

        return dp[sz - 1][toIdx(target)];
    }

private:
    int nums_sum;
    int x_size;

    inline int toIdx(int idx) const {
        return idx + nums_sum;
    }

    inline bool isValid(int idx) const {
        return idx >= 0 && idx < x_size;
    }
};

