class Solution {
public:
    int countSegments(string &s) {
        state = SPACECANT;
        int cnt = 0;
        for (char ch: s) {
            go(ch);
            if (state == ADD)
                ++cnt;
        }
        return cnt;
    }

private:
    int state;
    enum STATE {ADD, WORDCANT, SPACECANT};
    vector<vector<int>> state_map = {
            {WORDCANT, SPACECANT},
            {WORDCANT, SPACECANT},
            {ADD, SPACECANT},
    };

    void go(char ch) {
        state = state_map[state][ch == ' ' ? 1 : 0];
    }
};
