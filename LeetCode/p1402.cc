class Solution {
 public:
  int maxSatisfaction(vector<int> &satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    auto start = lower_bound(satisfaction.begin(), satisfaction.end(), 0);
    int idx = 1;
    auto [f, s] = accumulate(start, satisfaction.end(), make_pair(0, 0), [&idx](auto p, int s) {
      return make_pair(p.first + s * idx++, p.second + s);
    });
    auto f_prev = f;
    for (auto rit = vector<int>::reverse_iterator(start); f_prev <= f && rit != satisfaction.rend(); ++rit) {
      f_prev = f;
      s += *rit;
      f += s;
    }
    return max(f_prev, f);
  }
};

