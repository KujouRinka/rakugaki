class Solution {
public:
    string replaceSpace(string s) {
        int spaceNums = 0;
        auto strSize = s.size();
        for (auto &ch : s)
            if (ch == ' ')
                spaceNums++;

        s.resize(strSize + spaceNums * 2);
        for (auto rawRit = (string::reverse_iterator)(s.begin() + strSize),
                     newRit = s.rbegin(); rawRit != s.rend(); ++rawRit) {
            if (*rawRit == ' ') {
                *newRit++ = '0';
                *newRit++ = '2';
                *newRit++ = '%';
            } else {
                *newRit++ = *rawRit;
            }
        }
        return s;
    }
};
