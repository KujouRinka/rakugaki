class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        unordered_map<string, string> g;
        for (auto &i: paths)
            g[i[0]] = i[1];
        string now = paths[0][0];
        while (g.count(now))
            now = g[now];
        return {now};
    }
};
