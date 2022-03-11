class Solution {
    using ll = long long;
public:
    int countHighestScoreNodes(const vector<int> &parents) {
        _max_score = 0;
        _max_count = 0;
        _p_sz = parents.size();
        for (int i = 0; i < _p_sz; ++i)
            _m.insert({parents[i], i});
        // dfs
        dfsOfCount(-1);
        return _max_count;
    }

private:
    size_t _p_sz;
    ll _max_score;
    int _max_count;
    unordered_multimap<int, int> _m;

    int dfsOfCount(int node_no) {
        auto[it_begin, it_end] = _m.equal_range(node_no);
        int t[2] = {0};
        int i = 0;
        while (it_begin != it_end)
            t[i++] = dfsOfCount((it_begin++)->second);
        int ret = t[0] + t[1] + 1;
        int left = t[0] == 0 ? 1 : t[0];
        int right = t[1] == 0 ? 1 : t[1];
        int p = _p_sz - ret == 0 ? 1 : _p_sz - ret;
        ll v = static_cast<ll>(left)
               * static_cast<ll>(right)
               * static_cast<ll>(p);
        if (v > _max_score) {
            _max_count = 1;
            _max_score = v;
        } else if (v == _max_score) {
            ++_max_count;
        }
        return ret;
    }
};

