class Solution {
 public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int out_hp = max(static_cast<int>(costs.size()) - 2 * candidates, 0);
    priority_queue<int, vector<int>, greater<>> hp_left;
    priority_queue<int, vector<int>, greater<>> hp_right;
    if (out_hp == 0) {
      hp_left = decltype(hp_left)(costs.begin(), costs.end());
    } else {
      hp_left = decltype(hp_left)(costs.begin(), costs.begin() + candidates);
      hp_right = decltype(hp_right)(costs.rbegin(), costs.rbegin() + candidates);
    }
    int lp = candidates, rp = costs.size() - candidates - 1;

    long long ret = 0;
    for (int i = 0; i < k; ++i) {
      int lv = hp_left.empty() ? 0x7fffffff : hp_left.top();
      int rv = hp_right.empty() ? 0x7fffffff : hp_right.top();
      if (lv <= rv) {
        hp_left.pop();
        ret += lv;
        if (out_hp-- > 0) {
          hp_left.push(costs[lp++]);
        }
      } else {
        hp_right.pop();
        ret += rv;
        if (out_hp-- > 0) {
          hp_right.push(costs[rp--]);
        }
      }
    }

    return ret;
  }
};

