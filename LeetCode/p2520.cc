class Solution {
 public:
  int countDigits(int num) {
    int ret = 0;
    int n = num;
    while (n > 0) { 
      if (num % (n % 10) == 0) {
        ++ret;
      }
      n /= 10;
    }
    return ret;
  }
};

