class Solution {
public:
    int findLength(const vector<int> &nums1, const vector<int> &nums2) {
        auto sz1 = nums1.size(), sz2 = nums2.size();
        vector<vector<int>> dp(sz1, vector<int>(sz2));
        int r = 0;
        for (int i = 0; i < sz1; ++i) {
            dp[i][0] = nums1[i] == nums2[0] ? 1 : 0;
            r = max(r, dp[i][0]);
        }
        for (int i = 0; i < sz2; ++i) {
            dp[0][i] = nums1[0] == nums2[i] ? 1 : 0;
            r = max(r, dp[0][i]);
        }
        for (int i = 1; i < sz1; ++i) {
            for (int j = 1; j < sz2; ++j) {
                if (nums1[i] == nums2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                r = max(r, dp[i][j]);
            }
        }
        return r;
    }
};

