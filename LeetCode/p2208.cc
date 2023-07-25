class Solution {
 public:
  int halveArray(vector<int> &nums) {
    double sum = accumulate(nums.begin(), nums.end(), 0.0);
    double to_min = sum / 2.0;
    priority_queue<double> q(nums.begin(), nums.end());
    int ret = 0;
    while (to_min > 0) {
      double top = q.top();
      q.pop();
      to_min -= top / 2.0;
      q.push(top / 2.0);
      ++ret;
    }
    return ret;
  }
};

