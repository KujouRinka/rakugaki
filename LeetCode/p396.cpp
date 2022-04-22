class Solution {
public:
    int maxRotateFunction(vector<int> &nums) {
        int vec_sum = 0;
        int max_value = 0;
        auto sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            vec_sum += nums[i];
            max_value += nums[i] * i;
        }
        int current = max_value;
        for (int i = 1; i < sz; ++i) {
            current = current - vec_sum + sz * nums[(i + sz - 1) % sz];
            max_value = max(max_value, current);
        }
        return max_value;
    }
};

