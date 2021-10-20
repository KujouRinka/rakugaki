class Solution {
public:
    bool CheckPermutation(string &s1, string &s2) {
        if (s1.size() != s2.size())
            return false;
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for (int i = 0; i < s1.size(); ++i) {
            ++map1[s1[i]];
            ++map2[s2[i]];
        }
        for (auto &p: map1) {
            if (p.second != map2[p.first])
                return false;
        }
        return true;
    }
};
