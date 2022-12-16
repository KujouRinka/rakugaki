class Solution {
 public:
  int minElements(vector<int> &nums, int limit, int goal) {
    long long memo = 0;
    for_each(nums.begin(), nums.end(), [&memo](int i) { memo += i; });
    memo = abs(memo - goal);
    return ceil(memo / static_cast<double>(limit));
  }
};

