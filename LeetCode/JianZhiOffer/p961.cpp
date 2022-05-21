class Solution {
public:
    int repeatedNTimes(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if ((i >= 1 && nums[i - 1] == nums[i]) ||
                (i >= 2 && nums[i - 2] == nums[i]) ||
                (i >= 3 && nums[i - 3] == nums[i]))
                return nums[i];
        }
        return -1;  // never
    }
};

