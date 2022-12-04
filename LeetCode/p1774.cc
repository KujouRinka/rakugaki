class Solution {
 public:
  int closestCost(const vector<int> &baseCosts, const vector<int> &toppingCosts, int target) {
    ret = baseCosts[0];
    tc = toppingCosts;
    tg = target;
    for (int i : baseCosts)
      helper(0, i);
    return ret;
  }

 private:
  int ret;
  int tg;
  vector<int> tc;

  void helper(int ti, int cur_sum) {
    if (betterThan(cur_sum, ret))
      ret = cur_sum;
    if (ti == tc.size())
      return;
    if (cur_sum > tg)
      return;
    for (int i = 0; i < 3; ++i) {
      helper(ti + 1, cur_sum + i * tc[ti]);
    }
  }

  bool betterThan(int a, int b) {
    int a1 = abs(a - tg), a2 = abs(b - tg);
    return a1 < a2 || a1 == a2 && a < b;
  }
};

