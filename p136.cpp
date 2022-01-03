class Solution {
public:
    int singleNumber(const vector<int> &nums) {
        int xor_val = 0;
        for (int i: nums)
            xor_val ^= i;
        return xor_val;
    }
};

