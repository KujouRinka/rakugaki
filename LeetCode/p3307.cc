class Solution {
public:
  char kthCharacter(long long kk, const vector<int> &operations) {
    double k = kk - 1;
    double str_length = pow<double>(2, operations.size());

    int64_t offset = 0;
    for (auto op: operations | std::views::reverse) {
      if (out_of(str_length, k)) {
        throw logic_error("unreachable");
      }

      double half = str_length / 2;
      if (op == 0) {
        if (k - half >= 0) {
          k -= half;
        }
      } else if (op == 1) {
        if (k - half >= 0) {
          ++offset;
          k -= half;
        }
      }
      str_length = half;
    }
    return 'a' + offset % 26;
  }

private:
  static bool out_of(double length, double cur) {
    return cur + 1 > length;
  }
};

