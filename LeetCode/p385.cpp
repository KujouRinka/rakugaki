/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(const string &s) {
        stack<NestedInteger *> st;
        NestedInteger base;
        st.push(&base);   // add header
        auto *p_first = s.begin().base();
        auto *p_last = s.end().base();
        for (int i = 0; i < s.size();) {
            int i_mov = 0;
            if (s[i] == '[') {
                st.top()->add(NestedInteger());
                st.push(const_cast<NestedInteger *>(&st.top()->getList().back()));
                i_mov = 1;
            } else if (s[i] == ']') {
                st.pop();
                i_mov = 1;
            } else if (s[i] == ',') {
                i_mov = 1;
            } else {
                int value;
                auto idx = from_chars(p_first + i, p_last, value, 10);
                st.top()->add(NestedInteger(value));
                i_mov = idx.ptr - (p_first + i);
            }
            i += i_mov;
        }
        return st.top()->getList()[0];
    }
};

