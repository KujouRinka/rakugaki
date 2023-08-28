class Solution {
 public:
  int subtractProductAndSum(int n) {
    int m = 1, s = 0;
    while (n > 0) {
      int i = n % 10;
      m *= i;
      s += i;
      n /= 10;
    }
    return m - s;
  }
};

