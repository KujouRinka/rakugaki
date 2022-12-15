class Solution {
 public:
  int getLucky(const string &s, int k) {
    int ret = 0;
    for (char ch : s) {
      int n = ch - 'a' + 1;
      while (n > 0) {
        ret += n % 10;
        n /= 10;
      }
    }
    while (--k) {
      int tmp = 0;
      while (ret > 0) {
        tmp += ret % 10;
        ret /= 10;
      }
      ret = tmp;
    }
    return ret;
  }
};

