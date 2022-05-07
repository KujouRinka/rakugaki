class Solution {
public:
    int minMutation(const string &start, const string &end, vector<string> bank) {
        unordered_map<string, unordered_set<string>> g;
        bank.push_back(start);
        for (int i = 0; i < bank.size(); ++i) {
            for (int j = 0; j < bank.size(); ++j) {
                if (j == i)
                    continue;
                if (helper(bank[i], bank[j])) {
                    g[bank[i]].insert(bank[j]);
                }
            }
        }
        queue<string> q;
        q.push(start);
        int step = 0;
        while (!q.empty()) {
            ++step;
            for (int i = q.size(); i > 0; --i) {
                string ts = q.front();
                q.pop();
                for (auto &s: g[ts]) {
                    if (s == end)
                        return step;
                    q.push(s);
                }
                g[ts].clear();
            }
        }
        return -1;
    }

private:
    bool helper(string &s1, string &s2) {
        if (s1.size() != s2.size())
            return false;
        int c = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i])
                ++c;
        }
        return c == 1;
    }
};

