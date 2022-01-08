class Solution {
public:
    vector<vector<int>> combinationSum(const vector<int> &candidates, int target) {
        len = candidates.size();
        raw_data = candidates;
        m_target = target;
        tmp_vec.reserve(len);
        backtracking(0, 0);
        return result;
    }

private:
    int len;
    int m_target;
    vector<int> tmp_vec;
    vector<int> raw_data;
    vector<vector<int>> result;

    void backtracking(int sum, int start) {
        if (sum == m_target) {
            result.emplace_back(tmp_vec);
            return;
        }
        if (sum > m_target)
            return;
        for (int i = start; i < len; ++i) {
            tmp_vec.push_back(raw_data[i]);
            backtracking(sum + raw_data[i], i);
            tmp_vec.pop_back();
        }
    }
};

