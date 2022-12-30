class Solution {
 public:
  int finalValueAfterOperations(vector<string> &operations) {
    int ret = 0;
    for (auto &s : operations) {
      ret += s[1] == '+' ? 1 : -1;
    }
    return ret;
  }
};

