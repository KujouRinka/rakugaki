class Solution {
 public:
  int minOperations(vector<int> &nums, int x) {
    int sz = nums.size();
    int front = -1, back = 0;
    int ret = sz + 1;
    int l_sum = 0, r_sum = accumulate(nums.begin(), nums.end(), 0);

    while (front < sz) {
      if (front != -1)
        l_sum += nums[front];
      if (front == back) {
        r_sum -= nums[back++];
      }
      while (back < sz && l_sum + r_sum > x)
        r_sum -= nums[back++];
      if (l_sum + r_sum == x)
        ret = min(ret, front + 1 + (sz - back));
      ++front;
    }

    return ret > sz ? -1 : ret;
  }
};

