class Solution {
 public:
  int passThePillow(int n, int time) {
    if (n == 1) {
      return 1;
    }
    auto lp = time / (n - 1);
    auto remainder = time % (n - 1);
    return (lp & 1) ? n - remainder : remainder + 1;
  }
};

