class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int sum) {
        m_k = k;
        m_sum = sum;
        backtracking(0, 0, 1);
        return result;
    }

private:
    int m_k;
    int m_sum;
    vector<int> tmp_vec;
    vector<vector<int>> result;

    void backtracking(int n, int sum, int start) {
        if (n == m_k) {
            if (sum == m_sum)
                result.emplace_back(tmp_vec);
            return;
        }
        if (sum > m_sum)
            return;
        for (int i = start; i <= 9; ++i) {
            tmp_vec.push_back(i);
            backtracking(n + 1, sum + i, i + 1);
            tmp_vec.pop_back();
        }
    }
};

