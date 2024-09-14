class Solution {
 public:
  string removeStars(string s) {
    string ret;
    ret.reserve(s.size() / 2);

    for (char ch : s) {
      if (ch == '*') {
        ret.pop_back();
      } else {
        ret.push_back(ch);
      }
    }

    return ret;
  }
};

