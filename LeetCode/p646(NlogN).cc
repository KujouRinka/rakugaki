class Solution {
 public:
  int findLongestChain(vector<vector<int>> &pairs) {
    sort(pairs.begin(), pairs.end());
    vector<int> g(pairs.size() + 1, INT32_MIN);
    int ret = 0;
    for (int i = 0; i < pairs.size(); ++i) {
      auto it = lower_bound(g.begin(), g.begin() + ret + 1, pairs[i][0]);
      if (it == g.begin() + ret + 1) {
        ++ret;
        *it = pairs[i][1];
      } else if (pairs[i][0] < *it) {
        *it = min(pairs[i][1], *it);
      }
    }
    return ret;
  }
};

