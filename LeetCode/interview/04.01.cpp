class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target) {
        end = target;
        for (auto &v: graph)
            g[v[0]].insert(v[1]);
        return dfs(start);
    }

private:
    bool dfs(int start) {
        if (start == end)
            return true;

        for (auto next_val: g[start]) {
            if (visited.count({start, next_val}))
                continue;
            visited[{start, next_val}] = true;
            if (dfs(next_val))
                return true;
        }
        return false;
    }

    unordered_map<int, unordered_set<int>> g;
    map<pair<int, int>, bool> visited;
    int end;
};
