class Solution {
 public:
  int longestContinuousSubstring(const string &s) {
    int ret = 0;
    int f = 0, b = 0;
    while (f < s.size()) {
      b = f + 1;
      while (b < s.size() && s[b] - s[b - 1] == 1) {
        ++b;
      }
      ret = max(ret, b - f);
      f = b;
    }
    return ret;
  }
};

