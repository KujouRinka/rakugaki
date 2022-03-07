class Solution {
public:
    vector<vector<int>> getAncestors(int n, const vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        vector<int> inner(n, 0);
        vector<set<int>> result_map(n);
        queue<int> ne_q;
        for (auto &edge: edges) {
            g[edge[0]].push_back(edge[1]);
            ++inner[edge[1]];
        }
        for (int i = 0; i < n; ++i) {
            if (inner[i] == 0)
                ne_q.push(i);
        }
        while (!ne_q.empty()) {
            int in = ne_q.front();
            ne_q.pop();
            for (int out: g[in]) {
                result_map[out].insert(result_map[in].begin(), result_map[in].end());
                result_map[out].insert(in);
                if (--inner[out] == 0)
                    ne_q.push(out);
            }
        }

        vector<vector<int>> result;
        result.reserve(n);
        for (auto &rm: result_map)
            result.emplace_back(rm.begin(), rm.end());

        return result;
    }
};

