class Solution {
  const int MOD = 1e9 + 7;
 public:
  int waysToSplit(const vector<int> &nums) {
    ps.resize(nums.size() + 1);
    ps[0] = 0;
    for (int i = 1; i <= nums.size(); ++i)
      ps[i] = ps[i - 1] + nums[i - 1];
    int ret = 0;
    int front = 1, lower = 2, upper = 1;
    while (front < nums.size() - 1 && ps[front] * 3 <= ps.back()) {
      // find lower
      lower = max(lower, front + 1);
      while (lower < nums.size() - 1 && getPs(0, front) > getPs(front, lower)) {
        ++lower;
      }
      while (upper < nums.size() && getPs(front, upper) <= getPs(upper, nums.size())) {
        ++upper;
      }

      ret = (ret + (upper - lower) % MOD) % MOD;
      ++front;
    }
    return ret;
  }

 private:
  vector<int> ps;

  int getPs(int begin, int end) {
    return ps[end] - ps[begin];
  }
};

