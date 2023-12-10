class Solution {
 public:
  int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end(), [](auto l, auto r) {
      return l > r;
    });
    int cnt = 1;
    for (auto it = citations.begin(); it != citations.end() && cnt <= *it; ++it, ++cnt) {}
    return cnt - 1;
  }
};

