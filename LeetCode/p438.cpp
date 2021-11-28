class Solution {
public:
    vector<int> findAnagrams(const string &s, const string &p) {
        int p_count[26] = {0};
        int sz_p = p.size();
        int sz_s = s.size();
        for (char ch: p)
            ++p_count[getIdx(ch)];
        int left = 0, right = 0;

        vector<int> result;
        result.reserve(sz_s / 4);
        while (right < sz_s) {
            if (right - left == sz_p) {
                result.push_back(left);
                ++p_count[getIdx(s[left])];
                ++left;
            } else if (p_count[getIdx(s[right])] != 0) {
                --p_count[getIdx(s[right])];
                ++right;
            } else {
                ++p_count[getIdx(s[left++])];
            }
        }
        bool f = true;
        for (int i: p_count)
            if (i != 0)
                f = false;
        if (f)
            result.push_back(left);

        return result;
    }

private:
    inline static int getIdx(char ch) {
        return ch - 'a';
    }
};
