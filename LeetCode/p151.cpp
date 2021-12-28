class Solution {
public:
    string reverseWords(const string &s) {
        string result;
        int sz = s.size();
        result.reserve(sz);
        for (int i = sz - 1; i >= 0; --i) {
            if (s[i] != ' ' || s[i] == ' ' && (i != sz - 1 && i != 0 && s[i + 1] != ' '))
                result.push_back(s[i]);
        }
        if (result.back() == ' ')
            result.resize(result.size() - 1);

        auto it_front = result.begin();
        auto it_back = result.begin();
        while (true) {
            while (it_back != result.end() && *it_back != ' ') {
                ++it_back;
            }
            reverse(it_front, it_back);
            if (it_back == result.end())
                break;
            it_front = it_back = it_back + 1;
        }
        return result;
    }
};

