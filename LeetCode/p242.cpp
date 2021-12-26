class Solution {
public:
    bool isAnagram(const string &s, const string &t) {
        if (s.size() != t.size())
            return false;
        int record[26] = {0};
        for (char ch: s)
            ++record[chToRelInt(ch)];
        for (char ch: t) {
            if (--record[chToRelInt(ch)] < 0)
                return false;
        }
        return true;
    }

private:
    static inline int chToRelInt(char ch) {
        return ch - 'a';
    }
};

