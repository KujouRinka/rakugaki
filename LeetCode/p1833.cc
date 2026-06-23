class Solution {
public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end(), less());
    int ret = 0;
    while (ret < costs.size() && coins >= costs[ret]) {
      coins -= costs[ret];
      ++ret;
    }
    return ret;
  }
};

