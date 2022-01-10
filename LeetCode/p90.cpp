class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        raw_data = nums;
        len = nums.size();
        used = vector<bool>(len);
        sort(raw_data.begin(), raw_data.end());
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
        result.emplace_back(tmp_vec);
        if (start == len)
            return;
        for (int i = start; i < len; ++i) {
            if (i > 0 && raw_data[i] == raw_data[i - 1] && !used[i - 1])
                continue;
            tmp_vec.push_back(raw_data[i]);
            used[i] = true;
            backtracking(i + 1);
            used[i] = false;
            tmp_vec.pop_back();
        }
    }
};

