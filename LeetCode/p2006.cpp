class Solution {
public:
    int countKDifference(vector<int> &nums, int k) {
        int cnts[101] = {0};
        int sz = nums.size(), result = 0;
        for (int i = 0; i < sz; i++) {
            int t = nums[i];
            if (t - k >= 1) result += cnts[t - k];
            if (t + k <= 100) result += cnts[t + k];
            cnts[t]++;
        }
        return result;
    }
};

