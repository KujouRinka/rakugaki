class Solution {
public:
    int missingNumber(const vector<int> &nums) {
        int x = 0, sz = nums.size();
        for (int i = 0; i < sz; ++i)
            x ^= nums[i] ^ i;
        return x ^ sz;
    }
};
