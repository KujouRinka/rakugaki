class Solution {
public:
    vector<int> diStringMatch(string &s) {
        vector<int> r;
        int up, down;
        if (s[0] == 'I') {
            r.push_back(0);
            up = s.size();
            down = 1;
        } else {
            r.push_back(s.size());
            up = s.size() - 1;
            down = 0;
        }
        for (int i = 1; i < s.size(); ++i) {
            r.push_back(s[i] == 'I' ? down++ : up--);
        }
        r.push_back(down);
        return r;
    }
};

