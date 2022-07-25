class Solution {
 public:
  int arrayNesting(const vector<int> &nums) {
    if (nums.empty())
      return 0;
    vector<bool> used(nums.size(), false);
    int ret = 0;
    for (int i = 0; i < used.size(); ++i) {
      if (!used[i]) {
        used[i] = true;
        int cur_i = nums[i];
        int cur_cnt = 1;
        while (cur_i < nums.size() && !used[cur_i]) {
          used[cur_i] = true;
          cur_i = nums[cur_i];
          ++cur_cnt;
        }
        ret = max(ret, cur_cnt);
      }
    }
    return ret;
  }
};

