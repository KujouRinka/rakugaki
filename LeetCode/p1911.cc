class Solution {
 public:
  long long maxAlternatingSum(vector<int> &nums) {
    nums.push_back(0);
    auto [f, b] = make_tuple(0LL, 1LL);
    decltype(f) ret = 0;
    while (f < nums.size() && b < nums.size()) {
      if (nums[f] > nums[b])
        ret += nums[f] - nums[b];
      f = b++;
    }
    return ret;
  }
};

