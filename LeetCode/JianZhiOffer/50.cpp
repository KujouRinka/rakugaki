class Solution {
public:
    char firstUniqChar(string s) {
        short repeat[26] = {0};
        for (auto &ch : s)
            repeat[ch - 'a']++;
        for (auto &ch : s) {
            if (repeat[ch - 'a'] == 1)
                return ch;
        }
        return ' ';
    }
};
