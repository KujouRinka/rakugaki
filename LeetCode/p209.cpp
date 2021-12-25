class Solution {
public:
    int minSubArrayLen(int target, const vector<int> &nums) {
        int result = 0;
        int sz = nums.size();
        int p_front = 0, p_back = 0;
        int ps = 0;
        while (p_back < sz || ps >= target) {
            if (ps >= target) {
                if (result == 0 || p_back - p_front < result)
                    result = p_back - p_front;
                ps -= nums[p_front++];
            } else {
                if (p_back >= sz)
                    break;
                ps += nums[p_back++];
            }
        }
        return result;
    }
};

