class Solution {
 public:
  int minStoneSum(vector<int> &piles, int k) {
    priority_queue<int> hp;
    int ret = 0;
    for (int pile : piles) {
      ret += pile;
      hp.push(pile);
    }
    while (k--) {
      auto p = hp.top();
      hp.pop();
      auto to_remove = floor(p / 2);
      ret -= to_remove;
      hp.push(p - to_remove);
    }
    return ret;
  }
};

