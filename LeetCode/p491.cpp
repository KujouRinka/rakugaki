class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        raw_data = nums;
        len = nums.size();
        used = vector<bool>(len);
        backtracking(0);
        return result;
    }

private:
    int len;
    vector<int> raw_data;
    vector<bool> used;
    vector<int> tmp_vec;
    vector<vector<int>> result;

    void backtracking(int start) {
        if (tmp_vec.size() >= 2)
            result.emplace_back(tmp_vec);
        if (start == len)
            return;
        unordered_set<int> appeared;
        for (int i = start; i < len; ++i) {
            if (appeared.count(raw_data[i]))
                continue;
            if (!tmp_vec.empty() && raw_data[i] < tmp_vec.back())
                continue;
            appeared.insert(raw_data[i]);
            tmp_vec.push_back(raw_data[i]);
            used[i] = true;
            backtracking(i + 1);
            used[i] = false;
            tmp_vec.pop_back();
        }
    }
};

