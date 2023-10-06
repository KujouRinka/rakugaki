#include <execution>

class Solution {
 public:
  long long repairCars(vector<int> &ranks, int cars) {
    long long lower = 1, upper = INT64_MAX;
    while (lower <= upper) {
      auto mid = lower + ((upper - lower) >> 1);
      auto repaired_cars =
          transform_reduce(execution::par, ranks.begin(), ranks.end(), 0LL, std::plus{}, [mid](auto &rank) {
            return static_cast<long long>(std::sqrt(mid / rank));
          });
      if (cars > repaired_cars) {
        lower = mid + 1;
      } else {
        upper = mid - 1;
      }
    }
    return lower;
  }
};

