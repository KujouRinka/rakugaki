class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int who = nums[0];
        int vote = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (who == nums[i])
                ++vote;
            else
                --vote;
            if (vote == 0)
                who = nums[i + 1];
        }
        return who;
    }
};

