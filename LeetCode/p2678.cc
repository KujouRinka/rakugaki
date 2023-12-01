class Solution {
public:
    int countSeniors(vector<string>& details) {
        return accumulate(details.begin(), details.end(), 0, [this](auto acc, auto &s) {
            return acc + each_renrei(s);
        });
    }

    int each_renrei(const string &s) {
        return ((s[11] - '0') * 10 + s[12] - '0' > 60) ? 1 : 0;
    }
};

