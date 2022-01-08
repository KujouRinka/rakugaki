class Solution {
public:
    vector<vector<string>> partition(const string &s) {
        len = s.size();
        raw_s = s;
        backtracking(0);
        return result;
    }

private:
    int len;
    string raw_s;
    vector<string> t_result;
    vector<vector<string>> result;

    void backtracking(int start) {
        if (start == len) {
            result.emplace_back(t_result);
            return;
        }
        string ts;
        ts.reserve(len / 5);
        for (int i = start; i < len; ++i) {
            ts.push_back(raw_s[i]);
            if (!isPalindrome(ts))
                continue;
            t_result.push_back(ts);
            backtracking(i + 1);
            t_result.pop_back();
        }
    }

    bool isPalindrome(const string &s) {
        int start_idx = 0, end_idx = s.size() - 1;
        while (start_idx < end_idx) {
            if (s[start_idx++] != s[end_idx--])
                return false;
        }
        return true;
    }
};

