class Solution {
  static constexpr int MOD = 1e9 + 7;
  using unit = pair<int, int>;
  using hp_t = priority_queue<unit, vector<unit>, function<bool(unit &, unit &)>>;
 public:
  int getNumberOfBacklogOrders(const vector<vector<int>> &orders) {
    hp_t buy([](auto &l, auto &r) { return l.first < r.first; });
    hp_t sell([](auto &l, auto &r) { return l.first > r.first; });
    int ret = 0;
    for (auto item : orders) {
      if (item[2] == 0) {   // buy
        while (item[1] > 0 && !sell.empty() && sell.top().first <= item[0]) {
          int to_min = min(sell.top().second, item[1]);
          const_cast<unit &>(sell.top()).second -= to_min;
          item[1] -= to_min;
          ret = (ret + MOD - to_min) % MOD;
          if (sell.top().second == 0)
            sell.pop();
        }
        if (item[1] > 0)
          buy.push({item[0], item[1]});
      } else {    // sell
        while (item[1] > 0 && !buy.empty() && buy.top().first >= item[0]) {
          int to_min = min(buy.top().second, item[1]);
          const_cast<unit &>(buy.top()).second -= to_min;
          item[1] -= to_min;
          ret = (ret + MOD - to_min) % MOD;
          if (buy.top().second == 0)
            buy.pop();
        }
        if (item[1] > 0)
          sell.push({item[0], item[1]});
      }
      ret = (ret + item[1]) % MOD;
    }

    return ret;
  }
};

