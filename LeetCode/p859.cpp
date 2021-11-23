class Solution {
public:
    bool buddyStrings(const string &s, const string &goal) {
        int sz_s = s.size(), sz_goal = goal.size();
        if (sz_s != sz_goal)
            return false;
        int count1[26] = {0};
        int count2[26] = {0};
        int diff = 0;
        for (int i = 0; i < sz_s; ++i) {
            ++count1[s[i] - 'a'];
            ++count2[goal[i] - 'a'];
            if (s[i] != goal[i])
                ++diff;
        }
        bool f = false;
        for (int i = 0; i < 26; ++i) {
            if (count1[i] != count2[i])
                return false;
            if (count1[i] >= 2)
                f = true;
        }
        return diff == 2 || (diff == 0 && f);
    }
};
