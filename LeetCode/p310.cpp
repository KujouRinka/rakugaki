class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1)
            return {0};
        vector<int> degree(n);
        vector<vector<int>> g(n);
        for (auto &v: edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
            ++degree[v[0]];
            ++degree[v[1]];
        }
        queue<int> tq;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1)
                tq.push(i);
        }
        int all = n;
        while (all > 2) {
            for (int i = tq.size(); i > 0; --i) {
                int node = tq.front();
                tq.pop();
                --all;
                for (int conn: g[node]) {
                    if (--degree[conn] == 1)
                        tq.push(conn);
                }
            }
        }
        vector<int> result;
        while (!tq.empty()) {
            result.push_back(tq.front());
            tq.pop();
        }
        return result;
    }
};

