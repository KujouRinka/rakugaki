class Solution {
    using ll = long long;

public:
    long long subArrayRanges(const vector<int> &nums) {
        ll r = 0;
        auto sz = nums.size();
        for (int begin = 0; begin < sz; ++begin) {
            int in_max = nums[begin], in_min = nums[begin];
            for (int end = begin + 1; end < sz; ++end) {
                in_max = max(in_max, nums[end]);
                in_min = min(in_min, nums[end]);
                r += in_max - in_min;
            }
        }
        return r;
    }
};

