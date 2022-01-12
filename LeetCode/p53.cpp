class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ms = 0;
        int max_sum = INT32_MIN;
        for (int i: nums) {
            if (ms < 0)
                ms = 0;
            ms += i;
            max_sum = max(max_sum, ms);
        }
        return max_sum;
    }
};

