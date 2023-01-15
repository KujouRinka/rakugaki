class Solution {
  using ll = long long;
 public:
  int maxValue(int n, int index, int maxSum) {
    int left = 1, right = maxSum + 1;
    while (left < right) {
      int mid = left + ((right - left) >> 1);
      // check validation
      int left_item = min(index + 1, mid);
      int right_item = min(n - index, mid);
      ll left_sum = ((ll)mid + mid - left_item + 1) * left_item / 2;
      ll right_sum = ((ll)mid + mid - right_item + 1) * right_item / 2;
      ll sum = left_sum + right_sum - mid;
      if (sum <= maxSum - n) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};

