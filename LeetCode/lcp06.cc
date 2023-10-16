class Solution {
 public:
  int minCount(vector<int> &coins) {
    return accumulate(coins.begin(), coins.end(), 0, [](int acc, int x) {
      return acc + ((x + 1) >> 1);
    });
  }
};

