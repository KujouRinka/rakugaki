class Solution {
 public:
  string makeSmallestPalindrome(string s) {
    auto e = s.size() - 1;
    decltype(e) b = 0;
    while (b < e) {
      s[b] = s[e] = min(s[b], s[e]);
      ++b;
      --e;
    }
    return s;
  }
};

