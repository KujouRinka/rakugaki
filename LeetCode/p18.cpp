class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int k = 0; k < sz; ++k) {
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            for (int i = k + 1; i < sz; ++i) {
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;
                int p_front = i + 1;
                int p_back = sz - 1;
                while (p_front < p_back) {
                    long long t = static_cast<long long>(nums[k]) + static_cast<long long>(nums[i])
                                  + static_cast<long long>(nums[p_front]) + static_cast<long long>(nums[p_back]);
                    if (t > target) {
                        --p_back;
                    } else if (t < target) {
                        ++p_front;
                    } else {
                        result.push_back({nums[k], nums[i], nums[p_front], nums[p_back]});
                        while (p_front < p_back && nums[p_front] == nums[p_front++ + 1]);
                        while (p_front < p_back && nums[p_back] == nums[p_back-- - 1]);
                    }
                }
            }
        }
        return result;
    }
};

