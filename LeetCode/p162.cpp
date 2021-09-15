class Solution {
public:
    int findPeakElement(const vector<int> &nums) {
        auto sz = nums.size();
        auto get = [&sz, &nums](int index) -> int64_t {
            return index < 0 || index >= sz ? -0x7fffffffffLL : nums[index];
        };

        int left = 0, right = sz - 1;
        while (left <= right) {
            int mid = (left + right) / 2, ele = nums[mid];
            int l = mid - 1, r = mid + 1;
            if (get(l) < ele && get(r) < ele)
                return mid;
            else if (get(l) < ele && ele < get(r))
                left = r;
            else
                right = l;
        }
        return -1;
    }
};
