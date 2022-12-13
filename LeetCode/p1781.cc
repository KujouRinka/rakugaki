class Solution {
 public:
  int beautySum(const string &s) {
    int ret = 0;
    int mp[26] = {0};
    for (int front = 0; front < s.size(); ++front) {
      memset(mp, 0, sizeof(mp));
      int max_v = 0;
      for (int back = front; back < s.size(); ++back) {
        if (++mp[s[back] - 'a'] > max_v)
          ++max_v;
        int min_v = minInArr(mp);
        ret += max_v - min_v;
      }
    }
    return ret;
  }

 private:
  int minInArr(int *arr) {
    int ret = 0x7fffffff;
    for (int i = 0; i < 26; ++i) {
      if (arr[i])
        ret = min(ret, arr[i]);
    }
    return ret;
  }
};

