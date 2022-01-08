class Solution {
public:
    vector<vector<int>> combinationSum2(const vector<int> &candidates, int target) {
        len = candidates.size();
        m_target = target;
        used = vector<bool>(len);
        sorted_data = candidates;
        sort(sorted_data.begin(), sorted_data.end());
        backtracking(0, 0);
        return result;
    }

private:
    int len;
    int m_target;
    vector<int> sorted_data;
    vector<int> tmp_vec;
    vector<bool> used;
    vector<vector<int>> result;

    void backtracking(int sum, int start) {
        if (sum == m_target) {
            result.emplace_back(tmp_vec);
            return;
        }
        if (sum > m_target)
            return;
        for (int i = start; i < len; ++i) {
            if (i > 0 && sorted_data[i - 1] == sorted_data[i] && !used[i - 1])
                continue;
            tmp_vec.push_back(sorted_data[i]);
            used[i] = true;
            backtracking(sum + sorted_data[i], i + 1);
            used[i] = false;
            tmp_vec.pop_back();
        }
    }
};

