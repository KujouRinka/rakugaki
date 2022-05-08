class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> r;
        auto sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            while (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < sz; ++i) {
            if (nums[i] != i + 1)
                r.push_back(nums[i]);
        }
        return r;
    }
};

