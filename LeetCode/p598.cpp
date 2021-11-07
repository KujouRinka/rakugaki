class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        int max_m_bound = m, max_n_bound = n;
        for (auto &v: ops) {
            max_m_bound = min(max_m_bound, v[0]);
            max_n_bound = min(max_n_bound, v[1]);
        }
        return max_m_bound * max_n_bound;
    }
};
