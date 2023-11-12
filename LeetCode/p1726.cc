class Solution {
 public:
  int tupleSameProduct(vector<int> &nums) {
    unordered_map<int, int> stat;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        ++stat[nums[i] * nums[j]];
      }
    }
    int ret = 0;
    for (auto &[key, val] : stat) {
      if (val > 1) {
        ret += val * (val - 1) * 4;
      }
    }
    return ret;
  }
};

