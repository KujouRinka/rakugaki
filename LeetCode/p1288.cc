class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    std::ranges::sort(intervals, [](const auto &l, const auto &r) {
      return l[0] < r[0] || (l[0] == r[0] && l[1] > r[1]);
    });
    int max_right = 0;
    int ret = 0;
    for (auto &i: intervals) {
      if (i[1] > max_right) {
        max_right = i[1];
        ++ret;
      }
    }
    return ret;
  }
};

