class Solution {
 public:
  int alternateDigitSum(int n) {
    int ret = 0;
    int sign = 1;
    while (n > 0) {
      ret += n % 10 * sign;
      n /= 10;
      sign = -sign;
    }
    return sign * -ret;
  }
};

