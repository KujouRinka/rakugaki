class Solution {
 public:
  int expressiveWords(const string &s, vector<string> &words) {
    int ret = 0;
    for (auto &tcs : words) {
      if (doCheck(s, tcs))
        ++ret;
    }
    return ret;
  }

 private:
  bool doCheck(const string &s, const string &to_check) {
    int p1 = 0, p2 = 0;
    while (true) {
      if (p1 >= s.size()) {
        if (p2 >= to_check.size())
          break;
        return false;
      }

      char cp1 = s[p1];
      char cp2 = to_check[p2];
      if (cp1 != cp2)
        return false;

      int p1_cons = 0;
      int p2_cons = 0;
      while (p1 < s.size() && s[p1] == cp1) {
        ++p1_cons;
        ++p1;
      }
      while (p2 < s.size() && to_check[p2] == cp2) {
        ++p2_cons;
        ++p2;
      }
      if (!(p1_cons == p2_cons || (p1_cons > p2_cons && p1_cons >= 3)))
        return false;
    }
    return true;
  }
};

