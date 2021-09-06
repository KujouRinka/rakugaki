class Solution {
public:
    static int balancedStringSplit(const string &s) {
        int LNum = 0, RNum = 0;
        int count = 0;
        for (auto i : s) {
            if (i == 'L')
                ++LNum;
            else if (i == 'R')
                ++RNum;
            if (LNum == RNum) {
                ++count;
                LNum = RNum = 0;
            }
        }
        return count;
    }
};
