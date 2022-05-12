class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> hash;
        vector<int> dp(s.size());
        dp[0] = 1;
        hash[s[0]] = 0;
        int result = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (hash.count(s[i]) == 0) {
                dp[i] = dp[i - 1] + 1;
            } else {
                if (dp[i - 1] < i - hash[s[i]])
                    dp[i] = dp[i - 1] + 1;
                else
                    dp[i] = i - hash[s[i]];
            }
            hash[s[i]] = i;
            result = max(result, dp[i]);
        }
        return result;
    }
};

