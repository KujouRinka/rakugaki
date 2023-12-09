class Solution {
  constexpr static int MOD = 1e9 + 7;
 public:
  int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
    horizontalCuts.push_back(h);
    verticalCuts.push_back(w);
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int last = 0;
    int max_ho = 0;
    for (int ho : horizontalCuts) {
      max_ho = max(max_ho, ho - last);
      last = ho;
    }
    last = 0;
    int max_ve = 0;
    for (int ve : verticalCuts) {
      max_ve = max(max_ve, ve - last);
      last = ve;
    }
    return (static_cast<long long>(max_ho) % MOD) * (max_ve % MOD) % MOD;
  }
};

