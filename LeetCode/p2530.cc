class Solution {
 public:
  long long maxKelements(vector<int> &nums, int k) {
    priority_queue<int> hp(nums.begin(), nums.end());
    long long ret = 0;
    for (int i = 0; i < k; ++i) {
      auto t = hp.top();
      hp.pop();
      ret += t;
      hp.push((t + 2) / 3);
    }
    return ret;
  }
};

