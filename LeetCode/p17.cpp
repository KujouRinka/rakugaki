const string key_map[] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
};

class Solution {
public:
    vector<string> letterCombinations(const string &digits) {
        len = digits.size();
        if (len == 0)
            return {};
        m_digits = digits;
        backtracking(0);
        return result;
    }

private:
    string s_r;
    vector<string> result;
    string m_digits;
    int len;

    void backtracking(int idx) {
        if (idx == len) {
            result.emplace_back(s_r);
            return;
        }
        for (char ch: key_map[m_digits[idx] - '0']) {
            s_r.push_back(ch);
            backtracking(idx + 1);
            s_r.pop_back();
        }
    }
};

