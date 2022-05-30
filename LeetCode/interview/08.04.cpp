class Solution {
public:
    vector<vector<int>> subsets(const vector<int> &nums) {
        _n = nums.size();
        _nums_cp = nums;
        backtracking(0);
        return _result;
    }

private:
    int _n;
    vector<int> _nums_cp;
    vector<int> _current;
    vector<vector<int>> _result;

    void backtracking(int which) {
        if (which >= _n) {
            _result.emplace_back(_current);
            return;
        }
        backtracking(which + 1);
        _current.push_back(_nums_cp[which]);
        backtracking(which + 1);
        _current.pop_back();
    }
};

