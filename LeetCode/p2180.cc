class Solution {
 public:
  int countEven(int num) {
    int ret = -1;
    ret += num / 10 * 5;

    int memo = 0;
    int ad = num % 10 + 1;
    while (num > 0) {
      if (num % 10 & 1)
        ++memo;
      num /= 10;
    }
    ret += ad / 2 + ((ad & 1) && !(memo & 1) ? 1 : 0);

    return ret;
  }
};

