class Solution {
 public:
  bool checkIfPangram(const string &sentence) {
    int mp[26] = {0};
    int ok = 26;
    for (char ch : sentence) {
      if (mp[ch - 'a']++ == 0)
        --ok;
    }
    return ok == 0;
  }
};

