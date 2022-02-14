class Solution {
public:
    int singleNonDuplicate(const vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (true) {
            int mid = left + (right - left >> 1);
            int g = get(nums, mid);
            if (g == 0)
                return nums[mid];
            int len = mid - left + (g == -1 ? 1 : 2);
            if (len & 1)
                right = (g == -1 ? mid : mid - 1);
            else
                left = (g == -1 ? mid + 1 : mid);
        }
        return -1;  // never
    }

private:
    static inline int get(const vector<int> &nums, int idx) {
        int left = idx - 1;
        int right = idx + 1;
        if (left >= 0 && nums[left] == nums[idx])
            return -1;
        if (right < nums.size() && nums[right] == nums[idx])
            return 1;
        return 0;
    }
};

