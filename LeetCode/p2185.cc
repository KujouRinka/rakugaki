class Solution {
 public:
  int prefixCount(const vector<string>& words, const string &pref) {
    int ret = 0;
    auto len = pref.size();
    for (auto &s: words) {
      string_view view(s);
      if (view.substr(0, len) == pref)
        ++ret;
    }
    return ret;
  }
};

