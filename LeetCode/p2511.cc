class Solution {
 public:
  int captureForts(vector<int> &forts) {
    int b = 0;
    int ret = 0;
    int cnt = 0;
    for (int f : forts) {
      if (f == -1) {
        if (b == 1) {
          ret = max(ret, cnt);
        }
        cnt = 0;
        b = -1;
      } else if (f == 0) {
        ++cnt;
      } else {
        if (b == -1) {
          ret = max(ret, cnt);
        }
        cnt = 0;
        b = 1;
      }
    }
    return ret;
  }
};

