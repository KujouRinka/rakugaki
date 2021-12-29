class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int result = 0;
        stack<int> st;
        int sz = tokens.size();
        for (auto &s: tokens) {
            if (!(s == "+" || s == "-" || s == "*" || s == "/")) {
                st.push(stoi(s));
            } else {
                int rhs = st.top();
                st.pop();
                int lhs = st.top();
                st.pop();
                switch (s[0]) {
                    case '+':
                        st.push(lhs + rhs);
                        break;
                    case '-':
                        st.push(lhs - rhs);
                        break;
                    case '*':
                        st.push(lhs * rhs);
                        break;
                    case '/':
                        st.push(lhs / rhs);
                        break;
                    default:
                        break;
                }
            }
        }
        return st.top();
    }
};

