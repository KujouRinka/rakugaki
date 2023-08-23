class Solution {
 public:
  bool canChange(string start, string target) {
    if (start.size() != target.size()) {
      return false;
    }
    int lc = 0, rc = 0;
    for (int i = 0; i < start.size(); ++i) {
      auto ch1 = start[i];
      auto ch2 = target[i];
      if (ch2 == 'R' && lc != 0 || ch1 == 'L' && rc != 0) {
        return false;
      }
      if (ch1 == 'R') {
        --rc;
      }
      if (ch2 == 'L') {
        ++lc;
      } else if (ch2 == 'R' && rc++ == 0) {
        return false;
      }
      if (ch1 == 'L' && lc-- == 0) {
        return false;
      }
    }
    return lc == 0 && rc == 0;
  }
};

