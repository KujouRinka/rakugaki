class Solution {
 public:
  int lengthOfLongestSubstring(const string &s) {
    int hash[127] = {0};
    int front = 0, back = 0;
    int ret = 0;
    while (back < s.size()) {
      ++hash[s[back]];
      while (hash[s[back]] > 1)
        --hash[s[front++]];
      ret = max(ret, back - front + 1);
      ++back;
    }
    return ret;
  }
};

