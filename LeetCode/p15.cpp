class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        set<vector<int>> s;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] > 0)
                break;
            int p_front = i + 1;
            int p_back = sz - 1;
            while (p_front < p_back) {
                int t = nums[i] + nums[p_front] + nums[p_back];
                if (t > 0) {
                    --p_back;
                } else if (t < 0) {
                    ++p_front;
                } else {
                    s.insert({nums[i], nums[p_front], nums[p_back]});
                    ++p_front;
                }
            }
        }
        return {s.begin(), s.end()};
    }
};

