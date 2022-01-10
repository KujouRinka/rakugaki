class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        int sz = nums.size();
        int max_bit = 1 << sz;
        vector<vector<int>> result;
        vector<int> tmp_vec;
        tmp_vec.reserve(sz);
        for (int i = 0; i < max_bit; ++i) {
            tmp_vec.clear();
            for (int j = 0; j < sz; ++j) {
                if (i & (1 << j))
                    tmp_vec.push_back(nums[j]);
            }
            result.emplace_back(tmp_vec);
        }

        return result;
    }
};

