class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int count = 1;
        int pre_diff = 0;
        int cur_diff = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            cur_diff = nums[i + 1] - nums[i];
            if ((cur_diff > 0 && pre_diff <= 0) || (cur_diff < 0 && pre_diff >= 0)) {
                ++count;
                pre_diff = cur_diff;
            }
        }
        return count;
    }
};

