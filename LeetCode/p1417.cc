class Solution {
 public:
  string reformat(string s) {
    auto sz = s.size();
    ssize_t al = count_if(s.begin(), s.end(), ::isalpha);
    ssize_t di = sz - al;
    if (abs(al - di) > 1)
      return "";
    string ret(sz, ' ');
    if (al > di) {
      al = 0;
      di = 1;
    } else {
      al = 1;
      di = 0;
    }
    for_each(s.begin(), s.end(), [&](char ch) {
      if (isalpha(ch)) {
        ret[al] = ch;
        al += 2;
      } else {
        ret[di] = ch;
        di += 2;
      }
    });
    return ret;
  }
};

