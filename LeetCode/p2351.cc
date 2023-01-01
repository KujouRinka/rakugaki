class Solution {
 public:
  char repeatedCharacter(const string &s) {
    uint32_t ihash = 0;
    for (char ch : s) {
      if (ihash & (1 << ch - 'a'))
        return ch;
      ihash |= 1 << ch - 'a';
    }
    return -1;
  }
};

