class Solution {
public:
    int findPairs(const vector<int> &nums, int k) {
        int result = 0;
        unordered_map<int, int> m;
        for_each(nums.begin(), nums.end(), [&m](int i) {
            ++m[i];
        });
        for (int i: nums) {
            if (m[i] == 0)
                continue;
            if (k == 0) {
                result += m[i] > 1 ? 1 : 0;
            } else {
                if (m[i - k] > 0)
                    ++result;
                if (m[i + k] > 0)
                    ++result;
            }
            m[i] = 0;
        }
        return result;
    }
};

