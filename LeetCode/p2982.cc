namespace std {
template<>
struct hash<std::pair<int, int>> {
  std::size_t operator()(const std::pair<int, int> &p) const {
    auto h1 = std::hash<int>{}(p.first);
    auto h2 = std::hash<int>{}(p.second);
    return h1 ^ (h2 << 1);
  }
};
}

class Solution {
 public:
  int maximumLength(const string &s) {
    // ch * len, times
    unordered_map<pair<int, int>, int> m;

    int max_len = -1;

    int begin = 0;
    for (; begin < s.size();) {
      int end = begin;
      while (end < s.size() && s[begin] == s[end]) {
        ++end;
      }

      int len = end - begin;
      for (int i = 0; i < len; ++i) {
        m[make_pair(s[begin], i + 1)] += len - i;
        if (m[make_pair(s[begin], i + 1)] >= 3 && (i + 1) >= max_len) {
          max_len = i + 1;
        }
      }

      begin = end;
    }

    return max_len;
  }
};

