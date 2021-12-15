class Solution {
public:
    vector<int> loudAndRich(const vector<vector<int>> &richer, const vector<int> &quiet) {
        auto sz = quiet.size();
        result = vector<int>(sz, -1);
        vector<vector<int>> g(sz);
        vector<int> in(sz);
        for (auto &v: richer) {
            g[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        for (int i = 0; i < sz; ++i) {
            if (in[i] == 0)
                dfs(g, quiet, i);
        }

        return result;
    }

private:
    vector<int> result;

    int dfs(const vector<vector<int>> &g, const vector<int> &quiet, int this_node) {
        if (g[this_node].empty()) {
            result[this_node] = this_node;
            return this_node;
        }

        int min_person_idx = g[this_node][0];
        for (auto i: g[this_node]) {
            int next_min_idx;
            if (result[i] == -1)
                next_min_idx = dfs(g, quiet, i);
            else
                next_min_idx = result[i];
            if (quiet[next_min_idx] < quiet[min_person_idx]) {
                min_person_idx = next_min_idx;
            }
        }

        int ret;
        ret = result[this_node] = (quiet[min_person_idx] < quiet[this_node]) ? min_person_idx : this_node;
        return ret;
    }
};

