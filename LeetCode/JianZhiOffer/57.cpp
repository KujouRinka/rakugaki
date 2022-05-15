class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int front = 0, back = nums.size() - 1;
        while (front < back) {
            int sum = nums[front] + nums[back];
            if (sum < target)
                ++front;
            else if (sum > target)
                --back;
            else
                return {nums[front], nums[back]};
        }
        return {}; // never
    }
};
