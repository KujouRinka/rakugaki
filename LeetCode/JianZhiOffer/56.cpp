class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xor_v = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            xor_v ^= nums[i];
        int lowbit = xor_v & -xor_v;
        vector<int> result(2);
        for (int i: nums)
            result[(i & lowbit) ? 1 : 0] ^= i;
        result[0] ^= 0;
        result[1] ^= 0;
        return result;
    }
};

