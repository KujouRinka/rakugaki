class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p1 = 0, p2 = nums.size() - 1;
        while (p1 <= p2) {
            int mid = (p1 + p2) / 2;
            if (nums[mid] < target)
                p1 = mid + 1;
            else if (nums[mid] > target)
                p2 = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};
