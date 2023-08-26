class Solution {
 public:
  int maxAbsoluteSum(vector<int> &nums) {
    int ps = 0, ns = 0;
    int pm = 0, nm = 0;

    for (int i : nums) {
      ps += i;
      ns -= i;
      pm = max(pm, ps);
      nm = max(nm, ns);
      if (ps < 0) {
        ps = 0;
      }
      if (ns < 0) {
        ns = 0;
      }
    }
    return max(pm, nm);
  }
};

