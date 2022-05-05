class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int left = 0, right = 0;
        auto sz = nums.size();
        int cur_mul = 1;
        int result = 0;
        while (right < sz) {
            cur_mul *= nums[right++];
            while (left < right && cur_mul >= k)
                cur_mul /= nums[left++];
            result += right - left;
        }
        return result;
    }
};

