class Solution {
    int dp[31];

public:
    Solution() {
        dp[0] = dp[1] = 1;
        for (int i = 2; i < 31; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
    }

    int findIntegers(int n) {
        int len = 0;
        uint32_t t = n;
        while (n != 0) {
            ++len;
            n >>= 1;
        }

        int result = 0;
        int pre = 0;
        for (int i = len; i > 0; --i) {
            if (t & (1 << (i - 1))) {
                // have left and right
                result += dp[i];    // process left
                if (pre == 1) {     // process right
                    break;
                }
                pre = 1;
            } else {
                // only have left
                pre = 0;
            }

            if (i == 1)
                ++result;
        }
        return result;
    }
};
