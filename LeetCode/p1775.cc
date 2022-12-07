class Solution {
 public:
  int minOperations(const vector<int> &nums1, const vector<int> &nums2) {
    int mp1[7] = {0}, mp2[7] = {0};
    int delta = 0;
    for (int i : nums1) {
      ++mp1[i];
      delta += i;
    }
    for (int i : nums2) {
      ++mp2[i];
      delta -= i;
    }
    int ret;
    if (delta > 0) {  // nums1 > nums2
      ret = doCalc(mp1, mp2, delta);
    } else {
      ret = doCalc(mp2, mp1, -delta);
    }
    return ret;
  }

 private:
  int doCalc(int *mp1, int *mp2, int delta) {
    int ret = 0;
    int p1 = 6, p2 = 1;
    while (delta > 0 && p1 > 0) {
      while (mp1[p1] > 0 && delta > 0) {
        delta -= p1 - 1;
        --mp1[p1];
        ++ret;
      }
      while (mp2[p2] > 0 && delta > 0) {
        delta -= 6 - p2;
        --mp2[p2];
        ++ret;
      }
      if (p1 > 0 && (mp1[p1] == 0 && mp2[p2] == 0)) {
        --p1;
        ++p2;
      }
    }
    if (delta > 0)
      ret = -1;
    return ret;
  }
};

