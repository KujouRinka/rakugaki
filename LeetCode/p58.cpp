enum STATUS {
    NO, YES, FINISH,
};

class stringStatus {
public:
    stringStatus()
            : status(NO), pointerNext(0) {}

    explicit stringStatus(const string &s)
            : status(NO), raw(s), pointerNext(s.size() - 1) {}

    STATUS headOn() {
        if (pointerNext < 0)
            status = FINISH;
        if (status == FINISH)
            return FINISH;
        char ch = raw[pointerNext--];
        status = statusTable[status][ch == ' ' ? 0 : 1];
        return status;
    }

private:
    STATUS status;
    string raw;
    int pointerNext;
    vector<vector<STATUS>> statusTable{
            {NO,     YES},
            {FINISH, YES},
    };
};

class Solution {
public:
    int lengthOfLastWord(const string &s) {
        int cnt = 0;
        stringStatus st(s);
        while (st.headOn() == NO);
        do {
            ++cnt;
        } while (st.headOn() == YES);
        return cnt;
    }
};
