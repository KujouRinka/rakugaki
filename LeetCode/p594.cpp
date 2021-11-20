class Solution {
public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> m;
        for (int i: nums)
            ++m[i];
        int max_val = 0;
        for (auto [key, value]: m) {
            if (m.count(key + 1))
                max_val = max(max_val, value + m[key + 1]);
        }
        return max_val;
    }
};
