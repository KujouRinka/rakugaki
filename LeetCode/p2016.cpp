class Solution {
public:
    int maximumDifference(const vector<int>& nums) {
        int f_min = 0x7fffffff;
        int r = -1;
        for (int i: nums) {
            if (i - f_min > 0)
                r = max(r, i - f_min);
            f_min = min(f_min, i);
        }
        return r;
    }
};

