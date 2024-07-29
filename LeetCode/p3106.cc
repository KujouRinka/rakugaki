class Solution {
 public:
  string getSmallestString(string s, int k) {
    string ret;
    ret.reserve(s.size());

    for (char ch : s) {
      auto [c, l] = select(ch, k);
      ret.push_back(c);
      k -= l;
    }

    return ret;
  }

 private:
  pair<char, int> select(char ch, int k) {
    if (k >= 13) {
      return {'a', dist(ch, 'a')};
    }
    int b = ch - k;
    int e = ch + k;
    if (b <= 'a' || e > 'z') {
      return {'a', dist(ch, 'a')};
    }
    return {ch - k, k};
  }

  int dist(char a, char b) {
    return min(abs(a - b), min(abs(a - (b + 26)), abs(a + 26 - b)));
  }
};

