class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz; ) {
            if (i == nums[i]) {
                ++i;
                continue;
            }
            if (nums[i] == nums[nums[i]])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};
