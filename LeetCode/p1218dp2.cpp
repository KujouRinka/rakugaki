// 第二种 dp 时空消耗更少，官方题解
class Solution {
public:
    int longestSubsequence(const vector<int> &arr, int difference) {
        unordered_map<int, int> dp;
        int max = dp[0];
        for (int v: arr) {
            dp[v] = dp[v - difference] + 1;
            max = std::max(dp[v], max);
        }
        return max;
    }
};
