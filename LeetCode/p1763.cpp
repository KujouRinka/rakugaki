class Solution {
public:
    void dfs(const string &s, int start, int end, int & maxPos, int & maxLen) {
        if (start >= end) {
            return;
        }
        int lower = 0, upper = 0;
        for (int i = start; i <= end; ++i) {
            if (islower(s[i])) {
                lower |= 1 << (s[i] - 'a');
            } else {
                upper |= 1 << (s[i] - 'A');
            }
        }
        if (lower == upper) {
            if (end - start + 1 > maxLen) {
                maxPos = start;
                maxLen = end - start + 1;
            }
            return;
        } 
        int valid = lower & upper;
        int pos = start;
        while (pos <= end) {
            start = pos;
            while (pos <= end && valid & (1 << (tolower(s[pos]) - 'a'))) {
                ++pos;
            }
            dfs(s, start, pos - 1, maxPos, maxLen);
            ++pos;
        }
    }

    string longestNiceSubstring(const string &s) {
        int maxPos = 0, maxLen = 0;
        dfs(s, 0, s.size() - 1, maxPos, maxLen);
        return s.substr(maxPos, maxLen);
    }
};

