class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int idx = nums.size() - 1;
        int first = nums[idx];
        int second = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > first) {
                second = first;
                first = nums[i];
                idx = i;
            } else if (nums[i] > second) {
                second = nums[i];
            }
        }
        return first >= second * 2 ? idx : -1;
    }
};

