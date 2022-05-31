class Solution {
public:
    vector<string> generateParenthesis(int n) {
        _n = n;
        _left_par = 0;
        _right_par = 0;
        backtracking(_n);
        return _result;
    }

private:
    int _n;
    int _left_par;
    int _right_par;
    string _current;
    vector<string> _result;

    void backtracking(int leave) {
        if (leave == 0) {
            _result.push_back(_current);
            return;
        }
        if (_left_par < _n) {
            _current.push_back('(');
            ++_left_par;
            backtracking(leave);
            --_left_par;
            _current.pop_back();
        }
        if (_right_par < _left_par) {
            _current.push_back(')');
            ++_right_par;
            backtracking(leave - 1);
            --_right_par;
            _current.pop_back();
        }
    }
};

