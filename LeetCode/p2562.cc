class Solution {
 public:
  long long findTheArrayConcVal(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    long long ret = 0;
    while (l <= r) {
      if (l != r) {
        ret += stoll(to_string(nums[l]) + to_string(nums[r]));
      } else {
        ret += nums[l];
      }
      ++l;
      --r;
    }
    return ret;
  }
};

