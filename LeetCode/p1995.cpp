class Solution {
public:
    int countQuadruplets(vector<int> &nums) {
        int sz = nums.size();
        unordered_map<int, int> m;

        int result = 0;
        for (int b = sz - 3; b >= 0; --b) {
            for (int c = b + 1, d = b + 2; d < sz; ++d)
                ++m[nums[d] - nums[c]];
            for (int a = 0; a < b; ++a)
                result += m[nums[a] + nums[b]];
        }
        return result;
    }
};

