class Solution {
 public:
  bool check(vector<int>& nums) {
    int unordered_cnt = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < nums[i - 1])
        if (++unordered_cnt > 1)
          return false;
    }
    if (unordered_cnt == 1 && nums.front() < nums.back())
      return false;
    return true;
  }
};

