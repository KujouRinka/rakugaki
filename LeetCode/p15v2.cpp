class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        set<vector<int>> s;
        vector<vector<int>> result;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int p_front = i + 1;
            int p_back = sz - 1;
            while (p_front < p_back) {
                int t = nums[i] + nums[p_front] + nums[p_back];
                if (t > 0) {
                    --p_back;
                } else if (t < 0) {
                    ++p_front;
                } else {
                    result.push_back({nums[i], nums[p_front], nums[p_back]});
                    while (p_front < p_back && nums[p_front] == nums[p_front++ + 1]);
                    while (p_front < p_back && nums[p_back] == nums[p_back-- - 1]);
                }
            }
        }
        return result;
    }
};

