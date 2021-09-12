class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftBracket;
        stack<int> star;
        auto sz = s.size();
        for (int i = 0; i < sz; ++i) {
            switch (s[i]) {
                case '(':
                    leftBracket.push(i);
                    break;
                case '*':
                    star.push(i);
                    break;
                case ')':
                    if (!leftBracket.empty())
                        leftBracket.pop();
                    else if (!star.empty())
                        star.pop();     // regard star as left bracket
                    else
                        return false;
                    break;
                default:
                    break;
            }
        }
        while (!star.empty() && !leftBracket.empty()) {
            if (star.top() > leftBracket.top()) {
                star.pop();
                leftBracket.pop();
            } else
                return false;
        }
        return leftBracket.empty();
    }
};
