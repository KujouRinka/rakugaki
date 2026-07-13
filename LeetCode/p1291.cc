class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ret;
    for (int window_size = 1; window_size < 10; ++window_size) {
      int cur = 0;
      int MOD = pow(10, window_size - 1);
      for (int i = 0; i < window_size; ++i) {
        cur = cur * 10 + (i + 1);
      }
      if (cur > high) {
        goto goret;
      }
      if (cur >= low) {
        ret.push_back(cur);
      }
      for (int end = window_size + 1; end < 10; ++end) {
        cur = cur % MOD * 10 + end;
        if (cur > high) {
          goto goret;
        }
        if (cur >= low) {
          ret.push_back(cur);
        }
      }
    }

  goret:
    return ret;
  }
};

