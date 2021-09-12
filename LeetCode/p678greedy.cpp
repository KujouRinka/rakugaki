class Solution {
public:
    bool checkValidString(string s) {
        int unmatchedLeftMin = 0, unmatchedLeftMax = 0;
        for (char ch : s) {
            switch (ch) {
                case '(':
                    ++unmatchedLeftMin;
                    ++unmatchedLeftMax;
                    break;
                case '*':
                    --unmatchedLeftMin;
                    ++unmatchedLeftMax;
                    break;
                case ')':
                    --unmatchedLeftMin;
                    --unmatchedLeftMax;
                    break;
                default:
                    break;
            }
            if (unmatchedLeftMax < 0)
                return false;
            if (unmatchedLeftMin < 0)
                unmatchedLeftMin = 0;
        }
        return unmatchedLeftMin == 0;
    }
};
