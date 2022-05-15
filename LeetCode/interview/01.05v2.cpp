class Solution {
public:
    bool oneEditAway(string &first, string &second) {
        auto len1 = first.size(), len2 = second.size();
        if (int a = abs<int>(len1 - len2); a > 1)
            return false;
        else if (a == 1)
            return del(first, second, len1 - len2);
        else
            return rep(first, second);
    }

private:
    bool del(string &first, string &second, int a) {
        const char *p1, *p2;
        int len;
        if (a == -1) {
            p1 = first.c_str();
            p2 = second.c_str();
            len = first.size();
        } else {
            p1 = second.c_str();
            p2 = first.c_str();
            len = second.size();
        }
        int diff = 0;
        const char *end = p1 + len;
        while (p1 < end) {
            if (*p1 != *p2)
                ++diff;
            else
                ++p1;
            if (diff > 1)
                return false;
            ++p2;
        }
        return true;
    }

    bool rep(string &first, string &second) {
        int diff = 0;
        auto len = first.size();
        for (int i = 0; i < len; ++i) {
            if (first[i] != second[i])
                ++diff;
        }
        return diff <= 1;
    }
};
