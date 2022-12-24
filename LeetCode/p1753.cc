class Solution {
 public:
  int maximumScore(int a, int b, int c) {
    if (a > b + c) return b + c;
    if (b > a + c) return a + c;
    if (c > a + b) return a + b;
    return (a + b + c) >> 1;
  }
};

