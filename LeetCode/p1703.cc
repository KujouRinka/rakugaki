class Solution {
 public:
  int minMoves(const vector<int> &nums, int k) {
    vector<int> zeros;
    int p = 0;
    while (nums[p] == 0)
      ++p;
    while (p < nums.size()) {
      int f = p + 1;
      int b = f;
      while (b < nums.size() && nums[b] == 0)
        ++b;
      zeros.push_back(b - f);
      p = b;
    }
    zeros.pop_back();
    ps.resize(zeros.size() + 1);
    ps[0] = 0;
    partial_sum(zeros.begin(), zeros.end(), ps.begin() + 1);

    int cost = 0;
    int left = 0, right = k - 2;
    for (int i = 0; i <= right; ++i)
      cost += (min(i - left, right - i) + 1) * zeros[i];

    int ret = cost;
    ++left;
    ++right;
    while (right < zeros.size()) {
      int mid = (left + right) / 2;
      cost -= rangeSum(left - 1, mid - 1);
      cost += rangeSum(mid + k % 2, right);
      ret = min(ret, cost);
      ++left;
      ++right;
    }
    return ret;
  }

 private:
  vector<int> ps;

  int rangeSum(int left, int right) {
    return ps[right + 1] - ps[left];
  }
};

