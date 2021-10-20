class Solution {
public:
    bool isFlipedString(string &s1, string &s2) {
        if (s1.size() != s2.size())
            return false;
        string tmp = s2 + s2;
        return tmp.find(s1) != tmp.npos;
    }
};
