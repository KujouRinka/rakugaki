class Solution {
 public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> ret(nums.size());
    // find mid pos
    int r = 0;
    for (; r < nums.size() && nums[r] < 0; ++r);
    int l = r - 1;
    int rp = 0;
    while (l >= 0 && r < nums.size()) {
      int ll = nums[l], rr = nums[r];
      ret[rp++] = -ll < rr ? (--l, ll * ll) : (++r, rr * rr);
    }
    while (l >= 0) {
      int n = nums[l--];
      ret[rp++] = n * n;
    }
    while (r < nums.size()) {
      int n = nums[r++];
      ret[rp++] = n * n;
    }
    return ret;
  }
};

