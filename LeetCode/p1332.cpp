class Solution {
public:
    int removePalindromeSub(const string &s) {
        int front = 0, back = s.size() - 1;
        while (front < back)
            if (s[front++] != s[back--])
                return 2;
        return 1;
    }
};

