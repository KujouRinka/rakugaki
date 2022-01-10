class Solution {
public:
    vector<vector<int>> permute(const vector<int> &nums) {
        raw_data = nums;
        len = nums.size();
        used = vector<bool>(len);
        backtracking();
        return result;
    }

private:
    int len;
    vector<int> raw_data;
    vector<bool> used;
    vector<int> tmp_vec;
    vector<vector<int>> result;

    void backtracking() {
        if (tmp_vec.size() == len) {
            result.emplace_back(tmp_vec);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (used[i])
                continue;
            tmp_vec.push_back(raw_data[i]);
            used[i] = true;
            backtracking();
            used[i] = false;
            tmp_vec.pop_back();
        }
    }
};

