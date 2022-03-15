class Solution {
public:
    int countMaxOrSubsets(const vector<int> &nums) {
        int target = 0;
        for (int num: nums)
            target |= num;
        auto sz = nums.size();
        int end = 1 << sz;
        int r = 0;
        for (int i = 0; i < end; ++i) {
            int stat = 0;
            for (int j = 0; j < sz; ++j) {
                if (i & (1 << j))
                    stat |= nums[j];
            }
            if (stat == target)
                ++r;
        }
        return r;
    }
};

