class Solution {
public:
    bool canJump(const vector<int> &nums) {
        int black = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] - black <= 0) {
                if (i == 0)
                    return false;
                ++black;
            } else {
                black = 0;
            }
        }
        return true;
    }
};

