class Solution {
public:
    vector<string> permutation(string S) {
        _n = S.size();
        _s_cp = std::move(S);
        sort(_s_cp.begin(), _s_cp.end());
        _used = vector<bool>(_n, false);
        backtracking();
        return _result;
    }

private:
    size_t _n;
    string _current;
    string _s_cp;
    vector<string> _result;
    vector<bool> _used;

    void backtracking() {
        if (_current.size() == _n) {
            _result.push_back(_current);
            return;
        }
        for (int i = 0; i < _n; ++i) {
            if (_used[i] || (i > 0 && _s_cp[i] == _s_cp[i - 1] && !_used[i - 1]))
                continue;
            _current.push_back(_s_cp[i]);
            _used[i] = true;
            backtracking();
            _current.pop_back();
            _used[i] = false;
        }
    }
};

