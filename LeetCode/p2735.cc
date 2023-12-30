class Solution {
 public:
  long long minCost(vector<int> &nums, int x) {
    vector<int> cost(nums);
    long long ret = INT64_MAX;
    for (int offset = 0; offset < nums.size(); ++offset) {
      long long c = 0;
      for (int i = 0; i < nums.size(); ++i) {
        cost[i] = min(cost[i], nums[(i + offset) % nums.size()]);
        c += cost[i];
      }
      c += static_cast<long long>(x) * offset;
      ret = min(ret, c);
    }
    return ret;
  }
};

