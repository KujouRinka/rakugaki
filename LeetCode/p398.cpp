class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            _m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        return _m[target][rand() % _m[target].size()];
    }

private:
    unordered_map<int, vector<int>> _m;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

