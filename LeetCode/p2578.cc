class Solution {
 public:
  int splitNum(int num) {
    vector<int> v;
    v.reserve(10);
    while (num != 0) {
      v.push_back(num % 10);
      num /= 10;
    }
    sort(v.begin(), v.end());
    int n1 = 0, n2 = 0;
    bool st = true;
    for (auto i : v) {
      auto &ref = st ? n1 : n2;
      ref *= 10;
      ref += i;
      st = !st;
    }
    return n1 + n2;
  }
};

