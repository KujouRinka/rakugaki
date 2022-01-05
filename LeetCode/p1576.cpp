class Solution {
public:
    string modifyString(string &s) {
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            if (s[i] == '?') {
                char front = (i == 0 ? '!' : s[i - 1]);
                char back = (i == sz - 1 ? '!' : s[i + 1]);
                s[i] = selectCh(front, back);
            }
        }
        return s;
    }

private:
    static char selectCh(char front, char back) {
        for (char c = 'a'; c <= 'c'; ++c)
            if (c != front && c != back)
                return c;
        return '!';
    }
};

