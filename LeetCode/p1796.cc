class Solution {
 public:
  int secondHighest(const string &s) {
    int fi = -1, se = -1;
    for (char ch : s) {
      if (!isdigit(ch))
        continue;
      int d = ch - '0';
      if (d > fi) {
        se = fi;
        fi = d;
      } else if (d > se && d != fi) {
        se = d;
      }
    }
    return se;
  }
};

