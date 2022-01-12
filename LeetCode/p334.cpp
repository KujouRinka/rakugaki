class Solution {
public:
    bool increasingTriplet(const vector<int> &nums) {
        int first = nums[0];
        int second = 0x7fffffff;
        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            if (*it > second)
                return true;
            else if (*it > first)
                second = *it;
            else
                first = *it;
        }
        return false;
    }
};

