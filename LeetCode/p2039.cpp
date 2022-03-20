class Solution {
public:
    int networkBecomesIdle(const vector<vector<int>> &edges, const vector<int> &patience) {
        auto sz = patience.size();
        _g.resize(sz);
        _dist.resize(sz);
        _visited = vector<bool>(sz);
        for (auto &p: edges)
            addEdge(p[0], p[1]);
        bfs();
        int free_time = 0;
        for (int i = 1; i < sz; ++i) {
            int datagram = _dist[i] * 2 / patience[i] + (_dist[i] * 2 % patience[i] ? 1 : 0);
            free_time = max(free_time, (datagram - 1) * patience[i] + _dist[i] * 2 + 1);
        }
        return free_time;
    }

private:
    vector<vector<int>> _g;
    vector<int> _dist;
    vector<bool> _visited;

    void bfs() {
        queue<int> q;
        q.push(0);
        int cur_dist = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                int v = q.front();
                q.pop();
                if (_visited[v])
                    continue;
                _dist[v] = cur_dist;
                for (int next: _g[v])
                    q.push(next);
                _visited[v] = true;
            }
            ++cur_dist;
        }
    }

    inline void addEdge(int u, int v) {
        _g[u].push_back(v);
        _g[v].push_back(u);
    }
};

