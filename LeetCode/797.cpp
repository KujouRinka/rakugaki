class Solution {
    int maxInd;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> tp;
        maxInd = graph.size() - 1;
        dfs(graph, result, 0, tp);
        return result;
    }

    void dfs(vector<vector<int>> &g, vector<vector<int>> &result, int ref, vector<int> &tp) {
        tp.push_back(ref);
        if (ref == maxInd) {
            result.emplace_back(tp);
            tp.pop_back();
            return;
        }

        for (auto &i : g[ref])
            dfs(g, result, i, tp);
        tp.pop_back();
    }
};
