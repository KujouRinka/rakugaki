class Solution {
 public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    int left = 1, right = *max_element(nums.begin(), nums.end()) + 1;
    int ret = 0;
    while (left < right) {
      int mid = (left + right) >> 1;
      long long oper = 0;
      for (int i : nums)
        oper += (i - 1) / mid;
      if (oper <= maxOperations) {
        ret = mid;
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return ret;
  }
};

