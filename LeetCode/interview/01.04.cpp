class Solution {
public:
    bool canPermutePalindrome(const string &s) {
        bitset<128> char_set;
        for (char ch: s)
            char_set.flip(ch);
        auto count = char_set.count();
        return count == 0 || count == 1;
    }
};
