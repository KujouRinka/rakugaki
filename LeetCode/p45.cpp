class Solution {
public:
    int jump(const vector<int> &nums) {
        auto sz = nums.size();
        if (sz <= 1)
            return 0;
        int this_cover = 0;
        int times = 0;
        for (int i = 0;; ++times) {
            int next_cover = this_cover;
            if (next_cover >= sz - 1)
                return times;
            for (int j = i; j <= this_cover; ++j) {
                next_cover = max(j + nums[j], next_cover);
            }
            i = this_cover + 1;
            this_cover = next_cover;
        }
        return -1;  // never
    }
};

