class Solution {
public:
  string processStr(const string &s) {
    string ret;
    for (auto ch: s) {
      switch (ch) {
        case '*':
          if (!ret.empty()) {
            ret.pop_back();
          }
          break;
        case '#':
          ret.append(ret);
          break;
        case '%':
          reverse(ret.begin(), ret.end());
          break;
        default:
          ret.push_back(ch);
      }
    }
    return ret;
  }
};

