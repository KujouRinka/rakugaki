class Solution {
 public:
  int minimumMountainRemovals(vector<int> &nums) {
    vector<int> l(nums.size());
    LIS(nums.begin(), nums.end(), l.begin());
    vector<int> r(nums.size());
    LIS(nums.rbegin(), nums.rend(), r.rbegin());

    int t = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (l[i] > 1 && r[i] > 1) {
        t = max(t, l[i] + r[i] - 1);
      }
    }
    return nums.size() - t;
  }

 private:
  template<typename InputIter, typename OutputIter>
  void LIS(InputIter begin, InputIter end, OutputIter output) {
    vector<typename iterator_traits<InputIter>::value_type> memo;
    for (auto it = begin; it != end; ++it) {
      auto b = lower_bound(memo.begin(), memo.end(), *it);
      if (b == memo.end()) {
        memo.push_back(*it);
        *output++ = memo.size();
      } else {
        *b = *it;
        *output++ = distance(memo.begin(), b) + 1;
      }
    }
  }
};

