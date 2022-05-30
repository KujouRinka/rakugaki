class Solution {
public:
    vector<string> permutation(string S) {
        _n = S.size();
        _s_cp = std::move(S);
        _used = vector<bool>(_n, false);
        for (int i = 0; i < _n; ++i) {
            _current.push_back(_s_cp[i]);
            _used[i] = true;
            backtracking(i);
            _used[i] = false;
            _current.pop_back();
        }
        return _result;
    }

private:
    size_t _n;
    string _s_cp;
    string _current;
    vector<string> _result;
    vector<bool> _used;

    void backtracking(int which) {
        if (_current.size() == _n) {
            _result.emplace_back(_current);
            return;
        }
        for (int i = 0; i < _n; ++i) {
            if (_used[i])
                continue;
            _current.push_back(_s_cp[i]);
            _used[i] = true;
            backtracking(i);
            _used[i] = false;
            _current.pop_back();
        }
    }
};

