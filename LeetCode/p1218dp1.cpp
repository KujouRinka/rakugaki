// 第一种 dp，自己写的
class Solution {
public:
    int longestSubsequence(const vector<int> &arr, int difference) {
        int sz = arr.size();
        vector<int> dp(sz, 0);
        unordered_map<int, int> front_map;

        int max = dp[0];
        for (int i = 0; i < sz; ++i) {
            if (front_map.count(arr[i] - difference))
                dp[i] = dp[front_map[arr[i] - difference]] + 1;
            else
                dp[i] = 1;
            if (dp[front_map[arr[i]]] < dp[i])
                front_map[arr[i]] = i;
            max = std::max(dp[i], max);
        }

        return max;
    }
};
