class Solution {
 public:
  int minOperations(vector<int> &nums) {
    int ret = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1])
        continue;
      int nv = nums[i - 1] + 1;
      ret += nv - nums[i];
      nums[i] = nv;
    }
    return ret;
  }
};

