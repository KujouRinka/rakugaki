class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> window;
        auto sz = nums.size();
        for (int i = 0; i < k + 1 && i < sz; ++i) {
            if (window.contains(nums[i]))
                return true;
            window.insert(nums[i]);
        }
        int head = 0, next = k + 1;
        while (next < sz) {
            window.erase(nums[head++]);
            if (window.contains(nums[next]))
                return true;
            window.insert(nums[next++]);
        }
        return false;
    }
};

