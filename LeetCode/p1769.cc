class Solution {
 public:
  vector<int> minOperations(const string &boxes) {
    int left_cnt = 0, left_sum = 0;
    int right_cnt = 0, right_sum = 0;
    for (int i = 1; i < boxes.size(); ++i) {
      if (boxes[i] == '1') {
        ++right_cnt;
        right_sum += i;
      }
    }

    vector<int> ret(boxes.size());
    for (int i = 0; i < boxes.size(); ++i) {
      ret[i] = left_sum + right_sum;
      if (boxes[i] == '1')
        ++left_cnt;
      left_sum += left_cnt;
      right_sum -= right_cnt;
      if (i + 1 < boxes.size() && boxes[i + 1] == '1')
        --right_cnt;
    }
    return ret;
  }
};

