class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        auto sz = s.size();
        int add = 0;
        int i = 0;
        vector<int> result(sz);
        for (; s[i] != c; ++i)
            result[i] = 0x7fffffff;
        for (; i < sz; ++i) {
            if (s[i] == c)
                add = 0;
            result[i] = add++;
        }
        i = sz - 1;
        for (; s[i] != c; --i) {}
        for (; i >= 0; --i) {
            if (s[i] == c)
                add = 0;
            if (result[i] > add)
                result[i] = add;
            ++add;
        }
        return result;
    }
};

