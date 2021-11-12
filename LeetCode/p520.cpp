enum S {
    WAIT = 0, FU, FL, WU, WL, BAD,
};

class Solution2 {
    inline static bool isUpper(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }

public:
    bool detectCapitalUse(string &word) {
        S s = WAIT;
        bool f = true;
        for (char ch: word) {
            switch (s) {
                case WAIT:
                    s = isUpper(ch) ? FU : FL;
                    break;
                case FU:
                    s = isUpper(ch) ? WU : WL;
                    break;
                case FL:
                    s = isUpper(ch) ? BAD : WL;
                    break;
                case WU:
                    s = isUpper(ch) ? WU : BAD;
                    break;
                case WL:
                    s = isUpper(ch) ? BAD : WL;
                    break;
                case BAD:
                default:
                    f = false;
            }
            if (!f)
                break;
        }
        return s != BAD;
    }
};
