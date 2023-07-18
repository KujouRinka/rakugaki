class Solution {
 public:
  vector<int> minInterval(vector<vector<int>> &itv, vector<int> &q) {
    int n = q.size();
    vector<int> ans(n, -1);
    set<pair<int, int>> st;
    for (int i = 0; i < n; ++i) st.emplace(q[i], i);
    sort(itv.begin(), itv.end(), [&](const auto &a, const auto &b) { return a[1] - a[0] < b[1] - b[0]; });
    for (auto &v : itv) {
      auto it = st.lower_bound({v[0], -1});
      while (it != st.end() && it->first <= v[1]) {
        ans[it->second] = v[1] - v[0] + 1, st.erase(it++);
      }
    }
    return ans;
  }
};

