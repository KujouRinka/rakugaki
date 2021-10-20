class Solution {
public:
    bool isUnique(string &astr) {
        uint32_t b = 0;
        for (char ch: astr) {
            if (b & 1 << (ch - 'a'))
                return false;
            b |= 1 << (ch - 'a');
        }
        return true;
    }
};
