class Solution {
private:
    unordered_set<string> m_result_set;
    string m_raw_s;
    int m_max_len;
    int m_max_score;

public:
    vector<string> removeInvalidParentheses(string &s) {
        m_raw_s = std::move(s);
        string ts;
        ts.reserve(100);

        int del_l = 0, del_r = 0;
        int l = 0, r = 0;
        for (char ch: m_raw_s) {
            if (ch == '(')
                ++l;
            if (ch == ')')
                ++r;

            if (ch == '(') {
                ++del_l;
            } else if (ch == ')') {
                if (del_l)
                    --del_l;
                else
                    ++del_r;
            }
        }
        m_max_score = min(l, r);
        m_max_len = m_raw_s.size() - del_l - del_r;

        dfs(0, ts, 0, del_l, del_r);
        return {m_result_set.begin(), m_result_set.end()};
    }

private:
    void dfs(int score, string &s, int cur_ind, int del_l, int del_r) {
        if (del_l < 0 || del_r < 0 || score < 0 || score > m_max_score)
            return;
        if (cur_ind == m_raw_s.size()) {
            if (score == 0 && s.size() == m_max_len)
                m_result_set.insert(s);
            return;
        }

        switch (m_raw_s[cur_ind]) {
            case '(':
                s.push_back('(');
                dfs(score + 1, s, cur_ind + 1, del_l, del_r);
                s.pop_back();
                dfs(score, s, cur_ind + 1, del_l - 1, del_r);
                break;
            case ')':
                s.push_back(')');
                dfs(score - 1, s, cur_ind + 1, del_l, del_r);
                s.pop_back();
                dfs(score, s, cur_ind + 1, del_l, del_r - 1);
                break;
            default:
                s.push_back(m_raw_s[cur_ind]);
                dfs(score, s, cur_ind + 1, del_l, del_r);
                s.pop_back();
        }
    }
};
