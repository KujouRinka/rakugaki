class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        queen_quan = n;
        backtracking(0);
        return result;
    }

private:
    int queen_quan;
    vector<string> tmp_ans;
    vector<vector<string>> result;

    void backtracking(int which) {
        if (which == queen_quan) {
            result.emplace_back(tmp_ans);
            return;
        }
        string one_line(queen_quan, '.');
        for (int pos = 0; pos < queen_quan; ++pos) {
            if (pos > 0)
                one_line[pos - 1] = '.';
            one_line[pos] = 'Q';
            if (!check(which, pos))
                continue;
            tmp_ans.emplace_back(one_line);
            backtracking(which + 1);
            tmp_ans.pop_back();
        }
    }

    bool check(int which, int pos) {
        for (int i = which - 1; i >= 0; --i) {
            if (tmp_ans[i][pos] == 'Q')
                return false;
        }
        for (int delta = 1; delta <= which; ++delta) {
            int xl = pos - delta;
            int xr = pos + delta;
            int y = which - delta;
            if (isValid(xl, y) && tmp_ans[y][xl] == 'Q')
                return false;
            if (isValid(xr, y) && tmp_ans[y][xr] == 'Q')
                return false;
        }
        return true;
    }

    inline bool isValid(int x, int y) {
        return x >= 0 && x < queen_quan && y >= 0 && y < queen_quan;
    }
};

