class Solution {
public:
    bool wordBreak(const string &s, const vector<string> &wordDict) {
        // may replace unordered_set by Trie to save mem
        unordered_set<string> _set(wordDict.begin(), wordDict.end());
        auto sz = s.size();
        vector<bool> dp(sz + 1);
        dp[0] = true;
        for (int i = 1; i <= sz; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[i - j] && _set.count(s.substr(i - j, j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sz];
    }
};

