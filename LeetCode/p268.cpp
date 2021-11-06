class Solution {
public:
    int missingNumber(const vector<int> &nums) {
        int sz = nums.size();
        return sz * (sz + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
