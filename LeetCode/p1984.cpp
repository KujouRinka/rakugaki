class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        auto sz = nums.size();
        sort(nums.begin(), nums.end());
        int min_val = 0x7fffffff;
        for (int front = 0, back = k - 1; back < sz; ++front, ++back) {
            if (nums[back] - nums[front] < min_val)
                min_val = nums[back] - nums[front];
        }
        return min_val;
    }
};

