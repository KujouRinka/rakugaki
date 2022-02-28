class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        sz = requests.size();
        m_req = requests;
        is_select = vector<bool>(sz, false);
        check_vec = vector<int>(n, 0);
        backtracking(0, 0);
        return r;
    }

private:
    int sz;
    vector<vector<int>> m_req;
    vector<bool> is_select;
    vector<int> check_vec;
    int r = 0;

    void backtracking(int which, int cnt) {
        if (which == sz) {
            if (check()) 
                r = max(r, cnt);
            return;
        }
        is_select[which] = true;
        backtracking(which + 1, cnt + 1);
        is_select[which] = false;
        backtracking(which + 1, cnt);
    }

    bool check() {
        fill(check_vec.begin(), check_vec.end(), 0);
        for (int i = 0; i < sz; ++i) {
            if (is_select[i]) {
                --check_vec[m_req[i][0]];
                ++check_vec[m_req[i][1]];
            }
        }
        for (int i: check_vec) {
            if (i != 0)
                return false;
        }
        return true;
    }
};

