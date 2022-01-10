class Solution {
public:
    bool isAdditiveNumber(const string &num) {
        m_num = num;
        m_sz = num.size();
        return dfs(0);
    }

private:
    int m_sz;
    string m_num;
    vector<vector<int>> lst;

    bool dfs(int u) {
        int lst_sz = lst.size();
        if (u == m_sz)
            return lst_sz >= 3;
        int max = m_num[u] == '0' ? u + 1 : m_sz;
        vector<int> current;
        for (int i = u; i < max; ++i) {
            current.insert(current.begin(), m_num[i] - '0');
            if (lst_sz < 2 || highPrecCheck(lst[lst_sz - 2], lst[lst_sz - 1], current)) {
                lst.push_back(current);
                if (dfs(i + 1))
                    return true;
                lst.pop_back();
            }
        }
        return false;
    }

    bool highPrecCheck(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> ans;
        int t = 0;
        for (int i = 0; i < a.size() || i < b.size(); ++i) {
            if (i < a.size())
                t += a[i];
            if (i < b.size())
                t += b[i];
            ans.push_back(t % 10);
            t /= 10;
        }
        if (t)
            ans.push_back(1);
        bool ok = (c.size() == ans.size());
        for (int i = 0; i < c.size() && ok; ++i) {
            if (c[i] != ans[i])
                ok = false;
        }
        return ok;
    }
};

