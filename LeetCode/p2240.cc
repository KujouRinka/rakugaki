class Solution {
 public:
  long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long ret = 0;
    for (int c = total; c >= 0; c -= cost1) {
      ret += c / cost2 + 1;
    }
    return ret;
  }
};

