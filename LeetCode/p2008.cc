class Solution {
  struct Cmp {
    bool operator()(vector<int> *v_ptr, int i) { return (*v_ptr)[1] < i; }
    bool operator()(int i, vector<int> *v_ptr) { return i < (*v_ptr)[1]; }
  };
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
    vector<vector<int> *> end_ptr;
    end_ptr.reserve(rides.size());
    for (auto &ride : rides) {
      ride[2] += ride[1] - ride[0];
      end_ptr.push_back(&ride);
    }
    sort(end_ptr.begin(), end_ptr.end(), [](auto l, auto r) {
      return (*l)[1] < (*r)[1];
    });
    vector<long long> dp(n + 1);
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1];
      auto p = equal_range(end_ptr.begin(), end_ptr.end(), i, Cmp());
      for (auto it = p.first; it != p.second; ++it) {
        dp[i] = max(dp[i], dp[(**it)[0]] + (**it)[2]);
      }
    }
    return dp[n];
  }
};

