class Solution {
 public:
  bool canChoose(const vector<vector<int>> &groups, const vector<int> &nums) {
    int p_groups = 0;
    int p_nums = 0;
    while (p_groups < groups.size() && p_nums < nums.size()) {
      while (p_nums < nums.size()) {
        if (match(groups[p_groups], nums, p_nums)) {
          p_nums += groups[p_groups++].size();
          break;
        }
        ++p_nums;
      }
    }
    return p_groups == groups.size();
  }

 private:
  bool match(const vector<int> &to, const vector<int> &from, int idx) {
    int i = 0;
    while (i < to.size() && idx < from.size()) {
      if (to[i] != from[idx])
        return false;
      ++i;
      ++idx;
    }
    return i == to.size();
  }
};

