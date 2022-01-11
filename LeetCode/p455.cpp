class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child_idx = 0;
        for (int cookie_idx = 0; cookie_idx < s.size(); ++cookie_idx) {
            if (child_idx == g.size())
                break;
            if (s[cookie_idx] >= g[child_idx])
                ++child_idx;
        }
        return child_idx;
    }
};

