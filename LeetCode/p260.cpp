class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int xor_val = 0;
        for (int i: nums)
            xor_val ^= i;
        xor_val = xor_val == -0x7fffffff - 1 ? xor_val : xor_val & (-xor_val);
        int r1 = 0, r2 = 0;
        for (int i: nums) {
            if (i & xor_val)
                r1 ^= i;
            else
                r2 ^= i;
        }
        return {r1, r2};
    }
};
