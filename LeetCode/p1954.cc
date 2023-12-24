class Solution {
 public:
  long long minimumPerimeter(long long neededApples) {
    long long lower = 0;
    long long upper = 100000;
    while (lower < upper) {
      auto mid = lower + ((upper - lower) >> 1);
      if (q_apple(mid) < neededApples) {
        lower = mid + 1;
      } else {
        upper = mid;
      }
    }
    return lower * 8;
  }

 private:
  long long q_apple(long long x) {
    return x * (x + 1) * (2 * x + 1) * 2;
  }
};

