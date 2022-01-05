class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        m_n = n;
        m_k = k;
        vector<int> tmp;

        backtracking(tmp, 0);
        return result;
    }

private:
    vector<vector<int>> result;
    int m_n;
    int m_k;

    void backtracking(vector<int> &tmp, int tracking_val) {
        if (tmp.size() == m_k) {
            result.push_back(tmp);
            return;
        }

        for (int i = tracking_val + 1; i <= m_n; ++i) {
            tmp.push_back(i);
            backtracking(tmp, i);
            tmp.pop_back();
        }
    }
};

