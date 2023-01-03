class Solution {
 public:
  bool areNumbersAscending(const string &s) {
    int p = 0;
    int last = -1;
    while (true) {
      while (p < s.size() && !isdigit(s[p]))
        ++p;
      if (p == s.size())
        break;
      int cur = 0;
      while (p < s.size() && isdigit(s[p])) {
        cur *= 10;
        cur += s[p++] - '0';
      }
      if (last >= cur)
        return false;
      last = cur;
    }
    return true;
  }
};

