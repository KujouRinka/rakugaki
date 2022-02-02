class Solution {
public:
    string reversePrefix(const string &word, char ch) {
        string s(word);
        auto idx = s.find(ch);
        if (idx != string::npos) {
            reverse(s.begin(), s.begin() + idx + 1);
        }
        return s;
    }
};

